import Control.Applicative
import Control.Monad

t x = x * (x+1) `div` 2

triangular x = a <$ guard (t a == x)
    where a = head . dropWhile (\a -> t a < x) $ [1..]

main = putStrLn . maybe "Despedido" show . (triangular <=< (\[p,w] -> w `div` p <$ guard (mod w p == 0))) . map read . words =<< getContents
