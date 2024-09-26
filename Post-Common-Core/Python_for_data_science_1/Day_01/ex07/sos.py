import sys


class ArgError(Exception):
    '''ArgError class for error handling'''
    def __str__(self):
        return "AssertionError: the arguments are bad"


def pars_args(argv) -> bool:
    '''Pars the args gives as argv. Check their size and their type. If
they are not letters, digits or spaces, the function returns false'''
    if (len(argv) != 2):
        return False
    for elem in argv[1]:
        if not elem.isalnum() and not elem.isspace():
            return False
    return True


def print_morse(argv, morse_dict):
    '''Take the args passed throught argv and is args are valid, put to upper
case the letters and print the morse message by comparing caracter and key from
the morse_dict passed in args'''
    if not pars_args(argv):
        raise ArgError
    to_analyse = ''
    for elem in argv[1]:
        if elem.islower():
            to_analyse += elem.upper()
    to_print = ''
    for elem in to_analyse:
        for key, value in morse_dict.items():
            if elem == key:
                to_print += value
    print(to_print)
    return


def main():
    '''Main function. Handle errors, lauch the program by using all
functions'''
    argv = sys.argv
    morse_dict = {
        " ": "/",
        "A": ".-",
        "B": "-...",
        "C": "-.-.",
        "D": "-..",
        "E": ".",
        "F": "..-.",
        "G": "--.",
        "H": "....",
        "I": "..",
        "J": ".---",
        "K": "-.-",
        "L": ".-..",
        "M": "--",
        "N": "-.",
        "O": "---",
        "P": ".--.",
        "Q": "--.-",
        "R": ".-.",
        "S": "...",
        "T": "-",
        "U": "..-",
        "V": "...-",
        "W": ".--",
        "X": "-..-",
        "Y": "-.--",
        "Z": "--..",
        "0": "-----",
        "1": ".----",
        "2": "..---",
        "3": "...--",
        "4": "....-",
        "5": ".....",
        "6": "-....",
        "7": "--...",
        "8": "---..",
        "9": "----."
    }
    try:
        print_morse(argv, morse_dict)
    except ArgError as e:
        print(str(e))
    except KeyboardInterrupt:
        print("Signal: SIGINT. End of program")


if __name__ == '__main__':
    main()
