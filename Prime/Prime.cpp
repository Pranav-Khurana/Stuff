# include <iostream>
# include <conio.h>

using std::cin;
using std::cout;
using std::endl;

/*Eratosthenes' sieve algorithm from https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let p equal 2, the smallest prime number.
3. Enumerate the multiples of p by counting to n from 2p in increments of p, and mark them in the list 
(these will be 2p, 3p, 4p, ...; the p itself should not be marked).
4. Find the first number greater than p in the list that is not marked. If there was no such number, stop.
Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
*/

int BinSearch (int &val, int Ar[], int N) {
	int low = 0, high = N - 1, mid, flag = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (val < Ar[mid]) high = mid - 1;
		else if (Ar[mid] < val) low = mid + 1;
		else {
			flag = 1;
			break;
		}
	}
	if (flag) return flag;
	else return flag;
}

void Generate (int List[], int N) {
	cout << "Generating list: " << endl;
	for (int i = 0; i < N; i++) List[i] = i;
	List[0] = List[1];
}

void Show (int List[], int N, int prime) {
	for (int i = prime; i < N; i++) cout << List[i] << " ";
	cout << endl;
}

void Mark (int List[], int N, int &prime) {
	cout << "Marking multiples of " << prime << ": " << endl;
	for (int i = prime * prime; i < N; i += prime) 
		if (List[i] % prime == 0) List[i] = 0;
}

int nonZeroCount (int List[], int N, int &prime) {
	int count = 0;
	cout << "Counting non-zero elements: " << endl;
	for (int i = prime; i < N; i++) 
		if (List[i] == 0) continue;
		else count++;
	return count;
}

void Generate (int Sieve[], int List[], int N, int &prime) {
	int k = 0;
	cout << "Generating sieved list: " << endl;
	for (int i = prime; i < N; i++) {
		if (List[i] != 0) {
			Sieve[k] = List[i];
			k++;
		}
	}
}

void Prime (int &N) {
	int *List = new int[N + 1];
	Generate (List, (N + 1));
	int prime = List[2];
	Show (List, (N + 1), prime);
	do {
		Mark (List, (N + 1), prime);
		Show (List, (N + 1), prime);
		int count = 0;
		count = nonZeroCount (List, (N + 1), prime);
		cout << "Non-zero element count: " << count << endl;
		int *Sieve = new int[count];
		Generate (Sieve, List, (N + 1), prime);
		Show (Sieve, (count), 0);
		if (BinSearch (N, Sieve, (count))) {
			cout << N << " possibly prime!" << endl;
			cout << "Current prime: " << prime << endl;
			prime = Sieve[1];
			cout << "New prime: " << prime << endl;
			delete []Sieve;
		}
		else {
			cout << N << " not prime!" << endl;
			delete []Sieve;
			break;
		}
	}while (prime != N);
	if (prime == N) cout << N << " is prime!" << endl;
	else cout << N << " is not prime!" << endl;
}

int main () {
	cout << "Enter a number: ";
	int x;
	cin >> x;
	Prime (x);
	getch ();
	return 0;
}