/* The Pythagorean theorem states that the sum of the squares of the sides of a right triangle is equal to the square of the hypotenuse. 
 * For example, if two sides of a right triangle have lengths of 3 and 4, then the hypotenuse must have a length of 5. Together, the integers 3, 4 and 5 
 * form a Pythagorean triple. There are an infinite number of such triples. Given two positive integers, m and n, where m > n, a Pythagorean triple can be generated 
 * by the following formulas: 
 *      side 1 = m^2 - n^2
 *      side 2 = 2mn
 *      hypotenuse = m^2 + n^2 
 */

#include <stdio.h>

int main(){
  int m, n, side1, side2, hypotenuse;
  
  printf("Enter an integer>\n");
  scanf("%d", &m);
  
  printf("Enter another integer>\n");
  scanf("%d", &n);
  
  side1 = (m * m) - (n * n);
  side2 = 2 * (m * n);
  
  hypotenuse = (m * m) + (n * n);
  
  printf("The Pythagorean triple of these integers is %d, %d and %d\n", side1, side2, hypotenuse);
}