import sys
from ft_filter import ft_filter, superior_left


class WrongArg(Exception):
    '''WrongArg class used for error handling'''
    def __str__(self):
        return (("AssertionError: the arguement are bad"))


def check_digit(arg) -> bool:
    '''Checks if the argument gived is only composed by digit'''
    return arg.isdigit()


def pars_args(argv):
    '''Parse the arg passed as argv. Check size, type and string component:
it must be digit'''
    if len(argv) != 3:
        raise WrongArg
    if not isinstance(argv[1], str):
        raise WrongArg
    if not check_digit(argv[2]):
        raise WrongArg
    return


def pars_string(string) -> bool:
    '''Pars a string passed as argument. Check if the string is only
composed by letters, digits and spaces'''
    for elem in string:
        if not elem.isalpha() and not elem.isdigit() and not elem.isspace():
            return False
    return True


def initialize_list(string) -> list:
    '''Initialize a list based on a string by using 'split()' method'''
    elem = string.split(' ')
    if not pars_string(elem):
        raise WrongArg
    return elem


def main():
    '''Main function. Handle errors, lauch the program by using all
functions'''
    argv = sys.argv
    try:
        pars_args(argv)
        elem = initialize_list(argv[1])
        print(ft_filter(lambda x: superior_left(len(x), int(argv[2])), elem))
    except WrongArg as e:
        print(str(e))


if __name__ == '__main__':
    main()
