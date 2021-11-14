#ifndef STACK_H
#define STACK_H

const int MAX_STACK_SIZE = 1000;

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T* pStack;
    int Size;                  //������
    int TopIndex;              //������ ������� �����

public:
    Stack(int s);               //����������� +
    Stack(const Stack<T>& st);  //����������� ����������� +
    ~Stack();                   //���������� +

    void Push(const T st);      //������� �������� +
    T Pop();                    //���������� �������� +
    T Peek();                   //�������� �������� �������� (��� ��������) + 
    bool IsEmpty();             //�������� �� �������, +
    bool IsFull();              //�������� �� ������� +
    int GetSize();              //��������� ���������� ��������� � ����� +
    void Clear();               //������� ��������� +
};

template<class T>
Stack<T>::Stack(int s)
{
    if ((s >= 0) && (s <= MAX_STACK_SIZE))
    {
        Size = s;
        TopIndex = -1;
        pStack = new T[Size];
    }
    else
        throw false;
}

template<class T>
Stack<T>::Stack(const Stack<T>& st)
{
    Size = st.Size;
    TopIndex = st.TopIndex;
    pStack = new T[Size];
    for (int i = 0; i < Size; i++)
        pStack[i] = st.pStack[i];
}

template<class T>
Stack<T>::~Stack()
{
    delete[] pStack;
}

template<class T>
void Stack<T>::Push(const T st)
{
    if (IsFull())
        throw "stack is full";
    else
    {
        TopIndex++;
        pStack[TopIndex] = st;
    }
}

template<class T>
T Stack<T>::Pop()
{
    if (IsEmpty())
    {
        TopIndex--;
        return pStack[TopIndex + 1];
    }
    else
        throw "Error";
}

template<class T>
T Stack<T>::Peek()
{
    if (TopIndex != -1)
        return pStack[TopIndex];
    else
        throw "Error";
}

template<class T>
bool Stack<T>::IsEmpty()
{
    if (TopIndex < 0)
        return TopIndex;
}

template<class T>
bool Stack<T>::IsFull()
{
    if (TopIndex == Size)
        return Size;
}

template<class T>
int Stack<T>::GetSize()
{
    return Size;
}

template<class T>
void Stack<T>::Clear()
{
    return TopIndex = -1;
}

#endif