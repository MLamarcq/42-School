from load_image import ft_load, ImgError
import matplotlib.pyplot as plt
import numpy as np


def reshape_array(array):
    '''Reshape the array dimension to crop the image on a specific region.
    Change height and width for a 400x400 pixel image
    '''
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


def change_color(arr):
    '''Turns the color image to gray by using a mean method'''
    new_arr = np.mean(arr, axis=2, keepdims=True).astype(np.uint8)
    print(f"New shape after slicing: {new_arr.shape}")
    print(f"{new_arr}")
    return new_arr


def zoom(array):
    '''Use the reshape array and the change color function to apply a zoom
    on an image and turn its color to grey
    '''
    arr = reshape_array(array)
    new_arr = change_color(arr)
    return new_arr


def main(file):
    '''Main function:
        - Load an image and retruns its array
        - Apply a zoom on it
        - Display the zoomed image
        - Error handling
    '''
    try:
        output = ft_load(file)
        print(output[:1])
        new_arr = zoom(output)
        plt.imshow(new_arr, cmap='gray')
        plt.show()
    except FileNotFoundError as e:
        print(e)
    except ImgError as e:
        print(e)
    except EOFError as e:
        print(e)
    except KeyboardInterrupt:
        print("Process interrupted. End of program")


if __name__ == '__main__':
    main('animal.jpeg')
