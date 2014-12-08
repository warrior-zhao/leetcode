#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

class Solution{
public:
    int atoi(const char* str){
        if(NULL == str)
        {
            return 0;
        }
         
        //ignore space
        while(isspace(*str))
        {
            str++;
        }
       
        unsigned int is_negative = 0; 
        if((*str) == '+')
	    {
           str++;
        }
        else if((*str) == '-')
        {
           is_negative = 0x80000000;
           str++;
        }

        //calculate int value, using a unsigned var
        unsigned int boundary = 0xffffffff/10;
        unsigned int result = 0;
        while(isdigit(*str))
        {
            int tmp_result = result;
            int value = (*str) - '0';
            result = tmp_result*10 + value;
            str++;

            if((result >= 0x80000000) || (tmp_result > boundary))
            {
                result = 0x80000000;
                break;
            }
        }

        if(is_negative > 0)
        {
            if(result != 0x80000000)
            {
                result = ~result + 1;
            }
        }

        if((is_negative == 0) && (result == 0x80000000))
        {
            result = 0x7fffffff;
        }
         
        return (int)result;  
    }
};

int main(void)
{
    Solution solution1;
    const char* str = "10522545459";
    int result = solution1.atoi(str);
    printf("%d", result);
}
