factorial x = fct !! x
    where fct = 1 : zipWith (*) fct [1..]

main = putStrLn . unlines . map (show . factorial . read) . tail . words =<< getContents