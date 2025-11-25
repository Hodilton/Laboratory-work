{- HLINT ignore "Use guards" -}
{- HLINT ignore "Redundant if" -}
module Factorial where

-- 1. If .. then .. else
fac1 :: Int -> Int
fac1 n =
  if n == 0
    then 1
    else
      if n == 1
        then 1
        else n * fac1 (n - 1)

-- 2. Guards
fac2 :: Int -> Int
fac2 n
  | n == 0 = 1
  | n == 1 = 1
  | otherwise = n * fac2 (n - 1)

-- 3. Case without guards
fac3 :: Int -> Int
fac3 n = case n of
  0 -> 1
  1 -> 1
  _ -> n * fac3 (n - 1)

-- 4. Exact pattern matching
fac4 :: Int -> Int
fac4 0 = 1
fac4 1 = 1
fac4 n = n * fac4 (n - 1)

main :: IO ()
main = do
  putStrLn ("fac1 0 = " ++ show (fac1 1))
  putStrLn ("fac2 1 = " ++ show (fac2 1))
  putStrLn ("fac3 5 = " ++ show (fac3 5))
  putStrLn ("fac4 13 = " ++ show (fac4 13))
