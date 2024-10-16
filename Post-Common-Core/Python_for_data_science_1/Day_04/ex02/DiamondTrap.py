from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    def __init__(self, first_name, is_alive=True, family_name="Baratheon",
                 eyes="brown", hair="dark"):
        super().__init__(first_name, is_alive, family_name, eyes, hair)

    def set_eyes(self, color):
        '''Change the eyes color of the King'''
        colors = ["blue", "green", "brown", "black", "purple", "red", "pink",
                  "white", "orange", "yellow"]
        if color in colors:
            self.eyes = color
        else:
            print(f"I'm not sure if {color} is a color")

    def set_hairs(self, color):
        '''Change the hairs color of the King'''
        colors = ["blonde", "ginger", "light", "dark", "black", "blue",
                  "green", "purple", "pink", "lavender", "teal", "violet"]
        if color in colors:
            self.hair = color
        else:
            print(f"I'm not sure if {color} is a hair color")

    def get_eyes(self):
        '''Return the eyes color of the King'''
        return self.eyes

    def get_hair(self):
        '''Return the hairs color of the King'''
        return self.hair

    @classmethod
    def create_lannister(cls, name, is_alive):
        '''A King class method that create a new Lannister'''
        return Lannister(name, is_alive)

    @classmethod
    def create_lannister_chain(cls, number):
        '''A King class method that create 'x' new Lannister, define by\
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
