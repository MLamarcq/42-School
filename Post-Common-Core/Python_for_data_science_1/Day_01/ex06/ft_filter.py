class FuncError(Exception) :
	pass

def check_function(function) -> bool :
	return callable(function)

def addition(a, b) :
	if not (isinstance(a, int)) or not (isinstance(b, int)) :
		return False
	return a + b

def superior_right(a, b) :
	if not (isinstance(a, int)) or not (isinstance(b, int)) :
		return False
	return a < b

def superior_left(a, b) :
	if not (isinstance(a, int)) or not (isinstance(b, int)) :
		return False
	return a > b

def check_digit(char) :
	if not (isinstance(char, str)) :
		return False
	return char.isdigit()

def check_letter(char) :
	if not (isinstance(char, str)) :
		return False
	return char.isalpha()

def is_interger(char) :
	return isinstance(char, int)


def ft_filter(function, iterable) :
	if not check_function(function) : 
		raise FuncError(f"{function} error : you didn't call a function")
	res = [elem for elem in iterable if function(elem)]
	return res

def main() :
	
	test = [1, 4, 8, 2, 6, 5, 1, 7]
	test_2 = ("salut", "bonjour", "oui mec", "J'aime bien les frites", "48826")
	test_3 = {
		'45' : 'oui',
		'oui' : 'non',
		75 : 78,
		'boite' : "biblot"
	}

	try :

		print("test 1\n")

		print(ft_filter(lambda x: superior_right(x, 5), test))
		print(ft_filter(lambda x: superior_left(x, 5), test))
		print(ft_filter(check_digit, test))
		print(ft_filter(check_letter, test))
		print(ft_filter(is_interger, test))

		print("-----------------------------------------------")
		print("test2\n")

		print(ft_filter(lambda x: superior_right(x, 5), test_2))
		print(ft_filter(lambda x: superior_left(x, 5), test_2))
		print(ft_filter(check_digit, test_2))
		print(ft_filter(check_letter, test_2))
		print(ft_filter(is_interger, test_2))

		print("-----------------------------------------------")
		print("test_3\n")
		
		print(ft_filter(lambda x: superior_right(x, 5), test_3))
		print(ft_filter(lambda x: superior_left(x, 5), test_3))
		print(ft_filter(check_digit, test_3))
		print(ft_filter(check_letter, test_3))
		print(ft_filter(is_interger, test_3))

		print("-----------------------------------------------")
		print("test_exception\n")

		print(ft_filter("salut", test))
	except FuncError as e:
		print(str(e))

if __name__ == '__main__' :
	main()