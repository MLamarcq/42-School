from dataclasses import dataclass, field
import random
import string


def generate_id():
    '''Generate a random id'''
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    '''Class Student that is define and fill by the dataclass.
        It instanciate Student that have:
        - A name: define by dataclass at the instanciation
        - A surname: define by dataclass at the instanciation
        - A status: define by default to True
        - A login: define in the __post_init__ method
        - An id: define in the __post_init__ method

        The __post_init__ is used to initialize attribute that need to be\
configured by the programmer and not by the dataclass: the field(init=False)\
idicate to the dataclass that it must not touch to this attibute
    '''
    name: str = field(init=True)
    surname: str = field(init=True)
    active: bool = field(default=True)
    login: str = field(init=False)
    id: str = field(init=False)

    def __post_init__(self):
        '''__post_init__ method that initiate the last two attribute: login\
and id'''
        if not isinstance(self.name, str):
            self.name = str(self.name)
        if not isinstance(self.surname, str):
            self.surname = str(self.surname)
        if not self.name.isalpha():
            raise ValueError(f"{self.name}: wrong format, only alpha")
        if not self.surname.isalpha():
            raise ValueError(f"{self.name}: wrong format, only alpha")
        self.login = self.name[0] + self.surname
        self.id = generate_id()
