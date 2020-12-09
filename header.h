#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class exception_file {
public:
	exception_file() {
		std::cout << "\n Конец файла либо встречена пустая строка \n";
	}
};

bool have_mult_star(std::string str); // проверка на наличие *

bool have_plus(std::string str); // проверка на наличие +

bool have_minus(std::string str); // проверка на наличие -

bool in_bracket(std::string str); // проверка на наличие ()

std::string out_of_brackets(std::string str); // извлечение из ()

bool is_expression(std::string str);

bool is_term(std::string str);

bool is_multiplier(std::string str);

bool is_char(const char ch);

bool is_ident(const char ch);

bool is_unsign_int(std::string str);

void skip_al_readed(std::ifstream& in, int n);

std::string open_file(const std::string& path);

bool is_digit(const char ch);

#endif