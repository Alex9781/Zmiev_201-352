#include <iostream>
#include <string>
#include <fstream>

void ChooseTask();

std::string GetFileFormat(std::string fullPath);
std::string GetFileName(std::string fullPath);
std::string GetFilePath(std::string fullPath);
char GetFileDisc(std::string fullPath);
bool RenameFile(std::string oldFileFullPath, std::string newName);
bool CopyFile(std::string fullPath);

int main()
{
	ChooseTask();
}

void ChooseTask() //выбор задания
{
	int task = 0;
	std::cout << "choose task \n"
		<< "1. get format \n"
		<< "2. get name \n"
		<< "3. get path \n"
		<< "4. get disc \n"
		<< "5. remane \n"
		<< "6. copy \n"
		<< "0. exit \n";

	std::cin >> task;
	std::cout << std::endl;

	std::string path;
	std::string newName;

	std::getchar();

	switch (task)
	{
	case 1:
		std::getline(std::cin, path);
		std::cout << GetFileFormat(path) << std::endl << std::endl;
		ChooseTask();
		break;
	case 2:
		std::getline(std::cin, path);
		std::cout << GetFileName(path) << std::endl << std::endl;
		ChooseTask();
		break;
	case 3:
		std::getline(std::cin, path);
		std::cout << GetFilePath(path) << std::endl << std::endl;
		ChooseTask();
		break;
	case 4:
		std::getline(std::cin, path);
		std::cout << GetFileDisc(path) << std::endl << std::endl;
		ChooseTask();
		break;
	case 5:
		std::getline(std::cin, path);
		std::getline(std::cin, newName);
		std::cout << RenameFile(path, newName) << std::endl << std::endl;
		ChooseTask();
		break;
	case 6:
		std::getline(std::cin, path);
		std::cout << CopyFile(path) << std::endl << std::endl;
		ChooseTask();
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

std::string GetFileFormat(std::string fullPath)
{
	return	fullPath.substr(fullPath.find_last_of('.')); //берём подстроку начиная с точки и до конца строки
}

std::string GetFileName(std::string fullPath)
{
	return fullPath.substr(fullPath.find_last_of('\\') + 1/*, fullPath.find_last_of('.')*/); //имя берём с последнего слеша и до конца
}

std::string GetFilePath(std::string fullPath)
{
	return fullPath.substr(0, fullPath.find_last_of('\\') + 1); //путь с начала до последнего слеша
}

char GetFileDisc(std::string fullPath)
{
	return fullPath[0]; //имя диска состоит из одного символа и находится в начале строки
}

bool RenameFile(std::string oldFileFullPath, std::string newName)
{
	return !(rename(oldFileFullPath.c_str(), (GetFilePath(oldFileFullPath) + newName).c_str())); 
	//пользуясь встроенной функцие подаём ей старый путь до файли и вычисляем новый с помощью вышестоящей функции
}

bool CopyFile(std::string fullPath)
{
	try
	{
		std::ifstream fin(fullPath, std::ios::binary); //открываем поток копиремого файла

		//вычисляем путь до копии
		std::string copyFilePath = GetFilePath(fullPath) //путь до последнего слеша
			+ GetFileName(fullPath).substr(0, GetFileName(fullPath).find('.')) //имя без расширения
			+ "_copy" //плюсуем _copy
			+ GetFileFormat(fullPath); //возвращаем формат

		std::ofstream fout(copyFilePath, std::ios::binary); //открываем поток копии

		fout << fin.rdbuf(); //копируем

		fin.close(); //закрываем потоки
		fout.close();

		return true;
	}
	catch (const std::exception&) //если мы не смогли открыть копируемый файл или копию ловим исключение
	{
		return false;
	}
}