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