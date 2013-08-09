import Data.List

dedup xs = dedup' (sort xs)
    where dedup' xs = foldr (\x ys -> if null ys || x /= head ys then x:ys else ys) [] xs

main = print . length . dedup $ [a^b | a <- [2..100], b <- [2..100]]
