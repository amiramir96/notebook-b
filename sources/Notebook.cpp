#include <iostream>
#include <string>
#include "Direction.hpp"
#include <unordered_map>
#include <vector> 


#define P_COL 100
#define EMPTY_ROW "______________________________________________________________________________________________________________"

class Page
{ /* this class represent a specific page in a notebook*/ 
    public:

        int page_idx; 
        std::vector<std::string> content {""}; // each field of the vector represnts a line at the page which holds 100 chars 
        bool clear;

    Page(int idx)
    { /* const */
        // init vars
        page_idx = idx; 
        clear = true;
    }
    ~Page(){ /* dest */content.clear(); }

    void show()
    { 
        /* two cases of show: 
                1. page is clear -> shall print only first empty row
                2. page isnt clear -> shall print whole rows to make a page + one more empty line in the end of the page
        */
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

bool validate_readabillity(int col, int len)
{ /* validate check for notebook before read/write/erase while HORIZOTAL command*/
    if (col + len >= 100){ return false;}
    else { return true;}
}

class Notebook{
    /* this class represents a notebook using funcs of write,read,erase and show. using the Page class as objects of the notebook */

    public:
        std::unordered_map<int, Page> nbook;

        Notebook(){}
        ~Notebook(){}
    void write(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, std::string content){}
    std::string read(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len)
    {
        std::string output;
        return output; 
    }
    void erase(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len){}
    
    void show(unsigned int page)
    { /* prints the asken page via calling the show func of the specific page if exists, else: print empty page */
        /* 
        format of printing:
            'page:' <page_idx>
            1: content (string)
            2: content (string) etc.. 
            <last_page_row+1>: EMPTY_ROW 
        */

        if (nbook.contains(page))
        { // print the content of a specific page
            nbook[page].show();
        }
        else
        { // print empty page
            std::cout << "page: " << page << std::endl;
            std::cout << "1: " << EMPTY_ROW << std::endl;
        }
    }
};