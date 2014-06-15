-- Transposes stdin

import Data.List

main = putStrLn . unlines . transpose . lines =<< getContents
