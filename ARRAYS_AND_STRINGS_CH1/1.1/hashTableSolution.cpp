#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isUnique(const string &s)
{
	unordered_map<char, bool> myMap;

	for(char c : s)
	{
		if(myMap.find(c) != myMap.end())
		{
			return false;
		}
		myMap[c] = true;
	}

	return true;
}


int main()
{
	string s = "k1ad/fsv!l1";
	string k = "";

	cout << (isUnique(k) ? "true" : "false") << endl;

	return 0;
}