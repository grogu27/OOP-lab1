#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int** genRandMatrix(int size, int maxValue)
{
    srand(time(NULL));
    int cols;
    int** arr = new int* [size + 1];
    arr[0] = new int [1];
    arr[0][0] = size;
    for (int i = 1; i <= arr[0][0]; i++)
    {
        cols = rand() % 10;
        arr[i] = new int[cols + 1];
        arr[i][0] = cols;
        for (int j = 1; j <= arr[i][0]; j++)
            arr[i][j] = rand() % maxValue;
    }  
    // for (int i = 1; i < arr[0][0]; ++i) {
    // for (int j = 1; j < arr[i][0]; ++j) {
    //     arr[i][j] = rand() % 100; 
    //     }
    // }   
    return arr;    
}

void print(int** arr)
{
    cout << arr[0][0] << endl;
    for (int i = 1; i <= arr[0][0]; i ++)
    {
        cout << arr[i][0] << ": ";
        for (int j = 1; j <= arr[i][0]; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    print(matrix);

    for (int i = 0; i < matrix[0][0]; i++)
        delete [] matrix[i];
    
    delete [] matrix;
    return 0;
}
