#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

int KMPSearch(char* string, char* substring) {
	int sl, ssl;
	int res = -1;
	sl = strlen(string);
	ssl = strlen(substring);
	if (sl == 0)
		cout << "Невірно заданий рядок\n";
	else if (ssl == 0)
		cout << "Невірно заданий підрядок\n";
	else {
		int i, j = 0, k = -1;
		int* d;
		d = new int[1000];//масив довжини префіксів
		d[0] = -1;
		// заповнюємо масив довжини префіксів для зразка
		while (j < ssl - 1) {
			while (k >= 0 && substring[j] != substring[k])
				k = d[k];
			j++;
			k++;
			if (substring[j] == substring[k])
				d[j] = d[k];
			else
				d[j] = k;
		}
		i = 0; j = 0;
		// пошук входження підрядка
		while (j < ssl && i < sl) {
			while (j >= 0 && string[i] != substring[j])
				j = d[j];
			i++;
			j++;
		}
		delete[] d;
		//індекс першого входження підрядка
		res = j == ssl ? i - ssl : -1;
	}
	return res;
}
int main() {
	string path = "myFile.txt";
	char sb[] = "hole";

	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{ //Якщо не вдалося відкрити файл виводимо повідомлення про помилку
		cout << "File opening error" << endl;
	}
	else
	{
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
		int ind = KMPSearch(fin, sb);
		cout << "Result KMPSearch =" << ind << endl;
	}
	return 0;
}
