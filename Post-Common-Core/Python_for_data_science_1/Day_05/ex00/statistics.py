def pars_args(args):
    '''Pars the args received. Check if it is a list or a tuple. Then,
    if args is empty and to finish, check the elements in the args are int
    or float. If the function passes all the step, return, otherwise
    raise a specific error
    '''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    if len(args) == 0:
        raise ValueError("Args can not be empty")
    for elem in args:
        if not isinstance(elem, (int, float)):
            raise TypeError("Your list or tuple must containt int or float")
    return


def pars_kwargs(kwargs):
    '''Pars the kwargs received. Check if it is a dict. Then, check the
    values in the kwargs are in the list to_check. If the function passes all
    the step, return, otherwise raise a specific error
    '''
    if not isinstance(kwargs, dict):
        raise TypeError("Kwargs must be a dict")
    to_check = ["mean", "median", "quartile", "std", "var"]
    for value in kwargs.values():
        if value not in to_check:
            raise ValueError("The kwargs are waiting for: 'mean', 'median',\
 'quartile', 'std' and 'var'")
    return


def parsing(args, kwargs):
    ''''Args et kwargs parsing: call the pars_args and pars_kwqrgs function'''
    pars_args(args)
    pars_kwargs(kwargs)
    return


def do_mean(args):
    '''Do the mean of the element present in a gived list'''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    res = 0
    for elem in args:
        res += elem
    res = float(res / len(args))
    return res


def do_median(args):
    '''Do the median of the element present in a gived list'''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    new_list = sorted(args)
    median = int(len(args) // 2)
    if (len(args) % 2) != 0:
        res = new_list[median]
    else:
        res = (new_list[median] + new_list[median + 1]) // 2
    return res


def return_quartile(args):
    '''Do the quartile of the element present in a gived list'''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    new_list = sorted(args)
    size = len(args)
    q1 = size // 4
    q3 = (size * 3) // 4
    res = [new_list[q1], new_list[q3]]
    return res


def variance(args):
    '''Do the variance of the element present in a gived list'''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    var = 0
    mean = do_mean(args)
    count = 0
    res = []
    for value in args:
        res.append((value - mean) ** 2)
    for value in res:
        count += value
    var = count / (len(args))
    return var


def standard_deviation(args):
    '''Do the standard deviation of the element present in a gived list'''
    if not isinstance(args, (list, tuple)):
        raise TypeError("Args must be list or tuple")
    var = variance(args)
    std = var ** 0.5
    return std


def ft_statistics(*args: any, **kwargs: any) -> None:
    '''ft_statistics do the operation wanted by the user gived as kwargs on\
 the args given. It means: mean, median, quartile, variance, and\
 standart deviation'''
    parsing(args, kwargs)
    for value in kwargs.values():
        match value:
            case 'mean':
                mean = do_mean(args)
                print(f"mean = {mean}")
            case 'median':
                median = do_median(args)
                print(f"median = {median}")
            case 'quartile':
                quartile = return_quartile(args)
                print(f"quartile = {quartile}")
            case 'var':
                var = variance(args)
                print(f"var: {var}")
            case 'std':
                std = standard_deviation(args)
                print(f"std = {std}")
            case _:
                print("ERROR")
    return
