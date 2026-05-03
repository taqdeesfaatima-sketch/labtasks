#include<iostream>
using namespace std;

bool isIdentity(int arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j && arr[i][j]!=1) return false;
            if(i!=j && arr[i][j]!=0) return false;
        }
    }
    return true;
}

int main()
{
    int arr[3][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1}
        
    };
    if(isIdentity(arr))
        cout<<"Identity Matrix";
    else
        cout<<"Not Identity";

    return 0;
}