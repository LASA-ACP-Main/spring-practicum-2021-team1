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
    bool hasCovid;
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
    Student(int d,double r){
      vaccinated = false;
      atRisk = 0.0;
      LinkedList *schedule = new LinkedList();
      id = d;
      atRisk = r;
    }
    int maxClasses = 100;
    void testResults(bool result){
      if(result){
        hasCovid = true;
      }
      else{
        hasCovid = false;
      }
    }

};

#endif