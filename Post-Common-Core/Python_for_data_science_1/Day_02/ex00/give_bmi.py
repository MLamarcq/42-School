import numpy as np

class WrongArg(Exception) :
	pass


def check_list(height, weight) -> int :
	if not isinstance(height, list) or not isinstance(weight, list) :
		return (5)
	if (len(height) != len(weight)) :
		return (1)
	for elem in height :
		if not isinstance(elem, int) and not isinstance(elem, float) :
			return (2)
	for elem in weight :
		if not isinstance(elem, int) and not isinstance(elem, float) :
			return (2)
	for i in range(len(height)) :
		if (height[i] < 0.5 or height[i] > 3) :
			return (3)
		if (weight[i] < 20 or weight[i] > 200) :
			return (3)
		if (height[i] >= weight[i]) :
			return (4)
	return (0)

def convert_to_float_native(number) :
	if isinstance(number, np.float64) :
		return float(number)
	return (numer)

def arround_float(height, weight) -> tuple:
	height = [convert_to_float_native(np.around(elem,2)) if isinstance(elem, float) else elem for elem in height]
	weight = [convert_to_float_native(np.around(elem,2)) if isinstance(elem, float) else elem for elem in weight]
	return (height, weight)


def bmi_calcul(height, weight) -> list :
	res = []
	for i in range(len(height)) :
		count = weight[i] / (height[i])**2
		res.append(count)
	return (res)


def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float] :
	check = check_list(height, weight)
	match check :
		case 1 :
			raise WrongArg("List len don't match. Please try again")
		case 2 :
			raise WrongArg("One or several list were setted up with the wrong type. Float and int only")
		case 3 :
			raise WrongArg("A number or float in your list is out of range (0.5 to 2.5 for height and 50 to 200 for weight)")
		case 4 :
			raise WrongArg("Height can not be higher than weight")
		case 5 :
			raise WrongArg("Wrong type arg. Height and weight must be 'list' type")
		case _ :
			pass
	height, weight = arround_float(height, weight)
	return bmi_calcul(height, weight)


def check_args_limit(bmi, limit) -> int:
	if not isinstance(limit, int) or not isinstance(bmi, list):
		return (1)
	check = np.sign(limit)
	if check == -1 :
		return (2)
	return (0)

def apply_limit(bmi: list[int | float], limit: int) -> list[bool]: 
	check = check_args_limit(bmi, limit)
	match check :
		case 1 :
			raise WrongArg("Wront type for apply_limit. It has to be 'list' and 'int'")
		case 2 :
			raise WrongArg("Limit in apply_limit must be positive")
		case _ : 
			pass
	res = []
	for i in range(len(bmi)) :
		if (bmi[i] > limit) :
			res.append(True)
		else :
			res.append(False)
	return res