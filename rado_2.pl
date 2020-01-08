%Проверява дали даден елемент фигурира в спикък; генерира в Х чрез преудовлетворяване всички елементи от списъка.
%С други думи - дали Х е елемент на списък
isMember(H, [H|_]).
isMember(X, [H|T]):-isMember(X,T).

%Добавяне на списък след друг списък
%Конкатенация на списъци.
append([], B, B).
append([H|T], B, [H|C]):-append(T, B, C).

%Разделя сисъците по даден показател?
%Разделя списъка на две части - преди и след срещането на даден елемент Х.
split(_, [], [], []).
split(H, [H|T], [], T).
split(X, [H|T], [X|A], B):-split(X, T, A, B).

%Маха първото срещане на даден елемент
remove(_, [], []).
remove(H, [H|T], T):-!.
remove(X, [H|T], [H|N]):-remove(X, T, N).

%Маха всички срещания на даден елемент в списък
removeAll(_, [], []).
removeAll(H, [H|T], N):-removeAll(H, T, N), !.
removeAll(X, [H|T], [H|N]):-removeAll(X, T, N).

%Маха списък от списък
removeList([], L, L).
removeList([H|R], L, N):-remove(H, L, S), removeList(R, S, N).

%сложност - O(|L|^2)
%Връща списъка на обратно
reverse([], []).
reverse([H|T], R):-reverse(T, A), append(A, [H], R).
%как да я забързаме?

%Връща по-малкото от A и B.
min(A,B,B):-B=<A.
min(A,B,A):-A<B.

%Намира най-малкия елемент в списък. 
minimal(H, [H]).
minimal(X, [H|T]):-minimal(Y, T), min(H, Y, X).

%Сортиране от ляво на дясно по списъка
%Сортира в нарастващ ред
sortL([], []).
sortL([H], [H]).
sortL(L, [X|N]):-minimal(X,L), remove(X, L, A), sortL(A, N).

%Обикновен quicksort
quicksort([], []).
quicksort([H|L], S):-split(H, L, A, B), quicksort(A, SA), quicksort(B, SB), append(SA, [H|SB], S).

%Проверява дали един списък е сортиран
sorted([]).
sorted([H|T]):-minimal(H,[H|T]), sorted(T).

%Проверява дали един елемент се среща само веднъж в даден списък
uniqued([]).
uniqued([H|T]):-unique(T), not(isMember(H, T)).

%От ляво на дясно проверява дали един елемент се среща само веднъж.
%Ако се среща повече от веднъж, то оставя само първото срещане на дадения елемент
%Прави списъка уникален (премахва всички ОСТАНАЛИ срещания).
uniqueL([], []).
uniqueL([H|T], [H|L]):-removeAll(H, T, A), uniqueL(A, L).

%Намира дължината на списък като започва от ляво на дясно
%Рекурсията си върви по принцип от ляво на дясно
lengthL([], 0).
lengthL([H|T], N):-lengthL(T, M), N is M+1.

%Проверавя дали първият подаден списък е подмножество на втория
subset([],[]).
subset([H|A], [H|B]):-subset(A, B).
subset(A, [H|B]):-subset(A, B).

%Проверява дали X (първи параметър) е между A и B; гененира всички елементи между А и В.
between(B, B, B).
between(A, A, B):-A<B.
between(X, A, B):-A<B, A1 is A+1, between(X, A1, B).

%Генерира подмножество с N елемента
%Пръвият елемент е подадения списък, вторият е подмножество
subsetGenN(_, [], 0).
subsetGenN(L, [H|T], N):-N1 is N-1,subsetGenN(L, T, N1), isMember(H, L).

%Гененира декартовото произведение на A и B.
decart([], _, []).
decart(_, [], []).
decart(A, B, [X, Y]):-isMember(X, A), isMember(Y, B).

%Проверява дали N се дели на M
divisible(N, M):-0 is N mod M.

%Проверява дали едно число дали е просто
prime(2):-true, !.
prime(N):-N < 2, !, false.
prime(N):-not((N1 is N-1, between(X, 2, N1), prime(X), divisible(N, X))).

%Подава число и списък с прости делите.
%Проверя дали простите делители са делители на даденото число.
%Example: primeDivisors(6, [2, 3]).
%Използва се по-скоро за генериране на простите делители!!!!
primeDivisors(N, []):-N<2,!.
primeDivisors(N, [N]):-prime(N),!.
primeDivisors(N, [X|A]):-between(X, 2, N/2), prime(X), divisible(N, X), M is N/X, primeDivisors(M, A),!.

%Проверява от ляво на дясно дали първия списък е идентичен с втория.
equalL([], []).
equalL([H|A], [H|B]):-equalL(A, B).

%Greatest common dividor
gcd(X, X, X).
gcd(X, Y, G):-X>Y, Z is X-Y, gcd(Z, Y, G).
gcd(X, Y, G):-X<Y, Z is Y-X, gcd(X, Z, G).

%Генерира общите подредици на списъците A и В.
commonSubsequence([], [], []).
commonSubsequence([H|T], B, [H|C]):-isMember(H, B), split(H, B, _, A), commonSubsequence(T,A,C).
commonSubsequence([H|T], B, C):-commonSubsequence(T,B,C).

%Проверява кой от списъците L и S е по-дълъг.
longer(L, S, L):-lengthL(L, N), lengthL(S, M), N>M.
longer(L, S, S):-lengthL(L, N), lengthL(S, M), N<M.

%longest common subsequence
lcs(A, B, C):-commonSubsequence(A, B, C), not((commonSubsequence(A, B, S), longer(S, C, S))).

%Премества списъка с няколко позиции
shift(_, [], []).
shift(N, [H|T], [M|L]):-M is H+N, shift(N, T, L).
