#include <bits/stdc++.h>
using namespace std;

map<char,int>M1;
string S;

int LongestSubstring(string &S,map<char,int>&M1){
    int i=0,j=0,MaxLen=INT_MIN;
    
    while(j<S.size()){
        M1[S[j]]++;
        
        while(M1[S[j]]>1){
            M1[S[i]]--;
            i++;
        }
        MaxLen=max(MaxLen,(j-i+1));
        j++;
        
    }
        
    
    return MaxLen;
}

int main() {
	// your code goes here
	cin>>S;
	
	cout<<LongestSubstring(S,M1);

}
