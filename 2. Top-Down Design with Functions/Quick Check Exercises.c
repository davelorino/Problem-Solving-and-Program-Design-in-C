/* Chapter 3 - Top-Down Design with Functions 
 * Quickk Check Exercises
 */

#include <stdio.h>

int main(){
  printf("Ch3 Q1 - Developing a program from its documentation means that every statement has a comment. True or False?\n");
  printf("Answer:\tFalse\n\n");
  
  printf("Ch3 Q2 - A conversion of type double to type int will result in the loss any fractional part. True or False?\n");
  printf("Answer:\t True\n\n");
  
  printf("Ch3 Q3 - Write the following expression as a C assignment statement using functions exp, log and pow:\nx = e(^w+log n) + r^2");
  printf("Answer:\t x = exp(w+log(n)) + pow(r, 2)\n\n");
  
  printf("Ch3 Q4 - What is the purpose of a function argument?\n");
  printf("Answer\t It gives the function something to operate on.\n\n");

  printf("Ch3 Q5 - Each function is executed in order of appearance in the source file. True or False?\n");
  printf("Answer:\t False.");
  
  printf("Ch3 Q6 - How is a function in a C program executed?\n");
  printf("When it is declared in the main function.\n\n");
  
  printf("Ch3 Q7 - What is a formal parameter?\n");
  printf("Answer:\t A formal parameter is used in a function declaration to represent a corresponding argument.\n\n");
  
  printf("Ch3 Q8 - Explain how a structure chart differs from an algorithm.\n");
  printf("Answer:\t A structure chart shows the subordinate relationships between subproblems;\nAn algorithm lists the sequence in which the subproblem solutions are carried out.\n\n");
  
  printf("Ch3 Q9 - What does the following function print?\n");
  printf("Answer:\t It prints a square of hash symbols.\n\n");
  
  printf("Ch3 Q10 - What does the following function do?\n");
  printf("Answer:\t It calls the shape function with zero parameters four times and then quits.\n\n");
  
  printf("Ch3 Q11 - What will happen if an actual argument that contains the addition of two type double variables is passed to a type int formal parameter?\nWhat will happen if it is passed to a type double formal parameter?\n");
  printf("Answer:\t In the first case it will lose its decimal information, in the second case it will retain it.\n\n");
  
  
}
