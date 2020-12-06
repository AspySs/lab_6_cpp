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
		catch (...)
		{
			if (count == 1) {
				std::cout << "Файл не найден или пуст!" << std::endl << std::endl;
				break;
			}
			else {
				std::cout << std::endl << "Все возможные строки считаны и обработаны!" << std::endl << std::endl;
				break;
			}
		}
		count++;
	}
	return 0;
}