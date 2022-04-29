/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H

class Classroom{

  public:
    int posGridSize;
    std::string name;
    int positions[2][2];
    int ids[100][100];
    char riskCategory;
    Classroom(){
      posGridSize = 100;
    }
    Classroom(std::string n){
      posGridSize = 2;
      name = n;
    }
};

#endif