import sys
from ft_filter import ft_filter, check_function, superior_left

class WrongArg(Exception) :
	def __str__(self):
		return (("AssertionError : the arguement are bad"))

def check_digit(arg) -> bool :
	return arg.isdigit()

def pars_args(argv) :
	if len(argv) != 3:
		raise WrongArg
	if not isinstance(argv[1], str) :
		raise WrongArg
	if not check_digit(argv[2]) :
		raise WrongArg
	return

def pars_string(string) -> bool:
	for elem in string :
		if not elem.isalpha() and not elem.isdigit() and not elem.isspace() :
			return False
	return True

def initialize_list(string) -> list:
	elem = string.split(' ')
	if not pars_string(elem) :
		raise WrongArg
	return elem

def main() :
	argv = sys.argv
	
	try :
		pars_args(argv)
		elem = initialize_list(argv[1])
		print(ft_filter(lambda x: superior_left(len(x), int(argv[2])), elem))
	except WrongArg as e :
		print(str(e))

if __name__== '__main__' :
	main()
