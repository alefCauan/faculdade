/*
  Ex 01 - Crie uma regra que recebe duas listas e informe se a lista L1 é prefixo de L2
*/
prefixo([], _).
prefixo([H1 | T1], [H2 | T2]) :-
    H1 == H2,
    prefixo(T1, T2).


/*
  Ex 02 - Crie uma regra que recebe duas listas e informe se a lista L1 é sufixo de L2
*/
sufixo(L, L).
sufixo(L1, [_ | T2]) :-
    sufixo(L1, T2).


/*
  Ex 03 - Crie uma regra que recebe uma lista e retorna outra lista somente com os pares.
*/
/*
pares([L1], [L2]) :- 
    0 is L1 mod 2, L2 is L1.
pares([H | T], [H2 | T2]) :- 
    pares(T, T2),
    0 is H mod 2, H2 is H.    
*/
/*
pares([L1], [L2]) :- 
    0 is L1 mod 2, L2 is L1%.
    ;
    L2 = 0.

pares([H | T], L2) :- 
    T \= [],
    pares(T, [T2]),
    pares([H], [H2]),
    %write(T2), nl,
    %write(H2), nl,
    (H2 \= 0, T2 \= 0, L2 is [H2, T2]);
    (H2 \= 0, L2 is [H2]);
    (T2 \= 0, L2 is [T2]).
    %0 is H mod 2, H2 is H,
    %(
    %    (T2 == [], write('T2 Vazio'));
    %    ([H2] == [], write('H2 Vazio'));
    %    %T2 \= [],
    %    %H2 \= [],
    %    L2 = [H2 | T2]
    %
    %).
*/   
pares([], []).    
pares([H1 | T1], L) :-
    pares(T1, T2),
    (
        (H1 mod 2) =:= 0
        ->
        L = [H1 | T2]
        ;
        L = T2
    ).


/*
Ex 04 - Defina um predicado chamado todos_as(L), que retorna verdadeiro somente se todos os
elementos da lista L são o átomo a
*/
todos_as([a]).
todos_as([H | T]) :-
    todos_as([H]),
    todos_as(T).
    
todos_as2([]).
todos_as2([H | T]) :-
    H = a,
    todos_as2(T).

/*
Ex 05 - Defina o predicado contem_1(L), que retorna verdadeiro se a lista L contém pelo
menos um elemento 1
*/
contem_1([1]).
contem_1([H | T]) :-
    T \= [],
    (
        contem_1([H]);
        contem_1(T)
    ).

contem_1_2([1]).
contem_1_2([H | T]) :-
    (H = 1, !)
    ;
    contem_1_2(T).

/*
  Ex 06 - Considere a seguinte base de conhecimento:
  Crie uma regra, lista_traducao(E, P), que traduz uma lista de numerais em inglês na lista
  correspondente com os numerais em português.
  Por exemplo, lista_traducao([one, nine, two], X) deve retornar X = [um, nove, dois]
*/
traducao(one, um).
traducao(two, dois).
traducao(three, tres).
traducao(four, quatro).
traducao(five, cinco).
traducao(six, seis).
traducao(seven, sete).
traducao(eight, oito).
traducao(nine, nove).

lista_traducao([E], [P]) :-
  traducao(E, P).

lista_traducao(E, P) :-
  E \= [],
  [H | T] = E,
  traducao(H, H2),
  lista_traducao(T, T2),
  P = [H2 | T2].  

lista_traducao2([], []).
lista_traducao2([H | T], [H2 | T2]) :-
    traducao(H, H2),
    lista_traducao2(T, T2).