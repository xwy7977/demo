# extern-demo Project

## Overview
The `extern-demo` project is a simple C application that demonstrates the use of global variables across multiple C files. It includes four C files and one header file, showcasing how to declare and use global variables with the `extern` keyword.

## Project Structure
```
extern-demo
├── src
│   ├── main.c
│   ├── var1.c
│   ├── var2.c
│   ├── var3.c
│   └── globals.h
├── Makefile
└── README.md
```

## Files Description

- **src/main.c**: The entry point of the application. It initializes and prints the values of the global variables defined in the other C files.

- **src/var1.c**: Defines a global variable `int var1` and initializes it with a value. It includes `globals.h` to declare the variable as extern.

- **src/var2.c**: Defines a global variable `float var2` and initializes it with a value. It also includes `globals.h` to declare the variable as extern.

- **src/var3.c**: Defines a global variable `char var3` and initializes it with a value. It includes `globals.h` to declare the variable as extern.

- **globals.h**: A header file that declares the three global variables (`int var1`, `float var2`, and `char var3`) using the extern keyword.

## Build Instructions
To build the project, navigate to the `extern-demo` directory and run the following command:

```
make
```

This will compile the C files and link them into an executable.

## Running the Application
After building the project, you can run the application with the following command:

```
./main
```

This will execute the program and display the values of the global variables.