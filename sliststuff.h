#include <string>
using namespace std;
#include <bits/stdc++.h>


/*
Class Library File
*/
struct Node {
        string iata_code;
        float latitude;
        float longitude;
        string real_code;
        Node *next;
  };


class slist{

  public:


  

    //string type;
    Node* head;
    Node* tail;

    // Constructor
    slist(){
        head = NULL; // set head to NULL

        Node *newNode = new Node();
        newNode -> iata_code = "";
        newNode -> real_code = "";
        newNode -> latitude = 0;
        newNode -> longitude = 0;
    } 
    slist(string c, float la, float lo, string rc){
      Node* head = NULL;
      
      Node *newNode = new Node();
      newNode -> iata_code = c;
      newNode -> real_code = rc;
      newNode -> latitude = la;
      newNode -> longitude = lo;
    }
    

    // Destructor
    ~slist(){ 
      //clear(); 
      }


    // add(value)				//Adds a new value to the end of this list.
    void add(string code, float lat, float longi, string rc){
      Node *newNode = new Node();
      newNode -> iata_code = code;
      newNode -> real_code = rc;
      newNode -> latitude = lat;
      newNode -> longitude = longi;


      if(head == nullptr){
        head = newNode; // Basically if empty array, replace head or beginning with real value
        tail = head;
      }
      else{
        tail -> next = newNode; // Basically moving a tail at a time; tail iterates to next instead of iterating through all values
        tail = tail->next;
      }

      //Node* temp = head; // Creating temporary node to head node

      /*while(temp != NULL){ // Iterating through linked list
        temp = temp->next; // Iterating
      }

      temp = newNode; // Changing last node to the newNode*/
    }


    // clear()					//Removes all elements from this list.
    void clear(){
      Node* temp = head;

      while(temp->next != NULL){ // Iterating through linked list
        Node* tempDelete = temp->next;
        temp = temp -> next;
        delete tempDelete; // Iterating
      }
    }

    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(slist theList){

      Node* firstList = head;
      Node* otherList = theList.head;

      while(firstList->next != NULL && otherList->next != NULL){
        if((firstList -> iata_code != otherList -> iata_code) || (firstList -> iata_code != otherList -> iata_code) || (firstList -> iata_code != otherList -> iata_code)){
          return false;
        }

        firstList = firstList->next;
        otherList = otherList->next;
      }


      return true;
    }


    //get(index)				//Returns the element at the specified index in this list.
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

    //insert(index, value)		//Inserts the element into this list before the specified index.

    void insert(int index, string code, float lat, float longi, string rc){
      
      Node *newNode = new Node();
      newNode -> iata_code = code;
      newNode -> latitude = lat;
      newNode -> longitude = longi;

      Node* temp = newNode;
      Node* current = head;

      int count = 0;
      int tInd = index;

      if(index == 0){
        temp->next = head; // Changing addresses if 0
        head = newNode;
      }
      else if(index == size()-1){
        add(code, lat, longi, rc);
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

    //Replaces the element at the specified index in this list with a new value.
    void set(int index, string code, float lat, float longi){
      
      Node* thatNode = get(index);
      thatNode -> iata_code = code;
      thatNode -> latitude = lat;
      thatNode -> longitude = longi;

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


    // toString()				//Converts the list to a printable string representation.
    string toString(){
      string output = "";
      Node* temp = head;

      while(temp != NULL){
        output += temp->iata_code + ", Lat: " + to_string(temp->latitude) + ", Long: " + to_string(temp->longitude) + "\n"; 

        temp = temp->next;
      }

      return output;

    }

};