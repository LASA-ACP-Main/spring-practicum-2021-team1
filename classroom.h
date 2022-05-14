/*

Definition of Classroom

*/
#ifndef CLASSROOM_H
#define CLASSROOM_H
#define SIZE 5

class Classroom{

  public:
    std::string name;
    int ids[SIZE][SIZE];
    float riskMatrix[SIZE][SIZE];
    char riskCategory;
    int teacherId;
    Classroom(){
    }
    Classroom(std::string n){
      name = n;
    }
    void setPositions(int a[SIZE][SIZE]){
      for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
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
      for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
          std::cout<<ids[i][j]<<" ";
        }
        std::cout << endl;
      }
    }
    void displayRisk(){
      std::cout<<"CLASS: "<<name<<"\t RISK: "<<riskCategory<<endl;
      for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
          float risk = riskMatrix[i][j];
          std::cout << std::fixed << std::setprecision(2);
          std::cout<<ids[i][j]<<": "<<risk<<"\t";
        }
        std::cout << endl;
      }
    }
    void exposure(int id,double risk){
      int r = 0;
      int c = 0;
      for (int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
          if(ids[i][j]==id){
            r = i;
            c = j;
            riskMatrix[i][j]=risk;
          }
        }
      }
      //THIS IS THE ALGORITHM THAT DECIDES RISK
      if(riskCategory == 'H'){
        for (int i=0;i<SIZE;i++){
          for(int j=0;j<SIZE;j++){
            riskMatrix[i][j]=risk;
          }
        }
      }else if(riskCategory == 'M'){
          for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
              if(i==r && j==c){
                riskMatrix[i][j]==risk;
              }
              if(i==r-1 || i==r+1){
                if(riskMatrix[i][c]==0){
                  riskMatrix[i][c]=0.75*risk;
                  try{
                    if(riskMatrix[i][c+1]==0){
                      riskMatrix[i][c+1]=0.75*risk;
                    }
                  }catch(...){
                    continue;
                  }
                  try{
                    if(riskMatrix[i][c+1]){
                      riskMatrix[i][c-1]=0.75*risk;
                    }
                  }catch(...){
                    continue;
                  }
                }
                
              }
              if(j==c-1 || j==c+1){
                if(riskMatrix[r][j]==0){
                  riskMatrix[r][j]=0.75*risk;
                  try{
                    if(riskMatrix[r+1][j]==0){
                      riskMatrix[r+1][j]=0.75*risk;
                    }
                  }catch(...){
                    continue;
                  }
                  try{
                    if(riskMatrix[r+1][j]==0){
                      riskMatrix[r-1][j]=0.75*risk;
                    }
                  }catch(...){
                    continue;
                  }
                }
                
              }
            }
          }
        }else{
            for(int i=0;i<SIZE;i++){
              for(int j=0;j<SIZE;j++){
                if(i==r && j==c){
                riskMatrix[i][j]==risk;
                }
                if(i==r-1 || i==r+1){
                  if(riskMatrix[i][c]==0){
                    riskMatrix[i][c]=0.75*risk;
                  }
                }
                if(j==c-1 || j==c+1){
                  if(riskMatrix[r][j]==0){
                    riskMatrix[r][j]=0.75*risk;
                  
                }
              }
            }
          }    
        }
      }
};

#endif