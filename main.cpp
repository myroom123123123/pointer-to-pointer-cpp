#include <iostream>
#include <ctime>
using namespace std;

void addColumn(int**& arr, int& rows, int& cols, int pos) {
	int** newArr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		newArr[i] = new int[cols + 1];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < pos; j++) {
			newArr[i][j] = arr[i][j];
		}
		newArr[i][pos] = rand() % 100;
		for (int j = pos + 1; j < cols + 1; j++) {
			newArr[i][j] = arr[i][j - 1];
		}
	}
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = newArr;
	cols++;
}

int main() {
    using namespace std;

    int rows, cols, position;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    cout << "Enter the position to add a new column: ";
    cin >> position;

    if (position < 0 || position > cols) {
        cout << "Invalid position." << endl;
        return 1;
    }

    addColumn(array, rows, cols, position);

    cout << "Array after adding the column:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
