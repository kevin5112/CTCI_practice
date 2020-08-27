#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool checkPermutation(string s1, string s2)
{
	if(s1.size() != s2.size()) return false;
	if(s1.empty()) return true;

	unordered_map<char, int> m;

	for(int i = 0; i < s1.size(); ++i)
	{
		m[s1[i]]++;
		m[s2[i]]--;
	}

	for(auto it = m.begin(); it != m.end(); ++it)
		if(it->second != 0) return false;
	return true;
}


int main()
{
	cout << "enter s1: ";
	string s1;
	cin >> s1;

	cout << "enter s2: ";
	string s2;
	cin >> s2;

	cout << "isPermutation? " << (checkPermutation(s1, s2) ? "true" : "false") << endl;

	return 0;
}