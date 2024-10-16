from S1E9 import Character


class Baratheon(Character):
    '''Class Baratheon. Inherite from abstract class 'Character'.\
Define a character with Baratheon family name and with Baratheon caraceristics\
: brown eyes, dark hairs'''
    def __init__(self, first_name, is_alive=True, family_name="Baratheon",
                 eyes="brown", hairs="dark"):
        '''Constructor of Baratheon class. Use the super() method to\
 use the constructor from Character to initialise 'first_name' and 'is_alive'\
. In a next step, it initialise its own attribute: 'family_name,\
 eyes and hairs'''
        super().__init__(first_name, is_alive)
        self.family_name = family_name
        self.eyes = eyes
        self.hairs = hairs

    def __str__(self):
        '''__str__ Baratheon class method: give information of the current\
object: its family name, eyes color and hairs color'''
        return f"{self.family_name}, {self.eyes}, {self.hairs}"

    def __repr__(self):
        '''__repr__ Baratheon class method: give representation on=f the\
 current object: classe name, its family name, eyes color and hairs color'''
        return f"{self.__class__.__name__}: ({self.family_name!r},\
 {self.eyes!r}, {self.hairs!r})"

    def die(self):
        '''"Die" method that change "is_alive" attribute to False if it's
True. Print a error message otherwise'''
        if not self.is_alive:
            print(f"{self.first_name} already dead")
        else:
            self.is_alive = False

    @classmethod
    def create_baratheon(cls, name, is_alive):
        '''A Baratheon class method that create a new Baratheon'''
        baratheon = cls(name, is_alive)
        return baratheon

    @classmethod
    def create_baratheon_chain(cls, number):
        '''A Baratheon class method that create 'x' new Baratheon, define by\
 the parameter number. The user has to give name on a input and it\
 automaticaly set a new Baratheon with that new name if it's valid'''
        if not number or number < 0:
            raise ValueError("The number of new Baratheon is wrong")
        tab = []
        for i in range(number):
            name = input(str("What is the new Baratheon name? "))
            while any(baratheon.first_name == name for baratheon in tab):
                name = input(str(f"{name} already exist, give another one: "))
            while not name.isalpha():
                name = input(str("Wrong name, try again: "))
            tab.append(cls(name))
        return tab


class Lannister(Character):
    '''Class Lannister. Inherite from abstract class 'Character'.\
Define a character with Lannister family name and with Lannister caraceristics\
: blue eyes, light hairs'''

    def __init__(self, first_name, is_alive=True, family_name="Lannister",
                 eyes="blue", hairs="light"):
        '''Constructor of Lannister class. Use the super() method to\
 use the constructor from Character to initialise 'first_name' and 'is_alive'\
. In a next step, it initialise its own attribute: 'family_name,\
 eyes and hairs'''
        super().__init__(first_name, is_alive)
        self.family_name = family_name
        self.eyes = eyes
        self.hairs = hairs

    def __str__(self):
        '''__str__ Lannister class method: give information of the current\
object: its family name, eyes color and hairs color'''
        return f"{self.family_name}, {self.eyes}, {self.hairs}"

    def __repr__(self):
        '''__repr__ Lannister class method: give representation on=f the\
 current object: classe name, its family name, eyes color and hairs color'''
        return f"{self.__class__.__name__}: ({self.family_name!r},\
 {self.eyes!r}, {self.hairs!r})"

    def die(self):
        '''"Die" method that change "is_alive" attribute to False if it's
True. Print a error message otherwise'''
        if not self.is_alive:
            print(f"{self.first_name} already dead")
        else:
            self.is_alive = False

    @classmethod
    def create_lannister(cls, name, is_alive):
        '''A Lannister class method that create a new Lannister'''
        lannister = cls(name, is_alive)
        return lannister

    @classmethod
    def create_lannister_chain(cls, number):
        '''A Lannister class method that create 'x' new Lannister, define by\
 the parameter number. The user has to give name on a input and it\
 automaticaly set a new Lannister with that new name if it's valid'''
        if not number or number < 0:
            raise ValueError("The number of new Lannister is wrong")
        tab = []
        for i in range(number):
            name = input(str("What is the new Lannister name? "))
            while any(lannister.first_name == name for lannister in tab):
                name = input(str(f"{name} already exist, give another one: "))
            while not name.isalpha():
                name = input(str("Wrong name, try again: "))
            tab.append(cls(name))
        return tab
