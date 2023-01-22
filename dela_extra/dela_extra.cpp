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

// Dela_struct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

using namespace std;

struct date
{
	int dd;
	int mm;	
};


struct spisok
{
	string name;
	int prior;
	string opisan;
	date data;
};
struct sort
{
	string name;
	int prior;
};
void createDela(spisok* dela, const int &size)
{
	system("cls");
	int vibor = -1;
	for (int i = 0; i < size; i++) {		
		if (dela[i].name == "")
		{
			cout << "\n Введите имя нового дела.\n";
			cin >> dela[i].name;
			cout << " Приоритет от 1 до 5.\n";
			cin >> dela[i].prior;

			while (dela[i].prior < 1 || dela[i].prior > 5)
			{
				cout << " Приоритет от 1 до 5.\n";
				cin >> dela[i].prior;
			}

			cout << " Описание.\n";
			cin >> dela[i].opisan;
			cout << " Дату исполнения(Число).\n";
			cin >> dela[i].data.dd;

			while (dela[i].data.dd < 1 || dela[i].data.dd > 31)
			{
				cout << " Будьте внимательны, в месяце максимум 31 день\n";
				cout << " Дату исполнения(Число).\n";
				cin >> dela[i].data.dd;
			}
			cout << " Дату исполнения(Месяц).\n";
			cin >> dela[i].data.mm;

			while (dela[i].data.mm < 1 || dela[i].data.mm > 12)
			{
				cout << " Будьте внимательны, в году только 12 месяцев.\n";
				cout << " Дату исполнения(Месяц).\n";
				cin >> dela[i].data.mm;
			}

			cout << " Будете вносить еще дело? 1 - Да. 0 - Нет.\n";
			cin >> vibor;
			if (vibor == 0)
				break;
		}
		if (i == size - 1)
		{
			int menu = -1;
			while (menu != 1)
			{
				cout << " Ваш список переполнен (((. Для выхода в меню нажмите - 1.\n";
				cin >> menu;
			}
		}
		
	}
}
void redaktDelo(spisok* dela, const int& size)
{
	int number;
	int redakt;
	int exit = -1;
	while(exit !=0)
	{
	cout << "\n Какое дело по счету в списке хотите редактнуть?\n";
	cin >> number;
	number--;
	system("cls");
	cout << " Что в этом деле будете редактировать?\n";
	cout << " 1 - Имя. 2 - Приоритет. 3 - Описание. 4 - Дата." << endl;
	cin >> redakt;
	switch (redakt)
	{
	case 1:
	{
		cout << endl << " Напишите новое имя.\n";
		cin >> dela[number].name;
		break;
	}
	case 2:
	{
		cout << endl << " Напишите новый приоритет.\n";
		cin >> dela[number].prior;
		break;
	}
	case 3:
	{
		cout << endl << " Напишите новое описание.\n";
		cin >> dela[number].opisan;
		break;
	}
	case 4:
	{
		cout << endl << " Напишите новую дату, день и месяц через ентер.\n";
		cin >> dela[number].data.dd;
		cin >> dela[number].data.mm;
		break;
	}
	}
	cout << " \n Будете ещё редактировать что-то? 1 - Да. 0 - Нет." << endl;
	cin >> exit;
	}
}
void pokaz(spisok *dela,int &i)
{
	cout << endl << i + 1 << ". " << dela[i].name << "\t" << "Приоритет - " << dela[i].prior << "\t" << "Описание - " << dela[i].opisan << "\t";
	cout << "Дата - " << dela[i].data.dd << "." << dela[i].data.mm << ".";
}
void PoiskDela(spisok* dela, const int &size)
{
	system("cls");
	int poiskPo;
	cout << "\n По чему будете искать? \n";
	cout << " 1 - по имени. 2 - по приоритету. 3 - по описанию. 4 - По дате.\n";
	cin >> poiskPo;
	switch (poiskPo)
	{
	case 1:
	{
		string poisk;
		cout << "\n Теперь напишите ниже что там должно содержаться\n";
		cin >> poisk;
		for (int i = 0; i < size; i++) 
			if (dela[i].name != "")
				if (dela[i].name == poisk)
					pokaz(dela, i);
		break;
	}
	case 2:
	{
		int poisk;
		cout << "\n Теперь напишите ниже что там должно содержаться\n";
		cin >> poisk;
		for (int i = 0; i < size; i++) 
			if (dela[i].name != "")
				if (dela[i].prior == poisk)
					pokaz(dela, i);
		break;
	}
	case 3:
	{
		string poisk;
		cout << "\n Теперь напишите ниже что там должно содержаться\n";
		cin >> poisk;
		for (int i = 0; i < size; i++) 
			if (dela[i].name != "")
				if (dela[i].opisan == poisk)
					pokaz(dela, i);
		break;
	}
	case 4:
	{
		int poiskdd; int poiskmm;
		cout << "\n Теперь напишите ниже что там должно содержаться. Число и месяц через ентер.\n";
		cin >> poiskdd;
		cout << endl;
		cin >> poiskmm;
		for (int i = 0; i < size; i++)
			if (dela[i].name != "")
				if (dela[i].data.dd == poiskdd && dela[i].data.mm == poiskmm)
					pokaz(dela, i);
		break;
	}
	}
	int menu = -1;
	while (menu != 1)
	{
		cout << "\n\n Вот результаты поиска. Для выхода в меню нажмите - 1.\n";
		cin >> menu;
	}
}
void deleteDela(spisok *dela)
{
	int number;
	cout << "\n Дело под каким номером хотите удалить?\n";
	cin >> number;
	number--;
	dela[number].name = ""; dela[number].prior = '\0'; dela[number].opisan = ""; dela[number].data.dd = '\0'; dela[number].data.mm = '\0';
}
void vivodDela(spisok * dela, int &k, int  &nomer)
{
	cout << endl << nomer << ". " << dela[k].name << "\t" << "Приоритет - " << dela[k].prior << "\t" << "Описание - " << dela[k].opisan << "\t";
	cout << "Дата - " << dela[k].data.dd << "." << dela[k].data.mm << ".";
	nomer++;
}
void sortPriorit(spisok *dela, sort *massIndex, int &m, const int &size) 
{
	system("cls");
	int nomer = 1;
	for (int i = 0; i < m; i++) {
		for (int j = m - 1; j > i; j--) {
			if (massIndex[i].prior < massIndex[j].prior)
			{
				swap(massIndex[i].prior, massIndex[j].prior);
				swap(massIndex[i].name, massIndex[j].name);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < size; i++) {
			if (dela[i].name != "")
			{
				if (dela[i].name == massIndex[j].name)
					vivodDela(dela, i, nomer);
			}
		}
	}
}
void period(spisok* dela, const int& size)
{
	system("cls");
	int dd, mm, dd1, mm1;
	cout << endl << " Начиная с какого числа?" << endl;
	cin >> dd;
	cout << endl << " Начиная с какого месяца?" << endl;
	cin >> mm;
	cout << endl << " По какое число?" << endl;
	cin >> dd1;
	cout << endl << " Какой месяц?" << endl;
	cin >> mm1;

	int nomer = 1;
	sort massIndex[20];
	int m = 0;
	if (mm == mm1)
	{
		for (int i = 0; i < size; i++) {
			for (int j = dd; j <= dd1; j++) {
				if (dela[i].data.dd == j && dela[i].data.mm == mm)
				{
					vivodDela(dela, i, nomer);
					massIndex[m].name = dela[i].name;
					massIndex[m].prior = dela[i].prior;
					m++;
				}
			}
		}
	}
	if (mm != mm1)
	{
		for (int i = 0; i < size; i++) {
			for (int j = mm; j <= mm1; j++) {
				if (j == mm) {
					for (int k = dd; k <= 31; k++) {
						if (dela[i].data.dd == k && dela[i].data.mm == j)
						{
							vivodDela(dela, i, nomer);
							massIndex[m].name = dela[i].name;
							massIndex[m].prior = dela[i].prior;
							m++;
						}
					}
				}
				if (j != mm && j != mm1) {
					for (int k = 1; k <= 31; k++) {
						if (dela[i].data.dd == k && dela[i].data.mm == j)
						{
							vivodDela(dela, i, nomer);
							massIndex[m].name = dela[i].name;
							massIndex[m].prior = dela[i].prior;
							m++;
						}
					}
				}
				if (j != mm && j == mm1)
				{
					for (int k = 1; k <= dd1; k++) {
						if (dela[i].data.dd == k && dela[i].data.mm == j)
						{
							vivodDela(dela, i, nomer);
							massIndex[m].name = dela[i].name;
							massIndex[m].prior = dela[i].prior;
							m++;
						}
					}
				}
			}
		}
	}
	int vibor = -1;
	cout << " \n\n Сейчас вы видите ваши дела в порядке от самого близкого по выполнению позднего.\n\n";
	cout << " Скажите, вы хотели бы упорядочить их по приоритету, начиная самого важного?\n\n 1 - Да, хочу! 2 - Нет, не хочу.\n\n";
	cin >> vibor;
	if (vibor == 1)
	{
		sortPriorit(dela, massIndex, m, size);
		cout << "\n\n Теперь ваши дела за заданный период отсортированы по приоритету.";
	}
	int menu = -1;
	while (menu != 1)
	{
		cout << endl << endl << " Вот результаты ваших дел за заданный период." << endl << endl <<
			" Чтобы вернуться в меню нажмите - 1.\n";
		cin >> menu;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int size = 20;
	int vibor = -1;
	spisok dela[size];
	createDela(dela, size);
	while (vibor != 6)
	{
		system("cls");
		for(int i = 0;i < size;i++){
			if (dela[i].name != "")
			{
				cout << endl << i + 1 << ". " << dela[i].name << "\t" << "Приоритет - " << dela[i].prior << "\t" << "Описание - " << dela[i].opisan << "\t";
				cout << "Дата - " << dela[i].data.dd << "." << dela[i].data.mm << ".";
			}
			else
				cout << endl<< i + 1 << ".";
		}
		cout << "\n\n Что хотите сделать с данным списком?\n\n";
		cout << " 1 - Добавить еще дела.\n 2 - Редактировать дело.\n 3 - Поиск по...\n 4 - удаление.\n 5 - Отобразить дела за период (С возможностью сортировки).\n 6 - Выход.\n";
		cin >> vibor;
		if (vibor == 1)
			createDela(dela, size);
		if (vibor == 2)
			redaktDelo(dela, size);
		if (vibor == 3)
			PoiskDela(dela, size);
		if (vibor == 4)
			deleteDela(dela);
		if (vibor == 5)
			period(dela, size);
	}
}

