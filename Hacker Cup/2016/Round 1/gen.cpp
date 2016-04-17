#include <iostream>
#include <cstdlib>

using namespace std;

bool A[16][16];

int main(){
	srand(time(NULL));
	cout << 16 << endl;

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < i; j++){
			A[i][j] = rand() % 2;
			A[j][i] = !A[i][j];
		}

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			cout << A[i][j] << (j < 15 ? ' ' : '\n');
}
