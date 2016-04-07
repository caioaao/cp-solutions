import System.IO

solve :: Integer -> Integer -> IO ()
solve x 0 = do
  print x
solve x n = do
  currCmd <- getLine
  let [_,v,_] = currCmd
  if v == &#39;-&#39;
    then solve (x - 1) (n - 1)
    else solve (x + 1) (n - 1)

main :: IO ()
main = do
  mainloop

mainloop :: IO ()
mainloop = do
  ended <- isEOF
  if ended
    then return ()
    else do lineNum <- getLine
            solve 0 (read lineNum)
            mainloop
