#include "Phonebook.h"
c_abonent::c_abonent()
{
	this->name = (char*)"unknown";
	this->work_number = (char*)"unknown";
	this->mobile_number = (char*)"unknown";
	this->info = (char*)"unknown";
}

c_abonent::c_abonent(char* name, char* work_number, char* mobile_number, char* info)
{
	this->name = name;
	this->work_number = work_number;
	this->mobile_number = mobile_number;
	this->info = info;
}

c_phonebook::c_phonebook()
{
	arr = nullptr;
	size = 0;
}

c_phonebook::c_phonebook(c_abonent** arr, int size)
{
	this->arr = arr;
	this->size = size;
}

void c_phonebook::print()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->print();
	}
}

void c_phonebook::add(c_abonent* new_element)
{
	c_abonent** new_arr = new c_abonent * [size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = new_element;
	delete[](arr);
	arr = new_arr;
	size++;
}

void c_phonebook::delete_element(int pos)
{
	c_abonent** new_arr = new c_abonent * [size - 1];
	for (int i = 0; i < pos && i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	for (int i = pos + 1; i < size; i++)
	{
		new_arr[i - 1] = arr[i];
	}
	delete[](arr);
	arr = new_arr;
	size--;
}

void c_phonebook::search_name(char* name)
{
	for (int i = 0; i < size; i++) {
		if (_stricmp(arr[i]->getname(), name) == 0) arr[i]->print();
	}
}

void c_phonebook::save()
{
	FILE* pf;
	fopen_s(&pf, "data", "wt");
	fprintf(pf, "%i\n", size);
	for (int i = 0; i < size; i++)
	{
		fprintf(pf, "%s\t%s\t%s\t%s\n", arr[i]->getname(), arr[i]->getwnumber(), arr[i]->getmnumber(), arr[i]->getinfo());
	}
	fclose(pf);
}

void c_phonebook::load()
{
	FILE* pf;
	fopen_s(&pf, "data", "rt");
	if (pf != nullptr)
	{
		fscanf_s(pf, "%i", &size);
		c_abonent** new_arr = new c_abonent * [size];
		delete[](arr);
		arr = new_arr;
		for (int i = 0; i < size; i++)
		{
			arr[i] = new c_abonent();
			char name[50], work_number[15], mobile_number[15], info[50];
			fscanf_s(pf, "%s%s%s%s", name, 50, work_number, 15, mobile_number, 15, info, 50);
			arr[i]->setname(name);
			arr[i]->setwnumber(work_number);
			arr[i]->setmnumber(mobile_number);
			arr[i]->setinfo(info);
		}
		fclose(pf);
	}
	else std::cout << "error\n";
}
