#pragma once
#include <string>

class Person                                          // ��� �������� ������������ ��������
{
	int number_;

	std::string name_;

public:
	Person (int number, std::string name) : number_(number), name_(name) {}

	std::string getPersonName() { return name_; }

};