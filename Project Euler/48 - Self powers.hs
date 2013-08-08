import Data.Char

main = print . (`mod` 10^10) . sum . map (\n -> n^n) $ [1..1000]
