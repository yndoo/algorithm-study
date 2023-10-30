#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	float x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	//외적값 구하기
	float ans = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
	if (ans > 0) cout << 1;
	else if (ans < 0) cout << -1;
	else if (ans == 0) cout << 0;
	return 0;
}