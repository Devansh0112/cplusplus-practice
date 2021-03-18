// array representation
#include <iostream>

using namespace std;

int main()
{
    int matrix[3][3] = {
        {0, 0, 3},
        {4, 2, 0},
        {0, 5, 7}};

    int size = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i][j] != 0)
                size++;

    cout<< "size : "<<size<<endl;

    int sparse_matrix[3][size];
    int k = 0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(matrix[i][j] != 0)
            {
                sparse_matrix[0][k] = i;
                sparse_matrix[1][k] = j;
                sparse_matrix[2][k] = matrix[i][j];
                k++;
            }

    // printing sparse matrix
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
            cout << sparse_matrix[i][j];
        
        cout << endl;
    }
    return 0;
}