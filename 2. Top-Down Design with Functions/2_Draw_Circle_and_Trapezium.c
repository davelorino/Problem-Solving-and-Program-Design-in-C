/* Write to functions, one that displays a circle and one that displays a trapezium.
 * 
 * Use these functions to write a complete C program from the following outline:
 *    int main(void){
 *      draw circle;
 *      draw trapezium;
 *      display one blank line;
 *      draw circle;
 *      draw trapezium;
 *    }  
 */

#include <stdio.h>

int main(void){

  void draw_circle();
  void draw_trapezium();
  
  draw_circle();
  draw_trapezium();
  printf("\n");
  draw_circle();
  draw_trapezium();
}

void draw_circle(){
  printf("    *   \n");
  printf("*       *\n");
  printf("  *   *\n");
}

void draw_trapezium(){
  printf("\\--------\\\n");
  printf(" \\        \\\n");
  printf("  \\--------\\\n");
}