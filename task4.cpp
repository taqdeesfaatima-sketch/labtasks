#include<iostream>
using namespace std;
void printSum(int arr[][3], int rows)
{
    int sum=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<3;j++)
            sum += arr[i][j];

    cout<<"Sum = "<<sum;
}

int main()
{
    int rows;
    cout<<"Enter rows: ";
    cin>>rows;
    int arr[rows][3];

    for(int i=0;i<rows;i++)
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }

    printSum(arr, rows);
}
