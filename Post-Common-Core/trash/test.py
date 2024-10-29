import numpy as np

def initialisation(m: int, n: int):
	first_array = np.random.randn(m, n)
	print(first_array)
	second_array = np.ones(first_array.shape[0])
	second_array = second_array.reshape(first_array.shape[0], 1)
	print(second_array)
	final_array = np.concatenate((first_array, second_array), axis=1)
	print(final_array)
	print(final_array.shape)

	a = np.array([1, 2, 3])
	print(a.shape, a.size)
	b = np.array([4, 5, 6])
	print(b.shape, b.size)
	a = a.reshape(1, a.shape[0])
	b = b.reshape(1, b.shape[0])
	c = np.concatenate((a, b), axis=0)
	print(c)
	print(c.shape, c.size)
	d = np.vstack((a, b))
	print(d)
	print(d.shape, d.size)





def main():
	initialisation(2, 3)

if __name__ == '__main__':
	main()