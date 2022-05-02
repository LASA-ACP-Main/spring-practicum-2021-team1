#include <fstream>
#include <iostream>
<<<<<<< Updated upstream
#include <string>
#include <sstream>

typedef struct
{
    std::string csv_file_link; 
    std::string email; 
}Teacher; 

void process_teacher_csv_files(std::fstream *file); 
void get_teacher_gforms(); 

int main() 
{
    std::cout << "Enter a test option (0 = stdin input | 1 = csv file input| 2 = download teacher csv files): "; 
    int test_opt_flag = -1; 
    
    std::cin >> test_opt_flag;
    
    if(test_opt_flag == 0)
    {
        std::cout << "Enter the number of rows in the class: "; 
        int rows = -1; 
        std::cin >> rows;
    
        std::cout << "Enter the number of columns in the class: "; 
        int cols = -1; 
        std::cin >> cols;

        std::cout << "Enter a 6-digit numerical id for each spot of the class\n"; 

        int ids[10][10]; 
    
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                std::cout << "(" << i << ", " << j << "): "; 
                std::cin >> ids[i][j];
            }
        }

        {
            std::string str; 
            
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    str += "|"; 
                    str += std::to_string(ids[i][j]);
                }

                str += "|\n---------------------------------\n"; 
            }

            std::cout << str << std::endl; 
        }
    }
    else if(test_opt_flag == 1)
    {
        std::cout << "Enter the number of rows in the class: "; 
        int rows = -1; 
        std::cin >> rows;
    
        std::cout << "Enter the number of columns in the class: "; 
        int cols = -1; 
        std::cin >> cols;

        //id variables
        int id_len = 6; 
        std::string ids[rows][cols]; 

        std::fstream file ("test.csv", std::ios::in);
        std::string line, word;
        int i = 0; 
        
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int j = 0; 
                std::stringstream str(line);
     
                while(getline(str, word, ','))
                {
                    ids[i][j] = word;
                    j++; 
                }

                i++; 
            }
        }
        else
            std::cout << "Could not open the file\n";
        
        {
            std::string str; 
            
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    str += "|"; 
                    str += ids[i][j];
                }

                str += "\n|------------------------------------------------------\n"; 
            }

            std::cout << str << std::endl; 
        }
    }
    else if(test_opt_flag == 2)
    {
        get_teacher_gforms(); 
        
        std::fstream file("practicum_responses.csv", std::ios::in); 

        while(file.fail())
        {
            file = std::fstream("practicum_responses.csv", std::ios::in);
        }

        std::cout << "teacher csv file uploaded" << std::endl; 
        
        process_teacher_csv_files(&file); 
    }
    else if(test_opt_flag == 3)
    {
        system("python3 -u get_res.py"); 
    }
}

void process_teacher_csv_files(std::fstream *file)
{
    Teacher teachers[100];

    std::string line, word;
    int i = 0; 
    
    if(file->is_open())
    {   
        while(getline(*file, line))
        {
            int j = 0; 

            std::stringstream str(line);
 
            while(getline(str, word, ','))
            {
                if(i >= 1)
                {
                    if(j == 1)
                    {
                        teachers[i-1].email = word;
                    }
                    else if(j == 2)
                    {
                        teachers[i-1].csv_file_link = word; 
                    }
                }
                
                j++; 
            }

            i++; 
        }
    }
    else
        std::cout << "Could not open the file\n";

    int teachers_len = i-1; 

    {
        std::string str; 
        
        for(int idx = 0; idx < teachers_len; idx++)
        {
            str += "EMAIL: "; 
            str += teachers[idx].email; 
            str += " | CSV FILE LINK:"; 
            str += teachers[idx].csv_file_link; 
            str += "\n"; 
        }

        std::cout << str << std::endl; 
    }
}

void get_teacher_gforms()
{
    system("python3 -u get_file.py"); 
=======
#include  "student.h"
#include  "classroom.h"
#include "linkedlist.h"
#include <bits/stdc++.h>


int main() {
  //Global master school schedule
  LinkedList* globalSchedule = new LinkedList();
  /*TODO: DELETE THIS*/
  int arr[5][5] = {
                  {846624,153468,946825,754685,755748},
                  {456545,877786,985462,956432,154684},
                  {183542,584151,456855,433212,168956},
                  {128331,109531,124385,189312,021321},
                  {128315,429312,941421,982307,194722}
                  };

  int arr2[5][5] = {
                  {146624,153468,946825,754685,755748},
                  {456545,877786,985462,956432,154684},
                  {183542,584151,456855,433212,168956},
                  {128331,109531,124385,189312,021321},
                  {128315,429312,941421,982307,194722}
                  };

  int arr3[5][5] = {
                  {846624,153468,946825,754685,755748},
                  {456545,877786,985462,956432,154684},
                  {183542,584151,456855,433212,168956},
                  {128331,109531,124385,189312,021321},
                  {128315,429312,941421,982307,194722}
                  };

  int arr4[5][5] = {
                  {846624,153468,946825,754685,755748},
                  {456545,877786,985462,956432,154684},
                  {183542,584151,456855,433212,168956},
                  {128331,109531,124385,189312,021321},
                  {128315,429312,941421,982307,194722}
                  };

  Classroom* c = new Classroom("ACP_A1",10000,'M',arr);
  Classroom* d = new Classroom("ACP_A4",10000,'M',arr);
  Classroom* e = new Classroom("Digi_A2",11000,'L',arr);
  Classroom* f = new Classroom("PE_A3",696969,'H',arr);
  
  globalSchedule->add(*c);
  globalSchedule->add(*d);
  globalSchedule->add(*e);
  globalSchedule->add(*f);

>>>>>>> Stashed changes
}