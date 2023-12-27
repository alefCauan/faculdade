soma(A, B, S) :- S is A + B.

% Ex. 01 - Crie uma regra em Prolog que peça no console um número inteiro e imprima na
%tela se o número é maior que 100 ou se é menor ou igual a 100

maior100() :-   write('Digite um número inteiro: '),
                read(N),
                (
                    (N > 100, write('Maior que 100'))
                    ;
                    (N =< 100, write('Menor ou igual a 100'))
                ).


/*
    Ex. 02 Considerando que:
        Nota de 7.0 a 10.0 = Aprovado
        Nota de 5.0 a 6.9 = Recuperação
        Nota de 0.0 a 4.9 = Reprovado
    Escreva uma regra para identificar a situação de um determinado aluno
*/

nota(joao, 5.0).
nota(maria, 6.0).
nota(joana, 8.0).
nota(mariana, 9.0).
nota(cleuza, 8.5).
nota(jose, 6.5).
nota(joaquim, 4.5).
nota(mara, 4.0).
nota(mary, 10.0).

diario(Nome) :-
        nota(Nome, Nota),
        (
            write('Situação: '),
            ((Nota >= 7.0, Nota =< 10), write('Aprovado'));
            ((Nota >= 5.0, Nota =< 6.9), write('Recuperação'));
            ((Nota >= 0.0, Nota =< 4.9), write('Reprovado'))
        ).

imc(Peso, Altura) :- X is Peso/(Altura*Altura),
                     write('Seu IMC é: '), write(X).
