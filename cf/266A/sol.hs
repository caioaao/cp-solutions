import System.IO

slv :: String -> Integer
slv str = slvInt str 'i'
  where slvInt :: String -> Char -> Integer
        slvInt [] lastC = 0
        slvInt (x:xs) lastC
          | x == lastC = 1 + slvInt xs x
          | otherwise = slvInt xs x
main :: IO ()
main = do
  mainLoop


mainLoop :: IO ()
mainLoop = do
  inEnded <- isEOF
  if inEnded
    then return ()
    else do getLine
            str <- getLine
            print $ slv str
            mainLoop
