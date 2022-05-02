/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H
#define SIZE 5

class Classroom{

  public:
    std::string name;
<<<<<<< Updated upstream
    int positions[2][2];
    int ids[100][100];
=======
    int ids[SIZE][SIZE];
>>>>>>> Stashed changes
    char riskCategory;
    int teacherId;
    Classroom(){
    }
    Classroom(std::string n){
<<<<<<< Updated upstream
      posGridSize = 2;
=======
>>>>>>> Stashed changes
      name = n;
    }
    void setPositions(int a[SIZE][SIZE]){
      for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
          ids[i][j]=a[i][j];
        }
      }
    }
    Classroom(std::string n, int tId, char rc, int arr[SIZE][SIZE] ){
      name = n;
      setPositions(arr);
      riskCategory = rc;
      teacherId = tId;
    }
    void display(){
      for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
          std::cout<<ids[i][j]<<" ";
        }
        std::cout << endl;
      }
    }
};

#endif