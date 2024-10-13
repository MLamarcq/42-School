class calculator:
    def __init__(self, array: list):
        '''
            Calculator class construtor. Check if the array received is a list
            and check inside the array if its elements are int or float.
            If all good, we initialise a class attribute based on the array.
            Else, we raise an Exception
        '''
        if isinstance(array, (list)):
            check = all(isinstance(elem, (int, float)) for elem in array)
            if not check:
                raise Exception("The elem of your liste are in wrong type")
            self.array = array
        else:
            raise Exception("Give a list to the calculator !")

    def __str__(self):
        '''Str class method. Print the array registered'''
        return f"{self.array}"

    def __add__(self, object) -> None:
        '''
        Add method check if the object given is type int or float.
        If so, we take the array class attibute and add to all its elements
        the object given.
        Else, we raise an Exception
        '''
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem + object) for elem in self.array]
        print(self.array)
        return

    def __mul__(self, object) -> None:
        '''
        Mul method check if the object given is type int or float.
        If so, we take the array class attibute and multiplie to all its
        elements the object given.
        Else, we raise an Exception
        '''
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem * object) for elem in self.array]
        print(self.array)
        return

    def __sub__(self, object) -> None:
        '''
        Sub method check if the object given is type int or float.
        If so, we take the array class attibute and substract to all its
        elements the object given.
        Else, we raise an Exception
        '''
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        self.array = [(elem - object) for elem in self.array]
        print(self.array)
        return

    def __truediv__(self, object) -> None:
        '''
        Truediv method check if the object given is type int or float.
        If so, we take the array class attibute and divide to all its
        elements the object given.
        Else, we raise an Exception
        '''
        if not isinstance(object, (int, float)):
            raise Exception("Need int or float to do operation")
        if not object:
            raise Exception("You can't divide by 0")
        self.array = [(elem / object) for elem in self.array]
        print(self.array)
        return
