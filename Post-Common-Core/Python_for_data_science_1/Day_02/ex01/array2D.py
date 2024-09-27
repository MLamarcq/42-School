class WrongArg(Exception):
    '''Class WrongArg for error handling'''
    pass


def pars_array(family: list) -> int:
    '''Parse the array given. Check if there is a 2D array, then if all
content is int or float and then if all the content have all the same size.
Returns an error if any of these condition is fullfilled'''
    count_size = []
    for elem in family:
        if not isinstance(elem, list):
            return (0)
        for number in elem:
            if not isinstance(number, int) and not isinstance(number, float):
                return (0)
        count_size.append(len(elem))
    for i in range(len(count_size) - 1):
        if count_size[i + 1] and (count_size[i] != count_size[i + 1]):
            return (0)
    return (1)


def slice_arr(family, start, end):
    '''Apply the slice method on the array with the start and end given'''
    row_slice = 0
    tokken = False
    if start < 0:
        row_slice = slice(0, end)
    elif end < 0:
        row_slice = start
    elif (start < 0 and end < 0) or (start > end):
        return []
    elif start == end:
        row_slice = start
    else:
        row_slice = slice(start, end)
        tokken = True
    new_arr = family[row_slice]
    if tokken:
        row_slice = end - start
    return (new_arr, row_slice)


def take_first_dimensions(family: list) -> tuple:
    '''Returns a tuple of array dimension'''
    col = 0
    row = len(family)
    for elem in family:
        col = len(elem)
        break
    return (row, col)


def print_output(first_dimension: tuple, row_slice: int) -> str:
    '''Print the old and the new shape of the array'''
    output = ''
    output += f"My shape is: ({first_dimension[0]}, {first_dimension[1]})\n"
    output += f"My new shape is: ({row_slice}, {first_dimension[1]})\n"
    return output


def slice_me(family: list[int | float], start: int, end: int) -> list:
    '''Error handling, slice the array and print the shape'''
    if (not isinstance(family, list)
            or not isinstance(start, int)
            or not isinstance(end, int)):
        raise WrongArg("Your argument type are not as expected: 'list', 'int'")
    check_arr = pars_array(family)
    if not check_arr:
        raise WrongArg("Array error")
    first_dimension = take_first_dimensions(family)
    new_arr, row_slice = slice_arr(family, start, end)
    print(print_output(first_dimension, row_slice), end='')
    return new_arr
