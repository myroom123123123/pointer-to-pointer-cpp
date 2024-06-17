#include <iostream>
#include <ctime>
using namespace std;

void removeColumn(int** arr, int rows, int cols, int colToRemove)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = colToRemove; j < cols - 1; j++)
		{
			arr[i][j] = arr[i][j + 1];
		}
	}
}

int main()
{
	srand(time(0));
	int rows = 5, cols = 5, colToRemove = 2;
	int** arr = new int* [rows];
	cout << "Choose a column to remove (0-4): ";
	cin >> colToRemove;
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	removeColumn(arr, rows, cols, colToRemove);
	cout << "\nArray after removing column " << colToRemove << ":\n" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}