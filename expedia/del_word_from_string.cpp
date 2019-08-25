#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

void removeWords(string &str1, string &str2)
{
    vector<string> v;


    //extract words into vector from str2
    stringstream iss(str2);
    string word;

    while(iss >> word)
    {
        v.push_back(word);
    }

    for(int i=0; i<v.size(); i++)
    {
        size_t pos = str1.find(v[i]);

        if(pos != string::npos)
        {
            str1.erase(pos, v[i].length());
        }
    }
}

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    removeWords(str1, str2);

    cout << str1 << endl;

    return (0);
}