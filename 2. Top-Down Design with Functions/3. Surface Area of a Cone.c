/* Write a program that prompts the user to enter the radius of the circular base of a cone and the slant height of the cone.
 * 
 * The program must compute the total surface area of a right circular cone and display it back to the user.
 */

#include <stdio.h>
#include <math.h>

int main(){
  const double PI = 3.14159;
  double radius, slant_height; /* Inputs  */
  double SA;        /* Output  */

  double surfaceArea(double radius, double slant_height, const double PI);
  
  printf("Enter the radius of the base of the circle>\n");
  scanf("%lf", &radius);
  
  printf("Enter the slant height of the cone>\n");
  scanf("%lf", &slant_height);
  
  SA = surfaceArea(radius, slant_height, PI);
  
  printf("The radius of the base of the circle is %.2lf, the slant height of the cone is %.2lf and the total surface area of the cone is %.2lf\n", radius, slant_height, SA);
 
}

double surfaceArea(double radius, double slant_height, const double PI){
  double surface_area;
  surface_area = (PI * pow(radius, 2)) + (PI * radius) * (sqrt(pow(slant_height, 2) + pow(radius, 2)));
  return surface_area;
}
