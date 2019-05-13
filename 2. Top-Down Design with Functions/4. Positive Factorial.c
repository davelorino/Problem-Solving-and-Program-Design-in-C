/* 
 * Find the factorial of any positive integer. 
 * 
 * For any integer > 0, n! is defined as the product n * (n - 1) * (n - 2) ... * 2 * 1.
 * 0! is defined as 1. 
 * 
 * It is sometimes useful to have a closed-form definition instead; for this purpose, an approximation can be used.
 * 
 * R. W. Grosper proposed the following such approximation formula:
 * 
 *    n! = (n^n)(e^-n)sqrt((2n + 1/3)* PI)
 *    
 * Create a program the prompts the user to enter an integer (n), users Gosper's formula to approximate n!, and then displays the result. 
 * 
 * The message displaying the result should look something like this:
 * 
 * 5! equals approximately 119.97003
 * 
 * Your program will be easier to debug if you use some intermediate values instead of trying to compute the result in a single expression.
 * 
 * If you are not getting the correct results, then you can compare the results of your intermediate values to what you get when you do the calculation by hand. 
 * 
 * Use atleast two intermediate variables - one for 2n + 1/3 and one for sqrt(2n + 1/3) * PI.
 * 
 * Display each of these intermediate values to simplify debugging. 
 * 
 * Be sure to use a named constant for PI, and use the approximation 3.14159265. Test the program on nonnegative integers less than 8.
 *    
 */

#include <stdio.h>
#include <math.h>

int main(){
  double n;
  const double PI = 3.14159265;
  double intermediate1, intermediate2, factorial_final;

  double intermediator1(double n);
  double intermediator2(double var1, const double PI);
  double factorialiser(double n, double var2);
      
  printf("Enter any positive integer number>\n");
  scanf("%lf", &n);
  
  intermediate1 = intermediator1(n);
  intermediate2 = intermediator2(intermediate1, PI);
  factorial_final = factorialiser(n, intermediate2);
  
  printf("The integer you enered was %.0lf\nThe factorial of %.0lf is approximately %lf.\n", n, n, factorial_final);
}

double intermediator1(double n){
  double var1;
  var1 = (1.0 / 3.0) + (2.0 * n);
  return var1;
}

double intermediator2(double var1, const double PI){
  double var2;
  var2 = sqrt(var1 * PI);
  return var2;
}

double factorialiser(double n, double var2){
  double factorial;
  factorial = (pow(n, n) * exp((n * -1.0))) * var2;
  return factorial;
}












