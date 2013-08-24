import Control.Monad

isPalindrome n = n' == reverse n'
                 where n' = show n

isLychrel n = (foldr1 (>=>) (replicate 49 revsum)) n /= Nothing
    where revsum n = if isPalindrome n' then Nothing else Just n'
                     where n' = n + (read . reverse . show) n

main = print . length . filter isLychrel $ [1..10^4-1]
