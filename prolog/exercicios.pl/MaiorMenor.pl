maior([X], X) :- !.
maior([H|T], X) :- 
    maior(T, X2),
    (X2 < H -> X = H ; X = X2). 

menor([X], X) :- !.
menor([H|T], X) :- 
    menor(T, X2),
    (X2 > H -> X = H ; X = X2).
