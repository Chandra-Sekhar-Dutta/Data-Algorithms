#include <iostream>

using namespace std;

void print(int i){
    if(i>4){
        return;
    }
    
    print(i+1);//backtracking
    // the above line is excecuted till the last, here it is i=0, then, it will excecut the next line i.e., cout<<i<<"\t"
    cout<<i<<"\t";
}

int main()
{
    print(1);

    return 0;
}
