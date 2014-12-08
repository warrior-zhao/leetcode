#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t num_size = numbers.size();
        vector<int> index_array;
        map<int, int> val_map;
        for(size_t index=0; index<num_size; index++)
        {
            int other_val = target - numbers[index];
            if(val_map.find(other_val) != val_map.end())
            {
                index_array.push_back(val_map[index]+1);
                index_array.push_back(index+1);
                break;
            }

            val_map[numbers[index]] = index;
        }
        
        return index_array;
    }
};

int main(int argc, char* argv[])
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(10);
    int target = 9;
    Solution solution1;
    vector<int> index_array = solution1.twoSum(numbers, target);

    for(size_t index=0; index<index_array.size(); index++)
    {
        printf("%d\n", index_array[index]);
    }

    return 0;
}