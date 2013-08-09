knapsack xs n = last (foldr f (1:replicate n 0) xs)
    where f k xs = xs'
            where xs' = zipWith (+) xs ((replicate k 0) ++ xs')

main = print (knapsack [1,2,5,10,20,50,100,200] 200)
