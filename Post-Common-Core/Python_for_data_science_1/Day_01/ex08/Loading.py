import time
import sys

def print_output(actual, percent, total, length=103):
	bar_length = int(percent * length)
	bar = '=' * bar_length
	spaces = ' ' * (length - len(bar))
	percent_output = percent * 100
	if percent < 1:
		print(f"\r{percent_output:.0f}%|[{bar}{spaces}]| {actual}/{total}", end='', flush=True)
	else:
		bar += '>'
		print(f"\r{percent_output:.0f}%|[{bar}{spaces}]| {actual}/{total}", end='', flush=True)
	if percent == 1:
		print()

def ft_tqdm(lst: range) -> None:
	total = len(lst)
	for i, value in enumerate(lst):
		percent = (i + 1) / total
		print_output(value + 1, percent, total)
		yield value