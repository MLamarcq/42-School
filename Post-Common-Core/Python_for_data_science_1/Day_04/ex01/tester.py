from S1E7 import Baratheon

def main():
	try:
		Robert = Baratheon("Robert")
		print(Robert.family_name)
		print(Robert.__str__)
		print(Robert.__repr__)
		print(Robert)
		Bob = Baratheon.create_baratheon("Bob", True)
		print(Bob.first_name)
		family = Baratheon.create_baratheon_chain(2)
		print(family)
		for people in family:
			print(people.first_name)
	except Exception as e:
		print(f"{e}")

if __name__ == '__main__':
	main()