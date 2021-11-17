#ifndef STACK_H
#define STACK_H


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
    //Stack() {};
    Stack(int s = 10);               //����������� +
    Stack(const Stack<T>& st);  //����������� ����������� +
    ~Stack();                   //���������� +

    void Push(const T st);      //������� �������� +
    T Pop();                    //���������� �������� +
    T Peek();                   //�������� �������� �������� (��� ��������) + 
    bool IsEmpty();             //�������� �� �������, +
    int GetSize();              //��������� ���������� ��������� � ����� +
    void Clear();               //������� ��������� +
};

template<class T>
Stack<T>::Stack(int s)
{
        Size = s;
        TopIndex = -1;
        pStack = new T[Size];
}

template<class T>
Stack<T>::Stack(const Stack<T>& st)
{
    Size = st.Size;
    //TopIndex = st.TopIndex;
    pStack = new T[Size];
    for (int i = 0; i < TopIndex+1; i++)
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
    if (TopIndex + 1 < Size)
        pStack[++TopIndex] = st;
    else {
        Stack <T> Copy(*this);
        delete[] pStack;
        Size = Size * 2;
        pStack = new  T[Size];
        for (int i = 0; i <= TopIndex; i++)
            pStack[i] = Copy.pStack[i];
        pStack[TopIndex] = st;
    }
}

template<class T>
T Stack<T>::Pop()
{
    if (TopIndex != -1)
        return pStack[TopIndex--];
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
    if (TopIndex == -1) 
        return 1; 
    else 
        return 0;
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