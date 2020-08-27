#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
using namespace std;

void populateMap(unordered_map<char, int> &m, string s)
{
	for(char c : s)
	{
		if(m.find(c) == m.end())
			m[c] = 1;
		else
			m[c]++;
	}
}

bool oneAway(string s1, string s2)
{
	int diff = s1.size() - s2.size();
	diff = abs(diff);
	if(diff > 1) return false;

	unordered_map<char, int> charCount;
	int soloCount = 0;

	populateMap(charCount, s1);
	populateMap(charCount, s2);

	for(auto it = charCount.begin(); it != charCount.end(); ++it)
	{
		if(it->second % 2 == 1)
			soloCount++;
	}

	if(diff == 1) return soloCount == 1;
	else if(diff == 0) return soloCount == 2 || soloCount == 0;
	else return false;
}

int main()
{
	string s1 = "haha";
	string s2 = "hah";

	cout << "checkOneAway: " << (oneAway(s1, s2) ? "True" : "False") << endl;

	return 0;
}