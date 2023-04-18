#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "student.hpp"
using namespace std;

vector<Student> students;
void load_students() {
	ifstream file("c:\\student\\students.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			string id_str, name, age_str;
			getline(ss, id_str, ';');
			getline(ss, name, ';');
			getline(ss, age_str, ';');
			int id = stoi(id_str);
			int age = stoi(age_str);
			students.push_back(Student(id, name, age));
		}
		file.close();
	}
}
void save_students() {
	ofstream file("c:\\student\\students.txt");
	if (file.is_open()) {
		for (auto& s : students) {
			file << s.id << ';' << s.name << ';' << s.age << '\n';
		}
		file.close();
	}
}
void add_student() {
	int id, age;
	string name;
	cout << "Enter student's ID: ";
	cin >> id;
	cout << "Enter student's name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter student's age: ";
	cin >> age;
	students.push_back(Student(id, name, age));
	save_students();
	cout << "Student is added.\n";
}
void delete_student() {
	int id;
	cout << "Enter student's ID to delete: ";
	cin >> id;
	for (auto it = students.begin(); it != students.end(); ++it) {
		if (it->id == id) {
			students.erase(it);
			save_students();
			cout << "Student is deleted.\n";
			return;
		}
	}
	cout << "Student not found.\n";
}
void edit_student() {
	int id;
	cout << "Enter student ID to edit: ";
	cin >> id;
	for (auto& s : students) {
		if (s.id == id) {
			string name;
			int age;
			cout << "Enter new name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter new age: ";
			cin >> age;
			s.name = name;
			s.age = age;
			save_students();
			cout << "List has been updated.\n";
			return;
		}
	}
	cout << "Student not found.\n";
}
void search_student() {
	int id;
	cout << "Enter student's ID to search: ";
	cin >> id;
	for (auto& s : students) {
		if (s.id == id) {
			cout << "ID: " << s.id << " Name: " << s.name << " Age: " << s.age << '\n';
			return;
		}
	}
	cout << "Student not found.\n";
}
int main() {
	cout << "Enter: add    - add student\n       delete - delete student\n       edit   - edit student\n       find   - search for a student\n       exit   - exit the programme\n";
	string action;
	load_students();
	for (int i = 0; i < 17; i++) {
		cin >> action;
		if (action == "add") {
			add_student();
		}
		else if (action == "delete") {
			delete_student();
		}
		else if (action == "edit") {
			edit_student();
		}
		else if (action == "find") {
			search_student();
		}
		else if (action == "exit") {
			break;
		}
	} return 0;
}