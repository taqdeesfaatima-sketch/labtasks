#include <iostream>
using namespace std;

const int colSize = 5;

void printToyotaBlue(string cars[][colSize], int rows)
{
    for(int i=0;i<rows;i++)
    {
        if(cars[i][0]=="Toyota" && cars[i][1]=="Blue")
        {
            for(int j=0;j<colSize;j++)
                cout<<cars[i][j]<<" ";
            cout<<endl;
        }
    }
}
int countRed(string cars[][colSize], int rows)
{
    int count=0;
    for(int i=0;i<rows;i++)
        if(cars[i][1]=="Red") count++;
    return count;
}

int countNissan(string cars[][colSize], int rows)
{
    int count=0;
    for(int i=0;i<rows;i++)
        if(cars[i][0]=="Nissan") count++;
    return count;
}

int converter(string cars[][colSize], int rows, string color)
{
    int count=0;
    for(int i=0;i<rows;i++)
        if(cars[i][1]==color) count++;
    return count;
}

void transpose(string cars[][colSize], int rows)
{
    for(int j=0;j<colSize;j++)
    {
        for(int i=0;i<rows;i++)
        {
            cout<<cars[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string carData[3][colSize] = {
        {"Toyota","Blue","2020","Auto","Petrol"},
        {"Honda","Red","2019","Manual","Diesel"},
        {"Nissan","Blue","2021","Auto","Petrol"}
    };

    printToyotaBlue(carData,3);
    cout<<"Red Cars: "<<countRed(carData,3)<<endl;
    cout<<"Nissan Cars: "<<countNissan(carData,3)<<endl;
    cout<<"Blue Cars: "<<converter(carData,3,"Blue")<<endl;

    cout<<"Transpose:\n";
    transpose(carData,3);
}