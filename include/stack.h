#pragma once
#include <cassert> 


template <typename T>

class TStack {
private:
	T *st;									//����
	int Size;								//������ �����
	int LastIndex;							// ��������� �������
public:
	TStack(int s);							//�����������
	TStack(const TStack<T> &St);			//����������� �����������
	~TStack();								//����������
	int getSize() const {return Size;}		//����� ������ �����
	int getLastIndex() const {return LastIndex;}  //����� ��������� ������� �����
	void push(const T &value);				//�������� ������� � ����
	void printStack();						//������
	//T* getPtr() const {return st;}			// ������� ��������� �� ����
	bool pr1(T* &St);
};


template <typename T>
TStack<T>::TStack(int maxSize) : Size(maxSize) 
{
    st = new T[Size];						// �������� ������ ��� ����
	for (int i=0;i<Size;i++)
		st[i]=0;
    LastIndex = 0;							
}

template <typename T>
TStack<T>::~TStack()						 //����������
{
    delete [] st; 
}

template <typename T>                        //����������� �����������
TStack<T>::TStack(const TStack<T> & St) : Size(St.getSize()) 
{
    st = new T[Size];
    LastIndex = St.getLastIndex();
 
    for(int i=0;i<LastIndex;i++)
        st[i] = St.st[i];
}

template <typename T>						//�������� ������� � ����
void TStack<T>::push(const T &value)
{
    //assert(LastIndex < Size); // ����� �������� �������� ������ ���� ������ ������� �����
    pr1(st);
	st[LastIndex++] = value; // �������� ������� � ����
}
 
template <typename T>						//������ �����
void TStack<T>::printStack()
{
    for (int i = LastIndex - 1; i >= 0; i--)
        cout << st[i] << endl;
}

template <typename T>
bool TStack<T>::pr1(T* &St) {
	 if (LastIndex < Size)
		 return true;
	 else return false;
}


