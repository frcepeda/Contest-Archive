import Control.Applicative
import Data.List

solve n a = if c then "YES" else "NO"
    where xs = sort a
          f xs = length xs < 3 || not ((xs!!0)+1 == xs!!1 && (xs!!1)+1 == xs!!2)
          c = null xs || (head xs /= 1 && last xs /= n && all f (tails xs))

main = do
    n:m:a <- map read . words <$> getContents
    putStrLn $ solve n a
