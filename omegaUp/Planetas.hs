import qualified Data.ByteString.Char8 as B
import Control.Applicative
import Text.Printf
import Data.Maybe
import Data.List

force ps p = foldl' go 0 ps
    where go z x = z + 1 / (x - p)

getInt = fst . fromJust . B.readInt

bsearch 0 p a b = (a+b)/2
bsearch z p a b
    | p m       = bsearch (z-1) p m b
    | otherwise = bsearch (z-1) p a m
        where m = (a+b)/2

main = do
    nstr:rest <- B.splitWith (flip elem " \n") <$> B.getContents
    let n = getInt nstr
    let planets = sort . map (fromIntegral . fst) . mapMaybe B.readInt $ rest
    let ranges = mapMaybe takeTwo (tails planets)
         where takeTwo (a:b:_) = Just (a,b)
               takeTwo x = Nothing
    let sols = map (uncurry $ bsearch 24 ((< 0) . force planets)) ranges
    (printf "%d\n" :: Int -> IO ()) (n-1)
    mapM_ (printf "%.3f\n" :: Double -> IO ()) sols