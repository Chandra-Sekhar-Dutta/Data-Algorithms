#include <iostream>
#include <climits>
#include<vector>

using namespace std;

vector<int> V1 = {6,2,3,4,7,2,1,7,1};

int maximumSumofSubarrayOfFixedSize(vector<int>&V1,int k){
    int i=0,j=0,sum=0,maxSum=INT_MIN;
    
    while(j<V1.size()){
        sum+=V1[j];
        
        if(j-i+1<k){
            j++;
        }
        
        else if(j-i+1==k){
            maxSum=max(sum,maxSum);
            
            sum-=V1[i];
            i++;j++;
        }
        
        
    }
    
    return maxSum;

}

int main()
{
    int k;
    cout<<"Enter the value of k=";
    cin>>k;
    
    cout<<maximumSumofSubarrayOfFixedSize(V1,k);

    return 0;
}