// t4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
	char data;
	Node* next;
};

typedef Node* Que;

void Fill_Que(Que& head, Que& tail, int k)
{
	Que temp = new Node;
	temp->data = k;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
}
void read_Que(Que& head, Que& tail, int& x)
{
	if (head != nullptr)
	{
		Node* temp = head;
		x = head->data;
		head = head->next;
		delete temp;
	}
	else
		tail = nullptr;
}
void add(int key)
{
	ofstream fout;
	string path2 = "g.txt";
	fout.open(path2, ofstream::app);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		fout << key;
		fout << " ";

	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	string data;
	string path = "f.txt";
	getline(cin, data);
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		fout << data;
	}
	fout.close();

	int a, b;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;

	Que head = nullptr, tail = nullptr, head2 = nullptr, tail2 = nullptr;
	string path2 = "g.txt";
	fout.open(path2);
	fout.close();
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "ошибка" << endl;
	}
	else
	{
		cout << "Файл открыт" << endl;
		int key;

		while (fin >> key)
		{
			if (key < a)
			{
				add(key);
			}
			else
			{
				if ((key >= a) && (key <= b))
				{
					Fill_Que(head, tail, key);
				}
				else
				{
					Fill_Que(head2, tail2, key);
				}
			}
		}
	}
	fout.open(path2, ofstream::app);
	fout << endl;
	while (head != nullptr)
	{
		int x;
		read_Que(head, tail, x);
		add(x);
	}
	fout << endl;
	while (head2 != nullptr)
	{
		int x;
		read_Que(head2, tail2, x);
		add(x);
	}

}// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
