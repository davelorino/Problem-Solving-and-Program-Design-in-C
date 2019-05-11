
/* Write a program that outputs the equation of the perpendicular bisector of the line segment between two points.
 * Your program should:
 *  - prompt for and input the coordinate of the two points [for example, try tge points (2.0, -4.0) and (7.0, -2.0)];
 *  - compute the slope of the line between those two points;
 *  - compute the coordinates of the midpoint of the line segment between the two points by averaging the two x-coordinates and the two y-coordinates;
 *  - compute the slope of the perendicular bisector by taking the negative reciprocal of the slope of the line segment;
 *  - compute the y-intercept of the perpendicular bisector;
 *  - output with labels the original two points, and output in y = mx + b format the equation of the perpendicular bisector.
 *  
 *  Test your program to be sure it works on different pairs of coordinates. However, there will be some pairs of coordinates for which you cant make 
 *  your program work (at least not at this stage). Think about what points will cause your program to fail, and write a paragraph describing which points 
 *  fall in this category. 
 */

#include <stdio.h>

int main(){
  double x1, y1, x2, y2, slope, xmid, ymid, per_bisect, b;
  
  printf("Enter the coordinates for the first point> \n");
  scanf("%lf%lf", &x1, &y1);
  
  printf("Enter the coordinates for the second point> \n");
  scanf("%lf%lf", &x2, &y2);
  
  slope = (y2 - y1)/(x2 - x1);
  
  xmid = (x1 + x2)/ 2;
  ymid = (y1 + y2)/ 2;
  
  per_bisect = -1/(slope);
  
  b = ymid - (per_bisect * xmid);
  
  printf("The coordinates entered were (%.2lf, %.2lf) and (%.2lf, %.2lf).\nThe perpendicular bisect of this line is y = %.2lfx + %.2lf\n", x1, y1, x2, y2, per_bisect, b);
  
}