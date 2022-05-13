#ifndef STUDENTQUEUE_H
#define STUDENTQUEUE_H

#include <bits/stdc++.h>
#include "student.h"
#include "linkedlist.h"
#define SIZE 5
#define THRESHOLD 0.75
using namespace std;

struct QNode {
  Student data;
  QNode* next;
  QNode(Student s){
    data = s;
    next = NULL; 
  }
};

class  studentQueue{
  public:
    QNode *front, *rear;
    studentQueue(){
      front = rear = NULL;
    }
    void enQueue(Student s){
      QNode* temp = new QNode(s);
      if (rear==NULL){
        front = rear = temp;
        return;
      }
      rear->next = temp;
      rear = temp;
    }
  
    void deQueue(){
      if(front == NULL){
        return;
      }
      QNode* temp = front;
      front = front->next;
  
      if(front == NULL){
        rear = NULL;
      }
  
      delete temp;
    }
    //TODO: This is the core of our program.
    void studentLineUp(LinkedList * gc){
      Node * currentClass = gc->head;
      while(currentClass != NULL){
        for(int i=0;i<SIZE;i++){
          for(int j=0;j<SIZE;j++){
            if (currentClass->classroom.riskMatrix[i][j]>=THRESHOLD){
              enQueue(*(new Student(currentClass->classroom.ids[i][j],currentClass->classroom.riskMatrix[i][j])));
            }
          }
        }
        currentClass = currentClass->next;
      }
      Node * validClass = gc->head;
      QNode * infectedStudent = front;
      while(infectedStudent != NULL){
        while(validClass != NULL){
          for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
              if(validClass->classroom.ids[i][j]==infectedStudent->data.id){
                validClass->classroom.exposure(infectedStudent->data.id,infectedStudent->data.atRisk);
              }
            }
          }
          validClass = validClass->next;
          deQueue();
        }
        validClass = gc->head;
        infectedStudent = infectedStudent->next;
      }
    }
};

#endif