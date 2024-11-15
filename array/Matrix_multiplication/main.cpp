#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int r1,c1;
    cin>>r1>>c1;
    int mat1[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>mat1[i][j];
        }
    }

     int r2,c2;
     cin>>r2>>c2;
     int mat2[r2][c2];
        for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>mat2[i][j];
        }
    }

    int res[r1][c2];
    if(r2==c1){
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                int sum=0;
             for(int k=0;k<c1;k++){
                sum+=(mat1[i][k]*mat2[k][j]);
             }
             res[i][j]=sum;
            }
        }

            cout<<"The resultant matrix is"<<endl;

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    }
    else cout<<"Matrix multiplication is not possible";


    return 0;
}
