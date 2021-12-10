#include<iostream> 
#include"Phonebook.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	c_phonebook* phonebook = new c_phonebook();
	int choice;
	do
	{
		system("cls");
		cout << "1 - Вывести всех абонентов\n"
			<< "2 - Добавить абонента\n"
			<< "3 - Удалить абонента\n"
			<< "4 - Искать по ФИО\n"
			<< "5 - Сохранить\n"
			<< "6 - Загрузить\n"
			<< "0 - Выход\n";
		cin >> choice;
		cin.ignore();
		system("cls");
		switch (choice)
		{
		case 1:
			phonebook->print();
			break;
		case 2:
			cout << "Имя:";
			char name[50];
			gets_s(name, 50);
			cout << "Рабочий номер:";
			char wnumber[15];
			gets_s(wnumber, 15);
			cout << "Мобильный номер:";
			char mnumber[15];
			gets_s(mnumber, 15);
			cout << "Дополнительная информация:";
			char info[50];
			gets_s(info, 50);
			phonebook->add((new c_abonent(name, wnumber, mnumber, info)));
			break;
		case 3:
			cout << "Удаляемый абонент:";
			int num;
			cin >> num;
			phonebook->delete_element(num - 1);
			break;
		case 4:
			cout << "Искомое ФИО:";
			char fio[50];
			gets_s(fio, 50);
			phonebook->search_name(fio);
			break;
		case 5:
			phonebook->save();
			break;
		case 6:
			phonebook->load();
			break;
		}
		system("pause");
	} while (choice != 0);
	delete phonebook;
}