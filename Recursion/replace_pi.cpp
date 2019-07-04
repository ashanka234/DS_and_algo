#include<iostream>
using namespace std;

void replace_pi(char *str, char *output, int i, int j)
{
    if(str[i] == '\0')
    {
        output[j] = str[i];
        cout << output << endl;
        return;
    }

    if(str[i]=='p' && str[i+1]=='i')        //pi found 
    {
        output[j] = '3';
        output[j+1] = '.';
        output[j+2] = '1';
        output[j+3] = '4';

        replace_pi(str, output, i+2, j+4);
    }
    else
    {
        output[j] = str[i];
        replace_pi(str, output, i+1, j+1);
    }
    
}

int main() {

	char input[1000], ans[1000];
	int n;
	cin >> n;

	while(n--)
	{
		cin >> input;
		replace_pi(input, ans, 0, 0);
		//cout << ans << endl;
	}

	return 0;
}