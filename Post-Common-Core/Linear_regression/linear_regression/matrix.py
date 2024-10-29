import pandas as pd
import numpy as np

class myMatrix:
	def __init__(self, dataframe=None):
		if not isinstance(dataframe, pd.DataFrame):
			raise TypeError("Error from myMatrix class, failure load df")
		if not dataframe.empty:
			self.m = dataframe.shape[0]
			self.n = dataframe.shape[1] - 1
			self.matrix = np.ones((self.m, self.n + 1))
		if not isinstance(self.matrix, np.ndarray):
			raise TypeError("Failure to load np.ndarray in class myMatrix")
