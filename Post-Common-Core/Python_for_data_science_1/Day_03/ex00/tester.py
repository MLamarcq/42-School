from load_csv import load
import pandas as pd


def main():
    try:
        '''Main function, load a DataFrame from a .csv file'''
        print(load("life_expectancy_years.csv"))
        # print(load("../ex02/population_total.csv"))
        # print(load("tester.py"))
        # print(load("../ex01/salut"))
        # print(load("../ex01/aff_life.py"))
        # print(load("../ex01/life_expectancy_years.csv"))
    except FileNotFoundError as e:
        print(str(e))
    except pd.errors.ParserError as e:
        print(str(e))
    except Exception as e:
        print(str(e))


if __name__ == '__main__':
    main()
