# Get_next_line

The goal of this project is to write a function that reads a text file pointed to by the file descriptor and returns a single line. Repetead calls to the `get_next_line` function should read and return the entire text file, one line at a time.

## Key Concepts
- Memory management
- Static variables
- String manipulation

## How To Use
Clone the repository
```
git clone git@github.com:Zveaga/Get_next_line.git
```
Move inside the Libft directory
```
cd Get_next_line
```
Compile
```
make
```
An executable will be created. If you run it with `./get_next_line`, a test file will be displayed to the terminal. You can use any text file of your choosing, this one is just for seeing output the get_nex_line function.
To use the function, simply replace `text.txt` in the `main.c` file with the name of the file you want to read. Keep in mind that the function returns a single line, if you wish to read an entire text file, call the function inside a `while` loop (see `main.c` for reference).
