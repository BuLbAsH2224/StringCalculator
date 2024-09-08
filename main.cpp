#include "settings.h"
using namespace std;




int main() {
	setlocale(LC_ALL, "Russian");
	string apple = "";
	cout << "Как правильно написать выражение: " << endl;
	cout << "Все отрицательные значения должны быть написаны так `(-x)` \n Выражения пишутся без пробелов \n Арифметические знаки: + - / * ^ \n Список всех функций (Пример вызова: sqrt(x)):  " << endl;
	cout << "sqrt(x) - корень числа x\nsin(x) - синус угла \ncos(x) - косинус угла\nabs(x) - модуль или абсолютное значение от x\nlog(x) - натуральный логарифм x\nexp(x) - вычисление экспоненты" << endl;
	cout << "Введите пример" << endl;
	while (true) {
		cin >> apple;

		std::vector<std::string> Parse = ParsingAnExample(apple);
		cout << endl;
		cout << calculate(Parse) << std::endl;
	}
	return 0;
}