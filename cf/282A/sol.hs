solve :: [String] -> String
solve [] = []
solve (currNum:strs) = solve' 0 (read currNum) strs

solve' :: Integer -> Integer -> [String] -> String
solve' x 0 strs = (show x) ++ ['\n'] ++ solve strs
solve' x n (currCmd:currTail) | currCmd!!1 == '+' = solve' (x + 1) (n - 1) currTail
                              | otherwise         = solve' (x - 1) (n - 1) currTail

main :: IO ()
main = do
  interact $ solve . lines
