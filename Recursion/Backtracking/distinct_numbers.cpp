#include<iostream>
using namespace std;

int fibo(int n)
{
    //starting from 2nd fibonacci
	if(n<=1)
	{
		return 1;
	}

	return fibo(n-1) + fibo(n-2);
}

int main() {

	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin >>  n;
		cout << fibo(n+1) << endl;
	}

	return 0;
}