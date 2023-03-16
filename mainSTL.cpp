#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() 
{
	string path = "myFile.txt";
	ifstream fin; //������� ��� �� �����
	fin.open(path);
	if (!fin.is_open())
	{ //���� �� ������� ������� ���� �������� ����������� ��� �������
		cout << "File opening error" << endl;
	}
	else
	{ //������� ����������� � �����
		cout << "File opening" << endl;
	}
	fin.close();

	//find() - ������������ ������
	auto result = find(path.begin(), path.end(), "hole");
	if (result == path.end()) 
	{
		cout << "Word not found" << endl;
	}
	else 
	{
		cout << "This word is in the text" << endl;
	}

	//find_if() - ������������ ������
	auto result = find_if(path.begin(), path.end(), [](string a) 
		{
			return a;
		});

	//�������������� �� ���������
	////find_first() - ������������ ������
	//auto result = find_first(a)
	//	{
	//		return a;
	//	});

	////find_end() - ������������ ������
	//auto result = find_end(path.begin(), path.end(), [](string a)
	//	{
	//		return a;
	//	});
	//return 0;
}