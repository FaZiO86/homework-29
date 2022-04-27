#include <iostream>					//стандартная библиотека
#include <stdlib.h>					//библиотека для рандомайзера
#include <algorithm>				//заголовочный файл в стандартной библиотеке языка программирования C++, включающий набор функций для выполнения алгоритмических операций над контейнерами и над другими последовательностями. Все функции библиотеки расположены в пространстве имён std
#include <fstream>					//библиотека для работы с файловой системой. Содержит методы, классы, функции. классы: чтение данных, запись
#include <string>					//Библеоткеа для строк
#include <conio.h>					//char on input output



using namespace std;

int overwrite(string path, string str);


int main() {
	setlocale(LC_ALL, "Russian");
	
				//Задача 1
	//Запись
	cout << "Задача 1\n";
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);
	string str;
	cout << "Файл открыт для записи!\n";
	while (str != "end") {
		cout << "Введите строку: ";
		getline(cin, str);
		out << str << "\n";
	}
	out.close();

	//чтение
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		cout << "Файл открыт для чтения:\n";
		string str;
		char sym;
		while (in.get(sym))
			str += sym;
		cout << str << endl;
	}
	in.close();
	//Удаление
	if (remove("file.txt") == 0)
		cout << "Файл удалён!\n\n";
	else
		cout << "Ошибка удаления файла\n\n";
	

				//Задача 2
	cout << "Задача 2\n";
	string path1 = "overwrite.txt";
	ofstream out1;
	out1.open(path1, ios::app);
	string str1;
	string str2 = "Delete all!";
	cout << "Файл открыт для записи!\n";
		cout << "Введите строку: ";
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