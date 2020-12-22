-- Haskell solution.

import Data.List

spiral :: Int -> Int -> Int -> [[Int]]
spiral 0 _ _ = [[]]
spiral h w s = [s..s+w-1] : rot90 (spiral w (h-1) (s+w))
    where rot90 = (map reverse) . transpose

spiralSquare :: Int -> [[Int]]
spiralSquare n = spiral n n 1
