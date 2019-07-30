﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

void findPalindrome(string s, int &low, int &high)
{
	while (s[low] == s[high])
	{
		low--;
		high++;
		if (low < 0 || high > s.size() - 1) break;
	}
	low++;
	high--;
}

string longestPalindrome(string s) 
{
	if (s.size() == 1) return s;
	string res;
	res.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			int low = i - 1;
			int high = i;
			findPalindrome(s, low, high);
			if (high - low + 1 > res.size()) res = s.substr(low, high - low + 1);
		}
		if ((i + 1 < s.size()) && s[i - 1] == s[i + 1])
		{
			int low = i - 1;
			int high = i + 1;
			findPalindrome(s, low, high);
			if (high - low + 1 > res.size()) res = s.substr(low, high - low + 1);
		}
	}
	return res;
}

int main()
{
	vector<string> str;
	//str.push_back("babad");
	//str.push_back("babab");
	//str.push_back("cbbd");
	str.push_back("ac");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << s << endl;
		cout << longestPalindrome(s) << endl;
	}
}


//int main()
//{
//	vector<vector<int>> N;
//	vector<int> K;
//	vector<double> A;
//
//	//N.push_back({ 1,3,1 });
//	//K.push_back(1);
//	//A.push_back(0);
//
//	//N.push_back({ 1,3,1 });
//	//K.push_back(2);
//	//A.push_back(2);
//
//	N.push_back({ 95, 29, 47, 58, 80, 65, 26, 7, 69, 0, 1, 53, 61, 46, 66, 30, 78, 25, 1, 62, 5, 1, 78, 60, 81, 100, 52, 33, 9, 52, 7, 74, 94, 93, 47, 68, 80, 81, 50, 31, 9, 96, 8, 8, 64, 4, 40, 22, 50, 93 });
//	K.push_back(1142);
//	A.push_back(2);
//
//	for (int i = 0; i < A.size(); i++)
//	{
//		cout << endl << "/////////////////////////////" << endl;
//		printVectorInt(N[i]);
//		int a = smallestDistancePair(N[i], K[i]);
//		cout << "Find Smallest-Distance-Pair( " << K[i] << " ) = " << a << endl;
//		cout << "Answer = " << A[i] << endl;
//		if (a != A[i])
//		{
//			return 0;
//		}
//	}
//}
