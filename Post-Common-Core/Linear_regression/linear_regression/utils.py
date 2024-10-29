import numpy as np
import json
import os


def create_json_file(theta0=0, theta1=0, cost=0):
	if isinstance(theta0, np.ndarray):
		theta0 = float(theta0[0])
	if isinstance(theta1, np.ndarray):
		theta1 = float(theta1[0])
	res = {"theta1" : theta1, "theta0" : theta0, "cost" : cost}
	with open("../value.json", "w") as file:
		json.dump(res, file)


def get_value_from_file():
	data = {}
	theta0 = 0
	theta1 = 0
	with open("../value.json", "r") as file:
		data = json.load(file)
		theta0 = data['theta0']
		theta1 = data['theta1']
	return theta1, theta0


def standardisation(array):
	if not isinstance(array, np.ndarray):
		raise TypeError("Standardisation must be on a np.ndarray")
	return (array - array.mean(axis=0)) / array.std(axis=0)


def invert_standardisation(theta0, theta1, m, n):
	theta1 = theta1 * (np.std(n, axis=0) / np.std(m, axis=0))
	theta0 = (theta0 * np.std(n, axis=0)) + np.mean(n, axis=0) - theta1 * np.mean(m, axis=0)
	return theta0, theta1

def training_model(theta0, theta1, feature):
	return theta0 + (theta1 * feature)