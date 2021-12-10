// t2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
Stack* read_Stack(Stack* head, int & k)
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
    case'^':return pow(x,y);
        break;
    case'%':return x % y;
        break;
    }
   
}
int main()
{
    setlocale(LC_ALL, "ru");
    string data;
    getline(cin, data);
    Stack* head = nullptr;
    int i = 0,x,y,sum;
    char ch;
    for (i=0;i<data.length();i++)
    {
        int k = int(data[i]) - 48;
        if ((k >= 0) && (k <= 9))
        {
            head = Fill(head, k);
        }
        else
        {
            head = read_Stack(head, x);
            head = read_Stack(head, y);
            sum = Operation(x, y, data[i]);
            head = Fill(head, sum);
        }
    }
    read_Stack(head, x);
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
