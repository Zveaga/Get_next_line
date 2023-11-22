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
Move inside the directory
```
cd Get_next_line
```
Compile
```
make
```
An executable `get_next_line` will be created

Run it
```
./get_next_line
```
A sample text file will be displayed to the terminal. You can use any text file of your choosing. This one is just an example so you can see the output of the function.

To read any text file, replace `text.txt` in the [main.c](https://github.com/Zveaga/Get_next_line/blob/master/main.c) file with the name of the text file you want to read. 

Keep in mind that the entire text file will be displayed in my example. In [main.c](https://github.com/Zveaga/Get_next_line/blob/master/main.c), the function gets called from inside of a while loop until `line` becomes NULL, which means the end of the text file has been reached. If you wish to only return a single line, call the function from outside of a while loop.

Happy text file reading!
