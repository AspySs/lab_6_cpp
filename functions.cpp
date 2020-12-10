#include <iostream>
#include "header.h"
#include <fstream>
#include <string>

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
	if (is_term(str)) {
		return true;
	}
	else if (have_plus(str)) {
		int plus = str.find('+');
		if (is_term(str.substr(0, str.find('+'))) && is_expression(str.substr(str.find('+') + 1, str.size() - plus))) {
			return true;
		}
	}
	else if (have_minus(str)) {
		int minus = str.find('-');
		if (is_term(str.substr(0, str.find('-'))) && is_expression(str.substr(str.find('-') + 1, str.size() - minus))) {

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
	std::string temp = str.substr(1, str.size() - 2);
	return temp;
}

bool is_term(std::string str) {
	if (have_mult_star(str)) {
		int star = str.find('*');
		if (is_multiplier(str.substr(0, str.find('*'))) && is_term(str.substr(str.find('*') + 1, str.size() - star))) {
			return true;
		}
	}
	else if (is_multiplier(str)) {
		return true;
	}
	else if (in_bracket(str)) {
		std::string un_bracket = out_of_brackets(str);
		if (have_plus(str)) {
			int plus = un_bracket.find('+');
			if (is_multiplier(un_bracket.substr(0, un_bracket.find('+'))) && is_term(un_bracket.substr(un_bracket.find('+') + 1, un_bracket.size() - plus))) {
				return true;
			}
		}
	}
	return false;
}
bool is_multiplier(std::string str) {
	std::string temp = str;
	if (is_unsign_int(str) || is_ident(str[0])) { // проверил на целое без знака, индетификатор, (exp)
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