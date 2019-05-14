/*
 * Write a program that calculates the users Body Mass Index (BMI) and categorises it as underweight, normal, overweight or obese., based on the following:
 * 
 * Below 18.5         Underweight
 * 18.5 - 24.9        Normal
 * 25.0 - 29.9        Overweight 
 * 30.0 and above     Obese
 * 
 * To calculate BMI based on weight in pounds (wt_lb) and height in inches (ht_in) use this formula:
 * 
 * bmi = (703 * wt_lb) / pow(ht_in, 2)
 */

#include <stdio.h>

int main(){
  float ht_in, wt_lb, bmi;
  
  printf("Enter your weight in pounds>\n");
  scanf("%f", &wt_lb);
  
  printf("Enter your height in inches>\n");
  scanf("%f", &ht_in);
  
  bmi = (703 * wt_lb) / (ht_in * ht_in);
  
  if(bmi < 18.5){
  printf("Your BMI is %.2f which makes you underweight.\n", bmi);
  }
  else if(bmi >= 18.5 && bmi < 25){
    printf("Your BMI is %.2f which makes you normal.\n", bmi);
  }
  else if(bmi >= 25 && bmi < 30){
    printf("Your BMI is %.2f which makes you overweight.\n", bmi);
  }
  else if(bmi >= 30){
    printf("Your BMI is %.2f which makes you obese.\n", bmi);
  }
  return 0;
}



