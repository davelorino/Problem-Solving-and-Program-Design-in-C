
#include <stdio.h>

float celcius_at_depth(float kilometers);
float farenheit(float celcius);

int main(){
  float cel, far, kilometers;
  
  printf("Enter a depth in kilometers>\n");
  scanf("%f", &kilometers);
  
  cel = celcius_at_depth(kilometers);
  
  far = farenheit(cel);
  
  printf("Temperature at a Depth of %i km is:\n", (int)kilometers);
  printf("%i Degrees Celcius\n", (int)cel);
  printf("%i Degrees Farenheit\n", (int)far);
  
  
}

float celcius_at_depth(float kilometers){
  float celcius;
  celcius = (10*kilometers) + 20;
  return celcius;
}

float farenheit(float celcius){
  float faren;
  faren = (celcius*1.8) + 32;
  return faren;
}
