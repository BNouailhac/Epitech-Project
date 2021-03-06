import System.Environment
import System.Exit
import Data.Array (listArray, (!), bounds, elems)
 
-- Algoritme calcul
step rule a = listArray (l,r) res
  where (l,r) = bounds a
        res = [rule (a!r)     (a!l) (a!(l+1)) ] ++
              [rule (a!(i-1)) (a!i) (a!(i+1)) | i <- [l+1..r-1] ] ++
              [rule (a!(r-1)) (a!r) (a!l)     ]
 
runCA rule = iterate (step rule)

rule n l x r = n `div` (2^(4*l + 2*x + r)) `mod` 2
 
initial n = listArray (0,n-2) . center . padRight n
  where
    padRight n lst = take n $ lst ++ repeat 0
    center = take n . drop (n `div` 2+1) . cycle

displayCA n rule init =do
                 mapM_ putStrLn $ take n result
  where result = fmap display . elems <$> runCA rule init
        display 0 = ' '
        display 1 = '*'

-- Parse args
findarg :: String -> [String] -> Int
findarg str [] = -1
findarg name (it:lst) = if name == it then (read (head lst) :: Int) else findarg name lst

-- main
main = do
    args <- getArgs
    let i = length args
    if i == 0 then do exitWith (ExitFailure 84)
    else do
      let line = findarg "--lines" args
      let règle = findarg "--rule" args
      displayCA line (rule règle) (initial 81 [1])
      return 0