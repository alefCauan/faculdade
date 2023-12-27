% Desenvolva um sistema escolar simples em Prolog para gerenciar informações sobre disciplinas e estudantes. O sistema deve permitir o cadastro de disciplinas e alunos, matrícula de alunos em disciplinas, e consulta de alunos matriculados em uma disciplina.

% 1 - Cadastro de Disciplinas e Alunos: Permitir adicionar novas disciplinas e alunos ao sistema.

% 2 - Matrícula de Alunos em Disciplinas: Possibilitar a matrícula de alunos em disciplinas específicas.

% 3 - Consulta de Alunos Matriculados: Capacidade de consultar e listar os alunos matriculados em uma disciplina.

%___________________________________
% Declaração de predicados dinâmicos para a base de dados

:- dynamic disciplinas/1.  

adicionar_disciplina(Disciplina) :-
    assertz(disciplinas(Disciplina)).

:- dynamic alunos/1.  

adicionar_alunos(Aluno) :-
    assertz(alunos(Aluno)).

:- dynamic cadastro/2.

cadastrar_alunos(Disciplina, Aluno) :-

    disciplinas(Disciplina), alunos(Aluno), assertz(cadastro(Disciplina, Aluno)) -> fail ; 
    write('Disciplina ou aluno sem cadastro '), nl.    

%___________________________________
% Lidar com as varias requisições de nome

pegar_nome(Nome) :- write('Escreva o nome: '), read(Nome), nl.

%___________________________________
% Mostrar os alunos matriculados 

alunos_matriculados(Disc) :-
    cadastro(Disc, Aluno), write(Aluno), nl. 

%___________________________________
% Lidar com todas as possibilidades de escolha do menu principal 

lidar(1) :-
    write('1 - cadastrar disciplina'), nl,
    pegar_nome(Nome), 
    adicionar_disciplina(Nome), fail.

lidar(2) :-
    write('2 - cadastrar aluno'), nl,
    pegar_nome(Nome), 
    adicionar_alunos(Nome), fail.

lidar(3) :- 
    write('Nome do aluno'), nl, 
    pegar_nome(Aluno),
    write('Nome da disciplina'), nl, 
    pegar_nome(Disciplina),
    cadastrar_alunos(Disciplina, Aluno), fail.

lidar(4) :- 
    write('Materia para observar os alunos matriculados'), read(Disc), 
    disciplinas(Disc) -> alunos_matriculados(Disc) ; 
    write('Não há essa materia!'), nl.

lidar(0) :- write('Saindo...'), !.

%___________________________________
% Menu de escolha principal 

menu :-
    repeat,
    write('1 - cadastro de disciplinas'), nl,
    write('2 - cadastro de alunos'), nl,
    write('3 - matricular alunos'), nl,
    write('4 - consultar matricula'), nl,
    write('0 - sair'), nl,
    read(X),
    lidar(X).

    
    