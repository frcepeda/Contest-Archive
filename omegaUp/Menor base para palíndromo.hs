import Data.Char
toBase x b = [show b, toB x]
    where toB 0 = ""
          toB x = let (q,r) = quotRem x b in intToDigit r : toB q
main = putStrLn . unwords . head . filter (\[_,x] -> x == reverse x) . (\a -> map (toBase a) [2..10] ++ [["-1","0"]]) . read =<< getContents
