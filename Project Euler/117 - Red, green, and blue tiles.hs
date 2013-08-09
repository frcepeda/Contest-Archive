import Data.List

ways = 1:1:2:4:zipWith4 plus4 ways (drop 1 ways) (drop 2 ways) (drop 3 ways)
    where plus4 a b c d = a + b + c + d

main = print (ways !! 50)
