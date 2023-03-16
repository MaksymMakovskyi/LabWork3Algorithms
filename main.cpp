#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Find(const int* arr, int size, int element) {
	//¬иводимо значенн€ шуканого елемента масиву
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;

	//якщо в масив≥ немаЇ даного елементу, виводимо пов≥домленн€ про помилку
	string path = "myFile.txt"; //‘айл з €кого зчитуЇмо пов≥домленн€
	ifstream fin; 
	fin.open(path);
	cout << "\n";
	if (!fin.is_open())
	{ //якщо не вдалос€ в≥дкрити файл виводимо пов≥домленн€ про помилку
		cout << "File opening error" << endl;
	}
	else
	{ //«читуЇмо пов≥домленн€ з файлу
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
	return -1;
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    const int size = 5000;
    int arr[size];

    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (500);

    int findedElement;
    cout << "Enter the element of the array to be found: ";
    cin >> findedElement;
    int element = findedElement;

    int index = Find(arr, size, element);
	//¬иведенн€ елементу ≥ його ≥ндексу в консоль
    cout << "Element " << element << " found at index " << index << endl;

    system("pause");

    return 0;
}