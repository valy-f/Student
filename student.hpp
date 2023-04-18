#pragma once
#include <iostream>
using namespace std;

class Student {
public:
	int id;
	string name;
	int age;
	Student(int id, string name, int age) {
		this->id = id;
		this->name = name;
		this->age = age;
	}
};