from PIL import Image
import numpy as np


class ImgError(Exception) :
	pass

def check_img_format_and_mode(img) :
	check = ['JPEG', 'JPG']
	if img.format not in check : 
		raise ImgError("Wrong format, format wanted : JPEG and JPG")
	if img.mode != "RGB" :
		new_img = img.convert('RGB')
		print("Original mode of your image was not RGB. It has been converted to RGB")
		return new_img
	return img

def handle_shape(img) :
	height, width = img.size
	print(f"The shape of image is : ({height} {width} 3)")
	return

def get_RGB_return_array(img) :
	data = np.array(img)
	data = data.astype(np.float32) / 255.0
	return data


def ft_load(path: str) -> list:
	try :
		with Image.open(path) as img :
			img = check_img_format_and_mode(img)
			handle_shape(img)
			array = get_RGB_return_array(img)
			return array
	except FileNotFoundError :
		print("File can't be found")
	except OSError :
		print("Wrong file")
	except ImgError as e : 
		print(str(e))
