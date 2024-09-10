import sys

def parsing_argv(argv) :
	for elem in argv :
		if not elem.isdigit() :
			raise AssertionError

def is_even(arg) :
	nb = int(arg)
	return nb % 2 == 0

def main() :
	argv = sys.argv
	if (len(argv) < 2) :
		return
	if (len(argv) > 2) :
		print("AssertionError : more than one argument is provided")
		return
	try :
		parsing_argv(argv[1])
		if (is_even(argv[1])) :
			print("I'm Even.")
		else :
			print("I'm Odd.")
	except AssertionError :
		print(f"AssertionError : {argv[1]} is not an integer")


if __name__ == '__main__' :
	main()