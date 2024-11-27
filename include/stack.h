// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
#pragma once
#ifndef _Stack_H_
#define _Stack_H_

#include <iostream>
#include <vector>
//using namespace std;

template<typename T>
class TVectorStack {
	int top; //индекс верхушки
	std::vector<T> mem;
public:
	TVectorStack() : top(-1) { }
	size_t size() const { return top + 1; } //смотрим длину стека
	bool IsEmpty() const { return top == -1; } //смотрим пусто ли
	void Push(const T& val) {  //добавляем наверх
		mem.push_back(val); top++;
	}
	T Pop() { //убираем сверху
		if (IsEmpty()) {
			throw std::out_of_range("try to get element from empty stack");
		}
		T val = mem.back();
		mem.pop_back(); top--; return val;
	}
	T Top() { //смотрим верхушку
		if (IsEmpty()) {
			throw std::out_of_range("try to check element from empty stack");
		}
		return mem.back();
	}
};

#endif