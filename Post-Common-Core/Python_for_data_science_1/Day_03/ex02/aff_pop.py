import pandas as pd
import numpy as np
from load_csv import load
import seaborn as sns
import matplotlib.pyplot as plt

class ErrorDataFrame(Exception) :
	def __str__(self) :
		return "Error with DataFrame. End of program"

def get_data_frame(file) :
	df = load(file)
	if not isinstance(df, pd.DataFrame) :
		raise ErrorDataFrame
	return df

def get_specific_country(country, dataframe) :
	if dataframe.empty :
		raise ErrorDataFrame
	dataframe = dataframe.iloc[:, :249]
	specific_country = dataframe.groupby(['country']).get_group((country,))
	if not isinstance(specific_country, pd.DataFrame) :
		raise ErrorDataFrame
	return specific_country


def convert_string_to_float(element):
	if isinstance(element, str) :
		if 'M' in element :
			return float(element.replace('M', '').replace(',', '')) * 1e6
		elif 'B' in element:
			return float(element.replace('B', '').replace(',', '')) * 1e9
		elif 'k' in element:
			return float(element.replace('k', '').replace(',', '')) * 1e3
		else :
			return float(element.replace(',', ''))
	return np.nan

def apply_data_conversion(dataframe) :
	if dataframe.empty :
		raise ErrorDataFrame
	dataframe_2 = dataframe.copy()
	for col in dataframe_2.columns[1:] :
		dataframe_2[col] = dataframe_2[col].apply(convert_string_to_float)
	return dataframe_2


def set_dataframe(country, df) :
	if df.empty :
		raise ErrorDataFrame
	dataframe = get_specific_country(country, df)
	if dataframe.empty : 
		raise ErrorDataFrame
	dataframe = apply_data_conversion(dataframe)
	return dataframe

def get_axes(dataframe) :
	if dataframe.empty :
		raise ErrorDataFrame
	x_axe = dataframe.columns[1:]
	y_axe = dataframe.iloc[0, 1:]

	x_axe = [int(label) for label in x_axe]
	y_axe = [float(label) for label in y_axe]

	return (x_axe, y_axe)


def slice_axes(axe, start, end, step) :
	if start > end :
		print("You gave a start higter than end. Can't slice")
		return
	if not step or (step > (end - start)) :
		print("Wrong step configuration. Can't slice")
		return
	if axe == 'x' :
		plt.xlim(start - 10, end + 10)
		plt.xticks(range(start, end, step))
	elif axe == 'y' :
		plt.ylim(start - 10, end + 10)
		plt.yticks(range(start, end, step))
	else : 
		print("Wrong axe was gived. Can't do slicing operation")
	return


def set_plot_legend(x_label=None, y_label=None, title=None) :
	if not x_label or not y_label or not title : 
		print("Error setting legend. Please check you gave all the information")
		return 
	plt.xlabel(x_label)
	plt.ylabel(y_label)
	plt.title(title)

def change_value_for_plot(value, pos) :
	if value > 1e9 :
		return f"{value/1e9:.1f}B"
	elif value > 1e6 :
		return f"{value/1e6:.0f}M"
	return f"{value}"


def build_plot(dataframe, dataframe_2) :
	if dataframe.empty:
		raise ErrorDataFrame
	x1, y1 = get_axes(dataframe)
	x2, y2 = get_axes(dataframe_2)
	slice_axes('x', 1800, 2050, 40)
	slice_axes('y', 0, int(7e7), int(2e7))
	plt.gca().get_yaxis().set_major_formatter(plt.FuncFormatter(change_value_for_plot))
	set_plot_legend("Years", "Population", "Population Projections")
	plt.plot(x1, y1, label="France", color="green")
	plt.plot(x2, y2, label="Belgium", color="blue")
	plt.legend(loc='lower right')
	plt.show()

def main() :
	try :
		df = get_data_frame('population_total.csv')
		france = set_dataframe('France', df)
		belgium = set_dataframe('Belgium', df)
		build_plot(france, belgium)
	except ErrorDataFrame as e :
		print(str(e))
	except KeyError as e:
		print(f"Key error in DataFrame: {str(e)}")
	except KeyboardInterrupt :
		print("Signal SIGINT : end of program")


if __name__=='__main__' :
	main()
