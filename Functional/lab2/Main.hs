module Main where

-- 1. Sum of a list
sumList :: [Double] -> Double
sumList xs
  | null xs = 0
  | otherwise = head xs + sumList (tail xs)

-- 2. Multipy of a list
multiplyList :: [Double] -> Double
multiplyList xs
  | null xs = 1
  | otherwise = head xs * multiplyList (tail xs)

-- 3. Minimum of a list
minList :: [Double] -> Double
minList xs
  | null xs = error "Empty list has no minimum"
  | length xs == 1 = head xs
  | otherwise = min (head xs) (minList (tail xs))

-- 4. Maximum of a list
maxList :: [Double] -> Double
maxList xs
  | null xs = error "Empty list has no maximum"
  | length xs == 1 = head xs
  | otherwise = max (head xs) (maxList (tail xs))

-- 5. Average of a list
avgList :: [Double] -> Double
avgList xs
  | null xs = 0
  | otherwise = sumList xs / fromIntegral (length xs)

-- 6. Remove a number from a list
removeNumber :: Int -> [Int] -> [Int]
removeNumber n xs
  | null xs = []
  | head xs == n = removeNumber n (tail xs) -- skip this element
  | otherwise = head xs : removeNumber n (tail xs) -- keep this element

-- 7. Cubes of list elements
cubeList :: [Int] -> [Int]
cubeList xs
  | null xs = []
  | otherwise = (head xs ^ 3) : cubeList (tail xs)

-- 8. Squares of elements smaller than n
squaresBelow :: Int -> [Int] -> [Int]
squaresBelow n xs
  | null xs = []
  | head xs < n = (head xs ^ 2) : squaresBelow n (tail xs) -- keep if smaller
  | otherwise = squaresBelow n (tail xs) -- skip if not smaller

-- Main
main :: IO ()
main = do
  let nums_d = [1.0, 2.0, 3.0, 4.0, 5.0]
  let nums_i = [1, 2, 3, 4, 5]

  putStrLn ("sumList [1..5] = " ++ show (sumList nums_d))
  putStrLn ("multiplyList [1..5] = " ++ show (multiplyList nums_d))
  putStrLn ("minList [1..5] = " ++ show (minList nums_d))
  putStrLn ("maxList [1..5] = " ++ show (maxList nums_d))
  putStrLn ("avgList [1..5] = " ++ show (avgList nums_d))

  putStrLn ("removeNumber 3 [1..5] = " ++ show (removeNumber 3 nums_i))
  putStrLn ("cubeList [1..5] = " ++ show (cubeList nums_i))
  putStrLn ("squaresBelow 4 [1..5] = " ++ show (squaresBelow 4 nums_i))
