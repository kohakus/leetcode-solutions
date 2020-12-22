-- Haskell solution.

import Control.Monad
subsets :: [Int] -> [[Int]]
subsets lst = filterM (\_ -> [True, False]) lst
