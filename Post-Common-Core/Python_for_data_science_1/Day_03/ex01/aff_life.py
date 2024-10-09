from load_csv import load
import pandas as pd
import matplotlib.pyplot as plt


class DataFrameError(Exception):
    '''Class DataFrameError for error handling'''
    def __str__(self):
        return "An error occurs with DataFrame. End of program"


def get_data_frame(file):
    '''Load a DataFrame from a file. Raise an exception\
        if the loading failed'''
    df = load(file)
    if not isinstance(df, pd.DataFrame):
        raise DataFrameError
    return df


def get_specific_country(country, df):
    '''Extract France from the DataFrame and returns a new DataFrame
    based on it'''
    if df.empty:
        raise DataFrameError
    spe_country = df.groupby(['country']).get_group((country,))
    if not isinstance(spe_country, pd.DataFrame):
        raise DataFrameError
    return spe_country


def get_axes(dataframe):
    '''Set the x and y axes before building the plot'''
    if dataframe.empty:
        raise DataFrameError
    x_axe = dataframe.columns[1:]
    y_axe = dataframe.iloc[0, 1:]

    x_axe = [int(label) for label in x_axe]
    y_axe = [float(label) for label in y_axe]
    return (x_axe, y_axe)


def slice_axes(axe, start, end, step):
    '''Define the limits and the step of the axes to define their scale before
    building the plot
    '''
    if start > end:
        print("You gave a start higter than end. Can't slice")
        return
    if not step or (step > (end - start)):
        print("Wrong step configuration. Can't slice")
        return
    if axe == 'x':
        plt.xlim(start - 10, end + 10)
        plt.xticks(range(start, end, step))
    elif axe == 'y':
        plt.ylim(start - 10, end + 10)
        plt.yticks(range(start, end, step))
    else:
        print("Wrong axe was gived. Can't do slicing operation")
    return


def set_plot_legend(x_label=None, y_label=None, title=None):
    '''Set the axes legend before building the plot'''
    if not x_label or not y_label or not title:
        print("Error setting legend. Please check you gave all the\
        information")
        return
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)


def build_plot(dataframe):
    '''Configure the plot (axes, legend, scale), build the plot and display
    it
    '''
    if dataframe.empty:
        raise DataFrameError
    x_axe, y_axe = get_axes(dataframe)
    slice_axes('x', 1800, 2100, 40)
    legend_y = "Life Expectancy"
    legend_x = "Years"
    title = "France Life expectancy Projections"
    set_plot_legend(legend_x, legend_y, title)
    plt.plot(x_axe, y_axe)
    plt.show()


def main():
    '''Main function: 
        - Load a DataFrame from a .csv file
        - Extract specific data from the DataFrame, in that case, all the data
        relative to France
        - Build the plot from the data extracted
        - Error handling
    '''
    try:
        df = get_data_frame('life_expectancy_years.csv')
        spe_country = get_specific_country('France', df)
        build_plot(spe_country)
    except DataFrameError as e:
        print(str(e))
    except EOFError:
        print("EOF detected, end of program")
    except KeyboardInterrupt:
        print("Program has been interrupted by signal CTRL + C")


if __name__ == '__main__':
    main()
