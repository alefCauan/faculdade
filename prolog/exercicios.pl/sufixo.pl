sufixo([], []).
sufixo(L, L2) :- L = L2, !.
sufixo(L, [_|T]) :- sufixo(L, T).