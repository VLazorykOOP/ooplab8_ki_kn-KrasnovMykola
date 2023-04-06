#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
int partition(T arr[], int start, int end)
{
    T pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

int partition(char* arr[], int start, int end)
{
    char pivot[256];
    strcpy(pivot, arr[start]);

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (strcmp(arr[i], pivot) <= 0)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (strcmp(arr[i], pivot) <= 0)
            i++;
        while (strcmp(arr[j], pivot) > 0)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

template <typename T>
void quickSort(T arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
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
    quickSort(arrInt, 0, 4);
    printArray(arrInt, 5);
	cout << endl;
	double arrDouble[5] = { 3.1, 4.1, 3.0, 4.1, 2.5 };
    printArray(arrDouble, 5);
    quickSort(arrDouble, 0, 4);
    printArray(arrDouble, 5);
	cout << endl;
	char* arrString[5] = { (char*)"abc", (char*)"asd", (char*)"abc", (char*)"xyz", (char*)"qwe" };
    printArray(arrString, 5);
    quickSort(arrString, 0, 4);
    printArray(arrString, 5);
	cout << endl;
    return 0;
}