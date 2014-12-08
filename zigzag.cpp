
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(s.empty() || (nRows <= 0))
        {
            return "";
        }
        
         vector<string> str_array;
        str_array.resize(nRows);            
        bool inc = false;
        size_t row_index = 0;
        string::iterator it = s.begin();
        while(1)
        {
            if(it == s.end())
            {
                break;
            }

            for(size_t str_index=0; str_index<nRows; str_index++)
            {
                if(it == s.end())
                {
                    break;
                }

                if((row_index == (nRows-1)) || (row_index == 0))
                {
                    inc = !inc;//reverse direct when reach boundary
                }

                if(inc)
                {
                    //when increase, add char for each column
                    string& cur_str = str_array[str_index];
                    cur_str.push_back(*it);
                    it++;

                    row_index++;
                    continue;
                }


                if(!inc && (str_index == row_index))
                { 
                    //when decrease, add char only in a cross line                   
                    string& cur_str = str_array[str_index];
                    cur_str.push_back(*it);
                    it++;

                    row_index--;
                    break;
                }
            }
        }

        string tmp_str;
        for(size_t str_index=0; str_index<str_array.size(); str_index++)
        {
            string& cur_str = str_array[str_index];
            tmp_str += cur_str;
        }

        return tmp_str;   
    }
};

int main(void)
{
    Solution solution1;
    string str = "PAHNAPLSIIGYIR";
    string zigzag_str = solution1.convert(str, 3);
    printf("%s", zigzag_str.c_str());
    return 0;
}
