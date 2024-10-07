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


def transpose_arr_left(array):
    '''Change the array to transpose manually the array for a 90 degrees
    counterclockwise rotation
    '''
    temp = np.squeeze(array)
    rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
    for row in range(temp.shape[0]):
        for col in range(temp.shape[1]):
            rotate_arr[col, row] = temp[row, col]
    return rotate_arr


def transpose_arr_right(array):
    '''Change the array to transpose manually the array for a 90 degrees
    clockwise rotation
    '''
    temp = np.squeeze(array)
    rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
    for row in range(temp.shape[0]):
        for col in range(temp.shape[1]):
            new_row = temp.shape[0] - row - 1
            new_col = temp.shape[1] - col - 1
            rotate_arr[new_col, new_row] = temp[row, col]
    return rotate_arr


def transpose_arr_down(array):
    '''Change the array to transpose manually the array for a 180 degrees
    rotation
    '''
    temp = np.squeeze(array)
    rotate_arr = np.zeros((temp.shape[1], temp.shape[0]), dtype=np.uint8)
    for row in range(temp.shape[0]):
        for col in range(temp.shape[1]):
            new_row = temp.shape[0] - row - 1
            new_col = temp.shape[1] - col - 1
            rotate_arr[new_row, new_col] = temp[row, col]
    return rotate_arr


def main(file):
    '''Main function:
        - Load an image and retruns its array
        - Apply a zoom on it
        - Apply a rotation on it
        - Display the zoomed rotated image
        - Error handling
    '''
    try:
        output = ft_load(file)
        if not output.all:
            return
        print(output[:1])
        zoom_arr = zoom(output)
        rotate_arr = transpose_arr_left(zoom_arr)
        print(f"My new shape after transpose: {rotate_arr.shape}")
        print(f"{rotate_arr}")
        plt.imshow(rotate_arr, cmap='gray')
        plt.show()
    except EOFError:
        print("EOF detected. End of program")
    except KeyboardInterrupt:
        print("Process interrupted. End of program")
    except ImgError as e:
        print(str(e))
    except FileNotFoundError as e:
        print(e)
    except OSError as e:
        print(e)


if __name__ == '__main__':
    main('animal.jpeg')
