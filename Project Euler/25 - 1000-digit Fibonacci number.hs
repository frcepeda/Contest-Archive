import Data.List

newtype Matrix a = Matrix [[a]] deriving (Eq, Show)

instance Num a => Num (Matrix a) where
    Matrix as + Matrix bs = Matrix (zipWith (zipWith (+)) as bs)
    Matrix as - Matrix bs = Matrix (zipWith (zipWith (-)) as bs)
    Matrix as * Matrix bs =
       Matrix [[sum $ zipWith (*) a b | b <- transpose bs] | a <- as]
    negate (Matrix as) = Matrix (map (map negate) as)
    fromInteger x = Matrix (iterate (0:) (fromInteger x : repeat 0))
    abs m = m
    signum _ = 1

apply :: Num a => Matrix a -> [a] -> [a]
apply (Matrix as) b = [sum (zipWith (*) a b) | a <- as]

fib :: Integer -> Integer
fib n = head (apply (Matrix [[0,1], [1,1]] ^ n) [0,1])

bsearch :: Integer -> Integer -> Integer
bsearch lo hi
    | lo == hi    = hi
    | len >= 1000 = bsearch lo mid
    | otherwise   = bsearch (mid+1) hi
    where mid = (lo + hi) `div` 2
          len = (length . show)(fib mid)

main = print (bsearch 0 (2^20))
