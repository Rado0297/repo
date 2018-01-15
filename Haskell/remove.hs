remove :: Eq a => [a] -> a -> [a]
remove [] _ = []
remove xs element = if (head xs) == element then
    remove (tail xs) element
    else (head xs) : remove (tail xs) element

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort [i] = [i]
quicksort xs = (quicksort smaller) ++ [head xs] ++ (quicksort bigger)
    where smaller = [x | x <- xs, x < (head xs)]
          bigger = [y | y <- (tail xs), y >= (head xs)]

--for implementation
--average' :: [Int] -> Double

conv :: Int -> Double
conv x = (fromIntegral x) :: Double

sumroots :: Float -> Float -> Float -> Float
sumroots a b c = let d = b*b - 4*a*c
                    in if (d > 0) then ((-b + (sqrt d)) / 2*a) + ((-b - (sqrt d)) / 2*a)
                        else error "No roots"

--for implementation
prime :: Int -> Bool
prime k = null [ x | x <- [2..(sqrt k)], k `mod`x  == 0]

insert :: Int -> [Int] -> [Int]
insert x [] = [x]
insert x (y:ys) = if x < y then x:y:ys
                    else y:insert x ys

--insertion sort first way
insertionSort :: [Int] -> [Int]
insertionSort [x] = [x]
insertionSort (x:xs) = insert x (insertionSort xs)

--insertion sort second way
insertionSort' :: [Int] -> [Int]
insertionSort' xs = foldr insert [] xs
