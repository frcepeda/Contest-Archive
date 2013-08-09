import Data.Char
import Data.Set (Set, fromList, member)

charValue c = ord c - ord 'A' + 1
wordValue = sum . map charValue

triangles = fromList (takeWhile (<=10^4) a)
    where a = 1 : zipWith (+) [2..] a

isTriangular = flip member triangles

main = do
    list <- getContents
    let words :: [String]; words = read $ "[" ++ list ++ "]"
    print . length . filter isTriangular . map wordValue $ words
