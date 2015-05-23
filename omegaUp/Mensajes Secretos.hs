{-
f and g are parsers. f solves the problem by using g,
which assumes that the input it is fed is already inside
a parens, meaning it must be flipped.

g uses f, then, to avoid doing one extra flip when
it finds another parens inside what it's parsing.
-}

g = g' ""

g' z (')':xs) = (z, xs)
g' z ('(':xs) = let (a,b) = f xs; (x,y) = g b in (x++a++z, y)
g' z (x:xs) = g' (x:z) xs
g' z [] = (z, [])

f (')':xs) = ("", xs)
f ('(':xs) = let (a,b) = g xs; (x,y) = f b in (a ++ x, y)
f (x:xs) = let (a,b) = f xs in (x:a, b)
f [] = ([], [])

main = interact (fst . f)
