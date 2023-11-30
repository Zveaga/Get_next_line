# Get_next_line

The goal of this project is to write a function that reads a text file pointed to by the file descriptor and returns a single line. Repeated calls to the `get_next_line` function should read and return the entire text file, one line at a time.

## Return Value
Get_next_line returns a `single line` if successful. It returns `NULL` if there is nothing else to read or an error occurred 

## Key Concepts
- Memory management
- Static variables
- String manipulation

## How To Use
Clone the repository:
```
git clone git@github.com:Zveaga/Get_next_line.git
```
Move inside the directory:
```
cd Get_next_line
```
Compile:
```
make
```
This will create an executable called `get_next_line`.

Run it:
```
./get_next_line
```
A sample text file will be displayed to the terminal. You can use any text file of your choosing. The provided one is just an example for you to see the function's output.

To read any text file, replace `text.txt` in the [main.c](https://github.com/Zveaga/Get_next_line/blob/master/main.c) file with the name of the text file you want to read. 

Keep in mind that the entire text file will be displayed in my example. In [main.c](https://github.com/Zveaga/Get_next_line/blob/master/main.c), the function gets called from inside a while loop until `line` becomes NULL, indicating the end of the text file. If you wish to only return a single line at a time, call the function from outside a while loop.

Happy file reading!
