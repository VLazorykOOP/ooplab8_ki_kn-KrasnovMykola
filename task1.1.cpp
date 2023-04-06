#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
int lastIndexOf(T* arr, int size, const T key)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int lastIndexOf(char** arr, int size, const char* key)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (strcmp(arr[i], key) == 0)
			return i;
	}
	return -1;
}

template <typename T>
void printArray(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arrInt[5] = { 3, 1, 3, 4, 2 };
	printArray(arrInt, 5);
	cout << "Last index of 3: " << lastIndexOf<int>(arrInt, 5, 3) << endl;
	cout << "Last index of 4: " << lastIndexOf(arrInt, 5, 4) << endl;
	cout << "Last index of 10: " << lastIndexOf(arrInt, 5, 10) << endl << endl;
	double arrDouble[5] = { 3.1, 4.1, 3.0, 4.1, 2.5 };
	printArray(arrDouble, 5);
	cout << "Last index of 4.1: " << lastIndexOf<double>(arrDouble, 5, 4.1) << endl;
	cout << "Last index of 3.0: " << lastIndexOf(arrDouble, 5, 3.0) << endl;
	cout << "Last index of 10.0: " << lastIndexOf(arrDouble, 5, 10.0) << endl << endl;
	char* arrString[5] = { (char*)"abc", (char*)"asd", (char*)"abc", (char*)"xyz", (char*)"qwe" };
	printArray(arrString, 5);
	cout << "Last index of abc: " << lastIndexOf<char*>(arrString, 5, (char*)"abc") << endl;
	cout << "Last index of xyz: " << lastIndexOf(arrString, 5, (char*)"xyz") << endl;
	cout << "Last index of sdf: " << lastIndexOf(arrString, 5, (char*)"sdf") << endl;
    return 0;
}
