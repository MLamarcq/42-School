from PIL import Image
import numpy as np

# img = Image.open('animal.jpeg')

# img.show()

# print(img.format, img.size, img.mode)

# size = (128, 128)

# for infile in sys.argv[1:] :
# 	f, e = os.path.splitext(infile)
# 	outfile = f + ".thumbnail"
# 	if infile != outfile :
# 		try :
# 			with Image.open(infile) as im :
# 				im.thumbnail(size)
# 				im.save(outfile, "JPEG")
# 		except OSError :
# 			print("cannot convert", infile)

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
	print(f"test = {data.shape}")
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
