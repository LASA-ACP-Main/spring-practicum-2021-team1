/*

Student class: 

*/
#include <iostream>
#include "student.h"

void Student::addClass(int s){
  for (int i=0; i<maxClasses; i++){
    if (schedule[i] == 0){
      schedule[i] = s;
      break;
    }
  }
}
//*****TODO: THIS IS A TEMPORARY METHOD. DONT USE IT.***
void Student::removeClass(int s){
  for (int i=0; i<maxClasses; i++){
    if (schedule[i]==s){
      schedule[i]=0;
    }
  }
}