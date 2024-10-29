import numpy as np
import pandas as pd
from utils import standardisation
from matrix import myMatrix
from ploting import build_plot, initialise_interactiv_plot, interactiv_plot, end_intereactiv_plot


def load_dataframe(file):
	df = pd.read_csv(file)
	if not isinstance(df, pd.DataFrame):
		raise TypeError("Failure to generate DataFrame")
	return df


def normalize_values(array):
	if not isinstance(array, np.ndarray):
		print(type(array))
		raise TypeError("Failure to get dataframe from normalize_values")
	return standardisation(array)


def generate_series_standardised(df):
	m = df['km']
	n = df['price']
	if not isinstance(m, pd.Series) or not isinstance(n, pd.Series):
		raise TypeError("Failure to generate Series from dataframe")
	m = normalize_values(np.array(m))
	n = normalize_values(np.array(n))
	return m, n

def generate_normal_series(df):
	m = df['km']
	n = df['price']
	if not isinstance(m, pd.Series) or not isinstance(n, pd.Series):
		raise TypeError("Failure to generate Series from dataframe")
	return m, n


def define_model_matrix(matrix, theta0, theta1):
	matrix[0] = theta1
	matrix[1] = theta0
	return matrix


def calculate_prediction(myMatrix, matrix2):
	return myMatrix @ matrix2


def cost_function(prediction, n):
	return (1 / 2 * prediction.shape[0]) * (np.sum((prediction - n) ** 2))


def gradient(x, prediction, n):
	m = x.shape[0]
	x = np.transpose(x)
	vector = (1 / m) * (x @ (prediction - n))
	return vector


def gradient_descent(vector, matrix2, learning_rate=0.01):
	matrix2 = matrix2 - (learning_rate * vector)
	theta0 = matrix2[1]
	theta1 = matrix2[0]
	return theta0, theta1


def ft_linear_regression(theta0, theta1, max_epochs=1000, tolerance=1e-6):
	cost = []
	
	df = load_dataframe('../data.csv')
	
	x = myMatrix(df)
	matrix2 = np.ones((x.matrix.shape[1], 1))
	
	m, n = generate_series_standardised(df)
	n = n.reshape((n.shape[0], 1))
	
	x.matrix = np.concatenate((m.reshape(m.shape[0], 1), np.ones((m.shape[0], 1))), axis=1)
	matrix2 = define_model_matrix(matrix2, theta0, theta1)
	
	prediction = calculate_prediction(x.matrix, matrix2)
	line = initialise_interactiv_plot(m, n, prediction)

	for _ in range(max_epochs):
		prediction = calculate_prediction(x.matrix, matrix2)
		interactiv_plot(prediction, line)
		cost.append(cost_function(prediction, n))
		if max_epochs > 0 and len(cost) > 1 and abs(cost[-2] - cost[-1]) < tolerance:
			break
		vector = gradient(x.matrix, prediction, n)
		theta0, theta1 = gradient_descent(vector, matrix2)
		matrix2 = define_model_matrix(matrix2, theta0, theta1)
	end_intereactiv_plot()
	build_plot(m, n, prediction)
	mileage, price = generate_normal_series(df)
	return theta0, theta1, mileage, price