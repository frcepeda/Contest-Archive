{-# LANGUAGE BangPatterns #-}

import Control.Monad
import Control.Applicative
import Data.Maybe
import Data.List
import Data.Char
import qualified Data.ByteString.Lazy.Char8 as B

readInt = B.foldl' (\x c -> 10 * x + digitToInt c) 0

bsearch (n:ns) p = bs 1 (10^9)
    where bs lo hi
            | lo < hi = if cnt mid < p then bs lo mid else bs (mid+1) hi
            | otherwise = hi - 1
              where mid = (lo + hi) `div` 2
          cnt x = snd $ foldl' f (n,1) ns
            where f (a,!b) nxt
                   | nxt - a >= x = (nxt, b+1)
                   | otherwise = (a,b)

main = do
    (l:ls) <- B.lines <$> B.getContents
    let [_,p] = map readInt . B.split ' ' $ l
    let nums = sort . map readInt $ ls
    print $ bsearch nums p
