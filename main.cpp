#include "settings.h"
using namespace std;




int main() {
	setlocale(LC_ALL, "Russian");
	string apple = "";
	cout << "��� ��������� �������� ���������: " << endl;
	cout << "��� ������������� �������� ������ ���� �������� ��� `(-x)` \n ��������� ������� ��� �������� \n �������������� �����: + - / * ^ \n ������ ���� ������� (������ ������: sqrt(x)):  " << endl;
	cout << "sqrt(x) - ������ ����� x\nsin(x) - ����� ���� \ncos(x) - ������� ����\nabs(x) - ������ ��� ���������� �������� �� x\nlog(x) - ����������� �������� x\nexp(x) - ���������� ����������" << endl;
	cout << "������� ������" << endl;
	while (true) {
		cin >> apple;

		std::vector<std::string> Parse = ParsingAnExample(apple);
		cout << endl;
		cout << calculate(Parse) << std::endl;
	}
	return 0;
}