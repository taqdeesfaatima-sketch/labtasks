#include <iostream>
using namespace std;

int countIdentical(int arr[][3], int rows)
{
    int count=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=i+1;j<rows;j++)
        {
            if(arr[i][0]==arr[j][0] &&
               arr[i][1]==arr[j][1] &&
                arr[i][2]==arr[j][2])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[4][3] = {
        {0,0,0},
        {0,1,2},
        {0,0,0},
        {2,1,0}
     };

    cout<<countIdentical(arr,4);
}