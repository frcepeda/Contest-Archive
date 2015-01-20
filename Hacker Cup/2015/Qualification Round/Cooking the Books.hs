import Control.Applicative
import Control.Monad

pickOne [] = error "pickOne: empty list"
pickOne [x] = [([],x,[])]
pickOne (x:xs) = ([],x,xs) : map (\(l,m,r) -> (x:l,m,r)) (pickOne xs)

swapTwo [x] = [[x]]
swapTwo (x:xs) = map (x:) (swapTwo xs) ++ map (\(l,m,r) -> [m] ++ l ++ [x] ++ r) (pickOne xs) 

solve "0" = "0 0"
solve n = minimum pos ++ " " ++ maximum pos
    where pos = [x | x <- swapTwo n, head x /= '0']

main = do
    cases <- tail . lines <$> getContents
    forM_ (zip cases [1..]) $ \(c,n) -> do
        putStrLn $ "Case #" ++ show n ++ ": " ++ solve c
