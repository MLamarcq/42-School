def print_output(a, percent, t, length=103):
    '''Print the output of ft_tqdm function: a loading bar. This function
print the string with calcul of the actual statement of the progression.'''
    bar_length = int(percent * length)
    bar = '=' * bar_length
    spaces = ' ' * (length - len(bar))
    p_o = percent * 100
    if percent < 1:
        print(f"\r{p_o:.0f}%|[{bar}{spaces}]| {a}/{t}", end='', flush=True)
    else:
        bar += '>'
        print(f"\r{p_o:.0f}%|[{bar}{spaces}]| {a}/{t}", end='', flush=True)
    if percent == 1:
        print()


def ft_tqdm(lst: range) -> None:
    '''Tqdm python function reimplemented.'''
    t = len(lst)
    for i, value in enumerate(lst):
        percent = (i + 1) / t
        print_output(value + 1, percent, t)
        yield value
