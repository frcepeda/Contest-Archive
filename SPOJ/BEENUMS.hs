solve 1 = "Y"
solve n = if ((n-1) `mod` 3 /= 0) || 3*s*(s+1) /= (n-1) then "N" else "Y"
    where s = floor . sqrt . fromIntegral $ (n-1) `div` 3

main = do
    n <- fmap read getLine
    if n /= (-1)
        then do
            putStrLn . solve $ n
            main
        else
            return ()
