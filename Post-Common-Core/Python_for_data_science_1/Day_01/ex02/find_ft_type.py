def all_thing_is_obj(object: any) -> int:
	res = type(object)
	if isinstance(object, list) : 
		print(f"List : {res}")
	elif isinstance(object, tuple) :
		print(f"Tuple : {res}")
	elif isinstance(object, set) :
		print(f"Set : {res}")
	elif isinstance(object, dict) :
		print(f"Dict : {res}")
	elif isinstance(object, str) :
		output = object
		output += " is in the kitchen"
		print(f"{output} : {res}")
	else :
		print("Type not found")
	return 42

