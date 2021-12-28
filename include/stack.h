
#ifndef __TSTACK_H__
#define __TSTACK_H__
#define STACK_SIZE (1000)
#include <vector>

template <class StackType>
class TStack
{
protected:
    int Head;
    int Size;
    StackType* mStack;
    void Overcrowded();     // �������� �� ������������ 
public:
    //������������ � �����������
    TStack();
    ~TStack();
    //�������� �� ������
    void Push(StackType i); // ������� ��������
    StackType Pop();        // ���������� ��������
    StackType Top();        // �������� �������� �������� (��� ��������)
    bool Empty();           // �������� �� ������� 
    int Count();            // ��������� ���������� ��������� � �����
    void Clear();           // ������� �����
};

//���������� ������� ������ ������� 
//������������ � �����������    
template <class StackType>
TStack<StackType>::TStack()
{
    Head = 0;
    Size = STACK_SIZE;
    mStack = new StackType[Size];
}
template <class StackType>
TStack<StackType>::~TStack()
{
    delete[] mStack;
}
//�������� �� ������
template <class StackType> // ������� ��������
void TStack<StackType>::Push(StackType i)
{
    Overcrowded();
    mStack[Head] = i;
    Head++;
}
template <class StackType> // ���������� ��������
StackType TStack<StackType>::Pop()
{
    if (!Empty())
    {
        Head--; return mStack[Head];
    }
    else { throw 1; }
}
template <class StackType> // �������� �������� �������� (��� ��������)
StackType TStack<StackType>::Top()
{
    if (!Empty()) { return mStack[Head - 1]; }
    else { throw 1; }
}
template <class StackType> // �������� �� �������
bool TStack<StackType>::Empty()
{
    if (Head == 0) { return 1; }
    else { return 0; }
}
template <class StackType> // ��������� ���������� ��������� � �����
int TStack<StackType>::Count()
{
    return Head;
}
template <class StackType> // ������� �����
void TStack<StackType>::Clear()
{
    Head = 0;
}
template <class StackType> // �������� �� ������������ 
void TStack<StackType>::Overcrowded()
{
    if (Head == Size)
    {
        StackType* mStack1;
        mStack1 = mStack;
        Size = Size * 2;
        mStack = new StackType[Size];
        for (int i = 0; i < Size / 2; i++)
        {
            mStack[i] = mStack1[i];
        }
    }
}
#endif