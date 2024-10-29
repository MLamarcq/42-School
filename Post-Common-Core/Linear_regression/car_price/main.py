import json

def apply_model(theta0, theta1, mileage):
	return theta0 + (theta1 * mileage)


def pars_arg_return_int(string):
	if not string.isdigit():
		return None
	if len(string) > 6:
		return None
	mileage = int(string)
	if not mileage or mileage < 0:
		return None
	return mileage

def exctract_data_from_json(file):
	data = {}
	theta0 = 0
	theta1 = 0
	with open(file, "r") as file:
		data = json.load(file)
		theta0 = data['theta0']
		theta1 = data['theta1']
	return theta0, theta1


def define_mileage():
	while True:
		res = input("Choose a mileage for your car: ")
		mileage = pars_arg_return_int(res)
		
		if mileage is not None:
			return mileage
		else:
			print("Wrong format, try again.")


def main():
	try:
		theta0, theta1 = exctract_data_from_json('../value.json')
		mileage = define_mileage()
		price = apply_model(theta0, theta1, mileage)
		print(f"According to our estimation, for a mileage of {mileage} km,", end='')
		print(f" the price for your car is: {price:.2f} euros")
	except FileNotFoundError as e:
		print(f"{type(e).__name__}: {e}")
	except KeyboardInterrupt as e:
		print(f"{type(e).__name__}: {e}")
	except EOFError as e:
		print(f"{type(e).__name__}: {e}")
	except Exception as e:
		print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
	main()