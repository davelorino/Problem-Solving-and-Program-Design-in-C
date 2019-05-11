#include <stdio.h>
#include <math.h>

/* Ch2 Quick Check Exercises */
 
 int main(){
 
 /*Ch2 Quick Check 1. What type of information shod be specified in the block comment at the very beginning of the program? */
 
 printf("Ch2 Quick Check 1. What type of information shod be specified in the block comment at the very beginning of the program?\n");
 printf("Answer:\t It should explain what the program does.\n\n");

 /*Ch2 Quick Check 2. Which variables below are syntactically correct? */
  
 printf("Ch2 Quick Check 2. Which variables below are syntactically incorrect?\n");
 printf("\t\tMAX\t\tpeta\n\t\t_mid\t\thashpercentsymbol\n\t\tdouble\t\told avg\n\t\tvar@\t\t#num\n\n");
 printf("Answer:\t _mid, haspercentsymbol, double, old avg, var@ and #num\n\n");

 /*Ch2 Quick Check 3. What is the output of the following program fragment? */
  printf("Ch2 Quick Check 3. What is the output of the following program fragment?\n");
  printf("Answer:\t Value of p = 20, value of l = 6\n\n");
  
  /*Ch2 Quick Check 4. Stylistically, which of the following identifiers would be good choices for names of constant macros? */
  printf("Ch2 Quick Check 4. Stylistically, which of the following identifiers would be good choices for names of constant macros?\n");
  printf("gravity, G, MAX_SPEED, Sphere_Size\n");
  printf("Answer:\t G, MAX_SPEED\n\n");
  
  /*Ch2 Quick Check 5. Write the data requirements, necessary formulas, and algorithms for Programming Project 9 in the next section */
  printf("Ch2 Quick Check 5. Write the data requirements, necessary formulas, and algorithms for Programming Project 9 in the next section\n");
  printf("Data Requirements:\t\t length and width of yard (two integers), square feet of the yard (double/float), time (double/float)\n");
  printf("Necessary formula:\t\t Time it takes to mow grass is two square feet per second\n\n");
  
  /*Ch2 Quick Check 6. The average pH of citrus fruits is 2.2, and this value has been stored in the variable avg_citrus_pH. Provide a statement to display this information in a readable way.\n*/
  printf("Ch2 Quick Check 6. The average pH of citrus fruits is 2.2, and this value has been stored in the variable avg_citrus_pH. Provide a statement to display this information in a readable way.\n");
  static double avg_citrus_pH = 2.2;
  printf("The average pH levels of citrus fruit is: %.2lf\n\n", avg_citrus_pH);
  
  /* Ch2 Quick Check 7. List the three standard data types of C/n*/
  printf("Ch2 Quick Check 7. List the three standard data types of C/n");
  printf("Int, Char, Double\n\n");
  
  /* Ch2 Quick Check 8. Convert the program statements below to take input and echo it in batch mode\n
   * printf("Enter two characters> ");
   * scanf("%c%c", %c1, &c2);
   * printf("Enter three integers separated by spaces> ");
   * scanf("%d%d%d", &n, &m, &p);
   */ 
  printf("Ch2 Quick Check 8. Convert the program statements below to take input and echo it in batch mode\n");
  printf("Enter two characters> \n");
  char c1, c2;
  scanf("%c%c", &c1, &c2);
  printf("Enter three integers separated by spaces> \n");
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  printf("The values entered were:\n");
  printf("%c, %c, %d, %d, and %d\n\n", c1, c2, x, y, z);
  
  /*Ch2 Quick Check 9. Write an algorithm that finds the area of a rectangle, stores the result in the variable called area, and displays it */
  printf("Ch2 Quick Check 9. Write an algorithm that finds the area of a rectangle, stores the result in the variable called area, and displays it.\n");
  printf("Enter the length of the rectangle> \n");
  double area, length, width;
  scanf("%lf", &length);
  printf("Enter the width of the rectangle> \n");
  scanf("%lf", &width);
  area = length * width;
  printf("The area of the rectangle is: %2.lf\n\n", area);
  
  }