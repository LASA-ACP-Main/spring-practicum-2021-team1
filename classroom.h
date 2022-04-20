/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H

class Classroom{

  public:
    int posGridSize;
    std::string name;
    int positions[100][100];
    int ids[100][100];
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