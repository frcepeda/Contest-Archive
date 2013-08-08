import Data.Function

primes = 2 : filter ((==1) . length . primeFactors) [3,5..]

primeFactors :: Int -> [Int]
primeFactors n | n > 1 = factorize n primes
    where factorize n (p:ps)
                    | p * p > n      = [n]
                    | n `mod` p == 0 = p : factorize (n `div` p) ps
                    | otherwise      = factorize n ps

main = print . maximum . primeFactors $ 600851475143
