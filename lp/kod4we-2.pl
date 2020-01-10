%concentric(X,Y) - checks if X is strictly in Y

concentricSquares([X1,Y1, A1], [X2, Y2, A2]) :-
    MALAK_X_MALAK_KWADRAT is X1 - A1/2,
    GOLQM_X_MALAK_KWADRAT is X1 + A1/2,
    MALAK_Y_MALAK_KWADRAT is Y1 - A1/2,
    GOLQM_Y_MALAK_KWADRAT is Y1 + A1/2,
    MALAK_X_GOLQM_KWADRAT is X2 - A2/2,
    GOLQM_X_GOLQM_KWADRAT is X2 + A2/2,
    MALAK_Y_GOLQM_KWADRAT is Y2 - A2/2,
    GOLQM_Y_GOLQM_KWADRAT is Y2 + A2/2,
    MALAK_X_MALAK_KWADRAT > MALAK_X_GOLQM_KWADRAT,
    GOLQM_X_MALAK_KWADRAT < GOLQM_X_GOLQM_KWADRAT,
    MALAK_Y_MALAK_KWADRAT > MALAK_Y_GOLQM_KWADRAT,
    GOLQM_Y_MALAK_KWADRAT < GOLQM_Y_GOLQM_KWADRAT.


concentric([]).
concentric([[_,_,_]]).
concentric([FS, SS | T ]) :- concentricSquares(FS, SS), concentric([SS|T]).


% N -> A , X, B, A + B = L 
%append([], X, X).
%append([H|T], B, [H|T2]) :- append(T, B, T2).
%insert(X, L, N) :- append(A, B, L), append(A, [X], AX), append(AX, B, N).
%remove(X, N, L) :- insert(X, L, N).
remove(X,L,N) :- append(A,[X|B], L), append(A, B, N).
%remove(X, [X|T], T).
%remove(X, [H|T], [H, L]) :- remove(X, T, L).




member(_, []) :- false.
member(H, [H|_]).
member(H, [_|T]) :- member(H, T).

perm([], []).
perm([H|T], R) :- member(H, R),
    remove(H, R, P), perm(T, P).

subset([], _).
subset([H1|T1], L) :- member(H1, L), remove(H1, L, L1), subset(T1, L1).

p(X,Y) :- subset(Y, X), concentric(Y).
%p(X,Y) :- subset(SX, X), perm(Y, SX), concentric(Y).