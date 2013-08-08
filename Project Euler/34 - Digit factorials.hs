{- Explanation:
The largest number you can get by adding the factorials of an n-digit number is 9!*n.
The smallest number you can make with n digits is 10^{n-1}.
Therefore, there can only be an n-digit curious number iff 9!*n >= 10^{n-1} -> n <= 7.
--}

import Data.Char

fact = 1 : zipWith (*) [1..] fact

digitFact = sum . map ((fact !!) . digitToInt) . show

main = print . sum . filter (\x -> x == digitFact x) $ [3..10^7]
