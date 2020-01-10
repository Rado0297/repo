nat(c).
nat(s(X)):-nat(X).
sum(X,c,X).
sum(X,s(Y),s(Z)):-sum(X,Y,Z).
interpret(0,c).
interpret(N,s(X)):-interpret(M,X),N is M+1.
gen(0,c).
gen(N,s(X)):-N>0,M is N-1,gen(M,X).
bezout(X,0,X,1,0).
bezout(X,Y,D,U,V):-X>=Y,Y>0,X1 is X-Y,bezout(X1,Y,D,U,V1),V is V1-U.
bezout(X,Y,D,U,V):-X<Y,bezout(Y,X,D,V,U).
fib(X,X):-X=<1.
fib(N,F):-N>=2,fib(N-1,F1),fib(N-2,F2),F is F1+F2.
fib2(0,0,1).
fib2(N,F1,F2):-N>0,N1 is N-1,fib2(N1,F3,F1),F2 is F1+F3.
mem(X,[X|_]).
mem(X,[_|L]):-mem(X,L).
reverse([],L1,L1).
reverse([X|L2],L1,R):-reverse(L2,[X|L1],R).
rev(L,R):-reverse(L,[],R).
cat([],Y,Y).
cat([A|L],Y,[A|Z]):-cat(L,Y,Z).
mem2(X,L):-cat(_,[X|_],L).
perm([],[]).
perm([A|L1],P):-perm(L1,P1),cat(P2,P3,P1),cat(P2,[A|P3],P).
ordered([]).
ordered([_]).
ordered([A,B|L]):-A=<B,ordered([B|L]).
sort2(L,S):-permutation(L,S),ordered(S).
unordered(S):-cat(_,[A,B|_],S),A>B.
sort3(L,S):-perm(L,S),not(unordered(S)).
edge(E,U,V):-mem([U,V],E).
edge(E,U,V):-mem([V,U],E).
nonhamiltonian(E,H):-cat(_,[U,V|_],H),not(edge(E,U,V)).
hamiltonian(V,E,H):-perm(V,H),not(nonhamiltonian(E,H)).
subword(L,W):-cat(_,V,L),cat(W,_,V).
subsequence([],[]).
subsequence([A|L],[A|S]):-subsequence(L,S).
subsequence([_|L],S):-subsequence(L,S).
subset(V,_,V1):-subsequence(V,V1).
is_not_clique(E,V1):-mem(U,V1),mem(W,V1),U\=W,not(edge(E,U,W)).
is_clique(E,V1):-not(is_not_clique(E,V1)).
clique(V,E,V1):-subset(V,E,V1),is_clique(E,V1).
len([],0).
len([_|L1],N):-len(L1,N1),N is N1+1.
clique_size(V,E,V1,N1):-clique(V,E,V1),len(V1,N1).
exists_bigger_clique(V,E,N):-clique_size(V,E,_,N1),N1>N.
max_clique(V,E,V1):-clique_size(V,E,V1,N1),not(exists_bigger_clique(V,E,N1)).
between2(I,J,I):-I=<J.
between2(I,J,K):-I<J,I1 is I+1,between2(I1,J,K).
all_functions([],_,[]).
all_functions([A|V1],K,[[A,K1]|C1]):-between2(1,K,K1),all_functions(V1,K,C1).
is_not_colouring(_,E,C):-mem([U,K],C),mem([W,K],C),edge(E,U,W).
is_colouring(_,E,C):-not(is_not_colouring(_,E,C)).
colouring(V,E,K,C):-all_functions(V,K,C),is_colouring(V,E,C).
merge1(S1,[],S1).
merge1([],[A|S2],[A|S2]).
merge1([A|S1],[B|S2],[A|S]):-A=<B,merge1(S1,[B|S2],S).
merge1([A|S1],[B|S2],[B|S]):-A>B,merge1([A|S1],S2,S).
split1(L,L1,L2):-cat(L1,L2,L),len(L1,N1),len(L2,N2),N1-N2=<1,N1>=N2.
split([],[],[]).
split([A],[A],[]).
split([A,B|L],[A|L1],[B|L2]):-split(L,L1,L2).
merge_sort([],[]).
merge_sort([A],[A]).
merge_sort([A,B|L],S):-split([A,B|L],L1,L2),merge_sort(L1,S1),merge_sort(L2,S2),merge1(S1,S2,S).
transition_det(Q,T,S,F,P,A,P1):-mem([P,A,P1],T).
traverse_det(Q,T,S,F,P,[],P).
traverse_det(Q,T,S,F,P,[A|W1],P1):-transition_det(Q,T,S,F,P,A,P2),traverse_det(Q,T,S,F,P2,W1,P1).
recognise_det(Q,T,S,F,W):-traverse_det(Q,T,S,F,S,W,P),mem(P,F).
natural(0).
natural(X):-natural(Y),X is Y+1.
graph_g1(M,0,Y):-M mod 2 =:=1,Y is (M-1)/2.
graph_g1(M,X,Y):-M mod 2 =:=0,M1 is M/2,graph_g1(M1,X1,Y),X is X1+1.
pairs(X,Y):-natural(N),M is N+1,graph_g1(M,X,Y).
genA(N,X,Y):-between2(0,N,X),Y is N-X.
pairs2(X,Y):-natural(N),genA(N,X,Y).
genBoundedSeq(N,M,[]):-M>=0.
genBoundedSeq(N,M,[A]):-M>=1,between2(0,N,A).
genBoundedSeq(N,M,[A|[B|L]]):-M>=2,M1 is M-1,genBoundedSeq(N,M1,[B|L]),B1 is B-1,between2(0,B1,A).
genSet(S):-pairs2(N,M),genBoundedSeq(N,M,S).
genRelation([],[]).
genRelation([N|M],[[X,Y]|R]):-between2(0,N,X), Y is N-X,genRelation(M,R).
irreflexive(R):-mem2([X,_],R),not(mem2([X,X],R)).
irreflexive(R):-mem2([_,X],R),not(mem2([X,X],R)).
reflexive(R):-not(irreflexive(R)).
asymmetric(R):-mem2([X,Y],R),not(mem2([Y,X],R)).
symmetric(R):-not(asymmetric(R)).
intransitive(R):-mem2([X,Y],R),mem2([Y,Z],R),not(mem2([X,Z],R)).
transitive(R):-not(intransitive(R)).
genFiniteEquivalenceRelations(R):-genSet(S),genRelation(S,R),reflexive(R),symmetric(R),transitive(R).
