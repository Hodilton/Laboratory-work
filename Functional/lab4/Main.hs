module Main where

import Schedule

main :: IO ()
main = do
  putStrLn "Full Schedule"
  printSchedule schedule

  putStrLn "\nSchedule for 24-11-2025"
  printSchedule (scheduleByDate "24-11-2025" schedule)

  putStrLn "\nSchedule for group 122-1-1"
  printSchedule (scheduleByGroup "122-1-1" schedule)

  putStrLn "\nSchedule for teacher Dr. Smith"
  printSchedule (scheduleByTeacher "Dr. Smith" schedule)

  putStrLn "\nSchedule in room 2-523"
  printSchedule (scheduleByRoom "2-523" schedule)
