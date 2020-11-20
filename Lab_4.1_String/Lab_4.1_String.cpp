#include <iostream>

bool Palindrom(char* str);
int FindSubStr(char* str, char* subStr, int startPos);
int* FindSubStr(char* str, char* subStr);
void Encrypt(char* str, int key);
void FindTitles(char* str);

void ChooseTask();

int main()
{
	ChooseTask();
}

void ChooseTask() //выбор задания
{
	int task = 0;
	std::cout << "choose task \n"
		<< "1. task 1 \n"
		<< "2. task 2 \n"
		<< "3. task 3 \n"
		<< "4. task 4 \n"
		<< "5. task 5 \n"
		<< "0. exit \n";

	std::cin >> task;
	std::cout << std::endl;

	switch (task)
	{
	case 1:
	{
		const int len = 255;
		char text[len] = "";

		std::getchar();
		std::cin.getline(text, len, '\n');

		bool x = Palindrom(text);

		std::cout << x << std::endl;

		ChooseTask();
		break;
	}
	case 2:
	{
		const int len = 255;
		char text[len] = "";
		char subText[len] = "";

		std::getchar();
		std::cin.getline(text, len, '\n');
		std::cin.getline(subText, len, '\n');

		int index;
		std::cin >> index;

		int y = FindSubStr(text, subText, index);

		std::cout << y << std::endl;

		ChooseTask();
		break;
	}
	case 3:
	{
		const int len = 255;
		char text[len] = "";
		char subText[len] = "";

		std::getchar();
		std::cin.getline(text, len, '\n');
		std::cin.getline(subText, len, '\n');


		int* z = FindSubStr(text, subText);

		int _len = z[0];
		for (int i = 1; i <= _len; i++)
		{
			std::cout << z[i] << " ";
		}

		std::cout << std::endl;

		ChooseTask();
		break;
	}
	case 4:
	{
		const int len = 255;
		char text[len] = "";

		std::getchar();
		std::cin.getline(text, len, '\n');

		int key;
		std::cin >> key;

		Encrypt(text, key);

		int j = 0;
		while (text[j] != '\0')
		{
			std::cout << text[j];
			j++;
		}

		std::cout << std::endl;

		ChooseTask();
		break;
	}
	case 5:
	{
		const int len = 255;
		char text[len] = "";

		std::getchar();
		std::cin.getline(text, len, '\n');

		FindTitles(text);
		ChooseTask();
		break;
	}
	case 0:
		exit(0);
		break;
	default:
		std::cout << "error" << std::endl;
		ChooseTask();
		break;
	}
}

bool Palindrom(char* str) //проверка на полиндром
{
	bool isMono = true;

	for (int i = 0, j = 255 - 1; i < j; i++, j--)
	{
		if (str[i] == '\0') //игнорирование пустых символов
		{
			j++;
			continue;
		}
		if (str[j] == '\0')
		{
			i--;
			continue;
		}

		if (str[i] == ' ') i++; //игнорирование пробелов
		if (str[j] == ' ') j--;

		if (str[i] <= 90) str[i] += 32; //большие буквы к маленьким
		if (str[j] <= 90) str[j] += 32;

		if (str[i] != str[j])
		{
			isMono = false;
			break;
		}
	}

	return isMono;
}

int FindSubStr(char* str, char* subStr, int startPos) //поиск индексов подстроки
{
	for (int i = startPos; i < 255; i++) //перебираем все символы строки
	{
		if (str[i] == '\0') //игнорирование пустых символов
		{
			break;
		}

		if (str[i] == subStr[0]) //если текущий символ совпадает с началом подстроки
		{
			int buf = i;
			bool isSub = true;

			for (int j = 0, l = i; j < 255; j++, l++) //сверяем полностью ли совпадают строки
			{
				if (str[l] == '\0' || subStr[j] == '\0') //игнорирование пустых символов
				{
					break;
				}

				if (str[l] != subStr[j])
				{
					isSub = false;
					break;
				}
			}

			return buf;
		}
	}
}

int* FindSubStr(char* str, char* subStr) //поиск индексов подстроки
{
	static int index[255] = { 0 };
	int k = 1;

	for (int i = 0; i < 255; i++) //перебираем все символы строки
	{
		if (str[i] == '\0') //игнорирование пустых символов
		{
			break;
		}

		if (str[i] == subStr[0]) //если текущий символ совпадает с началом подстроки
		{
			int buf = i;
			bool isSub = true;

			for (int j = 0, l = i; j < 255; j++, l++) //сверяем полностью ли совпадают строки
			{
				if (str[l] == '\0' || subStr[j] == '\0') //игнорирование пустых символов
				{
					break;
				}

				if (str[l] != subStr[j])
				{
					isSub = false;
					break;
				}
			}

			if (isSub)
			{
				index[k] = buf;
				k++;
			}
		}
	}

	index[0] = k - 1;
	return index;
}

void Encrypt(char* str, int key) //шифрование Цезарем
{
	for (int i = 0; i < 255; i++)
	{
		if (str[i] == '\0') //игнорирование пустых символов
		{
			break;
		}

		if (str[i] == ' ') continue;

		//шифруем по таблице ascii
		if (str[i] >= 65 && str[i] <= 90)
		{
			if ((str[i] + key) > 90)
			{
				str[i] = 64 + ((str[i] + key) % 90);
			}
			else
			{
				str[i] += key;
			}
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			if ((str[i] + key) > 122)
			{
				str[i] = 96 + ((str[i] + key) % 122);
			}
			else
			{
				str[i] += key;
			}
		}
	}
}

void FindTitles(char* str) //поиск названий
{
	const int len = 255;
	bool isIn = false;
	char subText[len] = "";
	int j = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '\"') //если нашли кавычку
		{
			if (isIn) //и если мы уже внутри кавычек, считаем, что название законцилось
			{
				isIn = false;
				for (int i = 0; i < j; i++) //выводим получившееся название
				{
					std::cout << subText[i];
				}
				j = 0;
				std::cout << std::endl;
			}
			else //если мы не внутри кавычек, то начинем составлять название
			{
				isIn = true;
				continue;
			}
		}
		if (isIn) //составляем название
		{
			subText[j] = str[i];
			j++;
		}
	}
}