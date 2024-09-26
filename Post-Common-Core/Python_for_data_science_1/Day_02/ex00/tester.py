from give_bmi import give_bmi, apply_limit, WrongArg


def main():
    try:

        print("TEST 1: subject\n")
        height = [2.71, 1.15]
        weight = [165.3, 38.4]
        bmi = give_bmi(height, weight)
        print(bmi, type(bmi))
        print(apply_limit(bmi, 26))

        print("\n\n---------------------------------------------\n\n")

        # print("TEST 2: wrong arg\n")
        # bm = "test"
        # height = [2.71, bm]
        # weight = [165.3, 38.4]
        # bmi = give_bmi(height, weight)
        # print(bmi, type(bmi))
        # print(apply_limit(bmi, 26))

        # print("\n\n---------------------------------------------\n\n")

        # print("TEST 3: wrong arg\n")
        # bm = "test"
        # height = [2.71, 1.15]
        # weight = [165.3, 38.4]
        # bmi = give_bmi(height, weight)
        # print(bmi, type(bmi))
        # print(apply_limit(bm, 26))

        # print("\n\n---------------------------------------------\n\n")

        # print("TEST 4: wrong arg\n")
        # bm = "test"
        # height = [2.71, 1.15, 2, 2.85]
        # weight = [165.3, 38.4, 75.2, 124.635, 66, 87.22]
        # bmi = give_bmi(height, weight)
        # print(bmi, type(bmi))
        # print(apply_limit(bmi, 26))

        # print("\n\n---------------------------------------------\n\n")

        print("TEST 5: bigger list\n")
        height = [2.71, 1.15, 2, 2.85, 1.85, 1.36]
        weight = [165.3, 38.4, 75.2, 124.635, 66, 87.22]
        bmi = give_bmi(height, weight)
        print(bmi, type(bmi))
        print(apply_limit(bmi, 26))

    except WrongArg as e:
        print(str(e))


if __name__ == '__main__':
    main()
