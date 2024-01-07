
prefixo([], []).
prefixo([], _) :- !.
prefixo([H|T], [H2|T2]) :- H =:= H2, prefixo(T, T2).


sufixo([], []).
sufixo(L, L2) :- L = L2, !.
sufixo(L, [_|T]) :- sufixo(L, T).

pares([], []).
pares([H|T], Pares) :-  pares(T, Pares2),( 0 is H mod 2 -> Pares = [H|Pares2] ; Pares = Pares2). 
                                                    %   passar novo elemento  | Manter a lista atual "Lista igual a Lista"

todos_as([]).
todos_as([H|T]) :- todos_as(T), a = H.

contem_1([1]) :- !.
contem_1([H|T]) :- (H is 1 -> !) ; contem_1(T).


% GPT 


membro(X, [X|_]) :- !.
membro(X, [_|T]) :- membro(X, T).

conc([], L2, L2).
conc([X | L1], L2, [X | L3]) :-
    conc(L1, L2, L3).

inverte([],[ ]).
    inverte([H|T], ListaInv) :-
    inverte( T, ListaXsInv),
    conc( ListaXsInv,[H], ListaInv).



ultimo(X, [X|[]]) :- !.
ultimo(X, [_|T]) :- ultimo(X, T).


remover_repetido([], []).
remover_repetido([H|T], Lista) :-  
    remover_repetido(T, Lista2),
    (membro(H, Lista2) -> Lista = Lista2 ; Lista = [H|Lista2]).

% consecutivo(X, Y) :- Y is X + 1.


% consecutivo(X, [X, H|T]) :- H is X + 1.
% consecutivo(X, [_|T]) :- consecutivo(X, T).

consecutivo(_, []) :- !. 
consecutivo(X, [X|T]) :- X2 is X + 1, consecutivo(X2, T), !.
consecutivo(X, [H|T]) :- 
    H is X + 1,
    consecutivo(H, T).

tamanho(0, []).
tamanho(X, [_|T]) :- tamanho(X2, T), X is X2 + 1.

maior([X], X) :- !.
maior([H|T], X) :- 
    maior(T, X2),
    (X2 < H -> X = H ; X = X2). 

menor([X], X) :- !.
menor([H|T], X) :- 
    menor(T, X2),
    (X2 > H -> X = H ; X = X2).


