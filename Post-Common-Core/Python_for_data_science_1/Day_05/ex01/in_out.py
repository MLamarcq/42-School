def square(x: int | float) -> int | float:
	if not isinstance(x, (int, float)):
		raise TypeError("You must use int orfloat")
	square = x ** 2
	return square

def pow(x: int | float) -> int | float:
	if not isinstance(x, (int, float)):
		raise TypeError("You must use int or float")
	pow = x ** x
	return float(pow)

def outer(x: int | float, function) -> object:
	if not isinstance(x, (int, float)):
		raise TypeError("You must use int or float")
	check_func = callable(function)
	if not check_func:
		raise TypeError("Please be sure to give to outer a function")
	count = x
	def inner() -> float:
		nonlocal count
		count = (function(count))
		return count
	return inner