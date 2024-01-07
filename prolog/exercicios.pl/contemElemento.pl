contem_1([1]) :- !.
contem_1([H|T]) :- (H is 1 -> !) ; contem_1(T).