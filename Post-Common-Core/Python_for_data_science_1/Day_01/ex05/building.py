import sys

def pars_arg(argv) :
	if (len(argv) < 2) :
		return False
	elif (len(argv) > 2) :
		raise AssertionError
	return True

def prompt_condition(count_char) :
	print("On rentre dans cette condition")
	return count_char

def arg_condition(count_char, string) :
	for elem in string :
		if elem.isalpha() :
			if elem.isupper() :
				count_char['upper_letter'] += 1
			elif elem.islower() :
				count_char['lower_letter'] += 1
			else :
				print("Error with letters")
		elif elem.isdigit() :
			count_char['digit'] += 1
		elif elem.isspace() or elem == '\n':
			count_char['space'] += 1
		else :
			count_char['punctuation_mark'] += 1
	return count_char

def print_count_char(count_char) :
	count = 0
	for elem, number in count_char.items() :
		count += number
	print(f"The text countain {count} characters")
	for elem, number in count_char.items() :
		match elem :
			case "upper_letter" :
				print(f"{number} upper letters")
			case "lower_letter" :
				print(f"{number} lower letters")
			case "punctuation_mark" :
				print(f"{number} punctuation marks")
			case "space" :
				print(f"{number} spaces")
			case "digit" :
				print(f"{number} digits")
			case _ :
				print("Error")

def main() :
	argv = sys.argv
	count_char = {
		'upper_letter' : 0,
		'lower_letter' : 0,
		'punctuation_mark' : 0,
		'space' : 0,
		'digit' : 0
	}
	try :
		if not (pars_arg(argv)) :
			count_char =prompt_condition(count_char)
		else :
			count_char = arg_condition(count_char, argv[1])
		print_count_char(count_char)
	except AssertionError :
		print("AssertionError : more than one argument is provided")


if __name__=='__main__' :
	main()