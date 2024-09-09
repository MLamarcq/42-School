def is_nan(value) :
	return value != value

def NULL_not_found(object: any) -> int :
	res = type(object)
	if not object :
		if isinstance(object, int) :
			print(f"Zero : {object} {res}")
		elif isinstance(object, str) :
			print(f"Empty : {object} {res}")
		elif isinstance(object, bool) :
			print(f"Fake : {object} {res}")
		elif not object :
			print(f"Nothing: {object} {res}")
		else :
			print("Type not found")
	elif isinstance(object, float) :
		if is_nan(object) :
			print(f"Cheese : {object} {res}")
		else :
			print("Type not found")
			return (1)
	else :
		print("Type not found")
		return (1)
	return (0)

Nothing = None
Garlic = float("NaN")
Zero = 0
Empty = ''
Fake = False

NULL_not_found(Nothing)
NULL_not_found(Garlic)
NULL_not_found(Zero)
NULL_not_found(Empty)
NULL_not_found(Fake)
NULL_not_found("Brian")