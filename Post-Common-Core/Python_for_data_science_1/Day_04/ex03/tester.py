from ft_calculator import calculator


def main():
    ''' 
    Main function.
    Test all the operation on calculator object and test error handling
    '''
    try:
        # v1 test
        v1 = calculator([0.0, 1.0, 2.0, 3.0, 4.0, 5.0])

        print(f"V1 = {v1}\n")
        print("The result of the sum vector v1 + 5 = ", end='')
        v1 + 5

        print("\n\n", '-' * 30, "\n\n")

        print(f"V1 = {v1}\n")
        print("The result of the sum vector v1 * 5 = ", end='')
        v1 * 5

        print("\n\n", '-' * 30, "\n\n")

        print(f"V1 = {v1}\n")
        print("The result of the sum vector v1 - 5 = ", end='')
        v1 - 5

        print("\n\n", '-' * 30, "\n\n")

        print(f"V1 = {v1}\n")
        print("The result of the sum vector v1 / 5 = ", end='')
        v1 / 5

        print("\n\n", '-' * 30, "\n\n")

        # v2 test
        v2 = calculator([0.0, 1.0, 2.0, 3.0, 4.0, 5.0])

        print(f"V2 = {v2}\n")
        print("The result of the sum vector v2 + 10000 = ", end='')
        v2 + int(1e4)

        print("\n\n", '-' * 30, "\n\n")

        print(f"V2 = {v2}\n")
        print("The result of the sum vector v2 / 10000 = ", end='')
        v2 / int(1e4)

        print("\n\n", '-' * 30, "\n\n")

        print(f"V2 = {v2}\n")
        print("The result of the sum vector v2 * 10000 = ", end='')
        v2 * int(1e4)

        print("\n\n", '-' * 30, "\n\n")

        print(f"V2 = {v2}\n")
        print("The result of the sum vector v2 - 10000 = ", end='')
        v2 - int(1e4)

        print("\n\n", '-' * 30, "\n\n")

        # v3 test
        v3 = calculator([10.0, 15.0, 20.0])
        v3 - 5
        v3 / 5

        print("\n\n", '-' * 30, "\n\n")

        # Error testing
        # v4 = calculator([1, 2, "oui", 3])
        # v5 = calculator({
        #     '1': 2,
        #     '2': 4
        #     })
        # v1 + "salut"
    except Exception as e:
        print(str(e))


if __name__ == '__main__':
    main()
