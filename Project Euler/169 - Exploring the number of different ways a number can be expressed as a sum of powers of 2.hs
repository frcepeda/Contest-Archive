toBinary = reverse . toBinary'
    where toBinary' n
            | n == 0    = []
            | otherwise = let (q,r) = quotRem n 2 in r : toBinary' q

f bit (a0,a2) = if bit == 1 then (t1,t3) else (t0,t2)
    where t0 = a0
          t1 = a0 + a2
          t2 = a0 + a2
          t3 = a2

main = print . fst . foldr f (1,0) . toBinary . read =<< getContents -- $ 10^25
