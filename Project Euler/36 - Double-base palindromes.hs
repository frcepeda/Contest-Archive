rbase2 n
    | n == 0    = []
    | otherwise = r : rbase2 q
                  where (q,r) = n `divMod` 2

main = print . sum . filter doublePalindrome $ [1..10^6-1]
    where doublePalindrome x = dec == reverse dec &&
                               bin == reverse bin
                               where dec = show x
                                     bin = rbase2 x
