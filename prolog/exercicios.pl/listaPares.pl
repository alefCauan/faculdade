pares([], []).
pares([H|T], Pares) :-  pares(T, Pares2),( 0 is H mod 2 -> Pares = [H|Pares2] ; Pares = Pares2). 
                                                    %   passar novo elemento  | Manter a lista atual "Lista igual a Lista"