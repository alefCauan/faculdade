% consecutivo(X, Y) :- Y is X + 1.


% consecutivo(X, [X, H|T]) :- H is X + 1.
% consecutivo(X, [_|T]) :- consecutivo(X, T).

consecutivo(_, []) :- !. 
consecutivo(X, [X|T]) :- X2 is X + 1, consecutivo(X2, T), !.
consecutivo(X, [H|T]) :- 
    H is X + 1,
    consecutivo(H, T).