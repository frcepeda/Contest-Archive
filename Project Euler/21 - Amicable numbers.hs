import Data.Array
import Data.List

limit = 10^4

primes = 2 : filter ((==1) . length . primeFactors) [3,5..]

primeFactors n = factorize n primes
    where factorize n pss@(p:ps)
                | p * p > n      = [n]
                | n `mod` p == 0 = p : factorize (n `div` p) pss
                | otherwise      = factorize n ps

divisorSum n = dS ! n
        where dS = listArray (1,limit) (map divSum [1..])
              divSum n = (product . map (sum . (\(p,c) -> zipWith (^) (repeat p) [0..c])) . ps $ n) - n
                where ps = map (\x -> (head x, length x)) . group . primeFactors

isAmicable n = m /= n && m < limit && n == divisorSum m
    where m = divisorSum n

main = print . sum . filter isAmicable $ [1..limit-1]
