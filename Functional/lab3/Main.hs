module Main where

-- =========================================
-- Task 1: Search for an Int in a list
-- Returns (index, True) if found, (0, False) otherwise
-- =========================================
searchInt :: Int -> [Int] -> (Int, Bool)
searchInt n xs = searchHelper n xs 0
  where
    searchHelper _ [] idx = (0, False)
    searchHelper n (y : yt) idx
      | n == y = (idx, True)
      | otherwise = searchHelper n yt (idx + 1)

-- =========================================
-- Task 2: Generic search with a comparator function
-- Returns (index, True) if found, (0, False) otherwise
-- =========================================
searchGen :: (a -> Bool) -> [a] -> (Int, Bool)
searchGen f xs = searchHelper xs 0
  where
    searchHelper [] idx = (0, False)
    searchHelper (y : yt) idx
      | f y = (idx, True)
      | otherwise = searchHelper yt (idx + 1)

-- =========================================
-- Bonus Task: Playlist search
-- Track = (TrackNumber, SongName, Artist)
-- Returns all tracks by a given artist
-- =========================================
type Track = (Int, String, String)

tracksByArtist :: String -> [Track] -> [Track]
tracksByArtist artist [] = []
tracksByArtist artist (t@(_, _, a) : tt)
  | a == artist = t : tracksByArtist artist tt
  | otherwise = tracksByArtist artist tt

-- =========================================
-- Task 3: Bubble sort for Int
-- =========================================
bubbleSortInt :: [Int] -> [Int]
bubbleSortInt xs
  | swapped = bubbleSortInt newXs
  | otherwise = xs
  where
    (newXs, swapped) = bubblePass xs False

-- Single pass of bubble sort
bubblePass :: [Int] -> Bool -> ([Int], Bool)
bubblePass [] swapped = ([], swapped)
bubblePass [x] swapped = ([x], swapped)
bubblePass (x : y : xt) swapped
  | x > y = let (rest, s) = bubblePass (x : xt) True in (y : rest, s)
  | otherwise = let (rest, s) = bubblePass (y : xt) swapped in (x : rest, s)

-- =========================================
-- Task 4: Generic bubble sort
-- =========================================
bubbleSortGen :: (a -> a -> Bool) -> [a] -> [a]
bubbleSortGen cmp xs
  | swapped = bubbleSortGen cmp newXs
  | otherwise = xs
  where
    (newXs, swapped) = bubblePassGen cmp xs False

bubblePassGen :: (a -> a -> Bool) -> [a] -> Bool -> ([a], Bool)
bubblePassGen _ [] swapped = ([], swapped)
bubblePassGen _ [x] swapped = ([x], swapped)
bubblePassGen cmp (x : y : xt) swapped
  | cmp x y = let (rest, s) = bubblePassGen cmp (x : xt) True in (y : rest, s)
  | otherwise = let (rest, s) = bubblePassGen cmp (y : xt) swapped in (x : rest, s)

-- =========================================
-- Task 5: Check if list is sorted (generic)
-- =========================================
isSorted :: (a -> a -> Bool) -> [a] -> Bool
isSorted _ [] = True
isSorted _ [_] = True
isSorted cmp (x : y : xs)
  | cmp x y = False
  | otherwise = isSorted cmp (y : xs)

-- =========================================
-- Main
-- =========================================
main :: IO ()
main = do
  let nums = [5, 3, 8, 1, 4]
  putStrLn ("searchInt 8 in [5,3,8,1,4] = " ++ show (searchInt 8 nums))
  putStrLn ("searchInt 7 in [5,3,8,1,4] = " ++ show (searchInt 7 nums))

  putStrLn ("searchGen even [1,3,4,7] = " ++ show (searchGen even [1, 3, 4, 7]))
  putStrLn ("searchGen (>10) [1,3,4,7] = " ++ show (searchGen (> 10) [1, 3, 4, 7]))

  let playlist = [(1, "SongA", "Artist1"), (2, "SongB", "Artist2"), (3, "SongC", "Artist1")]
  putStrLn ("tracks by Artist1 = " ++ show (tracksByArtist "Artist1" playlist))

  putStrLn ("bubbleSortInt [5,3,8,1,4] = " ++ show (bubbleSortInt nums))
  putStrLn ("bubbleSortGen (<) [5,3,8,1,4] = " ++ show (bubbleSortGen (<) nums))

  putStrLn ("isSorted (>) [1,2,3] = " ++ show (isSorted (>) [1, 2, 3]))
  putStrLn ("isSorted (>) [3,2,1] = " ++ show (isSorted (>) [3, 2, 1]))
