#include <iostream>
using namespace std;

bool isGoalScored(char field[7][16])
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(field[i][j]=='0')
            {
                if(j>5 && j<10 && i<3)
                    return true;
            }
        }
    }
     return false;
}

int main()
{
    char field[7][16] = {0};

    // manually fill if needed

    if(isGoalScored(field))
        cout<<"Goal!";
    else
        cout<<"No Goal";
}