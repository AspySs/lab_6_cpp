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
	while (true) {

		try {

			std::string str = open_file(PATH);
			std::cout << "Строка номер " << count << '\n';
			std::cout << str << '\n';
			if (is_expression(str)) {
				std::cout << "ДА\n";
			}
			else {
				std::cout << "НЕТ\n";
			}
		}
		catch (exception_file& err) {
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
	if (str.empty()) {
		throw exception_file();
	}

	alreadyRead++;
	in.close();
	return str;
}

bool is_expression(std::string str) {
	std::string temp_mul = str;
	std::string temp_term = str;
	std::string temp_term_minus = str;
	std::string temp_expr = str;
	std::string temp_expr_minus = str;
	if (is_term(str)) {
		return true;
	}
	else if (have_plus(str)) {
		if (is_term(temp_term.erase(temp_term.find('+'), temp_term.size())) && is_expression(temp_expr.erase(0, temp_expr.find('+') + 1))) {
			return true;
		}
	}
	else if (have_minus(str)) {
		if (is_term(temp_term_minus.erase(temp_term_minus.find('-'), temp_term_minus.size())) && is_expression(temp_expr_minus.erase(0, temp_expr_minus.find('-') + 1))) {

		}
	}
	return false;
}

bool in_bracket(std::string str) {
	if (str.find('(') == 0 && str[str.size() - 1] == ')') {
		return true;
	}
	return false;
}

bool have_mult_star(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '*') {
			return true;
		}
	}
	return false;
}
bool have_plus(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			return true;
		}
	}
	return false;
}
bool have_minus(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			return true;
		}
	}
	return false;
}

std::string out_of_brackets(std::string str) {
	std::string temp = str;
	temp.erase(0, 1);
	temp.erase(str.size() - 1, str.size());
	return temp;
}

bool is_term(std::string str) {
	std::string temp_mul = str;
	std::string temp_term = str;
	if (is_multiplier(str)) {
		return true;
	}
	else if (have_mult_star(str)) {
		if (is_multiplier(temp_mul.erase(temp_mul.find('*'), temp_mul.size())) && is_term(temp_term.erase(0, temp_term.find('*') + 1))) {
			return true;
		}
	}
	else if (in_bracket(str)) {
		std::string un_bracket = out_of_brackets(str);
		if (have_plus(str)) {
			if (is_multiplier(un_bracket.erase(un_bracket.find('+'), un_bracket.size())) && is_term(un_bracket.erase(0, un_bracket.find('+') + 1))) {
				return true;
			}
		}
	}
	return false;
}
bool is_multiplier(std::string str) {
	std::string temp = str;
	if (is_unsign_int(str) || (is_ident(str[0]) && temp.erase(0, 1).empty())) { // проверил на целое без знака, индетификатор, (exp)
		return true;
	}
	else if (in_bracket(str)) {
		if (is_expression(out_of_brackets(str))) {
			return true;
		}
	}
	return false;
}


void skip_al_readed(std::ifstream& in, int n) {

	for (int i = 0; i < n; i++) {
		do {
			in.ignore(10000, '\n');
		} while (in.gcount() == 10000);
	}
}
bool is_unsign_int(std::string str) {
	std::string temp = str;
	if (str.empty()) {
		return true;
	}
	if (is_digit(str[0]) && is_unsign_int(temp.erase(0, 1))) {
		return true;
	}
	return false;
}

bool is_digit(const char ch) {

	if (ch == '0' || ch == '1') {
		return true;
	}
	return false;
}

bool is_char(const char ch) {

	if (ch == 'x' || ch == 'y' || ch == 'z') {
		return true;
	}
	return false;
}

bool is_ident(const char ch) {
	return is_char(ch);
}