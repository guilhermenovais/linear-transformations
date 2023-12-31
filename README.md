# Linear Transformations Evaluator

## About
This project involves exploring the dynamics of linear transformations in a playful context in the city of Nlogônia. In these circumstances, children apply such transformations to points on a sheet of paper during different instants of time, associating each moment with a linear transformation matrix that influences the trajectory of the points from birth to disappearance.

The objective is to determine the final position of a point, taking into account the moments of birth and disappearance, as well as the associated transformations. Children have the freedom to modify the transformations throughout the game, making it dynamic. Only the last 8 digits of the final coordinates are considered.

## Implementation
In this project, a segmentation tree was used to pre-compute solutions for subarrays, allowing quick execution of query and update operations.
The Segmentation Tree is an efficient data structure for performing queries and updates on intervals of a dataset. In the context of this problem, SegTree is applied to manage the linear transformations associated with points drawn on a sheet of paper during different instants of time.

## Instructions to compile and execute
To compile the program, simply run the `make all` command.

To run the program, simply execute the command `./bin/tp3.out < teste.txt`.

To clean the ‘.o’ files and the executable, simply run the `make clean` command.

To run tests with Valgrind and gdb, simply run the `make test` command.
