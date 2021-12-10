// t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Stack
{
    char data;
    Stack* next;
};

Stack *Fill(Stack* head, int k)
{
    Stack* temp = new Stack;
    temp->data=k;
    temp->next = head;
    head = temp;
    return head;
}
Stack* read_Stack(Stack* head, char &k)
{
    Stack* temp =head;
    k = temp->data;
    if (head->next!=nullptr)
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
bool solve(string data)
{
    Stack* head=nullptr;
    int i=0;
    char ch;
    bool f=true;
    while ((i<data.length())&&(f==true))
    {
        if ((data[i] == '(') || (data[i] == '[') || (data[i] == '{'))
        {
            head = Fill(head,data[i]);

        }
        else
        {
            if ((head != nullptr)&& ((data[i] == ')') || (data[i] == ']') || (data[i] == '}')))
            {
                head = read_Stack(head, ch);
                if (int(ch) - int(data[i]) > 2)
                {
                    f = false;
                }
                else
                {
                    f = true;
                }
            }
            else
            {
                if ((int(data[i]) == ')') || (data[i] == ']') || (data[i] == '}'))
                {
                f = false;
                }
                else
                {
                    f = true;
                }
            }
        }
        i++;
    }
    if (head != nullptr)
    {
        f = false;
    }
    return f;
}
int main()
{

    setlocale(LC_ALL, "ru");
    string data;
    bool cond;
    getline(cin,data );
    if (data != "")
    {
        cond = solve(data);
        if (cond==true)
        {
            cout << "Строка записана правильно";
        }
        else
        {
            cout << "Строка содержит ошибку ";
        }
    }
    else
    {
        cout << "строка пустая";
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
