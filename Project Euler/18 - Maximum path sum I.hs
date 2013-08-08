import Control.Monad
import Data.List

maximum' [] = 0
maximum' xs = maximum xs

solve = head . foldr1 (\xs ys -> zipWith (+) xs (map (maximum' . take 2) (tails ys)))

main = print . solve . parse =<< getContents
    where parse = map (map read . words) . lines
