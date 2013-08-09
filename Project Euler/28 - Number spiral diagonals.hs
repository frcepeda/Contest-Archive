corners = 1 : takeSteps 2 [3..]
    where takeSteps s xs = map head (take 4 steps) ++ takeSteps (s+2) (drop 2 (steps !! 4))
            where steps = iterate (drop s) xs

main = print . sum . take (500*4 + 1) $ corners
