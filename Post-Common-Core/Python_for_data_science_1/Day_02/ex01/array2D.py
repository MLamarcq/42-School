import numpy as np

class WrongArg(Exception) :
	pass

# def pars_array(family) -> int :
# 	count_size = []
# 	print(f"family = {family}")
# 	for elem in family :
# 		count_size.append(family.itemsize)
# 	print(f"count_size = {count_size}")
# 	for i in range(len(count_size) - 1) :
# 		print(f"count_size[{i}] = {count_size[i]}, len = {len(count_size)}")
# 		if count_size[i + 1] and (count_size[i] != count_size[i + 1]) :
# 			return 0
# 	return (1)

def pars_array(family: list) -> int :
	count_size = []
	for elem in family :
		if not isinstance(elem, list) :
			print("C1")
			return (0)
		for number in elem :
			if not isinstance(number, int) and not isinstance(number, float) :
				print("C2")
				return (0)
		count_size.append(len(elem))
	for i in range(len(count_size) - 1) :
		if count_size[i + 1] and (count_size[i] != count_size[i + 1]) :
			print("C3")
			return (0)
	return (1)

def slice_arr(family, start, end) :
	count_col = 0
	row_slice = 0
	col_slice = 0
	tokken = False
	for elem in family :
		count_col = len(elem)
		break
	col_slice = slice(0, count_col)
	if start < 0 :
		row_slice = slice(0, end)
	elif end < 0 :
		row_slice = start
	elif (start < 0 and end < 0) or (start > end) :
		return []
	elif start == end :
		row_slice = start
	else : 
		row_slice = slice(start, end)
		tokken = True
	new_arr = family[row_slice]
	if tokken :
		row_slice = end - start
	return (new_arr, row_slice)

def take_first_dimensions(family: list) -> tuple:
	col = 0
	row = len(family)
	for elem in family :
		col = len(elem)
		break
	return (row, col)

def print_output(first_dimension: tuple, row_slice: int) -> str :
	output = ''
	output += f"My shape is: ({first_dimension[0]}, {first_dimension[1]})\n"
	output += f"My new shape is : ({row_slice}, {first_dimension[1]})\n"
	return output


def slice_me(family : list[int | float], start: int, end: int) -> list :
	if not isinstance(family, list) or not isinstance(start, int) or not isinstance(end, int):
		raise WrongArg("Your argument type are not as expected : we need 'list', 'int' and 'int")
	check_arr = pars_array(family)
	if not check_arr :
		raise WrongArg("Array error")
	first_dimension = take_first_dimensions(family)
	new_arr, row_slice = slice_arr(family, start, end)
	print(print_output(first_dimension, row_slice), end='')
	return new_arr