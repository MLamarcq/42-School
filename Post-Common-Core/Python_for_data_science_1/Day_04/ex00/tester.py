from S1E9 import Character, Stark


def main():
    '''
    Main function:
        - Test the class Character and Stark and their methods
        - Test on instanciate an abstract class
        - Error handling
    '''
    try:
        Ned = Stark("Ned")
        print(Ned.__dict__)
        print(Ned.is_alive)
        Ned.die()
        print(Ned.is_alive)
        print(Ned.__doc__)
        print(Ned.__init__.__doc__)
        print(Ned.die.__doc__)

        print("\n\n", '-' * 30, "\n\n")

        Lyanna = Stark("Lyanna", False)
        print(Lyanna.__dict__)

        print("\n\n", '-' * 30, "\n\n")

        Ned.die()

        print("\n\n", '-' * 30, "\n\n")

        hodor = Character("hodor")
        hodor.die()

    except Exception as e:
        print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
