#include <iostream>
#include <string>
#include "Direction.hpp"
#include <vector> 

#define P_COL 100
#define EMPTY_ROW "______________________________________________________________________________________________________________"

class Page
{
    public:
    
        int page_idx;
        std::vector<std::string> content {""}; 
        bool clear;

    Page(int num)
    {
        page_idx = num;
        clear = true;
    }
    ~Page(){ content.clear(); }

    void show()
    {
        std::cout << "page: " << page_idx << std::endl; 
        if (clear == true)
        {
            std::cout << "1: " << EMPTY_ROW << std::endl;
        }
        else 
        {
            int i=0;
            for (; i < content.size() ; i++)
            {
                std::cout << i+1 << " " << content[i+1] << std::endl;
            }
            std::cout << i+1 << " " << EMPTY_ROW << std::endl; 
        }
    }
};