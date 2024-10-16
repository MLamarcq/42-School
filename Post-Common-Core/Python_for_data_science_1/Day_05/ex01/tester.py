from in_out import square
from in_out import pow
from in_out import outer


def main():
    try:
        my_counter = outer(3, square)
        print(my_counter())
        print(my_counter())
        print(my_counter())

        print("\n\n", '-' * 30, "\n\n")

        another_counter = outer(1.5, pow)
        print(another_counter())
        print(another_counter())
        print(another_counter())

    except Exception as e:
        print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
    main()
