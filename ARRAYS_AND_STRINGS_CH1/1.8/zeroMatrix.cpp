#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;


void print(int m[][5], int row) {
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cout << m[i][j] << ((j == 4) ? "" : " ");
		}
		cout << endl;
	}
	cout << endl;
}

void zeroMatrix(int matrix[][5], int row) {
	vector <pair <int, int> > v;
	unordered_set <int> rSet;
	unordered_set <int> cSet;

	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < 5; ++j) {
			if(matrix[i][j] == 0) {
				pair <int, int> p(i, j);
				v.push_back(p);
			}
		}
	}

	for(auto i : v) {
		if(rSet.find(i.first) == rSet.end()) {
			rSet.insert(i.first);
			for(int k = 0; k < 5; ++k) {
				matrix[i.first][k] = 0;
			}
		}
		if(cSet.find(i.second) == cSet.end()) {
			cSet.insert(i.second);
			for(int k = 0; k < row; ++k) {
				matrix[k][i.second] = 0;
			}
		}
	}
}

int main()
{
	int matrix[][5] = {{0, 5, 7, 0, 3},
					  {2, 4, 0, 7, 8},
					  {3, 2, 1, 3, 5},
					  {0, 3, 8, 9, 2},
					  {5, 5, 8, 2, 2}};

	print(matrix, 5);
	zeroMatrix(matrix, 5);
	print(matrix, 5);

	return 0;
}