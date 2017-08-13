#include<iostream>
#include<cmath>
using namespace std;

void arrayGen (int* &data,int s)
{
    data=new int[s];
}
void populateArray(int data[],int s)
{
    for(int i=0;i<s;i++)
        data[i]=0;
}
void markPrimeIndex(int data[],int s)
{
    data[0]=1;data[1]=1;
    for(int i=4;i<s;i+=2)
        data[i]=1;
    for(int i=3;i<(sqrt(s)+1);i+=2)
        if(data[i]==0)
            for(int j=i+i;j<s;j+=i)
                data[j]=1;
}

void viewPrimes (int data[],int s)
{
    int counter = 1;
    cout<<counter<<"'th prime is: "<<2<<endl;
    for(int i=3;i<s;i+=2)
        if(i>=3 && data[i]==0)
            cout<< ++counter<<"'th prime is: "<<i<<endl;
}

int main()
{
    int* Array; int size=0;
    do { cout<<"Provide Array Size: "; cin>>size; }
        while(size<=0);
    arrayGen(Array,size+1);
    populateArray(&Array[0],size+1);
    markPrimeIndex(&Array[0],size+1);
    viewPrimes(Array,size+1);
    return 0;
}
