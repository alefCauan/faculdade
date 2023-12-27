f(X, 0) :- X < 3, !.
f(X, 2) :- X < 6, !.
f(X, 4).

b.
d.
p.
q.
r.
s.
t.
u.
v.

c :- p, q, r, !, s, t, u.
c :- v.
a :- b, c, d.

a(1).
b(2).
c(1).
p(X) :- a(X), !, b(X).
p(X) :- c(X).
p(X) :- a(X).

m(1).
m(2) :- !.
m(3).
m1(X, Y) :- m(X), m(Y).
m2(X, Y) :- m(X), !, m(Y).
/* 
Respostas
m(X). - 1, 2
m1(X, Y). - (1, 1), (1, 2), (2, 1), (2, 2)
m2(X, Y). - (1, 1), (1, 2)
m(3). - True
*/