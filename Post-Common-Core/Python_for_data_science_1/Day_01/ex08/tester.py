from tqdm import tqdm
from Loading import ft_tqdm
import time


for i in ft_tqdm(range(333)) :
	time.sleep(0.005)
print()

for i in tqdm(range(333)) :
	time.sleep(0.005)
print()


