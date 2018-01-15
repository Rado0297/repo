duplicateElements :: [a] -> [a]
duplicateElements [] = []
duplicateElements (x:xs) = x:x:duplicateElements xs

-- ????
slice :: Int -> Int -> [a] -> [a]
slice _ _ [] = []
slice 0 end (x:xs) = take (end + 1) xs
slice start end (x:xs) = slice (start - 1) end xs

slice' :: Int -> Int -> [a] -> [a]
slice' start end xs = take (end - 1) (drop start xs)
-- ???

prime :: Int -> Bool
prime x = null [y | y <- [2..(x-1)], y `divides` x]
    where divides p q = q `mod` p == 0

primesUntil :: Int -> [Int]
primesUntil x = [y | y <- [2..x], prime y]

primeSum :: Int -> (Int, Int)
primeSum x = primeSum' x (primesUntil x)
    where primeSum' x (p:ps)
            | x - p `elem` ps = (p, (x - p))
            | otherwise = primeSum' x ps

-- hailstone :: Int -> [Int]
-- hailstone 1 = [1]
-- hailstone x
--     | even x = x : hailstone (x `div` 2)
--     | otherwise = x : hailstone (3*x + 1)
--
-- twoDigitOddCompositeNumbers = [x | x <- [10..99], odd x, not (prime x)]

-- squares :: [Int]
-- squares = map (^2) [1..7]
--
-- wot = length twoDigitOddCompositeNumbers - length [x + 2*y | x <- primesUntil 99, y <- squares, x + 2*y < 100]
--


-- intercalate " wow " ["I", "am", "a", "sentence"]
-- intercalate :: a -> [[a]] -> [a]
-- intercalate _ [] = []
-- intercalate x (xs:xxs) = xs ++ [x] ++ intercalate x xxs
