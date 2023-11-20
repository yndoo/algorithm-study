#include<bits/stdc++.h>
using namespace std;
int N, M;
int arrA[1000000];
int arrB[1000000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arrA[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> arrB[i];
	}

	int i = 0, j = 0, turn = N + M;
	while (turn--) {
		if (j == M) {
			cout << arrA[i++] << " ";
			continue;
		}
		else if (i == N) {
			cout << arrB[j++] << " ";
			continue;
		}
		else if (arrA[i] > arrB[j]) {
			cout << arrB[j++] << " ";
		}
		else {
			cout << arrA[i++] << " ";
		}
	}
	return 0;
}