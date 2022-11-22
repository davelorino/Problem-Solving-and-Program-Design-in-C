

/* Write a programm that interact with the user like this: 
* (1) First free service    
* (2) Second free service
* Enter the free service number>> 2
* Enter number of miles>> 3557
* Vehicle must be serviced

* Use the table below to determine the appropriate message:
* Free Services                             Miles (k)
* ---------------------------------------------------------
* First Service                            1500 < k < 3000
* Second Service                           3001 < k < 4500
*/

#include <stdio.h>

int main(){
    
  int status, temp, miles_travelled;
  int free_service_number = 99;

  printf("(1) First Free Service\n");
  printf("(2) Second Free Service\n");
  printf("Enter the Free Service number>>\n");
  
  status = scanf("%d", &free_service_number);
  while((status != 1) | ((free_service_number != 1) & (free_service_number != 2))){
    while((temp = getchar()) != EOF && temp != '\n');
    printf("Invalid input... please enter either a (1) or a (2)\n");
    status = scanf("%d", &free_service_number);
  }

  printf("Enter the number of miles travelled in numeric format>>\n");
  status = scanf("%d", &miles_travelled);
  while( (status != 1)){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf("Enter the miles travelled in numeric format>>\n");
    status = scanf("%d", &miles_travelled);
  }

  if((free_service_number = 1) & (miles_travelled > 1500) & (miles_travelled <= 3000)){
    printf("Vehicle must be serviced.\n");
  }

  else if((free_service_number = 2) & (miles_travelled > 3001) & (miles_travelled <= 4500)){
    printf("Vehicle must be serviced.\n");
  }

  else{
    printf("Vehicle does not qualify for a free service.\n");
  }
	
  return 0;
}