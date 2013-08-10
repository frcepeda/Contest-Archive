import Data.Map (fromListWith, foldrWithKey)

intSqrt = round . sqrt . fromIntegral

triangles = fromListWith (+) (map (flip (,) 1) sols)
    where sols = [a+b+c | a <- [1..500],
                          b <- [1..a],
                          let c = intSqrt (a^2 + b^2),
                          c^2 == (a^2 + b^2),
                          a+b+c <= 1000]

main = print . fst . foldrWithKey (\p c (a,b) -> if c > b then (p,c) else (a,b)) (0,0) $ triangles
