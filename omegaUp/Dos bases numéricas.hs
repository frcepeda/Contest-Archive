import Control.Applicative
import Data.Maybe
import Data.List

fromBase 0 _ = 0
fromBase x b = let (q,r) = quotRem x 10 in r + b * fromBase q b
matchBase x (eq,p) b
    | bx == eq = Just (eq,p,b)
    | otherwise = Nothing
        where bx = fromBase x b

main = do
    [a,b] <- map read . words <$> getContents
    let ps = zip (map (fromBase a) [2..10]) [2..10]
    let (n,p,q) = minimum $ mapMaybe (\x -> listToMaybe . mapMaybe (matchBase b x) $ [2..10]) ps
    print n
    print p
    print q
