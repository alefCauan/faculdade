/*
    Ex. 01 - Crie um programa em Prolog que leia um nṹmero, calcule e imprima o
    quadrado desse número.
    O programa deve continuar a execução até que o usuário digite a palavra 'stop'
*/

quadrado :-
    repeat,
        write('Digite um número [stop para]: '),
        read(X),
        (
            X = stop, !
            ;
            R is X * X,
            write(X), write(' ao quadrado é '), write(R), nl, nl, fail
        ).


/*
    Ex. 02 - Crie uma regra recursiva com um parâmetro que é um número inteiro, a regra
    deve imprimir os valores de zero até o número informado.
    Ex: imprimirAte(3) - 0, 1, 2, 3
*/
imprimirAte(0) :- write(0).
imprimirAte(X) :-
    X > 0,
    X2 is X - 1,
    imprimirAte(X2),
    write(' '), write(X).

/*
    Ex. 03 - Usando um acumulador, e somente as operações (+)(-)(*), crie uma regra que
    calcule X elevado a Y.
    Assuma X e Y inteiros
*/
potencia(_, 0, 1).
potencia(X, 1, X).
potencia(Base, Exp, Result) :-
    Exp > 1,
    Exp2 is Exp - 1,
    potencia(Base, Exp2, Result2),
    Result is Base * Result2.
