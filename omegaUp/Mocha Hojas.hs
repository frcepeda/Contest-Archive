-- 100/100 points
import Data.Array
import Data.List
import Control.Applicative

swap (a,b) = (b,a)
toTuple [a,b] = (a,b)
largestMult 0 _ = 0
largestMult m a = (a `div` m) * m

f g c n p
   | deg == 0 = (c!n, 1)
   | otherwise = (deg * m, deg * l)
      where ch = [f g c x n | x <- g!n, x /= p]
            deg = length (g!n) - (if n /= 1 then 1 else 0)
            (m,l) = foldl1' g ch
                  where g (a,b) (n,m) = (largestMult l (min a n), l)
                                           where l = lcm b m

main = do
	n <- read <$> getLine
	lCosts <- (map read . words <$> getLine)
	oneWay <- (map (toTuple . map read . words) . lines <$> getContents)
	let edges = oneWay ++ map swap oneWay
	let c = array (1,n) (zipWith (,) [1..] lCosts)
	let g = accumArray (flip (:)) [] (1,n) edges
	print $ sum lCosts -  fst (f g c 1 (-1))
