#include "Class.h"
#include <algorithm>

// Конструктор таблицы
Table::Table(int s) {
	current = m = new T[size = s];
}

// Деструктор таблицы
Table::~Table() {
	delete[] m;
}

// Возвращает указатель на первый элемент таблицы
T* Table::Begin() {
	return m;
}

// Возвращает указатель на первый свободный элемент таблицы
T* Table::End() {
	return current;
}

// Возвращает размер заполненной части таблицы
int Table::Length() {
	return current - m;
}

// Возвращает общий размер таблицы
int Table::GetSize() {
	return size;
}

// Удаление одного элемента в таблице (по индексу)
T* Table::Erase(T* pos) {
	(*pos)->dispose();
	for (T* i = pos; i < End(); i++)
		*i = *(i + 1);
	current--;
	return pos;
}

// Удаление всех элементов в таблице
void Table::Clear() {
	for (T* i = m; i < current; i++) {
		(*i)->dispose();
		delete (*i);
	}
	current = m;
}

// Вставка нового клиента в таблицу
T* Table::Insert(const T& newClient) {
	if (Length() < size)
		*current++ = newClient->copy();
	return current;
}

// Ввод таблицы
int Table::Input(T item) {
	int count;
	for (count = 0; Length() != GetSize(); count++) {
		if (!item->input())
			break;
		Insert(item);
	}
	return count;
}

// Вывод таблицы
void Table::Output() {
	bool flag = false;
	int counter = 1;
	for (T* i = Begin(); i != End(); i++) {
		std::cout << "Client #" << counter++ << std::endl;
		(*i)->output();
		flag = true;
		std::cout << std::endl;
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < GetSize(); i++) {
		for (int j = i + 1; j < GetSize(); j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const T& tempClient) {
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*tempClient))
			return i - Begin();
	}
	return -1;
}

// Удаление массива элементов в таблице
T* Table::Erase(T* first, T* last) {
	for (T* i = first; i < last; i++) {
		(*first)->dispose();
		for (T* j = first; j < End(); j++)
			*j = *(j + 1);
		current--;
	}
	return last;
}

// Замена клиента в таблице
int Table::Replace(const T& oldClient, const T& newClient) {
	int counter = 0;
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*oldClient)) {
			(*i)->dispose();
			(*i) = (newClient)->copy();
			counter++;
		}
	}
	return counter;
}

// Удаление всех вхождений
int Table::Remove(const T& badClient) {
	T* i = Begin();
	int n = 0;
	for (T* j = Begin(); j < End(); j++) {
		if (!(*j)->equal(*badClient)) {
			*i++ = *j;
		}
		else {
			(*j)->dispose();
			n++;
		}
	}
	current = i;
	return n;
}

// Вставка массива клиентов в таблицу
T* Table::Insert(T* pos, T* first_item, T* last_item) {
	if (Length() < size) {
		for (T* i = first_item; i <= last_item; i++)
			*current++ = (*i)->copy();
	}
	return current;
}

// Поиск в таблице массива first_item - last_item
T* Table::Search(T* first, T* last, T* first_item, T* last_item) {
	for (T* i = first; i < last; i++) {
		if ((*i)->equal(**first_item)) {
			int shift = 0;
			bool flag = false;
			for (T* j = first_item; j <= last_item; j++) {
				if ((*j)->equal(**(i + shift))) {
					if (j == last_item && !flag)
						return i;
					shift++;
				}
				else {
					shift++;
					flag = true;
				}
			}
		}
	}
	return NULL;
}

// Возвращает указатель на i-тую ячейку таблицы
T* Table::GetPntr(int i) {
	return &m[i];
}

// Возвращает индекс элемента в таблице по указатею на этот элемент
int Table::Describe(T* pntr) {
	return pntr - Begin();
}

// Замена всех вхождений клиента в таблице с индекса first по индекс last(не включительно)
int Table::Replace(T* first, T* last, const T& oldClient, const T& newClient) {
	int counter = 0;
	for (T* i = first; i < last; i++) {
		if ((*i)->equal(*oldClient)) {
			(*i)->dispose();
			(*i) = (newClient)->copy();
			counter++;
		}
	}
	return counter;
}

// Сортировка таблицы с индекса first, по индекс last(не включительно)
void Table::Sort(int first, int last) {
	if (first < 0 || last > GetSize() - 1) {
		std::cout << "Error!" << std::endl;
		return;
	}
	for (int i = first; i < last; i++) {
		for (int j = i + 1; j < last; j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}
