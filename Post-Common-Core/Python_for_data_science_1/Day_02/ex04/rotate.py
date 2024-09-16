from load_image import ft_load, ImgError
import matplotlib.pyplot as plt
import matplotlib.image as mpimage
from PIL import Image
import numpy as np


def reshape_array(array) :
	height, width, _ = array.shape
	to_crop = 400
	center_x = width / 2 + 145
	center_y = height / 2 - 80

	left = int(center_x - to_crop / 2)
	upper = int(center_y - to_crop / 2)
	right = int(center_x + to_crop / 2)
	down = int(center_y + to_crop / 2)

	temp = array[upper:down, left:right]
	return temp

def change_color(arr) :
	new_arr = np.mean(arr, axis=2, keepdims=True).astype(np.uint8)
	print(f"New shape after slicing: {new_arr.shape}")  # Devrait être (height, width)
	print(f"{new_arr}")
	return new_arr

def zoom(array) :
	arr = reshape_array(array)
	new_arr = change_color(arr)
	return new_arr

def transpose_arr_left(array) :
	temp = np.squeeze(array)
	rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
	for row in range(temp.shape[0]) :
		for col in range(temp.shape[1]) :
			rotate_arr[col, row] = temp[row, col]
	return rotate_arr


def transpose_arr_right(array) :
	temp = np.squeeze(array)
	rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
	for row in range(temp.shape[0]) :
		for col in range(temp.shape[1]) : 
			new_row = temp.shape[0] - row - 1
			new_col = temp.shape[1] - col - 1
			rotate_arr[new_col, new_row] = temp[row, col]
	return rotate_arr

def transpose_arr_down(array) :
	temp = np.squeeze(array)
	rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
	for row in range(temp.shape[0]) :
		for col in range(temp.shape[1]) : 
			new_row = temp.shape[0] - row - 1
			new_col = temp.shape[1] - col - 1
			rotate_arr[new_row, new_col] = temp[row, col]
	return rotate_arr




def main(file) :
	try :
		output = ft_load(file)
		if not output.all :
			return
		print(output[:1])
		zoom_arr = zoom(output)
		# rotate_arr = np.transpose(zoom_arr)
		rotate_arr = transpose_arr_right(zoom_arr)
		print(f"rotate_arr = {rotate_arr}")
		imgplot = plt.imshow(rotate_arr, cmap='gray')
		plt.show()
	except EOFError :
		print("EOF detected. End of program")
	except KeyboardInterrupt :
		print("Process interrupted. End of program")
	except ImgError as e : 
		print(str(e))
	except FileNotFoundError :
		print("File can't be found")
	except OSError :
		print("Wrong file")

if __name__ == '__main__' : 
	main('animal.jpeg')