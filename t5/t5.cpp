// t5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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



int main()
{
	setlocale(LC_ALL, "ru");
	int n,i=0;
	Que head = nullptr, tail = nullptr, head2 = nullptr, tail2 = nullptr;
	string data;
	string path = "f.txt";
	string path2 = "g.txt";
	ofstream fout;
	fout.open(path);
	fout.close();
	fout.open(path,ofstream::app);
	cout << "Введите кол-во строк: ";
	cin >> n;
	while (i<=n)
	{
		getline(cin, data);
		ofstream fout2;
		fout << data;
		fout << "\t";
		fout2.open(path2);
		fout2 << data<<endl;
		ifstream fin;
		fin.open(path2);
		if (!fin.is_open())
		{
			cout << "ошибка" << endl;
		}
		else
		{
			char key;
			while (fin >> key)
			{
				char temp_key = key;
				temp_key = int(temp_key) - 48;
				if ((temp_key >= 0) && (temp_key <= 9))
				{
					Fill_Que(head, tail, temp_key);
				}
			}
			while (head != nullptr)
			{
				int x;
				read_Que(head, tail, x);
				fout << " " << x;
			}
		}
	fout<<endl;
		i++;
	}

	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
