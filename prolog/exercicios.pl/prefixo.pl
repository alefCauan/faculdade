prefixo([], []).
prefixo([], _) :- !.
prefixo([H|T], [H2|T2]) :- H =:= H2, prefixo(T, T2).