#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <string>
using namespace std;
#include <bits/stdc++.h>

struct Node {
        Classroom classroom;
        Node *next;
  };

class linkedlist{

  public:


  Node* head;
  Node* tail;

  linkedlist(){
        head = NULL; // set head to NULL

        Node *newNode = new Node();
        newNode -> classroom = new Classroom;
    
  } 
  linkedlist(Classroom c){
      Node* head = NULL;
      
      Node *newNode = new Node();
      newNode -> classroom = c;
  }
  void add(Classroom c){
    Node *newNode = new Node();
    newNode -> classroom = c;
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
    Node* temp = head;

    while(temp->next != NULL){ // Iterating through linked list
      Node* tempDelete = temp->next;
      temp = temp -> next;
      delete tempDelete; // Iterating
    }
  }
  Node* get(int index){
    Node* temp = head;
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

  void insert(int index, Classroom c){
      
    Node *newNode = new Node();
    newNode -> classroom = c;

    Node* temp = newNode;
    Node* current = head;

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
      Node* curr = head;
      Node* prev = NULL;

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
      Node* ind1 = get(index1);
      Node* ind2 = get(index2);
      Node* temp = ind1;

      ind1 = ind2;
      ind2 = temp;
    }	

    //Swaps node located at index1 with node at index2
    void swap(int index1, int index2){
      Node* prevN1 = get(index1);
      Node* prevN2 = get(index2);

      Node* temp1 = head;
      Node* temp2 = head;

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


        Node* tempSwap = temp1->next;   // Before swapped the prevs, now swapping the nexts
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
      Node* temp = head;
      int count = 0;

      if(index == 0){
        head = head->next;
      }
      else if (index == size()-1){
        Node* last = get(size() - 2);
        last -> next = NULL;
      }
      else{
        Node* current = get(index - 1);
        Node* after = get(index + 1);
        current->next = after;
      }

    }
  void set(int index, Classroom c){
      
      Node* thatNode = get(index);
      thatNode -> classroom = c;

    }


    int size() { //Returns the number of elements in this list.
      
      int count = 0;
      Node* temp = head;
      
      while(temp != NULL){ // Iterating through linked list until it reaches end
        temp = temp->next; // Iterating
        count++;
      }

      return count;
    }		


    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    vector<Node*> subList(int start, int length){
      
      Node* temp = head;
      vector<Node*> vec = {};
      vector<Node*> vecFinal = {};
      

      while(temp != NULL){ // Iterating through linked list until it reaches end
          vec.push_back(temp);
          temp = temp->next; // Iterating 
      }

      for(int i = start; i < start+length; i++){
        vecFinal.push_back(vec.at(i));
      }

      return vecFinal;
    }
}

#endif 		//_LINKEDLIST_H_