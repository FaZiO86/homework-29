#include <iostream>					//����������� ����������
#include <stdlib.h>					//���������� ��� ������������
#include <algorithm>				//������������ ���� � ����������� ���������� ����� ���������������� C++, ���������� ����� ������� ��� ���������� ��������������� �������� ��� ������������ � ��� ������� ��������������������. ��� ������� ���������� ����������� � ������������ ��� std
#include <fstream>					//���������� ��� ������ � �������� ��������. �������� ������, ������, �������. ������: ������ ������, ������
#include <string>					//���������� ��� �����
#include <conio.h>					//char on input output



using namespace std;

int overwrite(string path, string str);


int main() {
	setlocale(LC_ALL, "Russian");
	
				//������ 1
	//������
	cout << "������ 1\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);
	string str;
	cout << "���� ������ ��� ������!\n";
	while (str != "end") {
		cout << "������� ������: ";
		getline(cin, str);
		out << str << "\n";
	}
	out.close();

	//������
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "���� ������ ��� ������:\n";
		string str;
		char sym;
		while (in.get(sym))
			str += sym;
		cout << str << endl;
	}
	in.close();
	//��������
	if (remove("file.txt") == 0)
		cout << "���� �����!\n\n";
	else
		cout << "������ �������� �����\n\n";
	

				//������ 2
	cout << "������ 2\n";
	string path1 = "overwrite.txt";
	ofstream out1;
	out1.open(path1, ios::app);
	string str1;
	string str2 = "Delete all!";
	cout << "���� ������ ��� ������!\n";
		cout << "������� ������: ";
		getline(cin, str1);
		out << str1 << "\n";
	out.close();
	cout << overwrite(path1, str2) << endl << endl;


	return 0;
}

int overwrite(string path, string str) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {
		out << str << "\n";
		out.close();
		return true;
	}
	return false;
}