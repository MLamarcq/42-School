import sys


def pars_arg(argv):
    '''Pars the arguments gives as argv. Checking size'''
    if (len(argv) < 2):
        return False
    elif (len(argv) > 2):
        raise AssertionError
    return True


def prompt_condition(count_char):
    '''Display a prompt on the standard output and fill a dict passed as
argument based on prompt input content by using count_characters_in_arg
function'''
    input_string = str(input("What is the text to count?\n"))
    count_char = count_characters_in_arg(count_char, input_string)
    return count_char


def count_characters_in_arg(count_char, string):
    '''Fill a dict passed as argument based on the string passed as argument
aswel by checking string characters'''
    punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
    for elem in string:
        if elem.isalpha():
            if elem.isupper():
                count_char['upper_letter'] += 1
            elif elem.islower():
                count_char['lower_letter'] += 1
            else:
                print("Error with letters")
        elif elem.isdigit():
            count_char['digit'] += 1
        elif elem.isspace() or elem == '\n':
            count_char['space'] += 1
        elif elem in punctuation:
            count_char['punctuation_mark'] += 1
    count_char['len'] = len(string)
    return count_char


def print_count_char(count_char):
    '''Display the final output'''
    print(f"The text countain {count_char['len']} characters")
    for elem, number in count_char.items():
        match elem:
            case "upper_letter":
                print(f"{number} upper letters")
            case "lower_letter":
                print(f"{number} lower letters")
            case "punctuation_mark":
                print(f"{number} punctuation marks")
            case "space":
                print(f"{number} spaces")
            case "digit":
                print(f"{number} digits")
            case "len":
                pass
            case _:
                print("Error")


def main():
    '''Main function. Handle errors, lauch the program by using all
functions'''
    print(pars_arg.__doc__)
    print(prompt_condition.__doc__)
    print(count_characters_in_arg.__doc__)
    print(print_count_char.__doc__)
    print(main.__doc__)
    argv = sys.argv
    count_char = {
        'upper_letter': 0,
        'lower_letter': 0,
        'punctuation_mark': 0,
        'space': 0,
        'digit': 0,
        'len': 0
    }
    try:
        if not (pars_arg(argv)):
            count_char = prompt_condition(count_char)
        else:
            count_char = count_characters_in_arg(count_char, argv[1])
        print_count_char(count_char)
    except AssertionError:
        print("AssertionError: more than one argument is provided")
    except EOFError:
        print("End of file detected. End of program")
    except KeyboardInterrupt:
        print("Signal SIGINT: end of program")


if __name__ == '__main__':
    main()
