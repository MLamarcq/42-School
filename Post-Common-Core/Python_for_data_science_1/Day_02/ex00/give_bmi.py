import numpy as np


class ArrayError(Exception):
    '''Class ArrayError for error handling'''
    pass


class WrongArg(Exception):
    '''Class WrongArg for error handling'''
    pass


def list_to_array(height: list[int | float], w: list[int | float]):
    '''Convert list to numpy array'''
    height = np.array(height)
    w = np.array(w)
    if not isinstance(height, np.ndarray) or not isinstance(w, np.ndarray):
        raise TypeError("Conversion from list to np.array failed")
    return (height, w)


def pars_array(height, weight):
    '''Handling array error: typeError, size, dimension and content'''
    if (not np.issubdtype(height.dtype, np.integer) and
            not np.issubdtype(height.dtype, np.floating)):
        raise TypeError("Array type must be int of float")
    if (not np.issubdtype(weight.dtype, np.integer) and
            not np.issubdtype(weight.dtype, np.floating)):
        raise TypeError("Array type must be int of float")
    if height.size != weight.size:
        raise ArrayError("ArrayError: Array have different size")
    if height.ndim != weight.ndim:
        raise ArrayError("ArrayError: Array have different dimension")
    for i in range(height.size):
        if (height[i] >= weight[i]):
            return (0)
    return (1)


def to_f(number):
    '''Convert a numpy float64 to float native'''
    if isinstance(number, np.float64):
        return float(number)
    return (number)


def arround_float(height, weight) -> tuple:
    '''Round float in array to 2 decimal'''
    height = np.around(height, 2)
    weight = np.around(weight, 2)
    return (height, weight)


def bmi_calcul(height, weight) -> list:
    '''Calcul the bmi'''
    res = []
    for i in range(height.size):
        count = weight[i] / (height[i])**2
        res.append(float(count))
    return (res)


def give_bmi(h: list[int | float], w: list[int | float]) -> list[int | float]:
    '''Error handling. If an error detected, raise an exception. Otherwise,
give the bmi by calculating it with bmi_calcul function and returns it'''
    h, w = list_to_array(h, w)
    check = pars_array(h, w)
    if not check:
        raise ArrayError("Height can not be higher than weight")
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
