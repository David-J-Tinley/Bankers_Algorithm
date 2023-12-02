# Operating Systems Project 2

Project 2 deals with deadlock avoidance using the banker's algorithm.

- David J Tinley
- 11/30/2023

## Overview

For this project we had to consider a system with 5 processes `(P_0, P_1, P_2, P_3, and P_4)`. The system also has 3 resources of types A, B, and C. From my understanding we then had to create a text file that would read in the allocated types and quantity assigned to each process. So the text file would essentially represent a 2D array, for example:<br>
`{`<br>
`{0, 1, 0},`<br>
`{1, 3, 2},`<br>
`{2, 1, 0},`<br>
`{2, 1, 2},`<br>
`{1, 1, 0},`<br>
`}`<br>
I assumed that we did not want to change maximum values that were described in the assignment description. I had to get some help with using and trying to understand the implementation of the bankers algorithm. I was able to find a resource at <https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/>. The example and description from this site used the same table as our assignment so that helped a lot.

## Features

The main feature that was added was the ability to read in from a file and assign the read in integers the program. Like I mentioned above, it was my understanding that we would only want to change the allocated resources of the program and not change the maximum. So the integers in the text file are structured in the same way as a 2D array.<br>
`0 1 0`<br>
`1 3 2`<br>
`2 1 0`<br>
`2 1 2`<br>
`1 1 0`<br>
It is _very important_ that the formatting of the integers in the text file are the same as above. The integers must also have a space between them as well, otherwise the they will be read in as a single integer.

## Usage

To use this program you must first compile it. You can do this by simply using the `Makefile` that is provided. Run `make main` in the project directory and it will compile the program with `gcc` or `clang` (if you are on macOS). After the program is sucessfully compiled you can run `./main allocated.txt` in the project folder. Be sure to add the `allocated.txt` file as the command line argument as that is where the program data is read from. To see different results you can edit the text file and replace the integers with different values. As said above, be sure to use the same format that is shown when changing the values in the text file. Afterwards you can run `make clean` in the project directory to remove the executable and dot files from the directory.

## Conclusion

Overall, I found this project to be challenging and I still need to review the algorithm to get a better understanding of how exactly each detail works. But a program like this does help to visualize some of the aspects of the banker's algorithm.
