:- dynamic mulher/1.
:- dynamic homem/1.
:- dynamic genitor/2.

mulher(pam).
mulher(ann).
mulher(liz).
mulher(pat).

homem(tom).
homem(bob).
homem(jim).

genitor(pam, bob).
genitor(tom, bob).
genitor(tom, liz).
genitor(bob, ann).
genitor(bob, pat).
genitor(pat, jim).

prole(X, Y) :- genitor(Y, X).
mae(X, Y) :- genitor(X, Y), mulher(X).
pai(X, Y) :- genitor(X, Y), homem(X).
avos(X, Z) :- genitor(X, Y), genitor(Y, Z).

%descendente(X, Y) :- genitor(Y, X).
%descendente(X, Y) :- genitor(Y, Z), genitor(Z, X).
%descendente(X, Y) :- genitor(Y, Z), genitor(Z, W), genitor(W, X).

descendente(X, Y) :- genitor(Y, X).
descendente(X, Y) :- genitor(Y, W), descendente(X, W).


fatorial(0, 1).
fatorial(Num, R) :- Num > 0,
                  N1 is Num-1,
                  fatorial(N1, R1),
                  R is (Num * R1).


% Ex. 01 - Descreva uma regra para determinar quais animais pertencem a cadeia alimentar de outro
animal(urso).
animal(peixe).
animal(peixinho).
animal(lince).
animal(raposa).
animal(coelho).
animal(veado).
animal(guaxinim).

planta(alga).
planta(grama).

come(urso, peixe).
come(lince, veado).
come(urso, raposa).
come(urso, veado).
come(peixe, peixinho).
come(peixinho, alga).
come(guaxinim, peixe).
come(raposa, coelho).
come(coelho, grama).
come(veado, grama).
come(urso, guaxinim).

cadeia(X, Y) :- animal(X), come(Y, X).
cadeia(X, Y) :- animal(X), come(Y, Z), cadeia(X, Z).

/* 
    Ex. 02 - Crie um programa em Prolog para resolver a equação de recorrência
    Regra:
        Caso base = X_1 = 2
        X_n = X_n-1 - 3n^2
    Predicado:
        regraRecorrencia/2
*/

recorrencia(1, 2).
recorrencia(N, Result) :- N > 1,
                        N1 is N - 1,
                        recorrencia(N1, Result1),
                        Result is Result1 - (3 * (N*N)).