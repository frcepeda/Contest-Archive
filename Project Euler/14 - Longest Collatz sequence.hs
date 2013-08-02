import Data.List

collatz' :: Integer -> Integer -> Integer
collatz' acc' n
        | n == 1         = acc
        | even n         = collatz' (acc+1) (n `div` 2)
        | otherwise      = collatz' (acc+1) (3 * n + 1)
	where acc = acc' `seq` acc'

collatz :: Integer -> Integer
collatz n = collatz' 0 n

argmax :: (Ord b) => (a -> b) -> [a] -> a
argmax f (x:xs) = fst $ foldl' step (x, f x) xs
                  where step (b,fb) curr = let a = curr
                                               fa = f a
                                           in if fa > fb then (a,fa) else (b,fb)

main = print $ argmax collatz [1..10^6]
