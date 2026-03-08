#include<iostream>
using namespace std;
int main()
{
int number1,number2;
cout<<"Please enter the first number:";
cin>>number1;
cout<<"Please enter the second number:";
cin>>number2;
if(number1<number2){
cout<<"Number" <<number2<<"is greater than"<<number1;
}   
else{
cout<<"Number"<<number1<<"is greater than"<<number2;
}    
}