#include <iostream>
#include <conio.h>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

void Generate (int List[], int N) {
	for (int i = 0; i < N; i++) List[i] = i;
	List[0] = List[1];
}

void Mark (int List[], int N, int &prime) {
	int i = prime * prime;
	if (i < 0) {
		for (i = prime; i < N; i += prime) 
			if (i == prime) continue;
			else if (List[i] % prime == 0) List[i] = 0;
	}
	else {
		for (; i < N; i += prime) 
			if (List[i] % prime == 0) List[i] = 0;
	}
}

int FindNextPrime (int List[], int N, int &prime) {
	for (int i = (prime + 1); i < sqrt(N); i++) 
		if (List[i] > prime && List[i] != 0) 
			return List[i];
	return -1;
}

void PrintPrimes (int &L, int &U) {
	int *List = new int[U + 1];
	Generate (List, (U + 1));
	int prime = List[2];
	do {
		Mark (List, (U + 1), prime);
		prime = FindNextPrime (List, (U + 1), prime);
	}while (prime > 0);
	List[0] = List[1] = 0;
	for (int i = L; i <= U; i++) 
		if (List[i] != 0) cout << List[i] << " ";
	delete []List;
}

int main () {
	int x, y;
	cout << "Enter a range [X, Y]: ";
	cin >> x >> y;
	cout << "Primes in the range [" << x << ", " << y << "]: " << endl;
	PrintPrimes (x, y);
	getch ();
	return 0;
}
