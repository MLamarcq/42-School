import matplotlib.pyplot as plt


def format_to_plot(value, pos):
	if value >= 1e3:
		return f"{value / 1e3:.0f}k"
	return f"{value}"


def build_plot(m, n, prediction):
	x, y = m, n
	plt.scatter(x, y, c='blue', alpha=1, marker='o')
	plt.plot(x, prediction, c='red', label="linear_regression")
	plt.xlabel("Car Milage")
	plt.ylabel("Car Price")
	plt.title("Car Price Define By Mileage")
	plt.legend()
	plt.show()


def initialise_interactiv_plot(m, n, prediction):
	x, y = m, n
	plt.ion()
	fig, ax = plt.subplots()
	ax.scatter(x, y, c='blue', alpha=1, marker='o', label="real_data")
	line, = ax.plot(x, prediction, c='red', label="linear_regression")
	ax.set_xlabel("Car Milage")
	ax.set_ylabel("Car Price")
	ax.set_title("Car Price Define By Mileage")
	ax.legend()
	return line


def interactiv_plot(prediction, line):
	line.set_ydata(prediction)
	plt.pause(0.01)


def end_intereactiv_plot():
	plt.ioff()
	plt.show()
