import Data.Sequence as S
import Data.Foldable (mapM_)

data Direction = Begin | End

splitOn ss [] = []
splitOn ss xs = p : s ++ splitOn ss rest
    where (p,seps) = span (not . flip elem ss) xs
          (s',rest) = span (flip elem ss) seps
          s = map (:[]) s'
          
key (s,_) "[" = (s,Begin)
key (s,_) "]" = (s,End)
key (s,Begin) xs = (xs <| s, Begin)
key (s,End) xs = (s |> xs, End)

main = Data.Foldable.mapM_ putStr . fst . foldl key (S.empty,End) . splitOn "[]" =<< getContents