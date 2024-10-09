from load_csv import load


def main():
    '''Main function, load a DataFrame from a .csv file'''
    print(load("population_total.csv"))


if __name__ == '__main__':
    main()
