import Data.List

kthPermutation k xs = buildPermutation xs (factoradic [] k 1)
                      where n = length xs
                            factoradic acc k i
                                       | i > n     = acc
                                       | otherwise = factoradic (next:acc) (k `div` i) (i+1)
                                                     where next = k `mod` i
                            buildPermutation [] _ = []
                            buildPermutation xs (i:is) = next : buildPermutation (delete next xs) is
                                                         where next = xs !! i

main = print $ kthPermutation 999999 [0..9]
