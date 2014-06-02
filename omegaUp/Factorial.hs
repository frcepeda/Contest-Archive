{-# LANGUAGE BangPatterns #-}

import Data.List
import Debug.Trace
import Control.Monad
import Control.Applicative

primes = [2,3,5,7,11,13,17,19,23,29,31]

factorize = fct primes
    where fct _ 1 = []
          fct pss@(p:ps) x = if r == 0 then p:fct pss q else fct ps x
            where (q,r) = quotRem x p

countFactorial !z !n p
    | n < p = z
    | otherwise = countFactorial (z+q) q p where q = div n p

solve :: [Int] -> Int
solve [n,b] = minimum $ map (\ps -> (countFactorial 0 n (head ps)) `div` length ps) facts
    where facts = group $ factorize b

main = void $ (flip replicateM) (print . solve . map read . words =<< getLine) =<< read <$> getLine
