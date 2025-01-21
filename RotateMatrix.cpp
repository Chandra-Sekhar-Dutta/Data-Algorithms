#include<iostream>

using namespace  std;

void rotateMatrix(int mat[][100],int n){
    int L=0,R=n-1;
    

    while(L<R){
        for(int i=0;i<R-L;i++){
            int T=L,B=R;
            int TopLeft=mat[T][L+i]; //here TopLeft is the temporary variable to strore the variable(at first - mat[0][0])
            
            // moving bottom left to top left   
            mat[T][L+i]=mat[B-i][L];

            // moving bottom right to bottom left
            mat[B-i][L]=mat[B][R-i];

            // moving top right to bottom right
            mat[B][R-i]=mat[T+i][R];

            // moving top left to top right
            mat[T+i][R]=TopLeft;

        }

        L++;
        R--;
    }

    // int L = 0, R = n - 1; // Left and Right
    // int T = 0, B = n - 1; // Top and Bottom

    // // Transpose the matrix
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         swap(mat[i][j], mat[j][i]);
    //     }
    // }

    // // Reverse rows to rotate 90 degrees clockwise
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0, k = n - 1; j < k; j++, k--) {
    //         swap(mat[i][j], mat[i][k]);
    //     }
    // }

}

int main(){

    int n;
    cout<<"Enter the size of the matrix-";
    cin>>n;

    int mat[100][100];

    cout<<"Enter the matrix-\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<"Original matrix-\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }

    // Original matrix-

    //      L                       R
    //  T   0       0       0       0
    //      1       1       1       1
    //      2       2       2       2
    //  B   3       3       3       3

    cout<<"After rotation the matrix looks like-\n";

    rotateMatrix(mat,n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }


    return 0;
}