:- dynamic paciente/2.

%  ------------------ BASE DE DADOS ------------------------------------------

% Paciente / Sexo / Idade / Hipertensão / Cardíaco/ Fumante/ IMC/ Hemoglobina/ Glicose/ Diabetes/
%                                                           >25     >=6,4      >=126       sim

paciente([maria, feminino, 37.0, nao, nao, passado, 30.5, 5.7, 100], nao).
paciente([gorete, feminino, 53.0, nao, nao, passado, 26.37, 4.5, 112], nao).
paciente([pedro, masculino, 54.0, nao, nao, nunca, 31.86, 6.6, 145],nao).
paciente([juliana, feminino, 37.0, nao, nao, passado, 21.25, 6.1, 200], nao).
paciente([catisvalda, feminino, 56.0, nao, nao, nunca, 30.95, 6.5, 145], nao).
paciente([ursulino, masculino, 79.0, nao, nao, passado, 31.19, 5.8, 155], nao).
paciente([jose, masculino, 67.0, nao, nao, sim, 27.32, 6.8, 220], sim).
paciente([marta, feminino, 74.0, nao, nao, sim, 29.51, 8.2, 240], sim).
paciente([jussara, feminino, 37.0, nao, nao, passado, 36.87, 8.8, 160], sim).
paciente([katia, feminino, 65.0, sim, sim, nunca, 33.55, 8.9, 202], sim).
paciente([marcelo, masculino, 55.0, nao, sim, passado, 30.42, 6.2, 300], sim).
paciente([ayla, feminino, 61.0, nao, nao, passado, 34.45, 6.5, 280], sim).
paciente([rafaela, feminino, 58.0, sim, nao, nunca, 38.31, 7.0, 200], sim).
paciente([cassia, feminino, 61.0, nao, nao, sim, 30.11, 6.2, 240], sim).
paciente([elisa, feminino, 26.0, nao, nao, passado, 27.32, 4.0, 200], nao).
paciente([alice, feminino, 74.0, nao, nao, passado, 28.12, 5.0, 100], nao).
paciente([jade, feminino, 45.0, sim, nao, nunca, 23.05, 4.8, 130], nao).
paciente([heloise, masculino, 56.0, nao, nao, nunca, 26.78, 4.8, 200], nao).
paciente([benicio, masculino, 20.0, nao, nao, passado, 23.04, 5.7, 160], nao).
paciente([paulo, masculino, 70.0, nao, nao, passado, 15.94, 5.8, 158], nao).
paciente([otavio, masculino, 30.0, nao, nao, passado, 15.8, 6.2, 90], nao).
paciente([isis, feminino, 80.0, nao, nao, nunca, 25.04, 9.0, 209], sim).
paciente([francinaldo, masculino, 63.0, nao, sim, passado, 27.32, 6.6, 300], sim).
paciente([juvelino, masculino, 58.0, nao, nao, passado, 32.38, 6.6, 159], sim).
paciente([maya, feminino, 43.0, sim, nao, nunca, 34.21, 9.0, 160], sim).
paciente([genetildes, masculino, 56.0, nao, nao, nunca, 37.59, 4.0, 159], nao).
paciente([waldisney, masculino, 60.0, nao, nao, passado, 25.4, 4.0, 200], nao).
paciente([reinaldo, masculino, 27.0, nao, nao, passado, 27.32, 3.5, 100], nao).
paciente([frederico, masculino, 54.0, nao, nao, passado, 30.41, 5.0, 158], nao).


% diabetico(Pessoa) :- paciente(Pessoa, sim).l

% diabetico([_, _, _, _, _, _, X, Y, Z], Diabetes) :- diabetes([_, _, _, _, _, _, X, Y, Z], Diabetes), (X > 20; X>25),  Y>=6.0,  Z>=126, Diabetes = sim.

% Predicados para adicionar, remover, listar pacientes....
pegar_dado(Entrada) :-
    read(Entrada),
    nl.


% calcular Índice de Massa Corporal (IMC)
calcular_IMC(Peso, Altura, IMC) :-
    IMC is Peso / (Altura * Altura).


% ADICIONAR O PACIENTE A BASE DE DADOS
adicionar_paciente(Dados, Situacao) :-
    assertz(paciente(Dados, Situacao)).

% EXCLUIR PACIENTE
excluir_paciente(Nome) :-
    paciente(Dados, _),
    member(Nome, Dados) -> retract(paciente(Dados, _)) ;
    write('Paciente não encontrado!'), nl.


% Diagnostico


contar([], 0).
contar([_|T], X) :- 
    contar(T, X2),
    X is X2 + 1.

total_lista([], 0).
total_lista([H|T], X) :- 
    total_lista(T, X2),
    X is X2 + H.

lista_nomes(Nomes) :- findall(Nome, paciente([Nome | _], _), Nomes).

lista_sexos(Sexos, ComDiabete, Sexualidade) :- 
    findall(Sexualidade, paciente([_ ,Sexualidade |_], _), Sexos),
    findall(Sexualidade, paciente([_ ,Sexualidade |_], sim), ComDiabete).
    
lista_idade(IdadeSem, IdadesCom) :- 
    findall(IdadeS, paciente([_,_,IdadeS|_], nao), IdadeSem),
    findall(IdadeC, paciente([_,_,IdadeC|_], sim), IdadesCom).

lista_hipertensao(Hipertensos, Hipertensos_Com, SITUACAO) :- 
    findall(SITUACAO, paciente([_, _, _, SITUACAO|_], _), Hipertensos),
    findall(SITUACAO, paciente([_, _, _, SITUACAO|_], sim), Hipertensos_Com).

lista_cardio(Cardiacos, Cardiacos_Com, SITUACAO) :-
    findall(SITUACAO, paciente([_, _, _, _, SITUACAO|_], _), Cardiacos),
    findall(SITUACAO, paciente([_, _, _, _, SITUACAO|_], sim), Cardiacos_Com).

lista_fumante(Fumantes, Fumantes_Com, SITUACAO) :- 
    findall(SITUACAO, paciente([_, _, _, _, _, SITUACAO|_], _), Fumantes),
    findall(SITUACAO, paciente([_, _, _, _, _, SITUACAO|_], sim), Fumantes_Com).

lista_imc(IMC_SEM, IMC_COM) :- 
    findall(IMC, paciente([_, _, _, _, _, _, IMC|_], nao), IMC_SEM),
    findall(IMC, paciente([_, _, _, _, _, _, IMC|_], sim), IMC_COM).

lista_hemoglobina(HEMO_sem, HEMO_com) :- 
    findall(Hemo, paciente([_, _, _, _, _, _, _, Hemo|_], nao), HEMO_sem), 
    findall(Hemo, paciente([_, _, _, _, _, _, _, Hemo|_], sim), HEMO_com).

lista_glicose(GLICOSES_sem, GLICOSES_com) :- 
    findall(Glicose, paciente([_, _, _, _, _, _, _, _, Glicose| _], nao), GLICOSES_sem),
    findall(Glicose, paciente([_, _, _, _, _, _, _, _, Glicose| _], sim), GLICOSES_com).



% CALCULAR A PROBABILIDADE DE OCORRENCIAS


% Com base na porcentagem, será calculada a probilidade da caracteristica diagnosticar diabete
dar_valor(Porcentagem, Probabilidade) :- 
    (
        Porcentagem >= 75 -> Probabilidade = 3
        ;
        Porcentagem >= 50 -> Probabilidade = 2
        ;
        Porcentagem >= 25 -> Probabilidade = 1
        ; 
        Probabilidade = 0
    ).

contar_ocorrencias([], _, 0).
contar_ocorrencias([Head|Tail], Element, Count) :-
    contar_ocorrencias(Tail, Element, TailCount),
    (Head = Element -> Count is TailCount + 1 ; Count = TailCount).


sexo_calcular(Probabilidade, Tipo) :- 
    lista_sexos(SEXO_sem, SEXO_com, Tipo), 
    contar(SEXO_sem, Todos),
    contar(SEXO_com, Filtrado),

    Media is (Filtrado * 100) / Todos,

    dar_valor(Media, Probabilidade).


idade_calcular(Probabilidade, IDADE_paciente) :-
    lista_idade(IDADE_sem, IDADE_com),
    contar(IDADE_sem, Q_sem),
    contar(IDADE_com, Q_com),
    total_lista(IDADE_sem, Valor_sem),
    total_lista(IDADE_com, Valor_com),
    
    Media_sem is Valor_sem / Q_sem,
    Media_com is Valor_com / Q_com,

    Margem is (Media_com * 10) / 100,

    (
      (IDADE_paciente >= Media_com -> Probabilidade = 3)
      ;
      (IDADE_paciente >= (Media_com - Margem) -> Probabilidade = 2)
      ;
      (IDADE_paciente >= Media_sem -> Probabilidade = 1)
      ;
      Probabilidade = 0
    ).

hipertensao_calcular(Probabilidade, Situacao) :-
    lista_hipertensao(LISTA_todos, LISTA_com_diabete, Situacao),
    contar(LISTA_todos, Todos),
    contar(LISTA_com_diabete, Filtrado),

    Media is (Filtrado * 100) / Todos,

    dar_valor(Media, Probabilidade).



cardiaco_calcular(Probabilidade, Situacao) :-
    lista_cardio(LISTA_todos, LISTA_com_diabete, Situacao),
    contar(LISTA_todos, Todos),
    contar(LISTA_com_diabete, Filtrado),

    Media is (Filtrado * 100) / Todos,

    dar_valor(Media, Probabilidade).


fumante_calcular(Probabilidade, Situacao) :-
    lista_fumante(LISTA_todos, LISTA_com_diabete, Situacao),
    contar(LISTA_todos, Todos),
    contar(LISTA_com_diabete, Filtrado),

    Media is (Filtrado * 100) / Todos,

    dar_valor(Media, Probabilidade).


imc_calcular(Probabilidade, IMC_paciente) :-
    lista_imc(IMC_sem, IMC_com),
    contar(IMC_sem, Q_sem),
    contar(IMC_com, Q_com),
    total_lista(IMC_sem, VALOR_sem),
    total_lista(IMC_com, VALOR_com),
    
    MEDIA_sem is VALOR_sem / Q_sem,
    MEDIA_com is VALOR_com / Q_com, 

    Margem is (MEDIA_com * 10) / 100,

    (
      (IMC_paciente >= MEDIA_com -> Probabilidade = 4)
      ;
      (IMC_paciente >= (MEDIA_com - Margem) -> Probabilidade = 2)
      ;
      (IMC_paciente >= MEDIA_sem -> Probabilidade = 1)
      ;
      Probabilidade = 0
    ).


hemoglobina_calcular(Probabilidade, HEMOGLOBINA_paciente) :-
    lista_hemoglobina(HEMO_sem, HEMO_com),
    contar(HEMO_sem, Q_sem),
    contar(HEMO_com, Q_com),
    total_lista(HEMO_sem, VALOR_sem),
    total_lista(HEMO_com, VALOR_com),
    
    MEDIA_sem is VALOR_sem / Q_sem,
    MEDIA_com is VALOR_com / Q_com, 

    Margem is (MEDIA_com * 20) / 100,

    (
      HEMOGLOBINA_paciente >= MEDIA_com -> Probabilidade = 5
      ;
      HEMOGLOBINA_paciente >= (MEDIA_com - Margem) -> Probabilidade = 3
      ;
      HEMOGLOBINA_paciente >= MEDIA_sem -> Probabilidade = 1
      ;
      Probabilidade = 0
    ).


glicose_calcular(Probabilidade, GLICOSE_paciente) :-
    lista_glicose(GLIC_sem, GLIC_com),
    contar(GLIC_sem, Q_sem),
    contar(GLIC_com, Q_com),
    total_lista(GLIC_sem, VALOR_sem),
    total_lista(GLIC_com, VALOR_com),
    
    MEDIA_sem is VALOR_sem / Q_sem,
    MEDIA_com is VALOR_com / Q_com, 

    Margem is (MEDIA_com * 10) / 100,

    (
      GLICOSE_paciente >= MEDIA_com -> Probabilidade = 5
      ;
      GLICOSE_paciente >= (MEDIA_com - Margem) -> Probabilidade = 3
      ;
      GLICOSE_paciente >= (MEDIA_sem + Margem) -> Probabilidade = 1
      ;
      Probabilidade = 0
    ).


calcular_(Sexo, Idade, Hipertensao, Cardio, Fumante, IMC, Hemoglobina, Glicose, PROBABILIDADE) :-
    sexo_calcular(P1, Sexo),
    idade_calcular(P2, Idade),
    hipertensao_calcular(P3, Hipertensao),
    cardiaco_calcular(P4, Cardio),
    fumante_calcular(P5, Fumante),
    imc_calcular(P6, IMC),
    hemoglobina_calcular(P7, Hemoglobina),
    glicose_calcular(P8, Glicose),
    
    PROBABILIDADE is (P1 + P2 + P3 + P4 + P5 + P6 + P7 + P8).

error(Mensagem) :-
    nl, write(Mensagem), nl.

% Retorna verdadeiro se a variavel conter numero
contem_numero(String) :-
    string_chars(String, Chars),    
    member(Char, Chars),             
    char_type(Char, digit) -> !.    


valida_nome(Nome, Novo_Nome) :-
    (   
        var(Nome) -> (error('|Apenas caracteres minusculos|'), 
            receber_dados('-> ', Temp), valida_nome(Temp, Novo_Nome))
        ; 
        contem_numero(Nome) -> (error('|Contem número, apenas caracteres|'),
            receber_dados('-> ', Temp), valida_nome(Temp, Novo_Nome))
        ; 
        Novo_Nome = Nome
    ).


aux_ValidaString(String, Validos) :-
    (
        (contem_numero(String) -> ( error('|Contem número, apenas caracteres|')))
        ;
        \+ member(String, Validos) -> ( write('|Resposta não é valida! Valido somente '), 
            write(Validos), write('|'), nl)
    ).

valida_string(String, Validos) :-
    (   
        var(String) -> ( error('|É permitido apenas caracteres minusculos|'), fail)
        ; 
        aux_ValidaString(String, Validos) -> fail
        ;
        true
    ).

valida_numero(Num, [Min, Max]) :-
    (
        \+ number(Num) -> ( error('|Apenas números pode ser aceitos|'), fail)
        ;
        ( Num > Max -> ( error('|Número está acima do permitido|')), fail)
        ;
        ( Num < Min -> ( error('|Número está abaixo do permitido|')), fail)
        ;
        true
    ).

receber_dados(Mensagem, Dado) :- nl,
    write(Mensagem),
    read(Dado), nl.


valida_entrada(FALSA_variavel, Retorno, Limites, Mensagem) :-
    \+ valida_string(FALSA_variavel, Limites) -> ( receber_dados(Mensagem, Temp), 
        valida_entrada(Temp, Retorno, Limites, Mensagem) ) ; Retorno = FALSA_variavel.

entrada_valida(FALSA_entrada, Retorno, Limites, Mensagem) :- 
    \+ valida_numero(FALSA_entrada, Limites) -> ( receber_dados(Mensagem, Temp),
        entrada_valida(Temp, Retorno, Limites, Mensagem) ) ; Retorno = FALSA_entrada.

calcular_probabilidade([_, Sexo, Idade, Hipertensao, Cardio, Fumante, IMC, Hemoglobina, Glicose], Probabilidade) :-
    sexo_calcular(P1, Sexo),
    idade_calcular(P2, Idade),
    hipertensao_calcular(P3, Hipertensao),
    cardiaco_calcular(P4, Cardio),
    fumante_calcular(P5, Fumante),
    imc_calcular(P6, IMC),
    hemoglobina_calcular(P7, Hemoglobina),
    glicose_calcular(P8, Glicose),

    Probabilidade is (P1 + P2 + P3 + P4 + P5 + P6 + P7 + P8).
    
   
calcular_probabilidade_pacientes :-
    paciente(Caracteristicas, _), 
    calcular_probabilidade(Caracteristicas, Probabilidade), 
    write('Probabilidade para '), write(Caracteristicas), write(': '), write(Probabilidade), nl, 
    fail.

armazenar_probabilidades(Lista_sim, Lista_nao) :-
    findall(Prob, (paciente(Caracteristicas, sim), calcular_probabilidade(Caracteristicas, Prob)), Lista_sim),
    findall(Prob, (paciente(Caracteristicas, nao), calcular_probabilidade(Caracteristicas, Prob)), Lista_nao),
    writeln(Lista_nao),
    writeln(Lista_sim).

media_probabilidades(MEDIA_sim, MEDIA_nao, S_margem, N_margem) :-
    armazenar_probabilidades(L_sim, L_nao),
    contar(L_sim, QUANTIDADE_sim),
    contar(L_nao, QUANTIDADE_nao),
    total_lista(L_sim, SOMA_sim),
    total_lista(L_nao, SOMA_nao),
    
    MEDIA_sim is SOMA_sim / QUANTIDADE_sim,
    MEDIA_nao is SOMA_nao / QUANTIDADE_nao,

    S_margem is (MEDIA_sim * 25) / 100,
    N_margem is (MEDIA_nao * 25) / 100.


diagnosticar_diabetes([N_, S_, I_, H_, C_, F_, IMC_, HEMO_, G_], Diabete) :- 
    ( valida_nome(N_, Nome) ),
    ( valida_entrada(S_, Sexo, [masculino, feminino], 'Sexo do paciente -> ') ),
    ( entrada_valida(I_, Idade, [1, 120], 'Idade do paciente -> ') ),
    ( valida_entrada(H_, Hipertensao, [sim, nao], 'O paciente possui hipertensão -> ') ),
    ( valida_entrada(C_, Cardio, [sim, nao] , 'O paciente é cardiaco -> ') ),
    ( valida_entrada(F_, Fumante, [sim, passado, nunca], 'O paciente é fumante -> ') ),
    ( var(IMC_) -> (receber_dados('Seu peso -> ', Peso),
        receber_dados('Sua altura -> ', Altura)),
        calcular_IMC(Peso, Altura, IMC) ; IMC = IMC_ ),
    ( entrada_valida(HEMO_, Hemoglobina, [0.0, 10.0], 'Hemoglobina do paciente -> ') ),
    ( entrada_valida(G_, Glicose, [70, 600], 'Glicose do Paciente -> ') ),

    calcular_(Sexo, Idade, Hipertensao, Cardio, Fumante, IMC, Hemoglobina, Glicose, PROBABILIDADE),
    media_probabilidades(MEDIA_sim, MEDIA_nao, S_margem, N_margem),

    (
        PROBABILIDADE >= MEDIA_sim -> nl,
            ( write('O diagnostico é conclusivo e o paciente possui diabetes'), Diabete = sim )
        ;
        PROBABILIDADE >= (MEDIA_sim - S_margem) -> nl,
            ( write('Paciente tem chances altas de possuir diabetes'), Diabete = sim )
        ;
        PROBABILIDADE =< MEDIA_nao -> nl,
            ( write('O diagnostico é conclusivo e o paciente não possui diabetes'), Diabete = nao ) 
        ;
        PROBABILIDADE =< (MEDIA_nao + N_margem) -> nl,
            ( write('Paciente tem baixas chances de possuir diabetes'), Diabete = nao ) 
        ;
        nl, write('O resultado é inconclusivo, o paciente necessita realizar novos exames'),
        Diabete = inconclusivo
    ), nl,
    
    write(Nome),
    write(' Probilidade = '), writeln(PROBABILIDADE),
    write('Media_sim = '), writeln(MEDIA_sim),
    write('Media_nao = '), writeln(MEDIA_nao).

    % write('Paciente deve ser adicionado a base de dados (sim/nao) -> '), read(Temp),
    %     valida_entrada(Temp, Retorno, [sim, nao], 'Resposta -> '),

    % Retorno = sim -> adicionar_paciente([Nome, Sexo, Idade, Hipertensao, Cardio, Fumante, IMC, Hemoglobina, Glicose], Diabete) ; !.

editar_paciente(Nome, [S_, I_, H_, C_, F_, IMC_, HEMO_, G_], D_) :- 
  
    paciente([Nome | _], _) ->
        
        paciente([Nome, Sexo_original, Idade_original, Hipertensao_original, Cardio_original, Fumante_original, IMC_original, Hemoglobina_original, Glicose_original], Diabete_original ),
       
        (var(S_) -> Sexo  = Sexo_original ; 
            valida_entrada(S_, Sexo, [masculino, feminino], 'Sexo do paciente -> ') ),
        (var(I_) -> Idade = Idade_original ; 
            entrada_valida(I_, Idade, [1, 120], 'Idade do paciente -> ') ),
        (var(H_) -> Hipertensao = Hipertensao_original ; 
            valida_entrada(H_, Hipertensao, [sim, nao], 'O paciente possui hipertensão -> ') ),
        (var(C_) -> Cardio = Cardio_original ; 
            valida_entrada(C_, Cardio, [sim, nao] , 'O paciente é cardiaco -> ') ),
        (var(F_) -> Fumante = Fumante_original ; 
            valida_entrada(F_, Fumante, [sim, passado, nunca], 'O paciente é fumante -> ') ),
        (var(IMC_) -> IMC = IMC_original; IMC = IMC_),
        (var(HEMO_) -> Hemoglobina = Hemoglobina_original ; 
            entrada_valida(HEMO_, Hemoglobina, [0.0, 10.0], 'Hemoglobina do paciente -> ') ),
        (var(G_) -> Glicose = Glicose_original ; 
            entrada_valida(G_, Glicose, [70, 600], 'Glicose do Paciente -> ') ),
        (var(D_) ->  Diabete = Diabete_original ; 
            valida_entrada(D_, Diabete, [sim, nao], 'Possui diabete -> ')),
        
        excluir_paciente(Nome),
        
        adicionar_paciente([Nome, Sexo, Idade, Hipertensao, Cardio, Fumante, IMC, Hemoglobina, Glicose], Diabete) , !
    ; 
    writeln('Nome não encontrado na base de dados.').