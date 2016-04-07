ri :: String -> Integer
ri = read

myDiv :: Integer -> Integer -> Integer
myDiv x y  | rem x y /= 0 = (div x y) + 1
           | otherwise = div x y

calc :: [Integer] -> Integer
calc [n,m,a] = (myDiv n a) * (myDiv m a)

main = do
     line <- getLine

     print $ calc (map ri (words line))