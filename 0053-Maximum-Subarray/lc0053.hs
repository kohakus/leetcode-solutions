-- Haskell solution

maxSub :: [Integer] -> Integer
maxSub = maximum . scanl1 (ap max . (+))
  where ap f g = \x -> f x (g x)
