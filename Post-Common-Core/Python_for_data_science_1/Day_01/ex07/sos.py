import sys

class ArgError(Exception) :
	def __str__(self) :
		return "AssertionError: the arguments are bad"


def pars_args(argv) -> bool :
	if (len(argv) != 2) :
		return False
	if not argv[1].isalnum() :
		return False
	return True

def print_morse(argv, morse_dict) :
	if not pars_args(argv) :
		raise ArgError
	to_analyse = ''
	for elem in argv[1] : 
		if elem.islower() :
			to_analyse += elem.upper()
	to_print = ''
	for elem in to_analyse :
		for key, value in morse_dict.items() :
			if elem == key :
				to_print += value
	print(to_print)
	return

# def initialize_dict() -> dict:
# 	morse_dict = {}
# 	flag = 65
# 	while (flag < 90) :
# 		morse_dict[chr(flag)] = 0
# 		flag += 1
# 	print(morse_dict)
# 	return morse_dict

def main() :
	argv = sys.argv
	morse_dict = {
		" " : "/",
		"A" : ".-",
		"B" : "-...",
		"C" : "-.-.",
		"D" : "-..",
		"E" : ".",
		"F" : "..-.",
		"G" : "--.",
		"H" : "....",
		"I" : "..",
		"J" : ".---",
		"K" : "-.-",
		"L" : ".-..",
		"M" : "--",
		"N" : "-.",
		"O" : "---",
		"P" : ".--.",
		"Q" : "--.-",
		"R" : ".-.",
		"S" : "...",
		"T" : "-",
		"U" : "..-",
		"V" : "...-",
		"W" : ".--",
		"X" : "-..-",
		"Y" : "-.--",
		"Z" : "--..",
		"0" : "-----",
		"1" : ".----",
		"2" : "..---",
		"3" : "...--",
		"4" : "....-",
		"5" : ".....",
		"6" : "-....",
		"7" : "--...",
		"8" : "---..",
		"9" : "----."
	}
	try :
		print_morse(argv, morse_dict)
	except ArgError as e :
		print(str(e))

if __name__ == '__main__' :
	main()