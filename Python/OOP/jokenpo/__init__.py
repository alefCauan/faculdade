'''from FuncionaldiadesA.utilidades import *
from random import randint

while True:
    menu('JO - KEN - PO')
    lin_()
    cpu = randint(1, 3)
    lista = ['Papel','Pedra','Tesoura']
    player = escolha(lista)

    while True:
        if player in (1, 2, 3):
            break
        else:
            player = leiaint(cor('Escolha uma opção valida: ','red'))
            if player in (1,2,3):
                break
            else:
                continue

    lin_()
    if cpu == player:
         resul = ('Temos um empate.')
    elif cpu == 1 and player == 2 or cpu == 2 and player == 3 or cpu == 3 and player == 1:
        resul = ('Derrota, tente novamente')
    else:
        resul = ('Vitória sobre as máquinas.')

    player = lista[player-1]
    cpu = lista[cpu-1]

    print(f'O jogador escolheu {sublinhar(player)}.')
    print(f'A maquina escolheu {sublinhar(cpu)}.')
    print(resul)
    lin_()'''