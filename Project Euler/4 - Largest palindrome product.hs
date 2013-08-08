isPalindrome n = digits n == reverse (digits n)
        where digits = show
{- Je suis dumb
                | n == 0    = []
                | otherwise = n `mod` 10 : digits (n `div` 10)
-}

solution = maximum [p | x <- [100..999], y <- [100..999], let p = x*y, isPalindrome p]

main = print solution
