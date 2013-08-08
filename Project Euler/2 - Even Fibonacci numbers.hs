fib :: [Integer]
fib = 0 : 1 : zipWith (+) fib (tail fib)

main = print . sum . filter even . takeWhile (<4000000) $ fib
