from S1E7 import Baratheon, Lannister

class King(Baratheon, Lannister):
    def __init__(self, first_name, is_alive=True,
                    family_name="Baratheon", eyes="brown", hair="dark"):
        super().__init__(first_name, is_alive, family_name, eyes, hair)


    def set_eyes(self, color):
        colors = ["blue", "green", "brown", "black", "purple", "red", "pink"
            "white", "orange", "yellow"]
        if color in colors:
            self.eyes = color
        else:
            print(f"I'm not sure if {color} is a color")


    def set_hairs(self, color):
        colors = ["blonde", "ginger", "light", "dark", "black", "blue", "green"
            , "purple", "pink", "lavender", "teal", "violet"]
        if color in colors:
            self.hair = color
        else:
            print(f"I'm not sure if {color} is a hair color")


    def get_eyes(self):
        return self.eyes


    def get_hair(self):
        return self.hair
    
    @classmethod
    def create_lannister(cls, name, is_alive):
        return Lannister(name, is_alive)
    
    @classmethod
    def create_lannister_chain(cls, number):
        if not number or number < 0:
            raise Exception("The number of new Lannister is wrong")
        tab = []
        for i in range(number):
            name = input(str("What is the new Lannister name?"))
            toggle = True
            while toggle:
                if not name.isalnum():
                    name= input(str("Wrong name, try again: "))
                else:
                    toggle = False
            tab.append(Lannister(name))
        return tab