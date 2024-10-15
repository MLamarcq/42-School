def callLimit(limit: int):
	if not isinstance(limit, int):
		raise TypeError("callLimit need an int as argument")
	count = 0
	def callLimiter(function):
		if not callable(function):
			raise TypeError("We need a function")
		def limit_function(*args, **kwargs):
			nonlocal count
			if count < limit :
				count += 1
				return function(*args, **kwargs)
			else:
				print(f"Error: {function} call too many times")
		return limit_function
	return callLimiter
