#pragma once
#define mSize 50



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
	bool operator==(const TStack<T>& s) const; 
	bool operator!=(const TStack<T>& s) const ;
    //T* getPtr() const {return st;}	    // ������� ��������� �� ����
	
	bool nFull(T* &St);						//�������� �� ��, ��� ���� �� ��� �� ������
	bool isEmpty();							//�������� �� ���� �� ����
	void push(const T &value);				//�������� ������� � ����
	int put ();								//������ ���������� ������� 
	int peek ();							//���������� ��������� �������
	void printStack();						//������
	
};

template <typename T>
TStack<T>::TStack()
{
    st = new T[mSize];
	Size=mSize;
	for (int i=0;i<Size;i++)
		st[i]=0;
    LastIndex = 0;							
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

template <typename T>						
void TStack<T>::push(const T &value)
{
    if(nFull(st))
		st[LastIndex++] = value; // �������� ������� � ����
}
 
template <typename T>						
void TStack<T>::printStack()
{
    for (int i = LastIndex-1; i >=0; i--)
        cout << st[i] << endl;
}

template <typename T>
bool TStack<T>::nFull(T* &St) {
	 if (LastIndex<Size) {
		 return true;}
	return false;
}

template <typename T>
bool TStack<T>:: isEmpty() {
	if (LastIndex==0)
		return true;
	else 
		return false;
}

template <typename T>
int TStack<T>::put(){
	if (this->isEmpty())
		throw ("Stek is empty");
	int top=st[LastIndex-1];
	LastIndex--;
	return top;
}

template <typename T>
int TStack<T>::peek(){
	if (this->isEmpty())
		throw ("Stek is empty");
	return st[LastIndex-1];
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
bool TStack<T>::operator==(const TStack<T>& s) const {
	if ((Size == s.Size) && (LastIndex == s.LastIndex)) {
		for (int i = 0; i < Size; i++) {
			if (st[i] != s.st[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}


template <typename T>
bool TStack<T>::operator!=(const TStack<T> &s) const 
{
	if ((*this)==s)
	{
		return false;
	}
	return true;
}


/*template <typename T>
bool TStack<T>::IsFull() {
	if (LastIndex == Size) {
		return true;
	}
	return false;
}*/



