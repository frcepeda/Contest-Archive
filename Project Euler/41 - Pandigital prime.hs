import Data.List
import Data.Ix
import Data.Char

isPrime 1 = False
isPrime n = null . tail . primeFactors $ n

primes = 2 : filter isPrime [3,5..]

primeFactors n = uniqfact n primes
    where uniqfact n (p:ps)
             | p * p > n      = [n]
             | n `mod` p == 0 = p : uniqfact n ps
             | otherwise      = uniqfact n ps

main = print . maximum . filter isPrime . concatMap (map read . permutations . map intToDigit . range) . zipWith (,) (repeat 1) $ [1..9]
