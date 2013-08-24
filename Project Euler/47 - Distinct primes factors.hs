import Data.List

primes = 2 : filter isPrime [3,5..]
isPrime = null . tail . factorize
factorize = factorize' primes
    where factorize' (p:ps) n
            | p*p > n        = [n]
            | n `mod` p == 0 = p : factorize' (p:ps) (n `div` p)
            | otherwise      = factorize' ps n

distinct4 = (==4) . length . group . factorize

consecutive4 xs = c4 1 ((-1):xs)
    where c4 4 (x:y:xs) = (x - 3)
          c4 n (x:y:xs) = if x+1 == y then
                            c4 (n+1) (y:xs)
                          else
                            c4 1 (y:xs)

main = print . consecutive4 . filter distinct4 $ [1..]
