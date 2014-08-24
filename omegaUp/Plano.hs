import Data.List
import Control.Monad
import Control.Applicative

factorial 0 = 1
factorial x = foldl1' (*) [1..x]
a `choose` b = factorial a `div` (factorial b * factorial (a - b))

ways [x,y,a,b] = (xd + yd) `choose` xd
    where xd = abs (x-a)
          yd = abs (y-b)

main = void $ (flip replicateM) (print . ways . map read . words =<< getLine) =<< read <$> getLine
