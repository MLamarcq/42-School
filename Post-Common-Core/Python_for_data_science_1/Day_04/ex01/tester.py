from S1E7 import Baratheon, Lannister


def main():
    try:
        print()
        Robert = Baratheon("Robert")
        print(Robert.__dict__)
        print(Robert.__str__)
        print(Robert.__repr__)
        print(Robert.is_alive)
        Robert.die()
        print(Robert.is_alive)
        print(Robert.__doc__)
        print("---")
        Cersei = Lannister("Cersei")
        print(Cersei.__dict__)
        print(Cersei.__str__)
        print(Cersei.is_alive)
        print("---")
        Jaine = Lannister.create_lannister("Jaine", True)
        print(f"Name : {Jaine.first_name, type(Jaine).__name__},\
 Alive : {Jaine.is_alive}")
        print()

#         print("\n\n", 30 * '-', "\n\n")

#         Bob = Baratheon.create_baratheon("Bob", True)
#         print(f"Bob = {Bob}")
#         family = Baratheon.create_baratheon_chain(2)
#         print(family)
#         for people in family:
#             print(f"name = {people.first_name}, is_alive =\
#  {people.is_alive}, {people.family_name}")

    except EOFError:
        print("\nEOFError: EOF called, end of program")
    except KeyboardInterrupt:
        print("\nCTRL+C signal: end or program")
    except Exception as e:
        print(f"\n{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
