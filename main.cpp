#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Find(const int* arr, int size, int element) {
	//�������� �������� �������� �������� ������
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;

	//���� � ����� ���� ������ ��������, �������� ����������� ��� �������
	string path = "myFile.txt"; //���� � ����� ������� �����������
	ifstream fin; 
	fin.open(path);
	cout << "\n";
	if (!fin.is_open())
	{ //���� �� ������� ������� ���� �������� ����������� ��� �������
		cout << "File opening error" << endl;
	}
	else
	{ //������� ����������� � �����
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
	//��������� �������� � ���� ������� � �������
    cout << "Element " << element << " found at index " << index << endl;

    system("pause");

    return 0;
}