#include<iostream>
using namespace std;

void swapVariables(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
int main(){
    int x=20,y=40;

    swapVariables(x,y);
    cout<<"Enter x & y:"<<x<<" "<<y<<endl;
}