class Item:
    def __init__(self, name: str, price: float, quantity=0):
        assert price >= 0, f"Price {price} is not greater than or equal to zero!"
        assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"
        self.name = name
        self.price = price
        self.quantity = quantity

    def calculate_total(self):
        return  self.price * self.quantity

a1 = Item('Laptop', -2999, 23)

'''class Item:
    pay_rate = 0.8
    def __init__(self, name: str, price: float, quantity=0):
        assert price >= 0, f"Price {price} is not greater than or equal to zero!"
        assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"
        self.name = name
        self.price = price
        self.quantity = quantity

    def calculate_total(self):
        return  self.price * self.quantity

    def discount(self):
        self.price = self.price * self.pay_rate


a1 = Item('Laptop', 2999, 23)
a1.discount()
print(a1.price)

a2 = Item('Phone',1200,12)
a2.pay_rate = 0.5
a2.discount()
print(a2.price)

#print(Item.csv.__dict__) # All the attibutes for Class level
#print(a1.__dict__) # All the attibutes for Instace level'''

'''
import csv
class Item:
    pay_rate = 0.8
    all = []

    def __init__(self, name: str, price: float, quantity=0):
        assert price >= 0, f"Price {price} is not greater than or equal to zero!"
        assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"
        # Designar para o propio objeto
        self.name = name
        self.price = price
        self.quantity = quantity

        # Actions to execute
        Item.all.append(self)

    def calculate_total(self):
        return  self.price * self.quantity

    def discount(self):
        self.price = self.price * self.pay_rate

    @classmethod
    def instantiete_from_csv(csl):
        with open('items.csv','r') as f:
            reader = csv.DictReader(f)
            items = list(reader)

        for item in items:
            Item(
                name = item.get('name'),
                price = float(item.get('price')),
                quantity = int(item.get('quantity')),
            )

    @staticmethod
    def is_integer(num):
        if isinstance(num, float):
            # Conta as flotilhas 'ponto zero' como inteiras
            return num.is_integer()
        elif isinstance(num, int):
            return True
        else:
            return False

    def  __repr__(self):
        return f"Item.csv('{self.name}, R${self.price}, {self.quantity}')"

Item.instantiete_from_csv()
print(Item.all)
print(Item.is_integer(7.0))'''

'''#When use Classmethod and when use static methods?
class item:

    @staticmethod
    def is_integer():
        
        #This should do something that has a relationship
       # with the class, but not something that must be unique per instance
        

    @classmethod
    def instantieate_from_something(cls):
        
       # O mesmo acima,but usually, those are used to manipulate
        #different structures of data to instantiente objects, like csv
        '''
'''
# Herança
import csv
class Item:
    pay_rate = 0.8
    all = []

    def __init__(self, name: str, price: float, quantity=0):
        assert price >= 0, f"Price {price} is not greater than or equal to zero!"
        assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"
        # Designar para o propio objeto
        self.name = name
        self.price = price
        self.quantity = quantity

        # Actions to execute
        Item.all.append(self)

    def calculate_total(self):
        return  self.price * self.quantity

    def discount(self):
        self.price = self.price * self.pay_rate

    @classmethod
    def instantiete_from_csv(csl):
        with open('items.csv','r') as f:
            reader = csv.DictReader(f)
            items = list(reader)

        for item in items:
            Item(
                name = item.get('name'),
                price = float(item.get('price')),
                quantity = int(item.get('quantity')),
            )

    @staticmethod
    def is_integer(num):
        if isinstance(num, float):
            # Conta as flotilhas 'ponto zero' como inteiras
            return num.is_integer()
        elif isinstance(num, int):
            return True
        else:
            return False

    def  __repr__(self):
        return f"{self.__class__.__name__}, R${self.price}, {self.quantity})"

class Phone(Item): # Herda as funçoes de Item
    def __init__(self, name: str, price: float, quantity=0, broken_phones = 0):
        super().__init__(
            name, price, quantity
        )
        assert broken_phones >= 0, f"Broken phones {broken_phones} is not greater or equal to zero!"
        self.broken_phones = broken_phones'''



