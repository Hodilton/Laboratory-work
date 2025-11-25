module Main where

-- 1. Guards
ack1 :: Int -> Int -> Int
ack1 m n
  | m == 0 = n + 1
  | n == 0 = ack1 (m - 1) 1
  | otherwise = ack1 (m - 1) (ack1 m (n - 1))

-- 2. Case without guards
ack2 :: Int -> Int -> Int
ack2 m n = case (m, n) of
  (0, n) -> n + 1
  (m, 0) -> ack2 (m - 1) 1
  (m, n) -> ack2 (m - 1) (ack2 m (n - 1))

-- 3. Exact pattern matching
ack3 :: Int -> Int -> Int
ack3 0 n = n + 1
ack3 m 0 = ack3 (m - 1) 1
ack3 m n = ack3 (m - 1) (ack3 m (n - 1))

main :: IO ()
main = do
  putStrLn ("ack1 (1, 2) = " ++ show (ack1 1 2))
  putStrLn ("ack2 (2, 2) = " ++ show (ack2 2 2))
  putStrLn ("ack3 (3, 3) = " ++ show (ack3 3 3))
  --   putStrLn ("ask3 (4, 1) = " ++ show (ack3 4 1))

  putStrLn "A(4, 1) usually causes stack overflow."
  putStrLn "A(5, n) is basically impossible to compute."
  putStrLn "So we will not test these cases here."
