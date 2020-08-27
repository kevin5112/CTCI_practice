#include <iostream>
#include <string>
using namespace std;

void substringHelper(string s1, string s2, string newString, int i, int j, bool& isSub)
{
	// cout << "bleh: " << newString << endl; 
	if(newString == s2)
	{
		isSub = true;
		return;
	}

	if(i >= s1.size())
		return;

	if(s1[i] == s2[j])
	{
		newString += s1[i];
		substringHelper(s1, s2, newString, i + 1, j + 1, isSub);
	}


}

bool isSubstring(string s1, string s2)
{
	bool isSub = false;
	int j = 0, i = 0;
	string newString;
	while(!isSub && i < s1.size())
	{
		substringHelper(s1, s2, newString, i, j, isSub);
		i++;
	}
	return isSub;
}

bool stringRotation(string s1, string s2)
{
	if(s1.size() == s2.size() && !s1.empty())
	{
		string s1s1 = s1 + s1;
		return isSubstring(s1s1, s2);
	}
	return false;
}



int main()
{
	string s1 = "plane";
	string s2 = "anepl";

	cout << "isRotate: " << (stringRotation(s1, s2) ? "yes" : "no") << endl;

	return 0;
}