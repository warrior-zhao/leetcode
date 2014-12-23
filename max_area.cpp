#include <vector>
#include <stdio.h>

using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
        return 0;
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