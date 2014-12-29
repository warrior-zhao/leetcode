#include <vector>
#include <stdio.h>
#include <limits.h>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxArea(vector<int> &height) {
        size_t array_size = height.size();
        if(array_size <= 1)
        {
            return 0;
        }

        int max_area = 0;
        int left = 0;
        int right = (int)(array_size - 1);
        while(left < right)
        {
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return max_area;
    }
};

int main(int argc, char* argv[])
{
    vector<int> height = {1,2,3};
    Solution solution1;
    int area = solution1.maxArea(height);
    printf("%d\n", area);
    return 0;
}