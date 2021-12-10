#pragma once
#include<iostream>
class c_abonent
{
private:
	char* name;
	char* work_number;
	char* mobile_number;
	char* info;
public:
	c_abonent();
	c_abonent(char* name, char* work_number, char* mobile_number, char* info);
	inline void print() const
	{
		std::cout << name << "\t" << work_number << "\t" << mobile_number << "\t" << info << "\n";
	}
	//gets
	inline char* getname() const
	{
		return this->name;
	}
	inline char* getwnumber() const
	{
		return this->work_number;
	}
	inline char* getmnumber() const
	{
		return this->mobile_number;
	}
	inline char* getinfo() const
	{
		return this->info;
	}
	//sets
	void setname(char* name)
	{
		this->name = name;
	}
	void setwnumber(char* work_number)
	{
		this->work_number = work_number;
	}
	void setmnumber(char* mobile_number)
	{
		this->mobile_number = mobile_number;
	}
	void setinfo(char* info)
	{
		this->info = info;
	}
};

class c_phonebook
{
private:
	c_abonent** arr;
	int size;
public:
	c_phonebook();
	c_phonebook(c_abonent** arr, int size);
	void print();
	void add(c_abonent* new_element);
	void delete_element(int pos);
	void search_name(char* name);
	void save();
	void load();
	~c_phonebook()
	{
		for (int i = 0; i < size; i++)
		{
			delete[](arr[i]);
		}
		delete[](arr);
	}
};