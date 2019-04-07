
/* Write a program that takes the length of a rectangular yard and the length and width of a rectangular house situated in the yard. 
 * Your program should compute the time required to cut the grass at the rate of two square feet per second.
 */

#include <stdio.h>

int main(){
  int length_of_yard, width_of_yard, time_to_cut_grass, square_feet_per_second, square_feet_of_yard;
  
  square_feet_per_second = 2;
  
  printf("Enter the length of the yard in feet> \n");
  scanf("%d", &length_of_yard);
  
  printf("Enter the width of the yard in feet> \n");
  scanf("%d", &width_of_yard);
  
  square_feet_of_yard = length_of_yard * width_of_yard;
  
  time_to_cut_grass = square_feet_of_yard / square_feet_per_second;
  
  printf("It waill take %d seconds to cut the grass in a yard of %d square feet\n", time_to_cut_grass, square_feet_of_yard);
  return 0;
}