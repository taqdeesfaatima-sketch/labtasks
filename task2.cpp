#include<iostream>
using namespace std;
void printCars(int cars[][5],int rowSize);

main()
{
    const int rowSize=5;
    const int colSize=5;
    int cars[rowSize][colSize]={{10,7,12,10,4},
                     {18,11,15,17,2},
                     {23,19,12,16,14},
                     {7,12,16,0,2},
                     {3,5,6,2,1}};
     printCars(cars ,rowSize);
}

void printCars(int cars[][5],int rowSize)
{
    for(int row=0;row<rowSize;row++)
    {
        for(int col=0;col<5;col++)
        {
            cout<<cars[col][row]<<"\t";
        }
        cout<<endl;
    }
    int sum=0;
     for(int i=0; i<sum; i++){
     cout<<"Blue Car"<<cardata[0][2];
}
}
    
