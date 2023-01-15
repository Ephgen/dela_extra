// dela_extra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <windows.h>

using namespace std;

void createDela(string* name, int* prioritet, string* opisanie, int* data, int* vnos)
{
	for (int i = 0; i < *vnos; i++) {
			cout << " \nВведите название " << i + 1 << " дела:\n";
			cin >> *(name + i);
			cout << " \nВведите его приоритет(1 - 5): \n";
			cin >> *(prioritet + i);
			cout << " \nВведите его описание: \n";
			cin >> *(opisanie + i);
			cout << " \nВведите его дату исполнения: \n";
			cin >> *(data + i);
	}
}

void viewDela(string* zagolovok, string* name, int* prioritet, string* opisanie, int* data, int* vnos)
{
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << *(zagolovok + i) << "\t\t";
	}
	cout << endl;
	for (int i = 0; i < *vnos; i++) {
		cout << *(name + i) << "\t\t" << *(prioritet + i) << "\t\t" << *(opisanie + i) << "\t\t" << *(data + i);
		cout << endl;
	}
}

void redakt(string* name, int* prioritet, string* opisanie, int* data, int index)
{
	int redChto;
	cout << "\n Что именно у этого дела будете редакторовать? \n 1 - название. \n 2 - приоритет. \n 3 - описание. \n 4 - дату исполнения.\n";
	cin >> redChto;
	switch (redChto)
	{
	case 1:
	{
		cout << "\n Редактируйте имя \n";
		cin >> *(name + index);
		break;
	}
	case 2:
	{
		cout << "\n Редактируйте приоритет \n";
		cin >> *(prioritet + index);
		break;
	}
	case 3:
	{
		cout << "\n Редактируйте описание \n";
		cin >> *(opisanie + index);
		break;
	}
	case 4:
	{
		cout << "\n Редактируйте дату исполнения \n";
		cin >> *(data + index);
		break;
	}
	}
}

void udalDelo(string* name, int* prioritet, string* opisanie, int* data, int index, int* vnos)
{
	for (int i = index; i < *vnos - 1; i++) {
		*(name + i) = *(name + i + 1);
		*(prioritet + i) = *(prioritet + i + 1);
		*(opisanie + i) = *(opisanie + i + 1);
		*(data + i) = *(data + i + 1);
	}
	*vnos -= 1;
}

void poisk(string* zagolovok, string* name, int* prioritet, string* opisanie, int* data, int poiskPo, int redaktUdal, int* vnos)
{

	switch (poiskPo)
	{
	case 1:
	{
		string poName;
		int index = 155;
		cout << "\n Какое название:\n";
		cin >> poName;
		for (int i = 0; i < *vnos; i++) {
			if (*(name + i) == poName)
				index = i;
			break;
		}
		if (index == 155)
			cout << " Нет такого дела, вы ошиблись.";
		else
		{
			cout << "\n Вот ваше дело \n";
			cout << *(name + index) << "\t\t" << *(prioritet + index) << "\t\t" << *(opisanie + index) << "\t\t" << *(data + index);
		}
		if (redaktUdal == 1)
		{
			redakt(name, prioritet, opisanie, data, index);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		if (redaktUdal == 2)
		{
			udalDelo(name, prioritet, opisanie, data, index, vnos);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		break;
	}
case2:
	{
		int poPrior;
		int index = 155;
		cout << "\n Какой приоритет:\n";
		cin >> poPrior;
		for (int i = 0; i < *vnos; i++) {
			if (*(prioritet + i) == poPrior)
				index = i;
			break;
		}
		cout << "\n Вот ваше дело \n";
		cout << *(name + index) << "\t\t" << *(prioritet + index) << "\t\t" << *(opisanie + index) << "\t\t" << *(data + index);
		if (redaktUdal == 1)
		{
			redakt(name, prioritet, opisanie, data, index);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		if (redaktUdal == 2)
		{
			udalDelo(name, prioritet, opisanie, data, index, vnos);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		break;
	}
	case 3:
	{
		string poOpis;
		int index = 155;
		cout << "\n Какое описание:\n";
		cin >> poOpis;
		for (int i = 0; i < *vnos; i++) {
			if (*(opisanie + i) == poOpis)
				index = i;
			break;
		}
		if (index == 155)
			cout << " Нет такого дела, вы ошиблись.";
		else
		{
			cout << "\n Вот ваше дело \n";
			cout << *(name + index) << "\t\t" << *(prioritet + index) << "\t\t" << *(opisanie + index) << "\t\t" << *(data + index);
		}
		if (redaktUdal == 1)
		{
			redakt(name, prioritet, opisanie, data, index);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		if (redaktUdal == 2)
		{
			udalDelo(name, prioritet, opisanie, data, index, vnos);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		break;
	}
	case 4:
	{
		int poDate;
		int index = 155;
		cout << "\n Какая дата:\n";
		cin >> poDate;
		for (int i = 0; i < *vnos; i++) {
			if (*(data + i) == poDate)
				index = i;
			break;
		}
		if (index == 155)
			cout << " Нет такого дела, вы ошиблись.";
		else
		{
			cout << "\n Вот ваше дело \n";
			cout << *(name + index) << "\t\t" << *(prioritet + index) << "\t\t" << *(opisanie + index) << "\t\t" << *(data + index);
		}
		if (redaktUdal == 1)
		{
			redakt(name, prioritet, opisanie, data, index);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		if (redaktUdal == 2)
		{
			udalDelo(name, prioritet, opisanie, data, index, vnos);
			viewDela(zagolovok, name, prioritet, opisanie, data, vnos);
		}
		break;
	}
	}
}

void sortDela(string* zagolovok, string* name,int* prioritet, string* opisanie,int* data,int* vnos, int sort)
{
	if (sort == 1)
	{
		for (int i = 0; i < *vnos; i++) {
			for (int j = 0; j < *vnos; j++) {
				if (*(prioritet + i) > *(prioritet + j))
				{
					swap(*(name + i), *(name + j));
					swap(*(prioritet + i), *(prioritet + j));
					swap(*(opisanie + i), *(opisanie + j));
					swap(*(data + i), *(data + j));
				}
					
			}
		}
	}
	else
	{
		
		
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string zagolovok[4]{ "Название", "Приоритет", "Описание", "Дата исполнения" };
	int vnos;

	cout << "Скажите, сколько дел Вы хотели бы внести?\n";
	cin >> vnos;
	string* name = new string[vnos];
	int* prioritet = new int[vnos];
	string* opisanie = new string[vnos];
	int* data = new int[vnos];
	createDela(name, prioritet, opisanie, data, &vnos);
	viewDela(zagolovok, name, prioritet, opisanie, data, &vnos);
	cout << "\n Хотели бы вы найти какое-то дело чтобы удалить или отредактировать? 1 - да, 0 - нет." << endl;
	int danet;
	cin >> danet;
	//while (danet != 0)
	//{
	if (danet == 1)
	{
		int poiskPo; int redaktUdal;
		cout << "\n Как его найти? \n 1 - по названию. \n 2 - по приоритету. \n 3 - по описанию. \n 4 - по дате исполнения. \n";
		cin >> poiskPo;
		cout << "\n Будете редактировать или удалять?\n 1 - редактировать. \n 2 - удалять ";
		cin >> redaktUdal;
		poisk(zagolovok, name, prioritet, opisanie, data, poiskPo, redaktUdal, &vnos);
	}
	//}
		int sort;
		cout << " Для удобства могу отсортировать ваши дела: \n 1 - по приритету. \n 2 - по дате исполнения.\n";
		cin >> sort;
		sortDela(zagolovok, name, prioritet, opisanie, data, &vnos, sort);
		viewDela(zagolovok, name, prioritet, opisanie, data, &vnos);
}

