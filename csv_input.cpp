#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

typedef struct
{
    std::string array_2D[100][100]; 
}Teacher; 

Teacher get_teacher_csv_file(); 
void get_teacher_gforms(); 

int main() 
{
    Teacher teacher = get_teacher_csv_file(); 

    /*
    std::string str; 
        
    for(int i = 0; i < *teachers_len; i++)
    {
        str += "EMAIL: "; 
        str += teachers->email; 
        str += " | CSV FILE LINK:"; 
        str += teachers->csv_file_link; 
        str += "\n"; 
    }

    std::cout << str << std::endl;
    */
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
                /*
                if(i == 0 && j == 0)
                {
                    teacher.array_2D[0][0] = word; 
                }
                else if(i == 1 && j == 0)
                {
                    teacher.array_2D[1][0] = word; 
                }
                
                if(i > 1)
                {
*/ 

                    teacher.array_2D[i][j] = word; 
                    std::cout << word << "\n"; 
                //}
                
                j++; 
            }

            i++; 
        }

        file.close(); 
    }
    else
        std::cout << "Could not open the file\n";

    std::string str; 
    
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 3; b++)
        {
            str += teacher.array_2D[a][b]; 
            str += "|"; 
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