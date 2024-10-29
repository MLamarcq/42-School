import matplotlib.pyplot as plt
import numpy as np

def init_dicit() -> dict:
	dataset = {f"experience{i}" : np.random.randn(100) for i in range(4)}
	return dataset

# def graphique(dataset: dict):
# 	if not isinstance(dataset, dict):
# 		raise Exception("Error, waiting for a dict")
# 	x = np.arange(0, 100, 1)
# 	color = ['red', 'blue', 'black', 'green']
# 	plt.figure()
# 	for i in range(4):
# 		key = 'experience' + str(i)
# 		y = dataset[key]
# 		plt.subplot(4, 1, i + 1)
# 		plt.plot(x, y, c=color[i])
# 		plt.title(key)
# 	plt.show()

def graphique(dataset: dict):
	if not isinstance(dataset, dict):
		raise Exception("Error, waiting for a dict")
	x = np.arange(0, 100, 1)
	color = ['red', 'blue', 'black', 'green']
	fig, ax = plt.subplots(4, 1, sharex=True)
	for i in range(4):
		key = 'experience' + str(i)
		y = dataset[key]
		ax[i].plot(x, y, c=color[i])
		plt.title(key)
	plt.show()



def main():
	try:
		dataset = init_dicit()
		graphique(dataset)
	except Exception as e:
		print(f"{type(e).__name__}: {e}")

if __name__ == '__main__':
	main()