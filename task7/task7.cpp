#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

string Checking_Str(char s[]);

int main()
{
	setlocale(LC_ALL, "Russian");
	int check, p;
	char c;
	int const n = 1000;
	char s[n];
	char ch[100];
	bool f = true;
	do
	{
		system("cls");
		cout << "Пример проверки на правильность ввода строки: " << endl;
		ifstream fin("C:\\Users\\ivan2\\source\\repos\\task7\\TextFile1.txt");
		if (fin.is_open())
		{
			string str;
			char buf[1000];
			while (!fin.eof())
			{
				getline(fin, str);
				cout << str << endl;
				strcpy_s(buf, str.c_str());
				cout << Checking_Str(buf) << endl;
			}
		}
		else
			cout << "Ошибка";
		do
		{
			cout << " " << endl;
			cout << "Введите строку, не превышающую 1000 элементов" << endl;
			cin >> s;
		} while (strlen(s) > 1000);
		cout << Checking_Str(s) << endl;
		cout << "Хотите еще раз запустить программу ? (y-да)" << endl;
		cin >> c;
	} while (c == 'y');
	system("pause");
}

string Checking_Str(char s[])
{
	char ch[1000];
	int res = 0;
	int cout = 0;
	int k = 0;
	bool flag = true;
	for (int i = 0; i < strlen(s); i++)
	{
		cout++;
	}
	if (cout < 128)
		res += 1;
	if (!isdigit(s[0]))
		res += 2;
	for (int i = 1; i < strlen(s); i++)
	{
		if (s[i] != '_' && !isdigit(s[i]) && !isalpha(s[i]))
		{
			flag = false;
			break;
		}
	}
	if (flag)
		res += 4;
	if (res == 7)
		strcpy_s(ch, "Строка является правильным идентификатором");
	if (res == 1)
		strcpy_s(ch, "Первым символом не должна быть цифра; символами идентификатора могут быть буквы(строчные или прописные), цифры(от 0 до 9) и символ подчеркивания ");
	if (res == 2)
		strcpy_s(ch, "Имя может содержать от 1 до 127 символов ");
	if (res == 4)
		strcpy_s(ch, "Имя может содержать от 1 до 127 символов; первым символом не должна быть цифра ");
	if (res == 3)
		strcpy_s(ch, "Символами идентификатора могут быть буквы(строчные или прописные), цифры(от 0 до 9) и символ подчеркивания ");
	if (res == 5)
		strcpy_s(ch, "Первым символом не должна быть цифра ");
	if (res == 6)
		strcpy_s(ch, "Имя может содержать от 1 до 127 символов ");
	if (res == 0)
		strcpy_s(ch, "Имя может содержать от 1 до 127 символов; первым символом не должна быть цифра; символами идентификатора могут быть буквы(строчные или прописные), цифры(от 0 до 9) и символ подчеркивания ");
	return ch;
}
