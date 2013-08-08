import Data.List

isPrime = (==1) . length . primeFactors

primes = 2 : filter isPrime [3,5..]

primeFactors n = factorize n primes
    where factorize n pss@(p:ps)
            | p * p > n      = [n]
            | n `mod` p == 0 = p : factorize (n `div` p) pss
            | otherwise      = factorize n ps

isCircular n = foldr ((&&) . isPrime) True cyclic
    where str = show n
          len = length str
          cyclic = take len $ map (read . take len) (tails (cycle str))

main = print . length . filter isCircular . takeWhile (<=10^6) $ primes
