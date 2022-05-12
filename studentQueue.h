#include <bits/stdc++.h>
#include "student.h"
#include "linkedlist.h"

using namespace std;

struct QNode {
  Student data;
  QNode* next;
  QNode(Student s){
    data = s;
    next = NULL; 
  }
};

struct Queue {
  QNode *front, *rear;
  Queue(){
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
  void studentLineUp(LinkedList* gc){
    Node * currentClass = gc->head;
    
  }
}