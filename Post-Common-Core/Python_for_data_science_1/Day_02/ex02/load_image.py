from PIL import Image
import numpy as np


class ImgError(Exception):
    '''Class ImgError for error handling'''
    pass


def check_img_format_and_mode(img):
    '''Check if the image is in good format and mode'''
    check = ['JPEG', 'JPG']
    if img.format not in check:
        raise ImgError("Wrong format, format wanted: JPEG and JPG")
    if img.mode != "RGB":
        new_img = img.convert('RGB')
        print("Original mode of your image was not RGB.", end='')
        print("It has been converted to RGB")
        return new_img
    return img


def get_RGB_return_array(img):
    # temp = []
    # temp = list(img.getdata())
    data = np.array(img)
    if not isinstance(data, np.ndarray):
        raise ImgError("Error: Array failed setted up")
    print(f"The shape of image is: {data.shape}")
    return data


def ft_load(path: str) -> list:
    try:
        with Image.open(path) as img:
            img = check_img_format_and_mode(img)
            array = get_RGB_return_array(img)
            # img.show()
            return array
    except FileNotFoundError:
        print("File can't be found")
    except OSError:
        print("Wrong file")
    except ImgError as e:
        print(str(e))
