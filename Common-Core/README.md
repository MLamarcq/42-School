# Common-Core - 42 Projects

This repository contains all the projects from the 42 school common core curriculum. These projects cover a range of domains, including system programming, graphics, and web development.

## Technologies Used

- **C**
- **C++**
- **Python**
- **HTML/CSS**
- **JavaScript**
- **Django**
- **PostgreSQL**
- **Docker**
- **Virtual Machines**

## Projects

### Libft

**Libft** is the first project in the 42 common core curriculum. The goal of this project is to re-implement several standard C library functions, which will be useful for other projects throughout the curriculum.

This project helps solidify your understanding of C by implementing functions related to:
- String manipulation
- Memory management
- Linked lists

Implemented functions include:
- `ft_strlen`: Computes the length of a string.
- `ft_strdup`: Duplicates a string.
- `ft_strjoin`: Concatenates two strings.
- `ft_atoi`: Converts a string to an integer.
- And more...

***

### Ft_Printf

**Ft_Printf** involves re-implementing the standard `printf` function from scratch. This project is designed to be used in subsequent projects where the standard `printf` function is not allowed.

Key learning outcomes include:
- Understanding the inner workings of `printf`
- Managing string formatting and conversion
- Calculating sizes and handling hexadecimal conversions
- Gaining a deeper knowledge of address handling

***

### Get_Next_line

**Get_next_line** is designed to read a file and return one line at a time. You can use it within a for or while loop to process the entire file. This program is particularly useful in system programming for reading input or in graphics programming for parsing files used for maps or images.

Key learnings from this project:
- Understanding the `read` function and its usage
- Extracting content from a file line by line
- Gaining a deeper understanding of how file descriptors work
- Managing string concatenation and copying efficiently
- Handling memory leaks

***

### Push_Swap

**Push_Swap** is a project focused on building a number sorting algorithm. The task involved working with two stacks of numbers while adhering to several requirements:

- The arguments must be within the integer range.
- Only numbers are allowed as input.
- A limited number of moves depending on how many numbers you want to sort.
- Only a few types of moves were allowed:
	- Swap: Swap the two numbers on top of a stack.
	- Rotate: Move the number on the top of the stack to the bottom.
	- Rotate both: Rotate the top numbers of both stacks to the bottom simultaneously.
	- Reverse Rotate: Move the number on the bottom of the stack to the top.
	- Reverse Rotate both: Reverse rotate the bottom numbers of both stacks to the top simultaneously.
	- Push: Push the number on top of one stack to the other stack.

Key learnings from this project:

- Parsing numbers from input.
- Developing a sorting algorithm using linked lists.
- Optimizing the algorithm to minimize the number of moves.
- Managing memory leaks.
- Handling errors effectively.

***

### So_long

**So_long** is an introductory graphics project. The goal was to create a 2D game where the player moves a character around a map, collecting all the consumables before exiting the game through an exit point.

The game is built using a .ber file that defines the map layout. The map consists of:

- 0 for empty spaces
- 1 for walls
- C for consumables
- P for the player
- E for the exit

The requirements were:

- The map must be surrounded by walls.
- There must be at least one consumable.
- There must be an exit.
- There must be a player.
- The file extension must be .ber.
- There must be a valid path that allows the player to collect all the consumables and reach the exit.
- The game must be implemented using the `mlx` library.

If any of these conditions are not met, the program displays an error.

Key learnings from this project:

- Extracting a map from a file.
- Parsing the map with string analysis.
- Configuring player movement using key management.
- Creating a game from images.
- Using the `mlx` library.
- Handling errors effectively.
- Managing memory leaks.


***

### Pipex

**Pipex** is a project that introduces the concepts of pipes, processes (child and parent), and environment variables. The challenge was to recreate the behavior of pipes ( `|` ) as seen in `bash`. The program takes an input file, two bash commands, and an output file as arguments.

The conditions were:

- The input file must exist; otherwise, the program returns an error.
- The commands must exist in /usr/bin/ and be executable.
- There should be no memory leaks or unclosed file descriptors, whether in the parent or child process.

Key learnings from this project:

- Manipulating the `pipe`, `access`, `execve`, `dup2`, and `fork` functions.
- Gaining a better understanding of how file descriptors work.
- Learning about process functionality.
- Working with environment variables.
- Developing a deeper knowledge of system programming.
- Handling errors effectively.
- Managing memory leaks.

***

### Minishell

**Minishell** is a project aimed at building a simplified shell based on bash.
Features to Handle:

- Pipes and Multiple Pipes: Support for command piping, allowing the output of one command to be used as input for another.
- File Redirection:
	- Reading (<)
	- Writing (>)
	- Appending (>>)
	- Heredocs (<<)
- Built-in Commands:
	- echo and echo -n: Prints any argument to the specified file descriptor (default is standard output, but can be redirected to a file with > or >>). The -n option suppresses the newline character.
	- cd: Changes the current directory.
	- pwd: Prints the current working directory.
	- env: Displays all environment variables.
	- unset: Deletes the specified environment variable if it exists.
	- export: Sets a new environment variable.
	- exit: Closes the shell, optionally with a specified exit code.
- Execution of Any Bash Command: The shell can execute any external bash command as well.

Key Learnings from This Project:

- Managing multiple child and parent processes.
- Handling numerous file descriptors.
- Parsing input using linked lists.
- Advanced string analysis.
- Perfecting knowledge of system programming.
- Handling errors effectively.
- Managing memory leaks.

***

### Philosophers

**Philosophers** is a project that introduces the concepts of `threads`, `mutexes`, `data races`, and `deadlocks`. The objective is to build a program that uses threads running in an infinite loop (unless an end condition is reached) where threads work together without conflicts, such as data races.

To achieve this, the project presents the classic Philosophers Problem. In this scenario, multiple philosophers, each represented by a thread, are seated around a table. Each philosopher has a fork on their right (each fork is represented by a mutex).

Each philosopher must perform the following actions in order:

- Eat: To eat, a philosopher must have two forks (one from their right and one from their left). This means that a philosopher may need to take a fork from another philosopher, preventing that philosopher from eating.
- Think
- Sleep

When a philosopher is performing one action (eating, thinking, or sleeping), they cannot perform the others.
Requirements for This Project:

- A maximum of 200 philosophers.
- Each philosopher must perform all three actions: eat, think, and sleep.
- Each philosopher has a defined time to eat, sleep, think, and a time before they die.
- A philosopher must eat before their "time to die" expires; otherwise, they die.
- The program must not crash, have memory leaks, or encounter data races.

Key Learnings from This Project:

- Understanding how threads work and their purpose.
- Coding a task simulation program.
- Parsing input data effectively.
- Manipulating time in programming.
- Handling threads in a multithreaded environment.
- Working with mutexes to prevent data races.
- Managing deadlocks and avoiding data races.

***

### Cub3D

**Cub3D** is the second graphic programming project in the 42 curriculum. While So_long focused on coding a 2D game, **Cub3D** introduces the concept of drawing in 3D. The project uses a simple yet fundamental technique in early video game graphics: `ray casting`.

The principle of ray casting involves "casting" rays from the player's position on a 2D map out to the maximum distance until the ray hits a wall. Based on mathematical calculations, when the coordinates of two points (the player and the wall) are known, it's possible to calculate the distance between them.

With the distance calculated, it's easy to determine if the wall is close to or far from the player. Using this information, we can draw a first-person view—essentially simulating a camera from the player's perspective—by applying perspective: the closer the walls are to the player, the larger they will appear on the screen; conversely, the farther away they are, the smaller they will appear.

To create this perspective, the drawing starts from the middle of the window's height, displaying the two halves of the wall in two directions (top and bottom).

***

### C++ Pool


At this stage of the 42 curriculum, students have primarily developed in C programming. Now, it's time to embrace a new technology—C++!

The C++ Pool is a week-long series of exercises designed to introduce students to the C++ language and object-oriented programming. Through these exercises, students will not only learn C++, but also gain a deeper understanding of object-oriented concepts.

All exercises are coded using the C++98 standard.
Pool Structure

The pool starts with the basics of C++, gradually introducing more complex concepts:

- Fundamentals of C++:
	- The namespace std
	- The string class and its methods
	- New features in C++, such as improved handling of standard input and output

- Object-Oriented Programming (OOP):
	- Introduction to classes, objects, and inheritance
	- Use of development tools that were previously prohibited, such as:
		- Error handling with try/catch
		- Conditional control structures with switch/case
		- The for loop

**Advanced Topics**

As the pool progresses, exercises become more challenging and cover more specific topics:

- Templates: Introduction to generic programming with templates.
- Containers: Usage of C++ Standard Library containers such as:
	- `std::vector`
	- `std::list`
	- `std::stack`
	- `std::map`

These containers are applied in specific exercises:

- Using `std::map` to search for data in a CSV file.
- Implementing the Reverse Polish Notation with `std::stack`.
- Recreating the Ford-Johnson algorithm (merge/insert sort) with `std::vector` and `std::list`.

Key Learnings from This Project:

- Mastering C++ and object-oriented programming concepts.

***

### Ft_IRC



## Getting Started

To get started with any of the projects, clone the repository and follow the individual project instructions located in their respective directories.

### Cloning the Repository

```bash
git clone https://github.com/yourusername/common-core.git
cd common-core
