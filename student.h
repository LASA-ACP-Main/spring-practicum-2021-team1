/*

Definition of Student

*/
#ifndef STUDENT_H
#define STUDENT_H

class Student{

  public:
    
    bool vaccinated;
    double atRisk;
    void addClass(int);
    void removeClass(int);
    int getSchedule();

    Student(){
      vaccinated = false;
      atRisk = 0.0;
      for(int i=0;i<100;i++){
        schedule[i]=0;
      }
    }

    int maxClasses = 100;
    int schedule[100];
};

#endif