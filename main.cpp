#include <iostream>
#include  "student.h"
#include  "classroom.h"
#include "linkedlist.h"
#include <bits/stdc++.h>
#include "linkedlistS.h"

int main() {
  //Global master school schedule
  LinkedList* globalSchedule = new LinkedList();
  LinkedListS* globalStudents = new LinkedListS();
  /*TODO: DELETE THIS*/
  int arr[5][5] = {
                  {846624,153468,946825,754685,755748},
                  {456545,877786,985462,956432,154684},
                  {183542,584151,456855,433212,168956},
                  {128331,109531,124385,189312,921321},
                  {128315,156875,941421,982307,194722}
                  };

  int arr2[5][5] = {
                  {846624,153468,146825,154685,155748},
                  {256545,277786,285462,256432,254684},
                  {383542,384151,356855,333212,368956},
                  {428331,409531,424385,489312,421321},
                  {528315,529312,541421,582307,594722}
                  };

  int arr3[5][5] = {
                  {846624,653468,646825,654685,655748},
                  {756545,777786,785462,756432,754684},
                  {883542,884151,856855,833212,868956},
                  {928331,909531,924385,989312,921321},
                  {128315,129312,141421,182307,994722}
                  };

  int arr4[5][5] = {
                  {846624,553468,546825,554685,455748},
                  {456545,477786,385462,456432,354684},
                  {783542,384151,256855,333212,268956},
                  {228331,209531,124385,289312,121321},
                  {128315,129312,041421,182307,294722}
                  };

  Classroom* c = new Classroom("ACP_A1",10000,'M',arr);
  Classroom* d = new Classroom("ACP_A4",10000,'M',arr2);
  Classroom* e = new Classroom("Digi_A2",11000,'L',arr3);
  Classroom* f = new Classroom("PE_A3",696969,'H',arr4);

  c->exposure(456855);
  
  globalSchedule->add(*c);
  globalSchedule->add(*d);
  globalSchedule->add(*e);
  globalSchedule->add(*f);

  globalSchedule->head->classroom.displayRisk();
  
  /*Node * iter = globalSchedule->head;
  while(iter->next != nullptr){
    iter->classroom.displayRisk();
    iter = iter->next;
  }*/

}