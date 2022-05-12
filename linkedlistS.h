#ifndef _LINKEDLISTS_H_
#define _LINKEDLISTS_H_
#include <string>
using namespace std;
#include <bits/stdc++.h>
#include "student.h"
#include "linkedlist.h"
struct NodeS {
        Student student;
        NodeS *next;
  };
class LinkedListS{

  public:


  NodeS* head;
  NodeS* tail;

  LinkedListS(){
        head = NULL; // set head to NULL

        NodeS *newNode = new NodeS();
        newNode->student = *new Student();
    
  } 
  LinkedListS(const Student c){
      NodeS* head = NULL;
      head = NULL;
      
      NodeS *newNode = new NodeS();
      newNode -> student = c;
  }
  void add(Student c){
    NodeS *newNode = new NodeS();
    newNode -> student = c;
    if(head == nullptr){
      head = newNode;
      tail = head;
    }
    else{
      tail -> next = newNode;
      tail = tail->next;
    }
  }
  void clear(){
    NodeS* temp = head;

    while(temp->next != NULL){ // Iterating through linked list
      NodeS* tempDelete = temp->next;
      temp = temp -> next;
      delete tempDelete; // Iterating
    }
  }
  NodeS* get(int index){
    NodeS* temp = head;
    int count = 0;
    while(temp != NULL){
      if(count == index){
        return temp; // Return pointer
      }
      count++;
      temp = temp->next;
    }
    return temp;
  }


  void display(){
    NodeS* temp = head;

    while(temp != NULL){ // Iterating through linked list
      std::cout << temp->student.id << '\n';
      temp = temp->next;
    }
  }


  void insert(int index, Student c){
      
    NodeS *newNode = new NodeS();
    newNode -> student = c;

    NodeS* temp = newNode;
    NodeS* current = head;

    int count = 0;
    int tInd = index;

    if(index == 0){
      temp->next = head; // Changing addresses if 0
      head = newNode;
    }
    else if(index == size()-1){
      add(c);
    }
    else{
      NodeS* curr = head;
      NodeS* prev = NULL;

      int count = 0;

      while (count < index) {
          prev = current; // Moving current back
          current = current->next; // Basically setting prev and current to what they should be before index

          if (current == NULL) { // If not equal to anything
              break;
          }

          count++;
      }

      newNode->next = current; // The value after inserted node 
      prev->next = newNode; // Value before inserted nnode

    }

  }
  //Switches the payload data of specified indexex.
    void exchg(int index1, int index2)	{
      NodeS* ind1 = get(index1);
      NodeS* ind2 = get(index2);
      NodeS* temp = ind1;

      ind1 = ind2;
      ind2 = temp;
    }	

    //Swaps node located at index1 with node at index2
    void swap(int index1, int index2){
      NodeS* prevN1 = get(index1);
      NodeS* prevN2 = get(index2);

      NodeS* temp1 = head;
      NodeS* temp2 = head;

      if(prevN1 == prevN2){ // If nodes are same, don't swap
        return;
      }

      while((temp1 != NULL) && (temp1!=get(index1))){
        prevN1 = temp1; // Moving prev for index1 to correct spot
        temp1 = temp1->next;
      }

      while((temp2 != NULL) && (temp2=get(index2))){
        prevN2 = temp2; // Moving prev for index2 to correct spot
        temp2 = temp2->next;
      }

      
      if(temp1 != NULL && temp2 != NULL){
        if(prevN1 != NULL){
          prevN1 -> next = temp2; // Basically pointing previous node for n1 to n2
        }
        else{ // Which means that it's head
          head = temp2;
        }

        if(prevN2 != NULL){
          prevN2 -> next = temp1; // Basically pointing previous node for n2 to n1
        }
        else{ // Which means that it's head
          head = temp1;
        }


        NodeS* tempSwap = temp1->next;   // Before swapped the prevs, now swapping the nexts
        temp1->next = temp2->next;   
        temp2->next = tempSwap;  
      }
    }

    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty(){
      return this->head == NULL; // Checking if head is null
    }

    //Removes the element at the specified index from this list.
    void remove(int index) {
      NodeS* temp = head;
      int count = 0;

      if(index == 0){
        head = head->next;
      }
      else if (index == size()-1){
        NodeS* last = get(size() - 2);
        last -> next = NULL;
      }
      else{
        NodeS* current = get(index - 1);
        NodeS* after = get(index + 1);
        current->next = after;
      }

    }
  void set(int index, Student c){
      
      NodeS* thatNode = get(index);
      thatNode -> student = c;

    }


    int size() { //Returns the number of elements in this list.
      
      int count = 0;
      NodeS* temp = head;
      
      while(temp != NULL){ // Iterating through linked list until it reaches end
        temp = temp->next; // Iterating
        count++;
      }

      return count;
    }		



    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    vector<NodeS*> subList(int start, int length){
      
      NodeS* temp = head;
      vector<NodeS*> vec = {};
      vector<NodeS*> vecFinal = {};
      

      while(temp != NULL){ // Iterating through linked list until it reaches end
          vec.push_back(temp);
          temp = temp->next; // Iterating 
      }

      for(int i = start; i < start+length; i++){
        vecFinal.push_back(vec.at(i));
      }

      return vecFinal;
    }
};

#endif 		//_LINKEDLISTS_H_