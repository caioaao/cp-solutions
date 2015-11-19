readToks  = map read . words -- type inferred

calc :: [Integer] -> Integer
calc [n, m, a] = (myDiv n a) * (myDiv m a)
     where
           myDiv :: Integer -> Integer -> Integer
           myDiv x y  | rem x y /= 0 = (div x y) + 1
                      | otherwise = div x y

main = do
     line <- getLine

     print $ calc (readToks line)
