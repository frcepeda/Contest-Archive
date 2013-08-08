import Data.List

main = print (foldl' lcm 1 [1..20])
