import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from load_csv import load

class DataFrameError(Exception) :
	def __str__(self) :
		return "Error occured with Data Frame. End of program"

def get_daframe(file) :
	dataframe = load(file)
	if dataframe.empty :
		raise DataFrameError
	return dataframe

def convert_string_to_float(element):
	if isinstance(element, str) :
		if 'M' in element : 
			return float(element.replace('M', '').replace(',', '')) * 1e6
		elif 'B' in element :
			return float(element.replace('B', '').replace(',', '')) * 1e9
		elif 'k' in element :
			return float(element.replace('k', '').replace(',', '')) * 1e3
		return float(element.replace(',', ''))
	return np.nan

def get_specific_date(dataframe, date, code) :
	match code :
		case 'life': 
			specific_date = dataframe.loc[:, date]
			if not isinstance(specific_date, pd.Series) :
				raise DataFrameError
			specific_date.dropna(axis=0, how='any', inplace=True)
			specific_date = specific_date.astype(np.uint8)
		case 'income' :
			specific_date = dataframe.loc[:, date]
			if not isinstance(specific_date, pd.Series) :
				raise DataFrameError
			specific_date = specific_date.apply(convert_string_to_float)
			specific_date.dropna(axis=0, how='any', inplace=True)
	return specific_date


# def define_axes(dataframe_1, dataframe_2) :


def main() :
	try: 
		dataframe_1 = get_daframe('life_expectancy_years.csv')
		dataframe_2 = get_daframe('income_per_person_gdppercapita_ppp_inflation_adjusted.csv')
		life_expectancy = get_specific_date(dataframe_1, '1900', 'life')
		income = get_specific_date(dataframe_2, '1900', 'income')
	except DataFrameError as e :
		print(str(e))
	except KeyError as e:
		print(f"Key error in DataFrame: {str(e)}")
	except KeyboardInterrupt :
		print("Signal SIGINT : end of program")


if __name__=='__main__':
	main()