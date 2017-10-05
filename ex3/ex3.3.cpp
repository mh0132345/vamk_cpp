#include <iostream>
using namespace std;

int main(void){
	int i, j, k, r1, c1, r2, c2;
	
	cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // Input until column of first matrix = row of second matrix
    while (c1!=r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }
	
	//Initializing for 2 matrix and the result matrix
	int** matrix1 = new int*[r1];
	for(int i = 0; i < r1; i++)
		matrix1[i] = new int[c1];
		
	int** matrix2 = new int*[r2];
	for(int i = 0; i < r2; i++)
		matrix2[i] = new int[c2];
		
	int** mult = new int*[r1];
	for(int i = 0; i < r1; i++)
		mult[i] = new int[c2];

    //Input first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
        {
            cout << "Enter element a" << i << j << " : ";
            cin >> matrix1[i][j];
        }

    // Input second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
        {
            cout << "Enter element b" << i << j << " : ";
            cin >>matrix2[i][j];
        }

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying 2 matrix
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += matrix1[i][k] * matrix2[k][j];
            }

    cout << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i){
		for(j = 0; j < c2; ++j)
			cout << " " << mult[i][j];
		cout << endl;
	}

    return 0;
}
			
	