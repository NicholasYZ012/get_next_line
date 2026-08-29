*This project has been created as part of the 42 curriculum by \<nilim>*

# Description
get_next_line is a function that is able to read and return a line from a file descriptor every time it is called. With a precaution to read as little as possible (limited by the buffer size) on each iteration.

# Instructions
A Makefile is included for compiling the library.

Standard commands (Usage: make *command*):
- all(default): compiles the object files, create and insert objects into ft_printf.a
- clean: removes all object files
- fclean: removes the object files and ft_printf.a
- re: updates the library and objects by removing them and recompiling and archiving again

# get_next_line (GNL)
1. When called, GNL uses the read function until it reads a newline char.
2. This means that the buffer it stores read bytes into are checked for the newline char everytime bytes are read.
3. The chars stored in a persistent stash starting from the first non-newline char until a newline char are returned as a string.

> If valgrind outputs a lot of errors, it might be due to buffer values not being initialised completely, causing garbage values to be read

## Methods
### Persistent string
The buffers after each read are strjoin-ed into a long string that acts as the stash.<br>
Returned string: strtrim the persistent string from the first char until the next newline char.

### Linked list
Each read causes the linked list to be expanded with a number of nodes equal to the size of chars successfully read.<br>
Returned string: strjoin-ing the chars at each node starting from the first node until the newline char.

## Ideas
### Linked list
1. Count the amount of nodes created and how many is created before newline is reached. Then, the return string can just merge that amount of nodes without needing to check for newline again. The way to store the ints is also using an array with max size of max amount of file descriptors

## Flaws
Since GNL reads in chunks of the specified buffer size, there will be remainders in the stash or nodes when '\n' is located in the middle of a chunk. In the scenario that GNL is not called again when there are leftovers, the leftovers will be lost memory.

The leftovers can never be freed because:
1. The stash has to be retained across calls to prevent losing read bytes, hence, it cannot be freed from within GNL.
2. The static stash is initialized in GNL, hence it is inaccessible and unable to be freed from main.

To minimize the damage of this inherent bug, GNL has been implemented to read as little as possible the buffer size allows, decreasing the amount of memory lost as much as possible while staying within the confines of the project.

# Resources


