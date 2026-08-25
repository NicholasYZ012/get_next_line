*This project has been created as part of the 42 curriculum by \<nilim>*

# Description
get_next_line is a function that is able to read and return lines in a file

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
3. The chars stored in a persistent storage starting from the first non-newline char until a newline char are returned as a string.

## Methods

### Persistent string
The buffers after each read are strjoin-ed into a long string that acts as persistent storage.<br>
Returned string: strtrim the persistent string from the first char until the next newline char.

### Linked list
Each read causes the linked list to be expanded with a number of nodes equal to the size of chars successfully read.<br>
Returned string: strjoin-ing the chars at each node starting from the first node until the newline char.

# Resources


