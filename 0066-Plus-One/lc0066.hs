-- Haskell solution.

plusOne :: [Int] -> [Int]
plusOne []  = [1]
plusOne lst
    | e == 9    = plusOne p ++ [0]
    | otherwise = p ++ [e+1]
    where e = last lst
          p = init lst
