import Data.List

duplicateElements :: [a] -> [a]
duplicateElements [] = []
duplicateElements (x:xs) = x : x : duplicateElements xs


slice :: Int -> Int -> [a] -> [a]
slice _ _ [] = []
slice 0 end xs = take (end + 1) xs
slice start end xs = take (end - 1) (drop start xs)


primeNum :: Int -> Bool
primeNum x = null [y | y <- [2..(x-1)], y `divides` x]
    where divides p q = q `mod` p == 0

--without list comprehension
-- primeNum'' :: Int -> Int -> Bool
-- primeNum'' x y
--     | y `divides` x = True
--     | y == (x - 1) = False
--     | otherwise = primeNum'' x (y + 1)
--         where divides p q = q  `mod` p == 0
-- primeNum' :: Int -> Int
-- primeNum' x = primeNum'' x 2

primesUntil :: Int -> [Int]
primesUntil x = [y | y <- [2..x], primeNum y]

primeSum :: Int -> (Int, Int)
primeSum x = primeSum' x (primesUntil x)
    where primeSum' x (p:ps)
            | x - p `elem` ps = (p, x - p)
            | otherwise = primeSum' x ps


hailstone :: Int -> [Int]
hailstone 1 = [1]
hailstone x
    | even x = x : hailstone (x `div` 2)
    | otherwise = x : hailstone (3*x + 1)


-- idea with head!!!
intercalate' :: [a] -> [[a]] -> [a]
intercalate' _ [] = []
intercalate' ys (xs:xxs) = xs ++ ys ++ intercalate' ys xxs


transpose' :: [[a]] -> [[a]]
transpose' xxs
    | allEmpty = []
    | otherwise = map head xxs : (transpose' (map tail xxs))
        where allEmpty = all null xxs

subset :: (Eq a) => [a] -> [a] -> Bool
subset [] _ = True
subset (x:xs) ys = x `elem` ys && subset xs ys

findColumns :: (Eq a) => [[a]] -> Int
findColumns (xs:xxs) = length $ nub [col | col <- transposed, row <- xxs, col `subset` row]
    where transposed = transpose' xxs


combine :: (a1 -> Int) -> (a1 -> Int) -> (Int -> Int -> Int) -> (a1 -> Int)
combine f g h = (\x -> h (f x) (g x))

equalOnInterval :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> Bool
equalOnInterval f g start end = map f interval == map g interval
                                where interval  = [start..end]

check :: Int -> Int -> [(Int -> Int)] -> [(Int -> Int -> Int)] -> Bool
check start end uns bins = not $ null [f | f <- uns, g <- uns, h <- bins,
                                            match <- uns, equalOnInterval (combine f g h) match start end]

-- let nats = [1..]
-- let sumOfSquares = [x | x <- nats, y <- [1..x], z <- [1..x], y < z, x == y^2 + z^2]


matchingVals :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> [Int]
matchingVals f g start end = [x | x <- [start..end], f x == g x]

makeIntervals :: [Int] -> [[Int]]
makeIntervals [] = []
makeIntervals (x:[]) = [[x]]
makeIntervals (x:y:xs)
    | x + 1 == y = (x : head intervs) : tail intervs
    | otherwise = [x] : makeIntervals (y:xs)
        where intervs = makeIntervals (y:xs)

--largestInterval :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> (Int -> Int)
