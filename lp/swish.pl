member1(X,[X|_]).
member1(X,[_|T]):- member1(X,T). 

len1([],0).
len1([_|L],N):-len1(L,X), N is X + 1.

len2([],0).
len2([_|L],N):-len2(L,X), N is X + 1. 

append1([],L,L).
append1([H|L1],L2,[H|L3]):- append1(L1,L2,L3).

suffix(X,L):-append1(_,X,L).
prefix(X,L) :- append1(X,_,L).

sub(S,L):-suffix(Suffix,L),prefix(S,Suffix).

div(_,0).
div(X,Y):-Y>=X,Z is Y-X,div(X,Z).

div_gen(_,0).
div_gen(X,Y):-div_gen(X,Z),Y is Z+X.

split([],[],[]).
split([A],[A],[]).
split([A,B|L],[A|L1],[B|L2]):-split(L,L1,L2).

merge([],L2,L2).
merge([A|L],[],[A|L]).
merge([A|L1],[B|L2],[A|L]):-A=<B,merge(L1,[B|L2],L).
merge([A|L1],[B|L2],[B|L]):-B<A,merge([A|L1],L2,L).

merge_sort([],[]).
merge_sort([A],[A]).
merge_sort([A,B|L],S):-split([A,B|L],L1,L2),merge_sort(L1,S1),
    					merge_sort(L2,S2),merge(S1,S2,S).

genN(0).
genN(N):-genN(N1),N is N1 + 1.

between2(I,J,I):-I=<J.
between2(I,J,K):- I<J,I1 is I+1,between2(I1,J,K).

