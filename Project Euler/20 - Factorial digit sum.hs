import Data.Char

fact n = foldr1 (*) [1..n]

main = print . sum . map digitToInt . show $ fact 100
