import Data.Array

fact n = foldr1 (*) [1..n]

choose n k = fact n `div` (fact k * fact (n-k))

main = print ((20+20) `choose` (20))
