#include <iostream>
#include <time.h>
#include <string>

void ChooseTask();
void Task1();
void Task2();
void Task3();

void PrintArray(int* arr, int len);
void PrintArray(char* arr, int len);

void SortType1(int* arr, int len);
void SortType2(char* arr, int len);
void SortType3(int* arr, int len, int lo, int hi);

int main()
{
	srand(time(0));
	ChooseTask();
	return 0;
}

void ChooseTask()
{
	int task = 0;
	std::cout << "choose task \n"
		<< "1. task 1 \n"
		<< "2. task 2 \n"
		<< "3. task 3 \n"
		<< "4. exit \n";

	std::cin >> task;

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
		exit(0);
		break;
	default:
		std::cout << "error" << std::endl;
		ChooseTask();
		break;
	}
}

void Task1()
{
	int arrLen;
	std::cout << "enter array len: ";
	std::cin >> arrLen;
	std::cout << std::endl;

	int arr[1000] = { 0 };

	for (int i = 0; i < arrLen; i++)
	{
		arr[i] = rand() % 200 - 100;
	}

	PrintArray(arr, arrLen);
	SortType1(arr, arrLen);
	ChooseTask();
}

void PrintArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

void PrintArray(char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

void SortType1(int* arr, int len)
{
	int temp;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	PrintArray(arr, len);
}

void Task2()
{
	int arrLen;
	std::cout << "enter array len: ";
	std::cin >> arrLen;
	std::cout << std::endl;

	std::string alp = "abcdefghijklmnopqrstuvwxyz";

	char arr[1000] = { 0 };

	for (int i = 0; i < arrLen; i++)
	{
		arr[i] = alp[rand() % 27];
	}

	PrintArray(arr, arrLen);
	SortType2(arr, arrLen);
	ChooseTask();
}

void SortType2(char* arr, int len)
{
	const int alp = 26;
	int iarr[alp] = { 0 };

	int j = 0;

	for (int i = 0; i < len; i++)
	{
		j = int(arr[i] - 'a');
		iarr[j]++;
	}
	int i = 0;
	j = 0;
	while (j <= alp)
	{
		if (iarr[j] > 0)
		{
			arr[i] = char(int('a') + j);
			i++;
			iarr[j]--;
		}
		else
		{
			j++;
		}
	}

	PrintArray(arr, len);
}

void Task3()
{
	int arrLen;
	std::cout << "enter array len: ";
	std::cin >> arrLen;
	std::cout << std::endl;

	int arr[1000] = { 0 };

	for (int i = 0; i < arrLen; i++)
	{
		arr[i] = rand() % 200 - 100;
	}

	PrintArray(arr, arrLen);
	SortType3(arr, arrLen, 0, arrLen - 1);
	PrintArray(arr, arrLen);
	ChooseTask();
}

void SortType3(int* arr, int len, int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}

	int mid = lo + (hi - lo) / 2;
	SortType3(arr, len, lo, mid);
	SortType3(arr, len, mid + 1, hi);

	int buf[1000] = { 0 };
	for (int k = lo; k <= hi; k++)
	{
		buf[k] = arr[k];
	}

	int i = lo;
	int j = mid + 1;

	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
		{
			arr[k] = buf[j];
			j++;
		}
		else if (j > hi)
		{
			arr[k] = buf[i];
			i++;
		}
		else if (buf[j] < buf[i])
		{
			arr[k] = buf[j];
			j++;
		}
		else
		{
			arr[k] = buf[i];
			i++;
		}
	}
}