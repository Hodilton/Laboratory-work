{- HLINT ignore "Use guards" -}
module Rating where

-- 1. If .. then .. else
ratingIf :: Int -> String
ratingIf n =
  if n < 0
    then "Error: rating cannot be negative"
    else
      if n > 9
        then "Error: rating cannot be greater than 9"
        else
          if n <= 2
            then "Terrible. Very bad."
            else
              if n <= 4
                then "Weak. Many problems."
                else
                  if n <= 6
                    then "Okay. Watch if you are bored."
                    else
                      if n <= 8
                        then "Great! Must watch."
                        else "Absolutely cinema!"

-- 2. Guards
ratingMultiIf :: Int -> String
ratingMultiIf n
  | n < 0 = "Error: rating cannot be negative"
  | n > 9 = "Error: rating cannot be greater than 9"
  | n <= 2 = "Terrible. Very bad."
  | n <= 4 = "Weak. Many problems."
  | n <= 6 = "Okay. Watch if you are bored."
  | n <= 8 = "Great! Must watch."
  | otherwise = "Absolutely cinema!"

-- 3. Case with guards
ratingCase :: Int -> String
ratingCase n = case n of
  x
    | x < 0 -> "Error: rating cannot be negative"
    | x > 9 -> "Error: rating cannot be greater than 9"
    | x <= 2 -> "Terrible. Very bad."
    | x <= 4 -> "Weak. Many problems."
    | x <= 6 -> "Okay. Watch if you are bored."
    | x <= 8 -> "Great! Must watch."
    | otherwise -> "Absolutely cinema!"

-- 4. Exact pattern matching
ratingExact :: Int -> String
ratingExact 0 = "Terrible. Very bad."
ratingExact 1 = "Terrible. Very bad."
ratingExact 2 = "Terrible. Very bad."
ratingExact 3 = "Weak. Many problems."
ratingExact 4 = "Weak. Many problems."
ratingExact 5 = "Okay. Watch if you are bored."
ratingExact 6 = "Okay. Watch if you are bored."
ratingExact 7 = "Great! Must watch."
ratingExact 8 = "Great! Must watch."
ratingExact 9 = "Absolutely cinema!"
ratingExact _ = "Error: rating must be between 0 and 9"

-- Main: one test value for each function
main :: IO ()
main = do
  putStrLn ("ratingIf 7 = " ++ ratingIf 7)
  putStrLn ("ratingMultiIf 2 = " ++ ratingMultiIf 2)
  putStrLn ("ratingCase (-5) = " ++ ratingCase (-5))
  putStrLn ("ratingExact 5 = " ++ ratingExact 5)
