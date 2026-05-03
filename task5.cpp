#include<iostream>
using namespace std;
int main()
{
    int arr[3][3];
    bool identity = true;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j && arr[i][j]!=1) identity=false;
            if(i!=j && arr[i][j]!=0) identity=false;
        }
    }

    if(identity)
        cout<<"Identity Matrix";
    else
        cout<<"Not Identity Matrix";
}