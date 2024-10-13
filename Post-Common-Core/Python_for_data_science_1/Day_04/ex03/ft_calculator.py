class calculator:
    def __init__(self, array: list):
        if isinstance(array, (list)):
            check = all(isinstance(elem, (int, float)) for elem in array)
            if not check:
                raise Exception("The elem of your liste are in wrong type")
            self.array = array
        else:
            raise Exception("Give a list to the calculator !")

    def __str__(self):
        return f"{self.array}"

    def __add__(self, object) -> None:
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem + object) for elem in self.array]
        print(self.array)
        return

    def __mul__(self, object) -> None:
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem * object) for elem in self.array]
        print(self.array)
        return

    def __sub__(self, object) -> None:
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem - object) for elem in self.array]
        print(self.array)
        return

    def __truediv__(self, object) -> None:
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        if not object:
            raise Exception("You can't divide by 0")
        self.array = [(elem / object) for elem in self.array]
        print(self.array)
        return
