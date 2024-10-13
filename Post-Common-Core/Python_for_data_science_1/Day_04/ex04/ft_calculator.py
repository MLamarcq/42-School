class calculator:
	def __init__(self):
		pass

	def check_list(self, vector):
		check = all(isinstance(elem, (int, float)) for elem in vector)
		if not check:
			raise ValueError("The calculator is waiting for int or float")

	def compare_list(self, V1, V2):
		if len(V1) != len(V2):
			raise ValueError("The two vector must have an identical size")

	def check_args(self, V1, V2):
		if not isinstance(V1, list) or not isinstance(V2, list):
			raise TypeError("The calculator is waiting for a list")
		self.check_list(V1)
		self.check_list(V2)
		self.compare_list(V1, V2)

	@classmethod
	def dotproduct(cls, V1: list[float], V2: list[float]) -> None:
		calc = cls()
		calc.check_args(V1, V2)
		res = 0
		for i in range(len(V1)):
			res = res + (V1[i] * V2[i])
		print(f"Dot product is: {res}")
		return

	@classmethod
	def add_vec(cls, V1: list[float], V2: list[float]) -> None:
		calc = cls()
		calc.check_args(V1, V2)
		res = [float(V1[i] + V2[i]) for i in range(len(V1))]
		print(res)
		return
	
	@classmethod
	def sous_vec(cls, V1: list[float], V2: list[float]) -> None:
		calc = cls()
		calc.check_args(V1, V2)
		res = [float(V1[i] - V2[i]) for i in range(len(V1))]
		print(res)
		return