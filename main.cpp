#include <iostream>
#include  "student.h"
#include  "classroom.h"
#include "linkedlist.h"


int main() {
  Classroom* c = new Classroom("suns in fo");
  LinkedList* l = new LinkedList();
  std::cout << "Hello World!\n";

  //add
  
  l->add(*c);
  std::cout<<l->get(0)->classroom.name;
  l->remove(0);
  if(l->head == nullptr){
    std::cout<<"this code sucks";
  }
  
}