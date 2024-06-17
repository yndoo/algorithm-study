#include <iostream>
int main()
{
	int arr1[26] = { 0, };
	int arr2[26] = { 0, };
	int result = 0;
	std::string str1, str2;
	std::cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); ++i)
	{
		++arr1[str1[i] - 'a'];
	}
	for (int i = 0; i < str2.size(); ++i)
	{
		++arr2[str2[i] - 'a'];
	}

	for (int i = 0; i < 26; ++i)
	{
		result += abs(arr1[i] - arr2[i]);
	}

	std::cout << result;
	return 0;
}