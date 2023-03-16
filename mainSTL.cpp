#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() 
{
	string path = "myFile.txt";
	ifstream fin; //зчитуЇмо дан≥ ≥з файлу
	fin.open(path);
	if (!fin.is_open())
	{ //якщо не вдалос€ в≥дкрити файл виводимо пов≥домленн€ про помилку
		cout << "File opening error" << endl;
	}
	else
	{ //«читуЇмо пов≥домленн€ з файлу
		cout << "File opening" << endl;
	}
	fin.close();

	//find() - демонстрац≥€ роботи
	auto result = find(path.begin(), path.end(), "hole");
	if (result == path.end()) 
	{
		cout << "Word not found" << endl;
	}
	else 
	{
		cout << "This word is in the text" << endl;
	}

	//find_if() - демонстрац≥€ роботи
	auto result = find_if(path.begin(), path.end(), [](string a) 
		{
			return a;
		});

	//≥дентиф≥катори не визначено
	////find_first() - демонстрац≥€ роботи
	//auto result = find_first(a)
	//	{
	//		return a;
	//	});

	////find_end() - демонстрац≥€ роботи
	//auto result = find_end(path.begin(), path.end(), [](string a)
	//	{
	//		return a;
	//	});
	//return 0;
}