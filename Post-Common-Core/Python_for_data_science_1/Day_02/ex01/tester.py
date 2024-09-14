from array2D import slice_me, WrongArg


def main() :
	try :
		test = [[2, 4, 1], [4, 5, 6], [4, 5, 2.3], [4, 5, 9]]
		print(slice_me(test, 1, 1))

		print("\n------------------------------------------\n\n")

		family = [[1.80, 78.4],
					[2.15, 102.7],
					[2.10, 98.5],
					[1.88, 75.2]]
		print(slice_me(family, 1, -2))

		print("\n------------------------------------------\n\n")

		family = [[1.80, 78.4],
					[2.15, 102.7],
					[2.10, 98.5],
					[1.88, 75.2]]
		print(slice_me(family, 1, 1))


		print("\n------------------------------------------\n\n")

		family = [[1.80, 78.4],
					[2.15, 102.7],
					[2.10, 98.5],
					[1.88, 75.2]]
		print(slice_me(family, 0, 3))

	except WrongArg as e:
		print(str(e))


if __name__=='__main__' :
	main()