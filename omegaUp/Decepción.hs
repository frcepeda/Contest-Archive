import Data.List

works front back xs = cnt xs == front && cnt (reverse xs) == back
    where cnt = fst . foldr (\n (c,m) -> if n > m then (c+1,n) else (c,m)) (0,0)

main = do
    line <- getLine
    let [count,front,back] = map read . words $ line
    print . length . filter (works front back) $ permutations [1..count]
