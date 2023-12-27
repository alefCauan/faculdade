'''class Dog:
    def __init__(self, name):
        self.name = name
        print(name)
    def add_one(self,x):
        return x + 1
d = Dog('Alef')
d2 = Dog('Sousa')'''

'''class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.age
    
    def set_age(self, age):
        self.age = age # pode sobrescrever
        
d = Dog('Alef',45)
print(d.get_age())
d.set_age(12)
print(d.get_age())'''

'''class Student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade
    def get_grade(self):
        return self.grade

class Course:
    def __init__(self, name, max_students):
        self.name = name
        self.max_students = max_students
        self.students = [] # Cria uma lista para os estudantes, virão da classe 'Student'

    def add_students(self, student):
        if len(self.students) < self.max_students:
            self.students.append(student) # add os estudantes na lista ^
            return  True
        return False
    def get_average(self):
        value = 0
        for student in self.students:
            value += student.get_grade()
        return value / len(self.students)
    
s1 = Student('Alef',19, 95)
s2 = Student('Sousa',18,100)
s3 = Student('Cauam',18,45)

course = Course('Spanish',2)
course.add_students(s3)
course.add_students(s2)
print(course.add_students(s3)) # False, não será adicionado.
#print(course.students[0].name)
print(course.get_average())'''

'''#Classes semelhantes, 'herança'
class Pet:
    def __init__(self,name, age):
        self.name = name
        self.age = age

    def show(self):
        if self.age > 1:
            print(f'Meu nome é {self.name} e tenho {self.age} anos de idade.')
        else:
            print(f'Meu nome é {self.name} e tenho {self.age} ano de idade.')

    def speak(self):
        print('Não sei falar nada')
class Cat(Pet): # HERDA OS COMANDOS DA CLASSE DE CIMA, REDUZINDO COMANDOS PARECIDOS
    def speak(self): # Metodos iguais das 'crianças' sobrescrevem os dos 'pais'
        print('Meow')

class Dog(Pet):
    def __init__(self,name, age, color):
        super().__init__(name,age)
        self.color = color
        print(f'Meu nome é {self.name} tenho {self.age} anos de idade e minha cor é {self.color}.')

    def speak(self):
        print('Uau')

class Fish(Pet):
    pass

p = Pet('Zinho', 1)
p.show()

c = Cat('Tinho', 2)
c.show()

d = Dog('Jill', 12, 'brown')
d.show()
d.speak()

f = Fish('bolha',3)
f.speak()'''

'''class Person:
    number_of_people = 0

    def __init__(self,name):
        self.name = name
        Person.add_person()

    @classmethod
    def NumberOf_People(cls):
        return cls.number_of_people

    @classmethod
    def add_person(cls):
        cls.number_of_people += 1

p1 = Person('Cauam')
p2 = Person('Sousa')
print(Person.NumberOf_People())'''






