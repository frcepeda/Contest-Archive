import Control.Applicative
import Data.List

data Matrix a = Matrix [[a]] a deriving (Eq, Show)

instance (Num a, Integral a) => Num (Matrix a) where
    Matrix a m * Matrix b _ = Matrix [[mod (sum $ zipWith (*) x y) m | y <- transpose b] | x <- a] m

identity x = [replicate i 0 ++ [1] ++ replicate (x-i-1) 0 | i <- [0..x-1]]

main = do
    [n,m,_mod] <- map read . words <$> getLine
    coeff <- map read . words <$> getLine

    let mat = Matrix (tail (identity n) ++ [coeff]) _mod
    let final = mat ^ (m-1) * Matrix (replicate n [1]) _mod

    print . head . head $ case final of Matrix i _ -> i
