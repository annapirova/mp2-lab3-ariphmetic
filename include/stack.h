#pragma once
#define mSize 50

#include <iostream>
using namespace std;

template <typename T>
class TStack {
private:
	T *st;									//����
	int Size;								//������ �����
	int LastIndex;							// ��������� �������
public:
	TStack();
	TStack(int s);							//�����������
	TStack(const TStack<T> &St);			//����������� �����������
	~TStack();								//����������
	int getSize() const {return Size;}		//����� ������ �����
	int getLastIndex() const {return LastIndex;}  //����� ��������� ������� �����
	TStack<T>& operator=(const TStack<T>& s);

	bool IsFull();
	bool nFull(T* &St);						//�������� �� ��, ��� ���� �� ��� �� ������
	bool isEmpty();							//�������� �� ���� �� ����
	void push(const T &value);				//�������� ������� � ����
	int put ();								//������ ���������� ������� 
	int peek ();							//���������� ��������� �������
	
	template <typename T>
	friend ostream& operator<<(ostream &out, const TStack<T> &v);
};

	
template <typename T>
ostream& operator<<(ostream &out, const TStack<T> &v)
{
	for (int i = v.LastIndex; i >=0; i--)
		out << v.st[i] << endl;
	return out;
}

template <typename T>
TStack<T>::TStack()
{
    st = new T[mSize];
	Size=mSize;
	for (int i=0;i<Size;i++)
		st[i]=0;
    LastIndex = -1;							
}

template <typename T>
TStack<T>::TStack(int maxSize) : Size(maxSize) 
{
	if (maxSize<0)
	{
		throw ("negative length");
	}
    st = new T[Size];						// �������� ������ ��� ����
	for (int i=0;i<Size;i++)
		st[i]=0;
    LastIndex = -1;							
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

template <typename T>						
void TStack<T>::push(const T &value)
{
	if(this->IsFull())
		cout << "Stek is Full"<<endl;
	else
	{
		LastIndex++;
		st[LastIndex] = value; // �������� ������� � ����
	}
}
 

template <typename T>
bool TStack<T>::nFull(T* &St) {
	 if (LastIndex<Size) {
		 return true;}
	return false;
}

template <typename T>
bool TStack<T>:: isEmpty() {
	if (LastIndex==-1)
		return true;
	else 
		return false;
}

template <typename T>
int TStack<T>::put(){
	if (this->isEmpty())
		throw ("Stek is empty");
	else{
	int top=st[LastIndex];
	LastIndex--;
	return top;
	}
}

template <typename T>
int TStack<T>::peek(){
	if (this->isEmpty())
		throw ("Stek is empty");
	return st[LastIndex];
}

template <typename T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s) {
	if (st == s.st) {
		return *this;
	}
	Size = s.Size;
	LastIndex = s.LastIndex;
	delete[]st;
	st = new T[Size];
	for (int i = 0; i < Size; i++) {
		st[i] = s.st[i];
	}
	return *this;
}



template <typename T>
bool TStack<T>::IsFull() {
	if (LastIndex == Size-1) {
		return true;
	}
	return false;
}



