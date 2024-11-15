#include <iostream>
#include <vector>
#include <string>
int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int n1 = s1.size(), n2 = s2.size();
	std::vector<std::vector<int>> LCS(n1 + 1, std::vector<int>(n2 + 1, 0));
	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
			{
				LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
	std::cout << LCS[n1][n2];
	return 0;
}