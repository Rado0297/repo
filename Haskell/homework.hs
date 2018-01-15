-- Bst - Binary Search Tree
-- типът очаква като аргументи два други типа, че да стане използваем:
-- тип за ключовете на дървото
-- и тип за стойностите
-- Например: Bst Int String е дърво с целочислени ключове и има низове за стойности
-- Както при обикновеното двоично дърво, имаме два случая - Или имаме празно дърво,
-- или имаме връх със стойност, ляво и дясно поддърво
-- Стойностите за нас са двойка от ключ и стойност
-- Свободни сте да променяте тази дефиниция на типа, стига промяната да улесни живота ви.


data Bst key value = Empty | Node (key,value) (Bst key value) (Bst key value) deriving Show

-- Търсим стойността на даден ключ (от тип а) в дадено дърво
-- (с ключове от тип а и стойности от тип b).
-- Тъй като търсеният ключ може да не съществува в дървото,
-- резултатът на функцията е Maybe b
search :: (Ord a) => a -> Bst a b -> Maybe b
-- TODO:

-- Искаме да вмъкнем дадена двойка (ключ, стойност) в дадено двоично дърво
-- и да върнем новото дърво като резултат
insert :: (Ord a) => (a,b) -> Bst a b -> Bst a b
-- TODO:

-- Обхождаме дадено двоично дърво и трупаме в резултатен списък
inOrder :: (Ord a) => Bst a b -> [(a,b)]
-- TODO:

-- Обхождаме дадено двоично дърво и трупаме в резултатен списък
preOrder :: (Ord a) => Bst a b -> [(a,b)]
-- TODO:

-- Обхождаме дадено двоично дърво и трупаме в резултатен списък
postOrder :: (Ord a) => Bst a b -> [(a,b)]
-- TODO:

-- Като допълнителна, но незадължителна задача, може да реализирате изтриване
-- на връх с даден ключ от дадено дърво

example :: Bst Int String
example = Node (30,"Thirty")
              (Node (10,"Ten")
                    Empty
                    Empty)
              (Node (40, "Fourty")
                  (Node (35, "Thirty-five")
                        Empty
                        Empty)
                  (Node (70, "Seventy")
                        Empty
                        Empty))home
