#include <iostream>
#include <string> 

int main() 
{
    std::cout << "Enter a test option (0 = stdin input | 1 = csv file input): "; 
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
    else if(test_opt_flag)
    {
        std::cout << "Enter the number of rows in the class: "; 
        int rows = -1; 
        std::cin >> rows;
    
        std::cout << "Enter the number of columns in the class: "; 
        int cols = -1; 
        std::cin >> cols;

        

        int ids[10][10]; 

        //read csv file

        std::ifstream file;

          file.open ("test.csv", std::ifstream::in);

        if (file.is_open())
        {
            while (infile.good())
            {
                file.getline(ids, 256,',');
            }
  
        		file.close();
        }
        else
        {
            std::cout << "Error opening csv file";
            exit(1); 
        }

  for(int i = 0; i < salesArrayCount; i++)
  {
    s[i] = &salesArr[i]; 
  }

  simpleSortTotal(*s, salesArrayCount); 



        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                std::cout << "(" << i << ", " << j << "): "; 
                std::cin >> ids[i][j];
            }
        }
        //

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
}