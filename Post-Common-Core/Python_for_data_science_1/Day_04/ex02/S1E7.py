from S1E9 import Character

class Baratheon(Character):
    def __init__(self, first_name, is_alive=True, family_name="Baratheon", 
                    eyes="brown", hair="dark"):
        super().__init__(first_name, is_alive)
        self.family_name = family_name
        self.eyes = eyes
        self.hair = hair

    def __str__(self):
        return f"{self.family_name}, {self.eyes}, {self.hair}"

    def __repr__(self):
        return f"{self.__class__.__name__}: ('{self.family_name}', '{self.eyes}', '{self.hair}')"

    def die(self) :
        if not self.is_alive:
            print(f"{self.first_name} already dead")
        else:
            self.is_alive = False

    @classmethod
    def create_baratheon(cls, name, is_alive):
        baratheon = cls(name, is_alive)
        return baratheon
    
    
    @classmethod
    def create_baratheon_chain(cls, number):
        if not number or number < 0:
            raise Exception("The number of new Baratheon is wrong")
        tab = []
        for i in range(number):
            name = input(str("What is the new Baratheon name?"))
            toggle = True
            while toggle:
                if not name.isalnum():
                    name= input(str("Wrong name, try again: "))
                else:
                    toggle = False
            tab.append(cls(name))
        return tab


class Lannister(Character):
    def __init__(self, first_name, family_name="Lannister", 
                    eyes="blue", hair="light", is_alive=True):
        super().__init__(first_name, is_alive)
        self.family_name = family_name
        self.eyes = eyes
        self.hair = hair

    def __str__(self):
        return f"{self.family_name}, {self.eyes}, {self.hair}"

    def __repr__(self):
        return f"{self.__class__.__name__}: ('{self.family_name}', '{self.eyes}', '{self.hair}')"
    

    def die(self) :
        if not self.is_alive:
            print(f"{self.first_name} already dead")
        else:
            self.is_alive = False

    @classmethod
    def create_lannister(cls, name, is_alive):
        lannister = cls(name, is_alive)
        return lannister

    @classmethod
    def create_lannister_chain(cls, number):
   f     if not number or number < 0:
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
            tab.append(cls(name))
        return tab