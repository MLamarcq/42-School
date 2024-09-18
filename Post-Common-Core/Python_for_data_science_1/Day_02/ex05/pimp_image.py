from load_image import ft_load, ImgError
import numpy as np
from PIL import Image


# print(ft_load('landscape.jpg'))

# def ft_change_to_red(array) :
# 	# print(height, width)
# 	new_arr = np.copy(array)
# 	print(f"first = {new_arr}")
# 	height, width = (new_arr.shape[0], new_arr.shape[1])
# 	for row in range(height) :
# 		for col in range(width) : 
# 			new_arr[row, col, 0] *= 1
# 			new_arr[row, col, 1] *= 0
# 			new_arr[row, col, 2] *= 0
# 	new_arr *= 255
# 	np.clip(new_arr,0, 255, out=new_arr)
# 	new_arr = new_arr.astype(np.uint8)
# 	# print("second", new_arr)
# 	return new_arr

# def ft_change_to_green(array) :
# 	new_arr = np.copy(array)
# 	height, width = new_arr.shape[0], new_arr.shape[1]
# 	for row in range(height) :
# 		for col in range(width) :
# 			new_arr[row, col, 0] -= new_arr[row, col, 0]
# 			new_arr[row, col, 2] -= new_arr[row, col, 2]
# 	new_arr *= 255
# 	np.clip(new_arr, 0, 255)
# 	new_arr = new_arr.astype(np.uint8)
# 	return new_arr

class ErrorColor(Exception) :
	def __str__(self) :
		return "Error in color. Program handle grey, green, red, blue and invert"


def invert_color(array, height, width) :
	for row in range(height) :
		for col in range(width) :
			for i in range(3) :
				# count = (128 - array[row, col, i]) + 128
				# if count == 256 :
				# 	count -= 1
				count = 255 - array[row, col, i]
				array[row, col, i] = count
	return array

def ft_change_color(array, color) :
	new_arr = np.copy(array)
	height, width = new_arr.shape[0], new_arr.shape[1]
	match color :
		case 'red' :
			for row in range(height) :
				for col in range(width) : 
					new_arr[row, col, 0] *= 1
					new_arr[row, col, 1] *= 0
					new_arr[row, col, 2] *= 0
		case 'green' : 
			for row in range(height) :
				for col in range(width) :
					new_arr[row, col, 0] -= new_arr[row, col, 0]
					new_arr[row, col, 2] -= new_arr[row, col, 2]
		case 'blue' :
			for row in range(height) :
				for col in range(width) :
					new_arr[row, col, 0] = 0
					new_arr[row, col, 1] = 0
		case 'grey' :
			for row in range(height) :
				for col in range(width) :
					new_arr[row, col, 1] = new_arr[row, col, 0]
					new_arr[row, col, 2] = new_arr[row, col, 0]
		case 'invert' :
			new_arr = invert_color(new_arr, height, width)
		case _ : 
			raise ErrorColor
	new_arr *= 255
	np.clip(new_arr, 0, 255)
	new_arr = new_arr.astype(np.uint8)
	return new_arr


def convert_to_image_and_display(array) : 
	img = Image.fromarray(array)
	img.show()

def ft_blue(array) :
	new_arr = ft_change_color(array, 'blue')
	convert_to_image_and_display(new_arr)


def ft_green(array) :
	new_arr = ft_change_color(array, 'green')
	convert_to_image_and_display(new_arr)

def ft_red(array) :
	new_arr = ft_change_color(array, 'red')
	convert_to_image_and_display(new_arr)

def ft_grey(array) :
	new_arr = ft_change_color(array, 'grey')
	convert_to_image_and_display(new_arr)

def ft_invert(array) :
	new_arr = ft_change_color(array, 'invert')
	convert_to_image_and_display(new_arr)

def main() :
	array = ft_load('landscape.jpg')
	# red_array = ft_change_to_red(array)
	try :
		ft_red(array)
	# green_array = ft_change_to_green(array)
		ft_green(array)
		ft_blue(array)
		ft_grey(array)
		ft_invert(array)
	except ErrorColor as e:
		print(e)

if __name__ == '__main__' :
	main()
