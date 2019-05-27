﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

#include "..\Common\TreeNode.h"
using namespace std;



class MinStack 
{
private:
	//自定义双链表，保存当前节点值+当前节点以前的最小值（含当前节点）
	struct Node
	{
		int val;
		Node *next;
		Node *pre;
		//当前节点前（含当前）的最小值
		int curMin;

		Node(int v)
		{
			val = v;
		}
	};

public:
	/** initialize your data structure here. */
	MinStack() : head(NULL), cur(NULL)
	{
		head = new Node(0);
	}

	void push(int x) 
	{
		if (cur == NULL) 
		{
			cur = new Node(x);
			head->next = cur;
			cur->pre = head;
			cur->curMin = x;
		}
		else 
		{
			cur->next = new Node(x);
			cur->next->pre = cur;
			cur = cur->next;
			cur->curMin = min(cur->pre->curMin, x);
		}
	}

	void pop() 
	{
		cur->pre->next = NULL;
		cur = cur->pre;
		if (cur == head)
			cur = NULL;
	}

	int top() 
	{
		return cur->val;
	}

	int getMin()
	{
		return cur->curMin;
	}

private:
	Node *head;
	Node *cur;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void initVectorInt(vector<int> &nums)
{
	//int A[] = { 1,2,3,1 };
	//int A[] = { 2,7,9,3,1 };
	//int A[] = { 2,4,8,9,9,3 };
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

void printfVectorInt(vector<int> &nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//vector<int> nums;
	//initVectorInt(nums);
	//Solution* obj = new Solution(nums);
	//vector<int> param_2 = obj->shuffle();
	//printfVectorInt(param_2);
	//vector<int> param_1 = obj->reset();
	//printfVectorInt(param_1);

	int x = 3;
	MinStack* obj = new MinStack();
	obj->push(x);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
}
