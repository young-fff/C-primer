#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> lvec;
        vector<int> rvec(n);
        
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] <= max)
                lvec.push_back(max);
            else {
                max = height[i];
                lvec.push_back(max);
            }
        }
        max = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (height[i] <= max)
                rvec[i] = max;
            else {
                max = height[i];
                rvec[i] = max;
            }
        }
        for (int i = 0; i < n; i++) {
            //cout << lvec[i] << " " << rvec[i]
            res += min(lvec[i], rvec[i]) - height[i];
        }
        return res;
    }

int main () 
{
    

    system("pause");
    return 0;
}