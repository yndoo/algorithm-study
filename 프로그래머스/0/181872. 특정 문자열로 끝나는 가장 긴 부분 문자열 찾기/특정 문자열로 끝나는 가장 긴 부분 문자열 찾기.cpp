#include <string>
#include <vector>

using namespace std;

// myString의 index번부터 패턴찾기 함수
bool FindPattern(string myString, string pat, int index)
{
	int target = index;
	for (int p = 0; p < pat.size(); ++p)
	{
		if (myString.size() <= target) return false;
		if (myString[target++] == pat[p])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

string solution(string myString, string pat) {
	string answer = "";
	for (int i = myString.size(); i >= 0; --i)
	{
		if (myString[i] != pat[0]) continue;

		if (true == FindPattern(myString, pat, i))
		{
			return myString.substr(0, i + pat.size());
		}
	}
}
