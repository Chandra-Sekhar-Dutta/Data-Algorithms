#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>V1 = {1, 2, 3, 4, 5};
    int size = V1.size();

    int k = 7;
    int left = 0, right = 0;
    int sum = 0;
    int length = 0;

    while (right < size) {
        sum += V1[right];
        
        if (sum <= k) {
            length = max(length, right - left + 1);
            // 1) length=max(0,1)
            // 2)length=max(1,2)
            // 3)length=max(2,3)
            // 4)length=max(3,2)
            // 5)length=max(3,1)
            right++;
        } 
        
        // while (sum >= k && left <= right)  (time complexity=O(n+m))
        if (sum >= k && left <= right)  //time complexity=O(n)
        {
            sum -= V1[left];
            left++;
        }
    }

    cout << "Maximum subarray length with sum less than " << k << " is: " << length << endl;
    return 0;
}