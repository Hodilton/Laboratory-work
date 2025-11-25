{- HLINT ignore "Use newtype instead of data" -}
module Schedule where

-- 1. Student
data Student = Student
  { studentName :: String
  }
  deriving (Show)

-- 2. Group of students
data Group = Group
  { groupName :: String,
    groupCourse :: String,
    groupStudents :: [Student]
  }
  deriving (Show)

-- 3. Classroom
data RoomType = Lecture | Lab | BigLecture | Gym deriving (Show)

data Room = Room
  { roomName :: String,
    roomType :: RoomType,
    roomFloor :: Int,
    roomAddress :: String
  }
  deriving (Show)

-- 4. Teacher
data TeacherType = FullTime | Guest deriving (Show)

data Teacher = Teacher
  { teacherName :: String,
    teacherType :: TeacherType
  }
  deriving (Show)

-- 5. Schedule item
data ScheduleItem = ScheduleItem
  { date :: String,
    startTime :: String,
    endTime :: String,
    discipline :: String,
    teacher :: Teacher,
    room :: Room,
    group :: Group
  }
  deriving (Show)

-- Sample data
student1 = Student "Ivan Ivanov"

student2 = Student "Anna Petrova"

student3 = Student "Pavel Sidorov"

group1 = Group "122-1-1" "4" [student1, student2]

group2 = Group "122-1-2" "4" [student3]

room1 = Room "2-523" Lecture 5 "Adress, 1"

room2 = Room "2-604" Lab 6 "Adress, 1"

teacher1 = Teacher "Dr. Smith" FullTime

teacher2 = Teacher "Prof. Johnson" Guest

schedule :: [ScheduleItem]
schedule =
  [ ScheduleItem
      "24-11-2025"
      "13:40"
      "15:10"
      "Math"
      teacher1
      room1
      group1,
    ScheduleItem
      "25-11-2025"
      "15:20"
      "16:50"
      "Programming"
      teacher2
      room2
      group1,
    ScheduleItem
      "24-11-2025"
      "09:50"
      "11:20"
      "Math"
      teacher1
      room1
      group2
  ]

-- Bubble sort
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

-- Filter functions
scheduleByGroup :: String -> [ScheduleItem] -> [ScheduleItem]
scheduleByGroup g [] = []
scheduleByGroup g (s : st)
  | groupName (group s) == g = s : scheduleByGroup g st
  | otherwise = scheduleByGroup g st

scheduleByDate :: String -> [ScheduleItem] -> [ScheduleItem]
scheduleByDate d [] = []
scheduleByDate d (s : st)
  | date s == d = s : scheduleByDate d st
  | otherwise = scheduleByDate d st

scheduleByTeacher :: String -> [ScheduleItem] -> [ScheduleItem]
scheduleByTeacher t [] = []
scheduleByTeacher t (s : st)
  | teacherName (teacher s) == t = s : scheduleByTeacher t st
  | otherwise = scheduleByTeacher t st

scheduleByRoom :: String -> [ScheduleItem] -> [ScheduleItem]
scheduleByRoom r [] = []
scheduleByRoom r (s : st)
  | roomName (room s) == r = s : scheduleByRoom r st
  | otherwise = scheduleByRoom r st

-- Sorting helper: True if x should come AFTER y
laterThan :: ScheduleItem -> ScheduleItem -> Bool
laterThan x y = (date x, startTime x) > (date y, startTime y)

-- Print schedule
printSchedule :: [ScheduleItem] -> IO ()
printSchedule [] = putStrLn "No schedule"
printSchedule items = go (bubbleSortGen laterThan items)
  where
    go [] = return ()
    go (s : rest) = do
      putStrLn $
        date s
          ++ " | "
          ++ startTime s
          ++ "-"
          ++ endTime s
          ++ " | "
          ++ discipline s
          ++ " | "
          ++ teacherName (teacher s)
          ++ " | "
          ++ roomName (room s)
          ++ " | "
          ++ groupName (group s)
      go rest
