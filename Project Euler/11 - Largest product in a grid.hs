import Control.Monad
import Data.List

prods = map (product . take 4) . tails

maxprod = maximum . foldr1 (++) . map prods

diagonals xss = drop 1 (map mainDiagonal left ++ map mainDiagonal right)
    where xss' = transpose xss
          left = take (length xss) . iterate tail $ xss
          right = take (length xss') . iterate tail $ xss'
          mainDiagonal = map head . takeWhile (not . null). zipWith drop [0..]

solve xss = maximum $ map maxprod [rows, cols, right, left]
    where rows = xss
          cols = transpose xss
          right = diagonals xss
          left = diagonals (map reverse xss)

main = print . solve . parse =<< getContents
    where parse = map (map read . words) . lines
