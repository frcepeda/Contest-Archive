import Data.Map as M hiding (map)
import Data.List
import Data.Ord

cycleLen :: Int -> (Int, Int)
cycleLen n = (n, cycleLen' 1 M.empty 0)
    where cycleLen' r vis soFar
            | r == 0  = 0
            | otherwise = let r' = r `mod` n in
                             case M.lookup r' vis of
                                 Just i  -> soFar - i
                                 Nothing -> cycleLen' (r'*10) (M.insert r' soFar vis) (soFar + 1)

main = print . fst . maximumBy (comparing snd) . map cycleLen $ [1..1000]
