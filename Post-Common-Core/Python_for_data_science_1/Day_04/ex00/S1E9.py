from abc import ABC, abstractmethod


class Character(ABC):
    '''Abstact class character. Gives a basis to create character. Character\
class has 2 attibute (first_name, is_alive) and 1 method (die)'''

    def __init__(self, first_name, is_alive=True):
        '''Constructor of abstract class character. Initialize attribute'''
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        '''Abstract method "die". Does nothing in that context of abstract\
class'''
        pass


class Stark(Character):
    '''Class Stark that inherited from Character abstaract class.\
 Stark class has 2 attibute (first_name, is_alive) and 1 method (die)'''

    def __init__(self, first_name, is_alive=True):
        '''Constructor of class Stark. Initialize attribute with super()\
 method: use the __init__ of Character class'''
        super().__init__(first_name, is_alive)

    def die(self):
        '''"Die" method that change "is_alive" attribute to False if it's\
 True. Print a error message otherwise: people can't die 2 times'''
        if self.is_alive:
            self.is_alive = False
        else:
            print(f"Character {self.first_name} is already dead")
