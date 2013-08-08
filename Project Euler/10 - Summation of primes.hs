primes = 2 : filter ((==1) . length . primeFactors) [3,5..]

primeFactors n = factorize n primes
            where factorize n (p:ps)
                        | p * p > n      = [n]
                        | n `mod` p == 0 = p : factorize (n `div` p) ps
                        | otherwise      = factorize n ps

main = print . sum . takeWhile (< 2000000) $ primes
