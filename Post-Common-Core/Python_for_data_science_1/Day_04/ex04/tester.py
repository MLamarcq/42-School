from ft_calculator import calculator

def main():
	try:
		a = [5, "salut", 2]
		b = [2, 4, 3]

		calculator.dotproduct(a, b)
		calculator.add_vec(a, b)
		calculator.sous_vec(a, b)
	except TypeError as e:
		print(f"{type(e).__name__}: {e}")
	except ValueError as e:
		print(f"{type(e).__name__}: {e}")

if __name__ == '__main__':
	main()