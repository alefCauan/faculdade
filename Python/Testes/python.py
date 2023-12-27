import os
import random
import turtle
import time 

delay = 0.5

# CRIANDO A JANELA PRICNIPAL
janela = turtle.Screen()
janela.title("Jogo da Cobra")
janela.bgcolor("white");
janela.setup(width=600, height=600)
janela.tracer(0) # deliga as atualizações de tela
janela.mainloop()

# CABEÇA DA COBRA 

head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("green")
head.penup()
head.goto(0, 0)
head.direction = "stop"


# funções

def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)











# loop principal

while True: 
    janela.update()

    move()

    time.sleep(delay)
    janela.mainloop()


