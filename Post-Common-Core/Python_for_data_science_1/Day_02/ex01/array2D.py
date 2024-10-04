import numpy as np


class ArrayError(Exception):
    '''Class ArrayError for error handling'''
    pass


class WrongArg(Exception):
    '''Class WrongArg for error handling'''
    pass


def list_to_array(family: list[int | float]):
    '''Convert list to np.ndarray and check if conversion succeded'''
    if not family:
        raise WrongArg("Error argument")
    family = np.array(family)
    if not isinstance(family, np.ndarray):
        raise ArrayError("Can not convert list to np.ndarray")
    return (family)


def pars_array(family):
    if (family.ndim != 2):
        raise ArrayError("Wrong array dimension. We need 2D array")
    for row in range(family.shape[0] - 1):
        if (row < family.shape[0] and
                (family[row].size != family[row + 1].size)):
            raise ArrayError("Array content was setted up with different size")
        for col in range(family.shape[1]):
            if (not np.issubdtype(family[row][col].dtype, np.integer) and
                    not np.issubdtype(family[row][col].dtype, np.floating)):
                raise ArrayError("ArrayError : wrong type content")
    return


def slice_arr(family, start, end):
    if (start < 0 and end <= 0):
        raise ArrayError("ArrayError: slicing dimision are wrong, can't slice")
    elif start < 0:
        family = family[:end]
    elif end <= 0:
        end = start + 1
        family = family[start:end]
    elif start == end or (start > end):
        end = start + 1
        family = family[start:end]
    else:
        family = family[start:end]
    return family


def take_first_dimensions(family: list) -> tuple:
    '''Returns a tuple of array dimension'''
    col = 0
    row = len(family)
    for elem in family:
        col = len(elem)
        break
    return (row, col)


def print_output(shape: tuple, family) -> str:
    '''Print the old and the new shape of the array'''
    output = ''
    output += f"My shape is: {shape}\n"
    output += f"My new shape is: {family.shape}\n"
    return output


def array_to_list(f, res):
    for row in range(f.shape[0]):
        res.append([
            float(elem) if np.issubdtype(f[row].dtype, np.floating)
            else int(elem) for elem in f[row]
        ])
    return res


def slice_me(family: list[int | float], start: int, end: int) -> list:
    '''Error handling, slice the array and print the shape'''
    if (not isinstance(family, list)
            or not isinstance(start, int)
            or not isinstance(end, int)):
        raise WrongArg("Your argument type are not as expected: 'list', 'int'")
    family = list_to_array(family)
    pars_array(family)
    shape = family.shape
    family = slice_arr(family, start, end)
    res = []
    print(print_output(shape, family), end='')
    res = array_to_list(family, res)
    return res
