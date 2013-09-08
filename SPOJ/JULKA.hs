solve = do
    s <- fmap read getLine
    d <- fmap read getLine
    let a = (s+d) `div` 2
    let b = a - d
    putStrLn (show a)
    putStrLn (show b)

main = sequence . take 10 . repeat $ solve
