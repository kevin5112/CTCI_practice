#include <iostream>
#include <string>
using namespace std;

bool checkRotation(string s1, string s2, int j)
{
	for(int i = 0; i < s1.size(); ++j, ++i)
	{
		if(j >= s1.size())
			j = 0;

		if(s1[j] != s2[i]) return false;
	}
	return true;
}

void findMatch(string s1, string s2, int& j)
{
	for(int i = 0; j < s1.size(); ++j)
	{
		if(s1[j] == s2[i])
			return;
	}
}

bool stringRotation(string s1, string s2) 
{
	if(s1.size() != s2.size()) return false;
	if(s1.empty()) return true;
	bool isRotate = false;
	int j = 0;

	while(j < s1.size()) 
	{ 
		findMatch(s1, s2, j);
		if(j < s1.size())
			isRotate = checkRotation(s1, s2, j);
		if(isRotate) return true;
		++j;
	}
	return false;
}

int main()
{
	string s1 = "ewew";
	string s2 = "weew";

	cout << "isRotation: " << (stringRotation(s1, s2) ? "yes" : "no") << endl;

	return 0;

}