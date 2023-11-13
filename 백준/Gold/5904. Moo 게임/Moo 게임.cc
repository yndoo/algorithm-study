#include<iostream>
using namespace std;
int N, k;
int arr[100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	arr[0] = 3;//moo
	for (int i = 0; i < 100; i++) {
		if (i == 0) arr[i] = 3;
		else arr[i] = 2 * arr[i - 1] + i + 3;
		if (N <= arr[i]) { k = i;  break; }
	}
	//cout << "======while======\n";
	
	while (true) {
		//cout << N << " " << k << "\n";
		if (k == 0) {
			if (N == 1) cout << "m";
			else cout << "o";
			break;
		}
		if (arr[k - 1] < N && N <= arr[k - 1] + k + 3) {
			if (N == arr[k - 1] + 1) cout << "m";
			else cout << "o";
			break;
		}
		else if (arr[k - 1] + k + 3 < N) {
			N = N - (arr[k - 1] + k + 3);
			//k 다시 찾기
			for (int i = k; i >= 0; i--) {
				if (arr[i - 1] < N && N <= arr[i]) { k = i; break; }
			}
		}
	}
	return 0;
}
