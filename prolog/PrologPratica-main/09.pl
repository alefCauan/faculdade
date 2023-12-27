% Um elemento pertence a uma lista?
pertence(X, [X | _]).
pertence(X, [_ | T]) :- pertence(X, T).

% Um elemento é o último elemento de uma lista?
ultimo(X, [X]).
ultimo(X, [_ | T]) :- ultimo(X, T).

% A lista tem 2 elementos consecutivos?
consecutivos(X, Y, [X, Y | _]).
consecutivos(X, Y, [_ | T]) :- consecutivos(X, Y, T).

% Retorne o tamanho de uma lista
tamanho([], 0).
tamanho([_ | T], Tam) :- tamanho(T, Tam2), Tam is 1 + Tam2.