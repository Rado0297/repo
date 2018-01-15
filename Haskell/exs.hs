-- function that get predicate and list and return first element, which return true for the predicate
find' :: (a -> Bool) -> [a] -> Maybe a
find' _ [] = Nothing
find' f (x:xs)
    | f x = Just x
    | otherwise = find' f xs

applyToMaybe :: (a -> b) -> Maybe a -> Maybe b
applyToMaybe _ Nothing = Nothing
applyToMaybe f (Just x) = Just (f x)

-- map' :: (a -> b) -> [a] -> [b]
-- map' _ [] = []
-- map' f (x:xs) = (f x) : map' f xs

--define new type..
type String  = [Char]
type SongID = [Char]

data Bool' = True' | False'

data Maybe' a = Nothig' | Just' a
data List a = Nil | Cons a (List a) deriving (Show)

length' :: List a -> Int
length' Nil = 0
length' (Cons x xs) = 1 + length' xs

foldr' :: (a -> b -> b) -> b -> List a -> b
foldr' _ null_value Nil = null_value
foldr' f null_value (Cons x xs) = f x (foldr' f null_value xs)

foldl' :: (a -> b -> a) -> a -> List b -> a
foldl' _ null_value Nil = null_value
foldl' f null_value (Cons x xs) = f (foldl' f null_value xs) x
