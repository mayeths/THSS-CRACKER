// 数据结构大作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "CharString.h"
#include "CharStringLink.h"
#include "Stack.h"
#include "getfiles.h"
#include "utils.h"
#include "mydic.h"
#include "DocLink.h"
#include "AVLTree.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <string>


using namespace std;

int main()
{
	wcout.imbue(locale("", LC_CTYPE));
	

	//vector<string>files;
	//getAllFile(files);
	int size = 781;

	//CharString* filename = new CharString[size];
	CharString* filepath = new CharString[size];

	//MyDicNode* dictionary = new MyDicNode;
	//initDictionary(dictionary);
	//cout << "init dic finish" << endl;

	//CharStringLink** link = new CharStringLink*[size];
	//for (int i = 0; i < size; i++)
	//{
	//	link[i] = new CharStringLink;
	//}

	for (int i = 0; i < size; i++)
	{
		CharString result;
		//filename[i] = files[i].c_str();
		//result = extractInfo(filename[i]);
		//divideWords(&result, dictionary, link[i]);
		

		//int j = filename[i].indexOf(L".");
		//int m;
		//for (m = j; m >= 0; m--)
		//{
		//	if (filename[i][m] == (wchar_t)'\\')
		//		break;
		//}
		
		//CharString name = filename[i].substring(m + 1, j - m - 1);
		CharString name = to_wstring(i);
		char path[128];
		_getcwd(path, 128);
		filepath[i] = path;
		filepath[i] += "\\output";
		filepath[i] += "\\";
		filepath[i] += name;
		filepath[i] += L".txt";
	}
	
	//delete[]filename;

	/*
	for (int i = 0; i < size; i++)
	{
		link[i]->traverse(filepath[i]);
	}
	*/

	cout << "creating AVLTree" << endl;
	AVLTree* tree = new AVLTree;
	creatAVL(filepath, tree, size);
	delete[]filepath;
	cout << "AVLTree created" << endl;

	double** connection = new double*[781];
	for (int i = 0; i < 781; i++)
	{
		connection[i] = new double[781];
		for (int j = 0; j < 781; j++)
		{
			connection[i][j] = 0;
		}
	}
	cout << "init connection" << endl;
	tree->initConnection(connection);
	cout << "init finished" << endl;
	cout << "doing query 1" << endl;
	Query1(tree);
	cout << "doing query 2" << endl;
	Query2(connection);
	system("pause");
	//_CrtDumpMemoryLeaks();
	return 0;
}
