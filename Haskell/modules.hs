import Data.List
import Data.Functor
import Data.Char

numUniques :: (Eq a) => [a] -> Int
numUniques = length. nub

intersperse' :: a -> [a] -> [a]
intersperse' _ [] = []
intersperse' z (x:xs) = if null xs then x:[] else x:z:intersperse' z xs

search :: (Ord a) => [a] -> [a] ->Bool
search needle haystack =
    let nlen = length needle
    in foldl (\acc xs -> if take nlen xs == needle then True else acc) False (tails haystack)

encode :: Int -> String -> String
-- encode shift msg =
--     let ords = map ord msg
--         shifted = map (+ shift) ords
--     in  map chr shifted
encode shift msg = map (chr.(+ shift).ord) msg

decode :: Int -> String -> String
decode shift msg = encode (negate shift) msg

findKey :: (Eq k) => k -> [(k,v)] -> Maybe v
findKey key [] = Nothing
findKey key ((k,v):xs) = if key == k
                            then Just v
                            else findKey key xs

findKey' :: (Eq k) => k -> [(k,v)] -> Maybe v  
findKey' key = foldr (\(k,v) acc -> if key == k then Just v else acc) Nothing
