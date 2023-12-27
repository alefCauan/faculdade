num([1, 2, 3 ,4, 5]).


% soma([], 0).
% soma([X|Corpo], Soma) :- soma(Corpo, Soma2), Soma is Soma2 + X. 

intersec([], [], []).
intersec([X|T1], [X|T2], [Lista|T3]) :- Lista = X,
    intersec(T1, T2, T3) -> !.
intersec([_|C], [_|C2], Lista) :- intersec(C, C2, Lista).

inverter([],[]).
inverter([X],X).
inverter([X|Y], Lista) :- inverter(Y, Lista), Lista = [Y|X].


elementosIguais([], _, []).
elementosIguais(_, [], []).
elementosIguais([X|Y], Lista2, [X|Cauda]) :- membro(X, Lista2), elementosIguais(Y, Lista2, Cauda) -> !.
elementosIguais([_|Y], Lista2, Cauda) :- elementosIguais(Y, Lista2, Cauda).


maior([H| []]) :- write('Maior é igual a '), write(H).
maior([_|T]) :- maior(T).

ordena([], []).
ordena([X], [X]).
ordena([H|T], [H2|T2]) :- sort([H|T], [H2|T2]), 
    Menor = H2, write('O menor número é '), 
    write(Menor),nl, maior(T2), nl.


    


%cocatenar(Lista1, Lista2, Lista3)
concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).

 
membro(X, [X|_]):- !.

membro(X, [_|T]) :- membro(X, T).

apagarElemento(X, [X|H], D) :- !, (membro(X, H) -> apagarElemento(X, H, D) ; D = H).

apagarElemento(X, [Y|C], [Y|D]) :- apagarElemento(X, C, D).

somalista([], 0).
somalista([C|H], X) :- somalista(H, X2),
X is C + X2.

fatorial(0, 0).
fatorial(1, 1) :- !.
fatorial(X, Y) :-
 X2 is X-1, 
 fatorial(X2, Y2), 
 Y is Y2 * X.


media([], 0).
media([X|H], Media) :- 
    soma([X|H], Total), 
    conta([X|H], Quant), 
    Media is Total/Quant, 
    verifica(Media, Y), 
    write('Sua situação é '), write(Y).


verifica(X, Situacao) :- 
    (
        (X >= 7 -> Situacao = aprovado)
        ;
        (X > 4, X < 7 -> Situacao = recuperacao)
        ;
        (X =< 4-> Situacao = final)
    
    ).

conta([], 0).
conta([_|T], X) :- conta(T, X2), X is X2 + 1.

soma([], 0).
soma([X|T], R) :- soma(T, X2), R is X2 + X.



hit(iver, alef).
hit(beliaver, alef).
hit(alsui, joo).


hit_hit(X) :- hit(H, X), hit(T, X), H \= T.

localizado_em(salvador, bahia).
localizado_em(bahia, brasil).
localizado_em(brasil, america).
localizado_em(maceio, brasil).
localizado_em(roma, italia).

nasceu_em(joao, salvador).
nasceu_em(maria, maceio).
nasceu_em(giuseppe, roma).

mora_em(X, Y) :- nasceu_em(X, Y).
mora_em(X, Y) :- nasceu_em(X, Z), outros(Z, Y).
outros(X, Y) :- localizado_em(X, Y).
outros(X, Y) :- localizado_em(X, Z), outros(Z, Y).

intervalo(X, Y, Z) :- (X >= Y -> ! ; Z is X).
intervalo(X, Y, Z) :- X2 is X + 1, intervalo(X2, Y, Z).



adiciona(X, [], [X]).
adiciona(X, [Head|Tail], [Head|Tail2]) :- adiciona(X, Tail, Tail2).

% Região Norte
estado(acre, 'AC', 'Rio Branco', norte).
estado(amazonas, 'AM', 'Manaus', norte).
estado(amapa, 'AP', 'Macapá', norte).
estado(para, 'PA', 'Belém', norte).
estado(roraima, 'RR', 'Boa Vista', norte).
estado(rondonia, 'RO', 'Porto Velho', norte).

% Região Nordeste
estado(alagoas, 'AL', 'Maceió', nordeste).
estado(bahia, 'BA', 'Salvador', nordeste).
estado(ceara, 'CE', 'Fortaleza', nordeste).
estado(maranhao, 'MA', 'São Luís', nordeste).
estado(paraiba, 'PB', 'João Pessoa', nordeste).
estado(pernambuco, 'PE', 'Recife', nordeste).
estado(piaui, 'PI', 'Teresina', nordeste).
estado(rio_grande_do_norte, 'RN', 'Natal', nordeste).
estado(sergipe, 'SE', 'Aracaju', nordeste).

% Região Centro-Oeste
estado(distrito_federal, 'DF', 'Brasília', centro_oeste).
estado(goias, 'GO', 'Goiânia', centro_oeste).
estado(mato_grosso, 'MT', 'Cuiabá', centro_oeste).
estado(mato_grosso_do_sul, 'MS', 'Campo Grande', centro_oeste).

% Região Sudeste
estado(espirito_santo, 'ES', 'Vitória', sudeste).
estado(minas_gerais, 'MG', 'Belo Horizonte', sudeste).
estado(rio_de_janeiro, 'RJ', 'Rio de Janeiro', sudeste).
estado(sao_paulo, 'SP', 'São Paulo', sudeste).

% Região Sul
estado(parana, 'PR', 'Curitiba', sul).
estado(rio_grande_do_sul, 'RS', 'Porto Alegre', sul).
estado(santa_catarina, 'SC', 'Florianópolis', sul).



sigla(X, Y) :- estado(X, Y, _, _).

regiao(X, Y) :- estado(X, _, _, Y).

capital(X, Y) :- estado(X, _, Y, _).

capest(X, Z, Y) :- estado(Y, _, Z, X).

