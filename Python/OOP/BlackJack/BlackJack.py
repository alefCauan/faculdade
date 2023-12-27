import random

class Card:
    def __init__(self, valor, tipo):
        self.tipo = tipo
        self.valor = valor

class Deck:
    def __init__(self):
        tipos = ["Ouro", "Copas", "Espada", "Paus"]
        valores = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Ás", "Dama", "Rei"]
        self.cards = [Card(valor, tipo) for tipo in tipos for valor in valores]
        random.shuffle(self.cards)

class Player:
    def __init__(self, nome):
        self.nome = nome
        self.mão = []

    def desenhar(self, deck, num_cards=1):
        for _ in range(num_cards):
            card = deck.cards.pop()
            self.mão.append(card)

    def pegar_carta(self, deck):
        resposta = input("Pegar mais uma carta? (s/n): ").lower()

        if resposta == "s":
            card = deck.cards.pop()
            self.mão.append(card)

    def calcular_pontuação(self):
        score = 0
        num_aces = 0

        for card in self.mão:
            if card.valor in ['Valet', 'Dama', 'Rei']:
                score += 10
            elif card.valor == 'Ás':
                score += 11
                num_aces += 1
            else:
                score += int(card.valor)

        while score > 21 and num_aces > 0:
            score -= 10
            num_aces -= 1

        return score

class Dealer:
    def __init__(self):
        self.hand = []

    
    def desenho(self, deck, num_cards=1):
        for _ in range(num_cards):
            card = deck.cards.pop()
            self.hand.append(card)


    def calcular_pontuação(self):
        score = 0
        num_aces = 0

        for card in self.hand:
            if card.valor in ['Valet', 'Dama', 'Rei']:
                score += 10
            elif card.valor == 'Ás':
                score += 11
                num_aces += 1
            else:
                score += int(card.valor)

        while score > 21 and num_aces > 0:
            score -= 10
            num_aces -= 1

        return score

class Game:
    def __init__(self):
        self.deck = Deck()
        self.player = Player('Jogador')
        self.dealer = Dealer()

    def play(self):
        self.player.desenhar(self.deck, 2)
        self.dealer.desenho(self.deck, 2)


        while True:
            print(f'\nMão do Jogador ({self.player.calcular_pontuação()}): {", ".join([card.valor for card in self.player.mão])}')
            print(f'Mão do Dealer ({self.dealer.calcular_pontuação()}): {", ".join([card.valor for card in self.dealer.hand])}')

            if self.player.calcular_pontuação() == 21:
                print("Blackjack! Jogador vence.")
                break

            if self.player.calcular_pontuação() > 21:
                print("Jogador estourou! Dealer vence.")
                break

            escolha = input("Pegar mais uma carta? (s/n): ").lower()
            if escolha == 's':
                self.player.pegar_carta(self.deck)
            else:
                while self.dealer.calcular_pontuação() < 17:
                    self.dealer.desenho(self.deck, 1)

                print(f'Mão final do Dealer: {", ".join([card.valor for card in self.dealer.hand])}')
 
                if self.dealer.calcular_pontuação() > 21:
                    print("Dealer estourou! Jogador vence.")
                elif self.player.calcular_pontuação() > self.dealer.calcular_pontuação():
                    print("Jogador vence!")
                elif self.player.calcular_pontuação() < self.dealer.calcular_pontuação():
                    print("Dealer vence.")
                else:
                    print("Empate!")

                break

if __name__ == "__main__":
    jogo = Game()
    jogo.play()
