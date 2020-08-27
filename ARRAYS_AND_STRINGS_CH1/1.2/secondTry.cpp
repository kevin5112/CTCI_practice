#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkPerm(string s, string q)
{
	unordered_map<char, int> m(0);

	for(char c : s)
	{
		m[c]++;
	}

	for(char c : q)
	{
		if(m.find(c) == m.end())
		{
			return false;
		}
		m[c]--;
	}

	for(auto it = m.begin(); it != m.end(); ++it)
	{
		if(it->second != 0)
		{
			return false;
		}
	}

	return true;
}


int main()
{
	string s = "12321";
	string q = "3212";

	cout << (checkPerm(s, q) ? "true" : "false") << endl;


	return 0;
}