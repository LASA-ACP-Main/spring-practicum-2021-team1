/*

Definition of Student

*/
#include "linkedlist.h"
#include "classroom.h"

#ifndef STUDENT_H
#define STUDENT_H

class Student{

  public:
    
    bool vaccinated;
    int id;
    double atRisk;
    void addClass(int);
    void removeClass(int);
    void displaySchedule();
    int getSchedule();
    LinkedList schedule;
    Student(){
      vaccinated = false;
      atRisk = 0.0;
      LinkedList *schedule = new LinkedList();
    }
    int maxClasses = 100;
    
};

#endif