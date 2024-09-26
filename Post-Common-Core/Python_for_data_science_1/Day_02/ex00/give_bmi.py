import numpy as np


class WrongArg(Exception):
    '''Class WrongArg for error handling'''
    pass


def check_list(height, weight) -> int:
    ''''Check if the lists given are valid or not'''
    if not isinstance(height, list) or not isinstance(weight, list):
        return (5)
    if (len(height) != len(weight)):
        return (1)
    for elem in height:
        if not isinstance(elem, int) and not isinstance(elem, float):
            return (2)
    for elem in weight:
        if not isinstance(elem, int) and not isinstance(elem, float):
            return (2)
    for i in range(len(height)):
        if (height[i] < 0.5 or height[i] > 3):
            return (3)
        if (weight[i] < 20 or weight[i] > 200):
            return (3)
        if (height[i] >= weight[i]):
            return (4)
    return (0)


def to_f(number):
    '''Convert a numpy float64 to float native'''
    if isinstance(number, np.float64):
        return float(number)
    return (number)


def arround_float(h, w) -> tuple:
    '''Round float in list to 2 decimal'''
    h = [to_f(np.around(e, 2)) if isinstance(e, float) else e for e in h]
    w = [to_f(np.around(e, 2)) if isinstance(e, float) else e for e in w]
    return (h, w)


def bmi_calcul(height, weight) -> list:
    '''Calcul the bmi'''
    res = []
    for i in range(len(height)):
        count = weight[i] / (height[i])**2
        res.append(count)
    return (res)


def give_bmi(h: list[int | float], w: list[int | float]) -> list[int | float]:
    '''Error handling. If an error detected, raise an exception. Otherwise,
give the bmi by calculating it with bmi_calcul function and returns it'''
    check = check_list(h, w)
    match check:
        case 1:
            raise WrongArg("List len don't match. Please try again")
        case 2:
            raise WrongArg("Wrong type. Float and int only")
        case 3:
            raise WrongArg("A number or float in your list is out of range")
        case 4:
            raise WrongArg("Height can not be higher than weight")
        case 5:
            raise WrongArg("Wrong type. Height and weight must be 'list' type")
        case _:
            pass
    h, w = arround_float(h, w)
    return bmi_calcul(h, w)


def check_args_limit(bmi, limit) -> int:
    '''Check if arg are on the right type and check if only positive
numbers were given'''
    if not isinstance(limit, int) or not isinstance(bmi, list):
        return (1)
    check = np.sign(limit)
    if check == -1:
        return (2)
    return (0)


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    '''Compare the bmi results to a limit. Append True in a list if bmi is
highter, False otherwise. Returns the list'''
    check = check_args_limit(bmi, limit)
    match check:
        case 1:
            raise WrongArg("Wrong type apply_limit: must be 'list' and 'int'")
        case 2:
            raise WrongArg("Limit in apply_limit must be positive")
        case _:
            pass
    res = []
    for i in range(len(bmi)):
        if (bmi[i] > limit):
            res.append(True)
        else:
            res.append(False)
    return res
