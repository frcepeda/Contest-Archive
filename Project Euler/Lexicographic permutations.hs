import Data.List
-- I know I'm lazy, but it runs in like 11 seconds, so meh.
main = print $ ((!!999999) . sort . permutations) [0..9]
