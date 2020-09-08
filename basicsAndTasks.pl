%isMember(X, L) - проверява дали X е елемент на списъка L; генерира всички елементи на L.
isMember(H, [H|_]).
isMember(X, [H|T]):-isMember(X,T).

%append(A, B, L) - L е конкатенацията на списъците A и B.
append([], B, B).
append([H|T], B, [H|C]):-append(T, B, C).

%split(X, L, A, B) - разделя списъка L спрямо елемента X: 
%в A се съдържат елементите преди първото срещане на X в L, а в B - останалите (без самия X).
split(_, [], [], []).
split(H, [H|T], [], T).
split(X, [H|T], [X|A], B):-split(X, T, A, B).

%splitLess(X, L, A, B) - разделя списъка L спрямо елемента X: 
%в A се съдържат елементите по-малки от X в L, а в B - останалите (без самия X).
splitLess(_, [], [], []).
splitLess(X, [H|T], A, [H|B]):-X<H,splitLess(X, T, A, B),!.
splitLess(X, [H|T], [H|A], B):-splitLess(X, T, A, B).


%remove(X, L, N) - N е списъкът, получен след премахване на (първото срещане на) елемента X от списъка L.
remove(_, [], []).
remove(H, [H|T], T):-!.
remove(X, [H|T], [H|N]):-remove(X, T, N).

%removeAll(X, L, N) -  N е списъкът, получен след премахване на (всички срещания на) елемента X от списъка L.
removeAll(_, [], []).
removeAll(H, [H|T], N):-removeAll(H, T, N), !.
removeAll(X, [H|T], [H|N]):-removeAll(X, T, N).

%removeList(R, L, N) - N е списъкът, получен след премахване от L на тези елементи, които се срещат в R.
removeList([], L, L).
removeList([H|R], L, N):-remove(H, L, S), removeList(R, S, N).

%reverseSlow(L, R) - списъкът R съдържа всички елементи на L в обърнат ред.
%сложност - O(|L|^2)
reverseSlow([], []).
reverseSlow([H|T], R):-reverseSlow(T, A), append(A, [H], R).

%rev(L, S, R) - помощна функция - генерира огледалния на L списък S и проверява дали S и R съвпадат.
%reverse(L, R) - списъкът R съдържа всички елементи на L в обърнат ред.
%сложност - O(|L|)
rev([], S, S).
rev([H|T], S, R):-rev(T, [H|S], R).
reverse(L, R):-rev(L, [], R).


%min(A,B,X) - в X се записва по-малкото от A и B.
min(A,B,B):-B=<A.
min(A,B,A):-A<B.

%minimal(X, L) - в X се записва минималният елемент на списъка L.
minimal(H, [H]).
minimal(X, [H|T]):-minimal(Y, T), min(H, Y, X).
 
%sortL(L, N) - списъкът N съдържа всички елементи от L в сортиран (в случая - нарастващ) ред.
sortL([], []).
sortL([H], [H]).
sortL(L, [X|N]):-minimal(X,L), remove(X, L, A), sortL(A, N).

%quicksort(L, N) - списъкът N съдържа всички елементи от L в сортиран (в случая - нарастващ) ред.
quicksort([], []).
quicksort([H|L], S):-splitLess(H, L, A, B), quicksort(A, SA), quicksort(B, SB), append(SA, [H|SB], S).

%sorted(L) - проверява дали списъкът L е сортиран.
sorted([]).
sorted([H|T]):-minimal(H,[H|T]), sorted(T).

%unique(L) - проверява дали L е съставен от уникални елементи.
unique([]).
unique([H|T]):-unique(T), not(isMember(H, T)).

%uniqueL(L, N) - списъкът N съдържа всички уникални елементи от L.
uniqueL([], []).
uniqueL([H|T], [H|L]):-removeAll(H, T, A), uniqueL(A, L).

%lengthL(L, N) - в N се записва дължината на списъка L.
lengthL([], 0).
lengthL([H|T], N):-lengthL(T, M), N is M+1.

%prefix(P, L) - провевява дали списъкът P е префикс на списъка L.
prefix(P, L):- append(P, _, L).

%suffix(S, L) - провевява дали списъкът S е суфикс на списъка L.
suffix(S, L):- append(_, S, L).

%infix(I, L) - проверява дали списъкът I е инфикс на списъка L.
infix(I, L):- append(_, I, P), prefix(P,L).

%subset(A, B) - проверява дефиницията A да е подмножество на B:
subset([],[]).
%subset(A, B):-not((isMember(X, A), not(isMember(X, B)))).
%а това е рекурсивната дефиниция:
subset([H|A], [H|B]):-subset(A, B).
subset(A, [H|B]):-subset(A, B).

%between(X, A, B) - X е елемент в интервала [A, B].
between(B, B, B).
between(A, A, B):-A<B.
between(X, A, B):-A<B, A1 is A+1, between(X, A1, B).

%subsetGenN(L, M, N) - генерира всички подмножества M на L с държина N.
subsetGenN(_, [], 0).
subsetGenN(L, [H|T], N):-N1 is N-1,subsetGenN(L, T, N1), isMember(H, L).

%decart(A, B, R) - генерира чрез преудовлетворянане в R декартовото произведение AxB. 
decart([], _, []).
decart(_, [], []).
decart(A, B, [X, Y]):-isMember(X, A), isMember(Y, B).

%divisable(N, M) - дали числото M е делител на числото N.
divisible(N, M):-0 is N mod M.

%prime(N) - проверява дали числото N е просто.
%notPrime(N) - понеже предикатът not е едноместен, се създава помощна функция, поддържаща отрицанието.
prime(2):-true, !.
prime(N):-N < 2, !, false.
prime(N):-not((N1 is N-1, between(X, 2, N1), prime(X), divisible(N, X))).

%primeDivisors(N, L) - генерира списъка L от всички прости делители на числото N.
primeDivisors(N, []):-N<2,!.
primeDivisors(N, [N]):-prime(N),!.
primeDivisors(N, [X|A]):-between(X, 2, N/2), prime(X), divisible(N, X), M is N/X, primeDivisors(M, A),!.

%equalL(A, B) - проверява дали списъците A и B са равни.
equalL([], []).
equalL([H|A], B):-remove(H, B, L), equalL(A, L).

%gcd(X, Y, G) - в G се записва най-малкия общ делител на числата X и Y.
gcd(X, X, X).
gcd(X, Y, G):-X>Y, Z is X-Y, gcd(Z, Y, G).
gcd(X, Y, G):-X<Y, Z is Y-X, gcd(X, Z, G).


%ratSimplify(X, Y) - дробта Y е опростената дроб X.
ratSimplify(A/B, M/N):-gcd(A, B, X), M is A/X, N is B/X.

%ratSimplify(X, Y, Z) - дробта Z е произведението на дробите X и Y.
ratMultiply(A/B, C/D, M/N):-M1 is A*C, N1 is B*D, ratSimplify(M1/N1, M/N). 

%ratDivide(X, Y, Z) - дробта Z е частното на дробите X и Y.
ratDivide(A/B, C/D, M/N):-M1 is A*D, N1 is B*C, ratSimplify(M1/N1, M/N).

%ratSum(X, Y, Z) - дробта Z е сумата на дробите X и Y.
ratSum(A/B, C/D, M/N):-M1 is (A*D)+(C*B), N1 is B*D, ratSimplify(M1/N1, M/N).

%ratSum(X, Y, Z) - дробта Z е разликата на дробите X и Y.
ratDif(A/B, C/D, M/N):-M1 is (A*D)-(C*B), N1 is B*D, ratSimplify(M1/N1, M/N).


%dist(X1, Y1, X2, Y2, D) - пресмята D - разстоянието между точките (X1, Y1) и (X2, Y2).
dist(X1, Y1, X2, Y2, D):- X is X1-X2, Y is Y1-Y2, D2 is (X*X)+(Y*Y), D is sqrt(D2). 

%commonSubsequence(A, B, C) - в списъка C се генерират чрез преудовлетворяване всички общи подредици на списъците A и B. 
commonSubsequence([], [], []).
commonSubsequence([H|T], B, [H|C]):-isMember(H, B), split(H, B, _, A), commonSubsequence(T,A,C).
commonSubsequence([H|T], B, C):-commonSubsequence(T,B,C).

%longer(L, S, N) - в списъка N се записва по-дългия от списъците L и S.
longer(L, S, L):-lengthL(L, N), lengthL(S, M), N>M.
longer(L, S, S):-lengthL(L, N), lengthL(S, M), N<M.

%lcs(A, B, C) - в списъка C се генерират всички най-дълги общи подредици на списъците A и B.
lcs(A, B, C):-commonSubsequence(A, B, C), not((commonSubsequence(A, B, S), longer(S, C, S))).

%shift(N, L, R) - измества всички елементи на списъка от числа L с естествено число N, получавайки нов списък R.
shift(_, [], []).
shift(N, [H|T], [M|L]):-M is H+N, shift(N, T, L).

:-[basics].

%------------------------------
%първо контролно КН 2011

%задача 1:
%Да се дефинира предикат p, приемащ списък от списъци X и генериращ чрез преудовлетворядане списък Y, съдържащ елементите на
%декартовото произведение на елементите на Х.
p([], []).
p([H], [X]):-isMember(X, H).
p([H, S], Y):-decart(H, S, Y).
p([H, S|T], [X|Y]):-isMember(X, H), p([S|T], Y).

%задача 2:
%Да се дефинира предикат q, който по дадени две числа разпознава дали имат едни и същи прости делители.
q(X, X).
q(X, Y):-primeDivisors(X, XD), uniqueL(XD, A), sort(A, SA),
		 primeDivisors(Y, YD), uniqueL(YD, B), sort(B, SB), equalL(SA, SB). 

%-------------------------------
%първо контролно КН 2010

%задача 1:
%Да се дефинира предикат g, приемащ списък от списъци X и генериращ списък Y,
%съдържащ най-малките елементи от всеки елемент на X и 
%няма друг списък със същото свойство и по-малко елементи. 
%allMinimal(X, A) - помощен предикат, генерираща списък A, съдържащ минималните елементи на всички списъци от X
allMinimal([], []).
allMinimal([H|T], [M|L]):-minimal(M, H), allMinimal(T, L).
g(X, Y):-allMinimal(X, A), uniqueL(A, Y).

%задача 2:
%Да се дефинира предикат h, приемащ естествено число A и генериращ чрез преудовлетворяване дробите K/L и M/N, където:
%M>N>0, L>K>0, (N/M)*(L/K)=2. M+K<A
%sumUnderA(M, K, A) - помощен предикат, генериращ чрез преудовлетворяване всички числа M и K, M+K<A
sumUnderA(M, K, A):-A1 is A-1, between(M, 0, A1), X is A1-M, between(K, 0, X).
h(A, K/L, M/N):-sumUnderA(M, K, A), M1 is M-1, between(N, 1, M1), ratDivide(2/1, N/M, L/K).


%-------------------------------
%писмен изпит Информатика 2012

%задача 1:
%Да се дефинира предикат pointIn, приемащ квадрат, зададен чрез X1, Y1 - координати на долен ляв ъгъл, и число A - дължина на страната,
%и окръжност с център (X2, Y2) и радиус R и генериращ чрез преудовлетворяване точките (X, Y), които попадат и в двете фигури.
%(квадратът е със страни, успоредни на координатните оси)
pointInSquare(X1, Y1, A, X, Y):-X2 is X1+A, Y2 is Y1+A, between(X, X1, X2), between(Y, Y1, Y2).
pointInCircle(X1, Y1, R, X, Y):-Xleft is X1-R, Ydown is Y1-R, R2 is R+R, pointInSquare(Xleft, Ydown, R2, X, Y), dist(X, Y, X1, Y1, D), D=<R.
pointIn(X1, Y1, A, X2, Y2, R, X, Y):-pointInSquare(X1, Y1, A, X, Y), pointInCircle(X2, Y2, R, X, Y).


%-----------------------------
%Второ контролно КН 2012

%задача 1:
%Да се дефинира предикат s, приемащ списък L и генериращ всечке списъци M, за които е изпълнено, че:
%--елементите на M образуват подмножество на множеството от елементите на L 
%--за всеки елемент X на M съществува такъв елемент Y от M, че множеството {X+Y, X*Y, X-Y} e подмножество на L.
%setS(X, Y, Z):-генериращ списъка Z, представящ множеството {X+Y, X*Y, X-Y}
%inL(X, Y, L) - помощен предикат, проверяващ дали {X+Y, X*Y, X-Y} e подмножество на L
setS(X, Y, [Z1, Z2, Z3]):-Z1 is X+Y, Z2 is X*Y, Z3 is X-Y.
inL(X, Y, L):-setS(X, Y, [Z1, Z2, Z3]), isMember(Z1, L), isMember(Z2, L), isMember(Z3, L).
s([], []).
s(L, M):-uniqueL(L, UL), subset(M, UL), not((isMember(X, M), not((isMember(Y, M), inL(X, Y, L))))).


%задача 2:
%Да се предифинира предикат transpose, приемащ матрица M (списък от списъци-редове) и генерира транспонираната й матрица T
%getColumn(M, C) - помощен предикат, извличащ първата колона.
%removeColumn(M, N) - помощен предикат, премахващ първата колона.
getColumn([], []).
getColumn([[X|_]|M], [X|C]):-getColumn(M, C).
removeColumn([], []).
removeColumn([[_|H]|M], [H|N]):-removeColumn(M, N).
transpose([[]|_], []).
transpose(M, [H|T]):-getColumn(M, H), removeColumn(M, N), transpose(N, T).
