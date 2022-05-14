#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

typedef struct Student
{
    std::string id; 
    bool vaccinated; 
}Student; 

typedef struct
{
    //CSV FILE WITH TEACHER ID AND STUDENT IDS AND CLASSNAME
    std::string array_2D[100][100]; 
}Teacher; 

Teacher get_teacher_csv_file(); 
void get_teacher_gforms(); 

int main() 
{
    //use teacher class for the 2d array of ids and other info
    Teacher teacher = get_teacher_csv_file(); 
}

Teacher get_teacher_csv_file()
{
    get_teacher_gforms(); 
    
    std::fstream file("file.csv", std::ios::in); 

    while(file.fail())
    {
        file = std::fstream("file.csv", std::ios::in);
    }

    std::cout << "teacher csv file uploaded" << std::endl; 

    ///////////////////////////
    
    Teacher teacher;

    std::string line, word;
    int i = 0, j = 0; 

    if(file.is_open())
    {   
        while(getline(file, line))
        {
            std::stringstream str(line);
            j = 0; 

            while(getline(str, word, ','))
            {
                teacher.array_2D[i][j] = word; 
                std::cout << word << "\n"; 
                
                j++; 
            }

            i++; 
        }

        file.close(); 
    }
    else
        std::cout << "Could not open the file\n";

    std::string str; 
    
    for(int a = 0; a < i; a++)
    {
        for(int b = 0; b < j; b++)
        {
            str += teacher.array_2D[a][b]; 
        }

        str += "\n"; 
    }

    std::cout << str << std::endl;

    return teacher; 
}

void get_teacher_gforms()
{
    system("python3 -u get_file.py"); 
}