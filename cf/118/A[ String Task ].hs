import Data.Char
import System.IO

procLine :: String -> String
procLine [] = []
procLine (x:xs) | x `elem` "aeiouAEIOUyY" = procLine xs
                | otherwise = [&#39;.&#39;, (toLower x)] ++ procLine xs

main = do
  mainLoop

mainLoop :: IO ()
mainLoop = do
  ineof <- isEOF
  if ineof
     then return ()
    else
    do line <- getLine
       putStrLn $ procLine line
       mainLoop
