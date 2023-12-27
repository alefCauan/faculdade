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

/*
assert/1 - assert(fato(variável)) - acrescenta o fato/regra como último item do predicado
asserta/1 - asserta(fato(variável)) - acrescenta o fato/regra como primeiro item do predicado

retract/1 - remove da base de conhecimento a primeira cláusula (fato ou regra)
            que se unifica com o termo que é passado como parâmetro
retractall/1 - remove da base de conhecimento todos os fatos ou regras cuja
            cláusula (fato ou regra) se unifique com o termo que é passado como
            parâmetro

abolish/1 - remove da base de conhecimento todos os fatos e regras pelo nome da
            regra ou fato/aridade que é passada como parâmetro (são removidos
            predicados estáticos também)
abolish/2 - semelhante a abolish/1, mas passando o nome do fato/regra e a sua
            aridade separadamente (são removidos predicados estáticos também)
*/