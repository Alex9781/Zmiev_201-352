#include <iostream>

void Task1();
void Task2();
void Task3();
void Task4();
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
		<< "0. exit \n";

	std::cin >> task;
	std::cout << std::endl;

	switch (task)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	case 4:
		Task4();
		break;
	case 0:
		exit(0);
		break;
	default:
		std::cout << "error" << std::endl;
		ChooseTask();
		break;
	}
}

void Task1() //проверка на полиндром
{
	const int len = 255;
	char text[len] = "";

	std::getchar();
	std::cin.getline(text, len, '\n');

	bool isMono = true;

	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		if (text[i] == '\0') //игнорирование пустых символов
		{
			j++;
			continue;
		}
		if (text[j] == '\0')
		{
			i--;
			continue;
		}

		if (text[i] == ' ') i++; //игнорирование пробелов
		if (text[j] == ' ') j--;

		if (text[i] <= 90) text[i] += 32; //большие буквы к маленьким
		if (text[j] <= 90) text[j] += 32;

		if (text[i] != text[j])
		{
			isMono = false;
			break;
		}
	}

	if (isMono) std::cout << "string is poly" << std::endl;
	else std::cout << "string isn't poly" << std::endl;

	ChooseTask();
}

void Task2() //поиск индексов подстроки
{
	const int len = 255;
	char text[len] = "";
	char subText[len] = "";

	std::getchar();
	std::cin.getline(text, len, '\n');
	std::cin.getline(subText, len, '\n');

	int index[255] = { 0 };
	int k = 0;

	for (int i = 0; i < len; i++) //перебираем все символы строки
	{
		if (text[i] == '\0') //игнорирование пустых символов
		{
			break;
		}

		if (text[i] == subText[0]) //если текущий символ совпадает с началом подстроки
		{
			int buf = i;
			bool isSub = true;

			for (int j = 0, l = i; j < len; j++, l++) //сверяем полностью ли совпадают строки
			{
				if (text[l] == '\0' || subText[j] == '\0') //игнорирование пустых символов
				{
					break;
				}

				if (text[l] != subText[j])
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

	for (int i = 0; i < k; i++) //выводим получившийся массив индексов
	{
		std::cout << index[i] << " ";
	}

	std::cout << std::endl;
	ChooseTask();
}

void Task3() //шифрование Цезарем
{
	const int len = 255;
	char text[len] = "";

	std::getchar();
	std::cin.getline(text, len, '\n');

	int key;
	std::cin >> key;
	std::cout << std::endl;

	for (int i = 0; i < len; i++)
	{
		if (text[i] == '\0') //игнорирование пустых символов
		{
			break;
		}

		text[i] += key; //шифруем по таблице ascii
		std::cout << text[i] << " ";
	}

	std::cout << std::endl;
	ChooseTask();
}

void Task4() //поиск названий
{
	const int len = 255;
	char text[len] = "";

	std::getchar();
	std::cin.getline(text, len, '\n');

	bool isIn = false;
	char subText[len] = "";
	int j = 0;

	for (int i = 0; i < len; i++)
	{
		if (text[i] == '\"') //если нашли кавычку
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
			subText[j] = text[i];
			j++;
		}
	}

	ChooseTask();
}