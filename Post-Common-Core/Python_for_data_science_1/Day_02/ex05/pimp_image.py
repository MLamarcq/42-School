from load_image import ft_load, ImgError
import numpy as np
from PIL import Image


class ErrorColor(Exception):
    '''Class Error Color for error handling'''
    def __str__(self):
        return "Error in color. Program handle grey, green, red, blue and\
        invert"


def invert_color(array, height, width):
    '''Invert the color of an image by modify the pixel color:
    We subtr'''
    if array.max() <= 1.0:
        return 1.0 - array
    else:
        return 255 - array


def ft_change_color(array, color):
    '''Apply a filter on a image by changing the pixel in array depending
    on a color parameter (a string taht indicate to the function the filter
    to apply)
    '''
    new_arr = np.copy(array)
    height, width = new_arr.shape[0], new_arr.shape[1]
    match color:
        case 'red':
            for row in range(height):
                for col in range(width):
                    new_arr[row, col, 0] *= 1
                    new_arr[row, col, 1] *= 0
                    new_arr[row, col, 2] *= 0
        case 'green':
            for row in range(height):
                for col in range(width):
                    new_arr[row, col, 0] -= new_arr[row, col, 0]
                    new_arr[row, col, 2] -= new_arr[row, col, 2]
        case 'blue':
            for row in range(height):
                for col in range(width):
                    new_arr[row, col, 0] = 0
                    new_arr[row, col, 1] = 0
        case 'grey':
            for row in range(height):
                for col in range(width):
                    grey_value = np.mean(new_arr[row, col, :])
                    new_arr[row, col, 0] = grey_value
                    new_arr[row, col, 1] = grey_value
                    new_arr[row, col, 2] = grey_value
        case 'invert':
            new_arr = invert_color(new_arr, height, width)
        case _:
            raise ErrorColor
    new_arr *= 255
    np.clip(new_arr, 0, 255)
    new_arr = new_arr.astype(np.uint8)
    return new_arr


def convert_to_image_and_display(array):
    '''Convert the final array to a Pillow Image and displays it'''
    img = Image.fromarray(array)
    img.show()


def ft_blue(array):
    '''Apply a blue filter on an image'''
    new_arr = ft_change_color(array, 'blue')
    convert_to_image_and_display(new_arr)


def ft_green(array):
    '''Apply a green filter on an image'''
    new_arr = ft_change_color(array, 'green')
    convert_to_image_and_display(new_arr)


def ft_red(array):
    '''Apply a red filter on an image'''
    new_arr = ft_change_color(array, 'red')
    convert_to_image_and_display(new_arr)


def ft_grey(array):
    '''Apply a blue filter on an image'''
    new_arr = ft_change_color(array, 'grey')
    convert_to_image_and_display(new_arr)


def ft_invert(array):
    '''Inverts the color of the image received'''
    new_arr = ft_change_color(array, 'invert')
    convert_to_image_and_display(new_arr)


def main():
    '''Main function:
       - Load an image and returns its array
       - Display the image
       - Apply all the color filter and display the new images
       - Error handling
    '''
    try:
        array = ft_load('landscape.jpg')
        img = Image.fromarray((array * 255).astype(np.uint8))
        img.show()
        ft_invert(array)
        ft_red(array)
        ft_green(array)
        ft_blue(array)
        ft_grey(array)
    except EOFError:
        print("End of file detected: end of program")
    except ImgError as e:
        print(e)
    except FileNotFoundError as e:
        print(e)
    except OSError as e:
        print(e)
    except KeyboardInterrupt as e:
        print(e)
    except ErrorColor as e:
        print(e)


if __name__ == '__main__':
    main()
