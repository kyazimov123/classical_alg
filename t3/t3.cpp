// t3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Stack
{
	int data;
	Stack* next;
};

Stack* Fill(Stack* head, int k)
{
	Stack* temp = new Stack;
	temp->data = k;
	temp->next = head;
	head = temp;
	return head;
}
Stack* read_Stack(Stack* head, int& k)
{
	Stack* temp = head;
	k = temp->data;
	if (head->next != nullptr)
	{
		head = head->next;
	}
	else
	{
		head = nullptr;
	}
	delete temp;
	return head;
}
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
int Operation(int x, int y, char ch)
{
	switch (ch)
	{
	case'+': return x + y;
		break;
	case'*':return x * y;
		break;
	case'/':return y / x;
		break;
	case'-':return y - x;
		break;
	case'^':return pow(x, y);
		break;
	case'%':return x % y;
		break;
	}

}
int main()
{
	Que head = nullptr, tail = nullptr;
	Stack* headst = nullptr;
	setlocale(LC_ALL, "ru");
	string data;
	getline(cin, data);
	int i = 0;
	for (i = 0; i < data.length(); i++)
	{
		int key_num = int(data[i]) - 48;
		int key = int(data[i]);
		if ((key_num >= 0) && (key_num <= 9))
		{
			Fill_Que(head, tail, key);
		}
		if ((data[i] == '/') || (data[i] == '*') || (data[i] == '+') || (data[i] == '-') || (data[i] == '^') || (data[i] == '%') || (data[i] == '('))
		{
			if (headst == nullptr)
			{
				headst = Fill(headst, key);
			}
			else
			{
				if (headst->data == '(')
				{
					headst = Fill(headst, key);
				}
				else
				{
					if (data[i] == '(')
					{
						headst = Fill(headst, key);
					}
					if ((data[i] == '+') || (data[i] == '-'))
					{
						if (((data[i] == '+') || (data[i] == '-')) && ((headst->data == int('(')) || (headst == nullptr)))
						{
							headst = Fill(headst, key);
						}
						else
						{
							while (headst->data != int('('))
							{
								int k;
								headst = read_Stack(headst, k);
								Fill_Que(head, tail, k);
								if (headst == nullptr)
								{
									headst = Fill(headst, key);
									break;
								}
							}
							if (headst->data != key)
							{
								headst = Fill(headst, key);
							}
						}
					}
					if (data[i] == '%')
					{
						if ((data[i] == '%') && ((headst->data == int('(')) || (headst == nullptr) || (headst->data == int('+')) || (headst->data == int('-'))))
						{
							headst = Fill(headst, key);
						}
						else
						{
							while (((headst->data != int('(')) && (headst->data != int('+')) && (headst->data != int('-'))))
							{
								int k;
								headst = read_Stack(headst, k);
								Fill_Que(head, tail, k);

								if (headst == nullptr)
								{
									headst = Fill(headst, key);
									break;
								}
							}
							if (headst->data != key)
							{
								headst = Fill(headst, key);
							}
						}
					}
					if ((data[i] == '*') || (data[i] == '/') || (data[i] == '^'))
					{
						if (((data[i] == '*') || (data[i] == '/') || (data[i] == '^')) && ((headst->data == int('(')) || (headst == nullptr) || (headst->data == int('+')) || (headst->data == int('-')) || (headst->data == int('%'))))
						{
							headst = Fill(headst, key);
						}
						else
						{
							while (((headst->data != int('(')) && (headst->data != int('+')) && (headst->data != int('-')) && (headst->data != int('%'))))
							{
								int k;
								headst = read_Stack(headst, k);
								Fill_Que(head, tail, k);
								if (headst == nullptr)
								{
									headst = Fill(headst, key);
									break;
								}
							}
							if (headst->data != key)
							{
								headst = Fill(headst, key);
							}
						}
					}
				}
			}
		}
		else
		{
			if (data[i] == ')')
			{
				while (headst->data != int('('))
				{
					int k;
					headst = read_Stack(headst, k);
					Fill_Que(head, tail, k);
				}
				int k;
				headst = read_Stack(headst, k);
			}
		}
	}
	while (headst != nullptr)
	{
		int k;
		headst=read_Stack(headst, k);
		Fill_Que(head, tail, k);
		if (headst == nullptr)
		{
			break;
		}
	}
	i = 0;

	ofstream fout;
	string path = "data.txt";
	fout.open(path);
	fout.close();
	fout.open(path,ofstream::app);
	while (head != nullptr)
	{
		int ikey;
		read_Que(head, tail, ikey);
		if ((ikey >= 0) && (ikey <= 9))
		{
			cout << ikey;
			fout << ikey;
			i++;
		}
		else
		{
			cout << char(ikey);
			fout << char(ikey);
			i++;
		}
	}



	fout.close();
	ifstream fin;
	fin.open(path);
	getline(fin, data);
	fin.close();

    headst = nullptr;
	int  x, y, sum;
	i = 0;
	char ch;
	for (i = 0; i < data.length(); i++)
	{
		int k = int(data[i]) - 48;
		if ((k >= 0) && (k <= 9))
		{
			headst = Fill(headst, k);
		}
		else
		{
			headst = read_Stack(headst, x);
			headst = read_Stack(headst, y);
			sum = Operation(x, y, data[i]);
			headst = Fill(headst, sum);
		}
	}
	read_Stack(headst, x);
	cout << endl;
	cout << sum;


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
