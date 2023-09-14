#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[9];
bool isused[10];

void back(int k) {
	if (k == M) {
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int j = 1; j <= N; j++) {
		if (!isused[j]) {
			arr[k] = j;
			isused[j] = true;
			back(k + 1);
			isused[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	back(0);

	return 0;
}