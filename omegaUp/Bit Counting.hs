import Data.Array as A
import Data.Bits
import Data.List
import Data.Char
import Data.Int

maxB = 63

toBits :: Int64 -> String
toBits 0 = "0"
toBits x = reverse $ unfoldr z x
	where z 0 = Nothing
	      z x = Just (intToDigit (fromIntegral r), q)
	      	where (q,r) = quotRem x 2

fact :: (Integral a) => a -> Integer
fact 0 = 1
fact n = foldl (*) 1 [1..fromIntegral n]
choose n k
	| n < k = 0
	| otherwise = fromIntegral $ fact n `div` (fact (n-k) * fact k)

k :: (Num a, Bits a) => a -> Int64
k 1 = 0
k x = 1 + k (popCount x)

g :: Int64 -> Int64 -> Int64
g y b = g' yb lb b
	where yb = toBits y
	      lb = fromIntegral $ length yb - 1
	      g' _ _ 0 = 1
	      g' [] _ _ = 0
	      g' ('0':y) l z = g' y (l-1) z
	      g' ('1':y) l z = choose l z + g' y (l-1) (z-1)

f x y = sum . map (g y) . filter ((== x-1) . k) $ [1..maxB]

solve :: [Int64] -> Int64
solve [lo,_,0] = if lo <= 1 then 1 else 0
solve [lo,hi,1] = fromIntegral $ length . takeWhile (<= fromIntegral hi) . dropWhile (< fromIntegral lo) $ p
	where p = 2 : map (*2) p
solve [lo,hi,x] = f x hi - f x (lo - 1)

main = print . solve . map read . words =<< getContents