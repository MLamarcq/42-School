import pandas as pd
import matplotlib.pyplot as plt

def check_arg(file) :
	data = pd.read_csv(file)
	return data


def load(file) :
	try :
		data = check_arg(file)
		print(f"Loading dataset of dimensions {data.shape}")
		head = data.head()
		tail = data.tail()
		return (data)
	except FileNotFoundError : 
		print("File not found")
	except pd.errors.ParserError :
		print("The file is not correct")
	except Exception as e:
		print(f"Une erreur s'est produite : {e}")
	return None
