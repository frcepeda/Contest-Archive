import Data.List

triangular = scanl (+) 0 [1..]
primes = 2 : filter ((==1) . length . primeFactors) [3,5..]

primeFactors n = factorize n primes
                 where factorize n pss@(p:ps)
                                | p * p > n      = [n]
                                | n `mod` p == 0 = p : factorize (n `div` p) pss
                                | otherwise      = factorize n ps

divisorCount n = product $ map ((+1) . length) (group (primeFactors n))

main = print . head . filter ((>500) . divisorCount) $ triangular
