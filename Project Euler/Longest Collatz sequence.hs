collatz' :: Integer -> Integer -> Integer
collatz' acc n
	| n == 1         = acc
	| n `mod` 2 == 0 = collatz' (acc+1) (n `div` 2)
	| otherwise      = collatz' (acc+1) (3 * n + 1)

collatz :: Integer -> Integer
collatz n = collatz' 0 n

argmax' :: (Ord b) => (a,b) -> (a -> b) -> [a] -> (a,b)
argmax' best f [] = best
argmax' (b,fb) f (x:xs) = let fx = f x
                              a = if fx > fb then (x,fx) else (b,fb)
                              in argmax' a f xs

argmax :: (Ord b) => (a -> b) -> [a] -> a
argmax f (x:xs) = fst $ argmax' (x, f x) f xs

main = print $ argmax collatz [1..10^6]
