from load_image import ft_load, ImgError
import numpy as np
from PIL import Image


class ErrorColor(Exception) :
    def __str__(self) :
        return "Error in color. Program handle grey, green, red, blue and invert"


def invert_color(array, height, width) :
    if array.max() <= 1.0:
        return 1.0 - array
    else:
        return 255 - array


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
        case 'grey':
            for row in range(height):
                for col in range(width):
                    grey_value = np.mean(new_arr[row, col, :])
                    new_arr[row, col, 0] = grey_value
                    new_arr[row, col, 1] = grey_value
                    new_arr[row, col, 2] = grey_value
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
    try :
        ft_invert(array)
        ft_red(array)
        ft_green(array)
        ft_blue(array)
        ft_grey(array)
    except ErrorColor as e:
        print(e)

if __name__ == '__main__' :
    main()
