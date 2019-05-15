/*
 * Write a progam that reports the contents of a compressed-gas cylinder based on the first letter of the cylinders colour. 
 * 
 * The program input is a character representing the observed colour of the cylinder: "Y" or "y" for yellow, "O" or "o" for orange and so on.
 * 
 * Cylinder colours and associated contents are as follows:
 * 
 * orange      ammonia
 * brown       carbon monoxide
 * yellow      hydrogen
 * green       oxygen
 * 
 * Your program should respond to input of a letter other than the first letters of the given colours with the message: contents unknown
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_O 79
#define ASCII_o 111
#define ASCII_B 66
#define ASCII_b 98
#define ASCII_Y 89
#define ASCII_y 121
#define ASCII_G 71
#define ASCII_g 103

int main(){
  char temp_color[100];
  int temp_colour = 79;
  
  printf("Enter the colour of the cylinder>\n");

  scanf("%s", temp_color);
  
  temp_colour = (int)temp_color[0];
  
  printf("String entered: %s\n", temp_color);
  printf("ASCII value of the first letter is: %d\n", temp_colour); 
  
  if((temp_colour - ASCII_O) == 0 || (temp_colour - ASCII_o) == 0)
  {
    printf("Cylinder contains: Ammonia\n");
  }
  else if((temp_colour - ASCII_B) == 0 || (temp_colour - ASCII_b) == 0)
  {
    printf("Cylinder contains: Carbon Monoxide\n");
  }
  else if((temp_colour - ASCII_Y) == 0 || (temp_colour - ASCII_y) == 0)
  {
    printf("Cylinder contains: Hydrogen\n");    
  }
  else if((temp_colour - ASCII_G) == 0 || (temp_colour - ASCII_g) == 0)
  {
    printf("Cylinder contains: Oxygen\n");    
  }
  else{printf("Contents unknown.\n");}
 return 0; 
}
