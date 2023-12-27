aluno(marcelo).
aluno(andre).
aluno(roberto).

escreverSemFail :- aluno(X), write(X).
escreverComFail :- aluno(X), write(X), nl, fail.
%write('olá'), nl, fail
%repeat, write('olá'), nl, fail

%repeat
%       lerDados
%       processarDados
%       condição

adivinhe_numero :-
    N is random(5) + 1, % gera de 0 a 4, ao somar com 1 se torna de 1 a 5
    repeat,
        lerDados(G),
        processarDados(G, N).

lerDados(G) :- write('Digite um número (1 até 5): '),
                read(G).

processarDados(G, N) :- G =:= N, write('Parabéns, você acertou!'), nl.
processarDados(G, N) :- G \= N, write('Você errou!'), nl, fail.

repete :- repeat,
            write('Digite a palavra: '),
            read(Palavra),
            (
                Palavra == fim -> !
                ;
                processar(Palavra), fail
            ).

processar(Palavra) :- write("===> "), write(Palavra), nl.