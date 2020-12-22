-- Haskell solution.

permute :: [a] -> [[a]]
permute []     = [[]]
permute (x:xs) = (permute xs) >>= (ins x)

ins :: a -> [a] -> [[a]]
ins x []     = [[x]]
ins x (y:ys) = [x:y:ys] ++ (map (y:) (ins x ys))
