from S1E9 import Character, Stark


def main():
	try:
		Ned = Stark("Ned")
		print(Ned.__dict__)
		print(Ned.is_alive)
		Ned.die()
		print(Ned.is_alive)
		Ned.die()
		hodor = Character("hodor")
	except TypeError as e:
		print(str(e))
	except KeyboardInterrupt as e:
		print(str(e))
	except EOFError as e:
		print(str(e))


if __name__ == '__main__':
	main()
