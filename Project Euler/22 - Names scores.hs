import Data.List
import Data.Char

-- Each name must be on a separate line

charToInt :: Char -> Int
charToInt = (+ (1 - ord 'A')) . ord

strValue :: (Int,String) -> Int
strValue (mult,str) = mult * (sum . map charToInt) str

main = do
    file <- readFile "names.txt"
    let names = (sort . lines) file
    print $ (sum . map strValue . zip [1..]) names
