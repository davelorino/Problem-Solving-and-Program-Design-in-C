#include <stdio.h>
#include <math.h>


int main(){
  float p;
  int h;
  
  /* Ch2 Q1 - What value is assigned to the type integer variable p by the statement: p = 3200.0 / 4.0 - 10.0 + 120.0 */ 
  
  printf("Ch2 Q1 - What value is assigned to the type integer variable p by the statement: p = 3200.0 / 4.0 - 10.0 + 120.0\n");
  
  
  p = 3200.0 / 4.0 - 10.0 + 120.0;
  
  printf("The value is %.2lf\n\n", p);
  
  /* Ch2 Q2 What value is assigned to p by the following statement, assuming p is 93.5? Statement: p = p / 0.5 */
  
  printf("Ch2 Q2 - What valus is assigned to p by the following statement, assuming p is 93.5? Statement: p = p / 0.5\n");  
  
  p = 93.5;
  printf("p = %.2lf\n", p);
  p = p / 0.5;
  printf("p = p / 0.5\n");
  printf("p = %.2lf\n\n", p);
  
  /* Ch2 Q3  */
  
  h = 9;
  printf("Ch2 Q3 - Show the exact output form of the output displayed when h is 9\n");
  printf("Four values of h are %2d*%3d*%4d*%d\n\n", h, h, h, h);
  
  /* Ch2 Q4 - Show the exact form of the output line displayed when p is 12.7092 */
  printf("Ch2 Q4 - Show the exact form of the output line displayed when p is 12.7092\n");
  p = 12.7092;
  printf("p = 12.7092\n");
  printf("Four values of p are %3.lf*%5.lf%6.2f*%f\n\n", p, p, p, p);
  
  /* What data types would you use to represent the following items: number of children at school, a letter grade on an exam, the average number of school days a child is absetn each year? */
  
  printf("Ch2 Q5 - What data types would you use to represent the following items: number of children at school, a letter grade on an exam, the average number of school days a child is absetn each year?\n");
  printf("int\nchar\ndouble\n\n");
  
  /* In which step of the software development method are the problem inputs and outputs identified? */
  printf("Ch2 Q6 - In which step of the software development method are the problem inputs and outputs identified?\n");
  printf("Analysis\n\n");
  
  /* Ch2 Q7 - If function scanf is getting two numbers from the same line of input, what characters should be used to seperate them?*/
  printf("Ch2 Q7 - If function scanf is getting two numbers from the same line of input, what characters should be used to seperate them?\n");
  printf("Blanks\n\n");
  
  /* How does the computer determine how many data values to get from the input device when a scanf operation is performed? */
  printf("Ch2 Q8 - How does the computer determine how many data values to get from the input device when a scanf operation is performed?\n"); 
  printf("It depends on the number of placeholders in the input string.\n\n");
  
  /* In an interactive program, how does the user know how many data values to enter when the scanf function is called? */
  printf("Ch2 Q9 - In an interactive program, how does the user know how many data values to enter when the scanf function is called?\n");
  printf("From reading the prompt\n\n");
  
  /* Does the compiler flag syntax or run-time errors? */
  printf("Ch2 Q10 - Does the compiler flag syntax or run-time errors?\n");
  printf("Syntax Errors\n\n");
  
  
  }



