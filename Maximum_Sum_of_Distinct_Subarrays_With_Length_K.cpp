#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MaxSumFromSubarray(vector<int>& V, int k) {
    int sum = 0, currentSum = 0, left = 0;
    map<int, int> Mp;

    for (int right = 0; right < V.size(); right++) {
        currentSum += V[right];
        Mp[V[right]]++;//Mp[v[right]]=Mp[V[right]]+1 which means the frequency of the element is incremented

        if (right - left + 1 > k) {
            currentSum -= V[left];
            Mp[V[left]]--;//which means the frequency of the element is decremented
            if (Mp[V[left]] == 0) {
                Mp.erase(V[left]);
            }
            left++;
        }

        if (right - left + 1 == k && Mp.size() == k) {
            sum = max(sum, currentSum);
        }
    }

    return sum;
}

int main() {
    vector<int> V = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    cout << MaxSumFromSubarray(V, k) << endl;

    return 0;
}
