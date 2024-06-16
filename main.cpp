// 禁用4996警告
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Management.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//Management m;
	//m.start();

	// 测试代码
	Management m;
	m.readData();
	m.start();

	return 0;
}