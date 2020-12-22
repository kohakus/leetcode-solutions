-- Haskell solution.

import Data.List

spiral :: [[a]] -> [a]
spiral (x:xs) = x ++ (spiral $ reverse $ transpose $ xs)
spiral _      = []
