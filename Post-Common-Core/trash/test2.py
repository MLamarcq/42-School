import numpy as np

def main():
	temp = []
	np.random.seed(0)
	a = np.random.randint(0, 100, [10, 5])
	print(a)
	for i in range(a.shape[1]):
		temp.append(a[:, i])
	print(temp)
	tmp = []
	for array in temp:
		tmp.append((array - np.mean(array)) / np.std(array))
	print(len(tmp))
	b = np.zeros(a.shape)
	for i in range(b.shape[0]):
		for j in range(b.shape[1]):
			b[i][j] = tmp[j][i]
	print(b.std(axis=0))

if __name__ == '__main__':
	main()