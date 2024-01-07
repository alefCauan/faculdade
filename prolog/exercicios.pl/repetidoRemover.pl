membro(X, [X|_]) :- !.
membro(X, [_|T]) :- membro(X, T).

remover_repetido([], []).
remover_repetido([H|T], Lista) :-  
    remover_repetido(T, Lista2),
    (membro(H, Lista2) -> Lista = Lista2 ; Lista = [H|Lista2]).