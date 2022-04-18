/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "student.h"

class Classroom{

  public:
    int posGridSize = 100;
    int positions[100][100];
    Student ids[100][100];
    char category;

};

#endif