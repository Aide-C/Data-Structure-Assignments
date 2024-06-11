# Data-Structure-Assignments
These are 5  C++ assignments that I did for my Fall 2021 Data & Structures & Algorithms course at TXST.

## Description 
 
1st assignment: In queueTest.cpp, the main function interacts with the user to test the functionalities of the template class 'myQueue. It prompts the user to specify the maximum size of the queue, then offers options to enqueue (e), dequeue (d), or stop (s). Depending on the user's choice, it enqueues or dequeues integers into/from the queue or exits the program. In myQueue.h, the myQueue class is defined. It includes methods to enqueue, dequeue, check if the queue is empty or full, and determine the current size of the queue. The queue is implemented using an array with dynamic memory allocation.
In stackTest.cpp, there's a demonstration of how to use the myStack class to perform basic stack operations like pushing and popping elements. It also includes a function postfixTest() that utilizes a stack to evaluate postfix expressions entered by the user.
In myStack.h, the myStack class is defined. It provides methods for pushing elements onto the stack, popping elements off the stack, and checking if the stack is empty or full. The stack is implemented using an array with dynamic memory allocation.
The postfix expression evaluation in stackTest.cpp works by iterating through the input expression character by character. If an operand (a digit) is encountered, it's pushed onto the stack. If an operator (+, -, *, /) is encountered, it pops the necessary operands from the stack, performs the operation, and pushes the result back onto the stack. After processing all characters in the expression, the final result is popped from the stack. If the expression is valid, the result is printed; otherwise, an error message is displayed.
 
2nd assignment: This assignment requires implementing three recursive functions without using loops. In hanoi.cpp implements the recursive function moveTower() to solve the Hanoi Tower problem. The output should be a sequence of movements indicating how disks are moved from one peg to another. In pow.cpp implements the recursive function pow() to calculate \( x^y \), handling all cases of \( y \), including negative integers. You've been given a hint to use the observation \( x^y = x \times x^{(y-1)} \) and reminded that \( x^y = 1/(x^{-y}) \) for negative \( y \). In improvedPow.cpp implements the recursive function improvedPow() to calculate \( x^y \) with better runtime. Consider optimizing by avoiding redundant calculations, especially for large values of \( y \) and small values of \( x \). 

3rd assignment: In mergeSort.cpp implement the merge sort algorithm by creating and using the merge() and mergeSort() functions. In quicksort.cpp implement the quick sort algorithm by creating and using the functions swap(), partition(), and quickSort(). 

4th assignment: In the bst.cpp file, we're tasked with implementing functions within a Binary Search Tree (BST) class, called myBST(). Implement public function findInBST() to find a specified value in the BST. We can choose whether to implement it recursively or not. If using recursion, a helper private function find_helper() may be beneficial. Implement public function insertToBST() to insert a new value into the BST. Like findInBST(), you can choose whether to implement it recursively or not, and you may use a helper private function insert_helper() if needed. Implement private functions preOrder(), postOrder(), and inOrder() to perform pre-order, post-order, and in-order traversals of the BST, respectively. They should be recursive functions, and no loops should be used within them.

5th assignment: In the graph.cpp file, we're tasked with implementing functions within a Graph class that uses an adjacent matrix to represent a directed graph. Implement public function BFTraversal() to output a breadth-first traversal of the graph. To achieve this, we need to implement a private function BFS() that performs breadth-first search from a given vertex. In BFTraversal(), we may need to call BFS() multiple times (in loops) to traverse disconnected sub-graphs. When choosing from multiple unvisited vertices, prioritize the one with the lowest index for consistency in grading. We need to use a queue to implement BFS(). Implement this public function DFTraversal() to output a depth-first traversal of the graph. To achieve this, we need to implement a private function DFS() that performs depth-first search from a given vertex. In DFTraversal(), we may need to call DFS() multiple times (in loops) to traverse disconnected sub-graphs. Additionally, we're asked to implement DFS() using recursion. Similar to BFTraversal(), prioritize the lowest index for unvisited vertices.

## Getting Started

### Dependencies

* Visual Studio Code C++ Extension Package
* C++ Compiler - MinGW

### Installing

* Download the zip file on GitHub
* Clone repository
* Fork repository

### Executing program

Use the build/run button on Visual Studio code or C++ development environment (Code::Blocks, DevC++, etc.).

## Author

Aide Cuevas (LinkedIn in profile)

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

## Acknowledgments 

Inspiration, code snippets, etc.
* Mr.Kecheng Yang, TXST Data Structure & Algorithms - CS3358 
