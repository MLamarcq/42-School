import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from load_csv import load


class DataFrameError(Exception):
    def __str__(self):
        return "Error occured with Data Frame. End of program"


def get_daframe(file):
    dataframe = load(file)
    if dataframe.empty:
        raise DataFrameError
    return dataframe


def series_to_dataframe(life_expectancy, income):
    if life_expectancy.empty or income.empty:
        raise DataFrameError("Error: series are empty")
    data = pd.DataFrame({
        "life_expectancy": life_expectancy,
        "income": income
    })
    # data.fillna(0, inplace=True)
    # data.replace([np.inf, -np.inf], 0, inplace=True)
    data.replace(0, np.nan, inplace=True)
    data.dropna(axis=0, how='any', inplace=True)
    data = data.astype(int)
    print(data.head(), data.tail())
    return (data)


def convert_string_to_float(element):
    if isinstance(element, str):
        if 'M' in element: 
            return float(element.replace('M', '').replace(',', '')) * 1e6
        elif 'B' in element:
            return float(element.replace('B', '').replace(',', '')) * 1e9
        elif 'k' in element:
            return float(element.replace('k', '').replace(',', '')) * 1e3
        return float(element.replace(',', ''))
    elif isinstance(element, int):
        return (element)
    return np.nan


def get_specific_date(dataframe, date, code):
    match code:
        case 'life': 
            specific_date = dataframe.loc[:, date]
            if not isinstance(specific_date, pd.Series):
                raise DataFrameError
            specific_date.dropna(axis=0, how='any', inplace=True)
            specific_date = specific_date.astype(np.uint8)
        case 'income':
            specific_date = dataframe.loc[:, date]
            # print(f"specific date in income = {specific_date.size}")
            if not isinstance(specific_date, pd.Series):
                raise DataFrameError
            specific_date = specific_date.apply(convert_string_to_float)
            specific_date.dropna(axis=0, how='any', inplace=True)
    return specific_date


def define_axes(dataframe):
    x_axe = dataframe["income"]
    y_axe = dataframe["life_expectancy"]

    x_axe = [int(elem) for elem in x_axe]
    y_axe = [int(elem) for elem in y_axe]

    return x_axe, y_axe


def ajust_axes(axe, start, end, step=0):
    if start > end:
        print("Can't slice plot axes, end is highter than start")
        return
    if step and step > (end - start):
        print("Error with step configuration, can't slice plot axes")
        return
    if axe == 'x':
        plt.xlim(start, end + 1000)
        plt.xticks(range(start, end, step))
    elif axe == 'y':
        plt.ylim(start - 2, end)
        plt.yticks(range(start, end, step))
    else:
        print("Error axe doesn't exist. plsease give a valid one")
    return


def axes_labels(x_label=None, y_label=None, title=None):
    if not x_label or not y_label or not title: 
        print("Error setting legend. Please check you gave all the information")
        return
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)
    return


def change_value_for_axes(value, pos):
    if value >= 1e3:
        return f"{value/1e3:.0f}k"
    return f"{value}"


def build_plot(data):
    x_axe, y_axe = define_axes(data)
    ajust_axes('x', 300, int(1e4), 1000)
    ajust_axes('y', 20, 55, 5)
    plt.xscale('log')
    plt.gca().get_xaxis().set_major_formatter(plt.FuncFormatter(change_value_for_axes))
    plt.scatter(x_axe, y_axe, c="blue", alpha=1, marker="o")
    axes_labels("Gross domestic product", "Life Expectancy","1900")
    plt.show()


def main():
    try: 
        dataframe_1 = get_daframe('life_expectancy_years.csv')
        dataframe_2 = get_daframe('income_per_person_gdppercapita_ppp_inflation_adjusted.csv')
        # print(dataframe_2.head())
        life_expectancy = get_specific_date(dataframe_1, '1900', 'life')
        income = get_specific_date(dataframe_2, '1900', 'income')
        data = series_to_dataframe(life_expectancy, income)
        build_plot(data)
    except DataFrameError as e:
        print(str(e))
    except KeyError as e:
        print(f"Key error in DataFrame: {str(e)}")
    except KeyboardInterrupt:
        print("Signal SIGINT: end of program")


if __name__ == '__main__':
    main()