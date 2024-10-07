from load_image import ft_load, ImgError
import matplotlib.pyplot as plt
import matplotlib.image as mpimage
from PIL import Image
import numpy as np


def reshape_array(array):
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
    new_arr = np.mean(arr, axis=2, keepdims=True).astype(np.uint8)
    print(f"New shape after slicing: {new_arr.shape}")  # Devrait être (height, width)
    print(f"{new_arr}")
    return new_arr


def zoom(array):
    arr = reshape_array(array)
    new_arr = change_color(arr)
    return new_arr


def main(file):
    output = ft_load(file)
    print(output[:1])
    
    new_arr = zoom(output)
    try: 
        imgplot = plt.imshow(new_arr, cmap='gray')
        plt.show()
    except EOFError:
        print("EOF detected. End of program")
    except KeyboardInterrupt:
        print("Process interrupted. End of program")


if __name__ == '__main__':
    main('animakkl.jpeg')
