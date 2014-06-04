import Data.List

main = putStrLn . (\x -> show (length x) ++ "\n" ++ unlines x) $ [[a,b] | a <- ['a'..'z'], b <- ['a'..'z']] \\ ["ab", "bc", "cd", "db"]
