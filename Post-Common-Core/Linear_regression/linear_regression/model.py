from ploting import build_plot
from ft_linear_regression import ft_linear_regression
from utils import create_json_file, invert_standardisation
import pandas as pd


def main():
	try:
		theta0 = 0
		theta1 = 0
		theta0, theta1, mileage, price = ft_linear_regression(theta0, theta1)
		theta0, theta1 = invert_standardisation(theta0, theta1, mileage, price)
		create_json_file(theta0, theta1)
	except FileNotFoundError as e:
		print(f"{type(e).__name__}: {e}")
	except KeyboardInterrupt as e:
		print(f"{type(e).__name__}: {e}")
	except pd.errors.ParserError as e:
		print(f"{type(e).__name__}: {e}")
	except Exception as e:
		print(f"{type(e).__name__}: {e}")


if __name__ == '__main__':
	main()