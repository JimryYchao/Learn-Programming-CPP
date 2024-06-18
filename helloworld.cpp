// cpptest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	int i = INT_MAX + 1; // warning:'+':integral constant overflow
	wchar_t wch = 'A';	 // OK
	char c = wch;
	// warning:'initializing':conversion from 'wchar_t' to 'char', possible loss of data

	unsigned char c2 = 0xfffe;
	// warning:'initializing':truncation from 'int' to 'unsigned char'

	int j = 1.9f;
	// warning:'initializing':conversion from 'float' to 'int', possible loss of data

	int k = 7.7;
	// warning:'initializing':conversion from 'double' to 'int', possible loss of data
}
