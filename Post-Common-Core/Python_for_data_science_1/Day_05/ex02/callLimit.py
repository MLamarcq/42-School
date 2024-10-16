def callLimit(limit: int):
    '''Use the gived arg 'limit' to count with what frequency a function\
 has been called and block the new call it the limit has been reached.\
 It is possible by using subfunction: callLimiter who use itself a\
 subfuction 'limit_function'. The function we want to execute will be executed\
 after these three function.'''
    if not isinstance(limit, int):
        raise TypeError("callLimit need an int as argument")
    count = 0

    def callLimiter(function):
        if not callable(function):
            raise TypeError("We need a function")

        def limit_function(*args, **kwargs):
            nonlocal count
            if count < limit:
                count += 1
                return function(*args, **kwargs)
            else:
                print(f"Error: {function} call too many times")

        return limit_function

    return callLimiter
