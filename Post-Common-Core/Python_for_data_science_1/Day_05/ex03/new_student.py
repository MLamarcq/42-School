from dataclasses import dataclass, field
import random
import string


def generate_id():
	return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
	name: str = field(init=True)
	surname: str = field(init=True)
	active: bool = field(default=True)
	login: str = field(init=False)
	id: str = field(init=False)


	def __post_init__(self):
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
