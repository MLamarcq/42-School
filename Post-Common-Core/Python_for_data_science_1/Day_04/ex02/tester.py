from DiamondTrap import King

def main():
    try:
        Joffrey = King("Joffrey")
        print(Joffrey.__dict__)
        Joffrey.set_eyes("blue")
        Joffrey.set_hairs("light")
        print(Joffrey.get_eyes())
        print(Joffrey.get_hair())
        print(Joffrey.__dict__)

#         print("\n\n", 30  * '-', "\n\n")

#         print(Joffrey.is_alive)
#         Joffrey.die()
#         print(Joffrey.is_alive)

#         print("\n\n", 30  * '-', "\n\n")

#         Cersei = King.create_lannister("Cersei", True)
#         print(f"Cersei = {Cersei}, name = {Cersei.first_name}, eyes =\
#  {Cersei.eyes}")

#         print("\n\n", 30  * '-', "\n\n")

#         pool = King.create_baratheon_chain(2)
#         print(pool)
#         for people in pool:
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
