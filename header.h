#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class exception_file {
public:
	exception_file() {

	}
};

bool have_mult_star(std::string str); // �������� �� ������� *

bool have_plus(std::string str); // �������� �� ������� +

bool have_minus(std::string str); // �������� �� ������� -

bool in_bracket(std::string str); // �������� �� ������� ()

std::string out_of_brackets(std::string str); // ���������� �� ()

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