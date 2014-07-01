import qualified Data.ByteString.Lazy.Char8 as B
import Data.Maybe

mergeAll [xs] = xs
mergeAll xs = mergeAll (mergePairs xs)

mergePairs (x:y:xs) = merge x y: mergePairs xs
mergePairs x = x

merge xs ys = merge' xs (reverse ys) 
    where merge' [] ys = ys
          merge' xs [] = xs
          merge' xss@(x:xs) yss@(y:ys)
            | x <= y  = x : merge' xs yss
            | x > y  = y : merge' xss ys

nievesSort = mergeAll . map (:[])

main = putStrLn . unwords . map show . nievesSort . map (fst . fromJust . B.readInt :: B.ByteString -> Int) . B.split ' ' . head . tail . B.split '\n' =<< B.getContents