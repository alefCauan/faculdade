% Ex. 01.1 - Fazer uma regra indicando quais são os alunos de um professor X
aluno(joao, calculo).
aluno(maria, calculo).
aluno(joel, programacao).
aluno(joel, estrutura).

frequenta(joao, puc).
frequenta(maria, puc).
frequenta(joel, ufrj).

professor(carlos, calculo).
professor(ana_paula, estrutura).
professor(pedro, programacao).

funcionario(pedro, ufrj).
funcionario(ana_paula, puc).
funcionario(carlos, puc).

alunos_do_professor(Aluno, Prof) :- professor(Prof, Materia), aluno(Aluno, Materia), 
                             funcionario(Prof, Faculdade), frequenta(Aluno, Faculdade).
% Ex. 01.2 - Fazer uma regra indicando quais pessoas frequentam a faculdade X
associados(Pessoa, Faculdade) :- frequenta(Pessoa, Faculdade);
                                 funcionario(Pessoa, Faculdade).



% Ex. 02 - Elaborar um programa que forneça o nome da capital de qualquer Estado da região Sudeste
estados(mg, 'Belo Horizonte').
estados(sp, 'São Paulo').
estados(rj, 'Rio de Janeiro').
estados(es, 'Vitória').
capital(Estado, Capital) :- estados(Estado, Capital).



% Ex. 03 - Elaborar um programa para determinar quais tipos sanguíneos podem doar/receber sangue de quais tipos
doa(a, a).
doa(a, ab).
doa(b, b).
doa(b, ab).
doa(ab, ab).
doa(o, a).
doa(o, b).
doa(o, ab).
doa(o, o).
recebe(X, Y) :- doa(Y, X).
