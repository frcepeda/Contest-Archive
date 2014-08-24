import Data.List
import Text.Printf
area [x,y] = (sum (zipWith (*) xs (tail ys)) - sum (zipWith (*) ys (tail xs))) / 2
    where xs = x ++ [head x]
          ys = y ++ [head y]
main = (\a -> (printf "%.01f\n%s\n" :: Double -> String -> IO ()) (abs a) (if a < 0 then "SM" else "SCM")) . area . transpose . map (map read . words) . tail . lines =<< getContents
