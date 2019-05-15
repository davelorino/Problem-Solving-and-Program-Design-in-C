/*
 * An internet service provider charges its subscribers every month based on the following:
 * 
 * Data Usage (Gbs)          Charges
 * 0.0 < n <= 1.0            250
 * 1.0 < n <= 2.0            500
 * 2.0 < n <= 5.0            1000
 * 5.0 < n <= 10.0           1500
 * n > 10                    2000      
 * 
 * Given the amount of data used by the subscriber (i.e. n), write a program to calculate the charges paid by the subscriber.
 * 
 * Print a message to indicate bad data as well.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void monthly_internet_bill(int data_consumption);

int main(){
  char data_consumption[20];
  char data_consumption_clean[10];
  int data_consumption_int = 0, i;
  int read = 1;
  
  while(read == 1){
  printf("Enter the data consumption for the month>\n");
  scanf("%s", data_consumption);
  
  
  for(i = 0; data_consumption[i] != '\0'; i++){
  if(data_consumption[i] > 47 && data_consumption[i] < 57){
    strcpy(data_consumption_clean, data_consumption);
    data_consumption_int = atoi(data_consumption_clean);
    }
  }
  
    if(data_consumption_int == 0)
    {
      printf("Invalid input - enter a positive number in Gigabytes\n");
    }
    
    else if(data_consumption_int != 0)
    {
      read = 2;
    }
  }
  
  monthly_internet_bill(data_consumption_int);
  
}

void monthly_internet_bill(int data_consumption){
  if(data_consumption > 0 && data_consumption <= 1){
    printf("Your bill is $250\n");
  }
  else if(data_consumption > 1 && data_consumption <= 2){
    printf("Your bill is $500\n");
  }
  else if(data_consumption > 2 && data_consumption <= 5){
    printf("Your bill is $1000\n");
  }
  else if(data_consumption > 5 && data_consumption <= 10){
    printf("Your bill is $2000\n");
  }
  else{
    printf("Please enter a positive number\n");
  }
}

