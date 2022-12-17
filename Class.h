#pragma once
#include <iostream>

class Client {
private:
	char* name; // Имя клиента
	char city[30]; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
public:
	Client();
	Client(const char* n, const char* c, int p, int a);
	Client(const Client& t);
	void dispose();
	~Client();
	int input();
	void output();
	int cmp(const Client& t);
	int equal(const Client& t);
	Client* copy();
};

typedef Client* T; // Теперь таблица работает с абстрактным типом T

class Table {
private:
	int size; // Размер таблицы
	T* m; // Таблица клиентов
	T* current; // Указатель на первый свободный в таблице
public:
	Table(int s);
	~Table();
	T* Begin();
	T* End();
	int Length();
	int GetSize();
	T* Erase(T* pos);
	void Clear();
	void Resize(int plusSize);
	T* Insert(const T& newClient);
	int Input(T item);
	void Output();
	void Sort();
	int Search(const T& tempClient);
	int Replace(const T& oldClient, const T& newClient);
	int Remove(const T& badClient);
	T* GetPntr(int i);
	int Describe(T* pntr);
	// Индивидуальные функции
	T* Insert(T* pos, T* first_item, T* last_item);
	int Remove(T* first, T* last, T* first_item, T* last_item);
	T* Search(T* first, T* last, T* first_item, T* last_item);
	T* Erase(T* first, T* last);
	int Replace(T* first, T* last, const T& oldClient, const T& newClient);
	void Sort(int first, int last);
};
