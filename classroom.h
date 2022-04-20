/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "student.h"

class Classroom{

  public:
    int posGridSize;
    std::string name;
    int positions[100][100];
    Student ids[100][100];
    char riskCategory;
    Classroom(){
      posGridSize = 100;
    }
    Classroom(std::string n){
      posGridSize = 100;
      name = n;
    }
};

#endif