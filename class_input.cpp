#include <fstream>
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

        //id variables
        int id_len = 6; 
        std::string ids[rows][cols]; 

        std::ifstream infile;
        
        infile.open ("test.csv", std::ifstream::in);
        
		if (infile.is_open())
            
		{
    		while (infile.good())
    		{
    		    for(int i = 0; i < rows; i++)
                {
                    //infile.getline(tmp, 256, '\n');
                    
                    for(int j = 0; j < cols; j++)
                    {
                        char id_char_arr[id_len]; 
                        if(j < cols-1)
                            infile.getline(id_char_arr, 256, ','); 
                        std::string id_str(id_char_arr); 
                        std::strcpy(ids[i][j],id_char_arr); 
                    }

                    char tmp[256]; 
                    infile.getline(tmp, 256, '\n');

                    std::cout << std::endl; 
                }
    		}
  
    		infile.close();
    	}
    	else
    	{
    		std::cout << "Error opening file";
    	}


        std::cout << ids[2][3]; 
        
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
}