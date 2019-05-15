/* 
 * Write a program that demonstrated Cs short-circuit evaluation of the && and || operators. 
 * 
 * Include two user-defined functions, fun1 and fun2. 
 * 
 * Function fun1 should prompt the user to enter T for true or F for false. 
 * 
 * If the user input is T, the function should return 1; otherwise it should return 0;
 * 
 * Function `fun2` should simply display "function 2 executed" and then return 1.
 * 
 * Function `main` should include two conditional statements: "the test of && complete" if the && function calls to f1 and f2 is true. 
 * 
 * The second conditional statement should display "the test of || complete" if the || of calls to fun1 and fun2 is true.
 * 
 * Before the first conditional statement display the message "Testing &&" and before the second, "Testing ||" then test your program four times
 * with inputs TT, TF, FT and FF.
 * 
 * Predict the output of each run before running it to verify your understanding of the short-circuit evaluation of these two operators.  
 */

#include <stdio.h>

#define ASCII_T 84
#define ASCII_F 

int fun1(void);
int fun2(void);

int main(){
  fun1();
  fun2();
  
  
}

int fun1(void){
  char letter;
  printf("Enter a letter\n");
  scanf("%c", &letter);
  
  printf("Testing &&\n");
  
  if(letter == ASCII_T){
    printf("fun1 executed\n");
  }
  else{
    printf("fun1 failed.\n");
  }
  return 0;
}

int fun2(void){
  char letter;
  printf("Enter a letter\n");
  fgetc(stdin);
  scanf("%c", &letter);
  
  printf("Testing ||\n");
  
  if(letter == ASCII_T){
    printf("fun2 executed\n");
  } 
  else{
    printf("fun2 failed.\n");
  }
  return 0;
}