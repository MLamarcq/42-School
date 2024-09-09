import time
import datetime

def format_time():
	current_time = time.time()
	scientific_notation = "{:.2e}".format(current_time)
	formatted_date = datetime.datetime.fromtimestamp(current_time).strftime("%b %d %Y")
	print(f"Seconds since January 1, 1970: {current_time:.4f} or {scientific_notation} in scientific notation")
	print(f"{formatted_date}$")

if __name__ == "__main__":
	format_time()
