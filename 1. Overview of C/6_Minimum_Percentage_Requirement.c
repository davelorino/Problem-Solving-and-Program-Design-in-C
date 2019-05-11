/* Write a program that predicts the score needed on a final exam to achieve a desired grade in a course.
 * The program should interact with the user as follows:
 * Enter the desired grade> B
 * Enter the minimum average required> 79.5
 * Enter the current average in course> 74.6
 * Enter how much the final counts as a percentage of the course grade> 25
 * 
 * You need a score of 94.20 on the final to get a B.
 */

#include <stdio.h>

int main(){
  char desired_grade;
  float minimum_average_required, current_average, weight_of_final_exam, score_needed_on_final_exam;
  printf("Enter the desired grade>\n");
  scanf("%c", &desired_grade);
  printf("Enter the minimum average required>\n");
  scanf("%f", &minimum_average_required);
  printf("Enter your current average>\n");
  scanf("%f", &current_average);
  printf("Enter how much the final exam counts as a percentage>\n");
  scanf("%f", &weight_of_final_exam);
  score_needed_on_final_exam = minimum_average_required + current_average * (weight_of_final_exam / 100);
  printf("Score needed on final exam is: %f to get a grade of %c\n", score_needed_on_final_exam, desired_grade);
}

