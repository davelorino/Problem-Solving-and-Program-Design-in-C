/*
 * Write a program that takes two numbers points on a cartesian plane and tells the user which quadrant the intersection of those points belongs to.
 */

#include <stdio.h>

int main(){
  int x, y;
  printf("Enter the x coordinate>\n");
  scanf("%d", &x);
  
  printf("Enter the y coordinate>\n");
  scanf("%d", &y);
  
  if(x == 0){
    printf("X-Axis\n");
  }
  else if(y == 0){
    printf("Y-Axis\n");
  }
  else if(x > 0 && y > 0){
    printf("Quandrant 1.\n");
  }
  else if(y < 0 && y > 0){
    printf("Quadrant 2.\n");
  }
  else if(x < 0 && y < 0){
    printf("Quadrant 2.\n");
  }
  else if(x > 0 && y < 0){
    printf("Quadrant 4.\n");
  }
  return 0;
}