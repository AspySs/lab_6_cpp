// Программа подсчитывает количество столбцов в матрице, содержащих в себе только уникальные элементы

#include <iostream>
#include "header.h"
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "ru");
	const std::string PATH = "input.txt";
	int count = 1;
	while (true){

		try{

			std::string str = open_file(PATH);
			std::cout << "Строка номер " << count << '\n';
			std::cout << str << '\n';
			if (is_expression(str)){
				std::cout << "ДА\n";
			}
			else{
				std::cout << "НЕТ\n";
			}
		}
		catch (exception_file& err){
			std::cout << err.getError() << std::endl << std::endl;
			break;
		}
		count++;
	}
	return 0;
}

std::string open_file(const std::string& path)
{
	static int alreadyRead = 0;
	std::ifstream in;
	std::string str = "";
	in.open(path, std::ios::in);

	skip_al_readed(in, alreadyRead);

	getline(in, str, '\n');
	if (str.empty()){
		throw exception_file();
	}

	alreadyRead++;
	in.close();
	return str;
}
bool is_term(std::string str) {
	if (is_multiplier(str) || (is_multiplier(str.erase(0,str.find('*'))) && is_term(str.erase( str.find('*'), str.size())))) {

	}

}

bool is_multiplier(std::string str) {
	if (is_unsign_int(str) || is_ident(str[0]) || ((str[0] == '(' ) && (str[str.size() - 1] == ')') && is_expression(str.erase(str.find('('), str.find(')'))))) {
		return true;
	}
	return false;
}



void skip_al_readed(std::ifstream& in, int n){

	for (int i = 0; i < n; i++){
		do {
			in.ignore(10000, '\n');
		} while (in.gcount() == 10000);
	}
}
bool is_unsign_int(std::string str){

	if (str.empty()){
		return true;
	}
	if (is_digit(str[0]) && is_unsign_int(str.erase(0, 1))){
		return true;
	}
	return false;
}

bool is_digit(const char ch){

	if (ch == '0' || ch == '1'){
		return true;
	}
	return false;
}

bool is_char(const char ch){

	if (ch == 'x' || ch == 'y' || ch == 'z'){
		return true;
	}
	return false;
}

bool is_ident(const char ch){
	return is_char(ch);
}