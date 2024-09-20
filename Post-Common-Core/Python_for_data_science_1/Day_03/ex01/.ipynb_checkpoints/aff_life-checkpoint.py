import seaborn as sns
from load_csv import load
import numpy as np
import pandas as pd

class DataFrameError(Exception) :
	def __str__(self) :
		return "An error occurs with DataFrame. End of program"


def get_data_frame(file) :
	df = load(file)
	return df

def get_specific_country(country, df) :
	if df.empty : 
		raise DataFrameError
	spe_country = df.groupby(['country']).get_group((country,))
	if not isinstance(spe_country, pd.DataFrame):
		raise DataFrameError
	test = spe_country.loc[:, ['1800', '1801']]
	sns.pairplot(test)
	print("test = ", type(test))
	return spe_country


def main() :
	try :
		df = get_data_frame('life_expectancy_years.csv')
	# print(df.head(), df.tail())
	# print(type(df))
		spe_country = get_specific_country('France', df)
		# print(spe_country.head())
		# sns.pairplot(spe_country)
	except DataFrameError as e :
		print(str(e))


if __name__=='__main__' :
	main()


# sns.pairplot(df)