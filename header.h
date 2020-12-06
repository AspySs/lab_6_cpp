#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class exception_file{

private:
	const std::string s_error = "������� ��� ������";
public:
	exception_file(){

	}
	const char* getError(){
		return s_error.c_str();
	}
};
bool have_mult_star(std::string str);
bool have_plus(std::string str);
bool have_minus(std::string str);
bool is_bracket(const char ch);

bool is_expression(std::string str);

bool is_term(std::string str);

bool is_multiplier(std::string str);

bool is_char(const char ch);

bool is_ident(const char ch);

bool is_unsign_int(std::string str);

void skip_al_readed(std::ifstream& in, int n);

std::string open_file(const std::string& path);

bool isInteger(std::string str);

bool is_digit(const char ch);

#endif