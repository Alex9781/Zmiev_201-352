#include <iostream>

void ChooseTask(int *arr, int *arr_len);

void Task1(int* arr, int* arr_len);
void Task2(int* arr, int* arr_len);
void Task3(int* arr, int* arr_len);
void Task4(int* arr, int* arr_len);

int DigitSum(int* n);

int main()
{
	int arr_len = 0;
	int* arr = new int[arr_len];
	ChooseTask(arr, &arr_len);
	return 0;
}

void ChooseTask(int* arr, int* arr_len)
{
	int task = 0;
	std::cout << "choose task \n"
		<< "1. task 1 \n"
		<< "2. task 2 \n"
		<< "3. task 3 \n"
		<< "4. task 4 \n"
		<< "5. exit \n";

	std::cin >> task;
	std::cout << std::endl;

	switch (task)
	{
	case 1:
		Task1(arr, arr_len);
		break;
	case 2:
		Task2(arr, arr_len);
		break;
	case 3:
		Task3(arr, arr_len);
		break;
	case 4:
		Task4(arr, arr_len);
		break;
	case 5:
		exit(0);
		break;
	default:
		std::cout << "error" << std::endl;
		ChooseTask(arr, arr_len);
		break;
	}
}

void Task1(int* arr, int* arr_len)
{
	std::cout << "array len: ";
	std::cin >> *arr_len;
	std::cout << std::endl;

	for (int i = 0; i < *arr_len; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << std::endl;
	ChooseTask(arr, arr_len);
}

void Task2(int* arr, int* arr_len)
{
	for (int i = 0; i < *arr_len; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::endl;
	ChooseTask(arr, arr_len);
}


void Task3(int* arr, int* arr_len)
{
	for (int i = 0; i < *arr_len; i++)
	{
		for (int j = 0; j < *arr_len - i - 1; j++)
		{
			if (DigitSum(&arr[j]) > DigitSum(&arr[j + 1]))
			{
				int buff = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = buff;
			}
		}
	}

	ChooseTask(arr, arr_len);
}

int DigitSum(int* n)
{
	int result = 0;
	int buff = *n;
	int k = 0;
	while (buff > 0)
	{
		buff /= 10;
		k++;
	}

	for (int i = 1; i < k; i += 2)
	{
		result += (*n / int(pow(10, i))) % 10;
	}
	return result;
}

void Task4(int* arr, int* arr_len)
{
	for (int i = 0; i < *arr_len; i++)
	{
		for (int j = 0; j < *arr_len - i - 1; j++)
		{
			if (arr[j] % 10 > arr[j + 1] % 10)
			{
				int buff = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = buff;
			}
			else if ((arr[j] % 10 == arr[j + 1] % 10) && (arr[j] < arr[j + 1]))
			{
				int buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
		}
	}

	ChooseTask(arr, arr_len);
}