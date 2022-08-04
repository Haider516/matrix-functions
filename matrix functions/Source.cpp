
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class Matrix
{
	private:
	
		int row_no;
		int column_no;
	public:
		Matrix()
		{
			row_no = column_no = 0;
			
		}
		Matrix(int   n,int m)
		{
			row_no = n; column_no = m;		
		}
		//_____SET AND GET FOR ROW
		int get_rows_no()
		{
			return row_no;
		}

		int set_rows_no(int input)
		{
			row_no = input;
			return row_no;
		}
		//_____SET AND GET FOR COLUMN
		int get_column_no()
		{
			return column_no;
		}

		int set_column_no(int input1)
		{
			column_no = input1;
			return column_no;
		}
	//_________________________________________________________
	
		void read_from_file(char file_name[], int& row, int& col);
		void getting_values_from_file(int** a,int&,int &);	
		void getting_values_randomly(int** list, int& , int& );
		void Printing_matrix(int** list, int& R_limit, int& C_limit);
		void  add(int** matrix_array1, int** matrix_array2, int& R_limit, int& C_limit);
		void  sub_marix(int** matrix_array1, int** matrix_array2, int& R_limit, int& C_limit);
		void transpose(int** matrix1, int& R_limit, int& C_limit);
		void mult_matrix(int** matrix_array1 ,int& R_limit, int& C_limit);
		void Menu_driven_funcion(int** matrix_array1, int** matrix_array2, int& R_limit, int& C_limit);
	//_________________________________________________________

};

void Matrix::read_from_file(char file_name[],int & row,int  & col)
{
	Matrix s;
	ifstream output;
	output.open(file_name);//FILE  NAME  FROM MAIN GIVEN  BY USER
	 //row and column
	output >> row;
	output >> col;
	
}

void Matrix::getting_values_randomly(int** list, int& R_limit, int& C_limit)
{
	cout << "RANDOMLY GENERATED MATRIX :\n";
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			 (list[loop][loop1])=1+rand()%80;

		}
	}	 
	Printing_matrix(list, R_limit, C_limit);
}

void Matrix::getting_values_from_file(int** list, int& R_limit, int& C_limit)
{
	
	char File_name[20];
	cout << "\nENTER FILE NAME FOR GENERATING MATRIX:";
	cin.getline(File_name, 20);
	cout << "\nMATRIX CONSTRUCTED FROM USERS FILE:\n";
	ifstream output;
	output.open(File_name);	//FILE  NAME  FROM MAIN GIVEN  BY USER
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			output>>(list[loop][loop1]);
		}
	}	
	Printing_matrix(list, R_limit, C_limit);
}

void  Matrix::Printing_matrix(int**list,int & R_limit, int & C_limit)
{
	cout << "\n MATRIX :\n";
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			cout << list[loop][loop1] << " ";
		}
		cout << endl;
	}	
}

void  Matrix:: add(int**matrix_array1, int**matrix_array2, int &R_limit, int&C_limit)
{

	int** sum= new int* [R_limit];
	for (int loop = 0; loop < R_limit; loop++)
	{
		sum[loop] = new int[C_limit];
	}
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			sum[loop][loop1] = matrix_array1[loop][loop1] + matrix_array2[loop][loop1];
		}
		cout << endl;
	}
	Printing_matrix(sum, R_limit, C_limit);
}

void Matrix::sub_marix(int** matrix_array1, int** matrix_array2, int& R_limit, int& C_limit)
{
	int** sub = new int* [R_limit];
	for (int loop = 0; loop < R_limit; loop++)
	{
		sub[loop] = new int[C_limit];
	}
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			sub[loop][loop1] = matrix_array1[loop][loop1] - matrix_array2[loop][loop1];
		}
		cout << endl;
	}

	Printing_matrix(sub, R_limit, C_limit);

};

void Matrix::mult_matrix(int** matrix_array1, int& R_limit, int& C_limit)
{
	int col;
	int row;
	cout << "Entre Column for Second Matrix :"; cin >> col;
	cout << "Entre Row for Second Matrix :"; cin >> row;
	while (C_limit!=row)
	{
		cout << "LOGIC ERROR!...RE-ENTRE THE ROW AND COLUMN FOR SECOND MATRIX ";
		cout << "\nEntre Column for Second Matrix :"; cin >> col;
		cout << "\nEntre Row for Second Matrix :"; cin >> row;
	}
	//INTIALIZING A NEW MATRIX
	int** list = new int* [row];
	for (int loop = 0; loop < row; loop++)
	{
		list[loop] = new int[col];
	}
	getting_values_randomly( list, row, col);

	//INTIALIZING A  MATRIX TO STORE RESULTING MATRIX
	int** mult = new int* [R_limit];
	for (int loop = 0; loop < R_limit; loop++)
	{
		mult[loop] = new int[C_limit];
	}

	//INTIALIZING A  MATRIX TO ZERO
	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)
		{
			mult[loop][loop1] = 0;
		}
	}
	

	for (int loop = 0; loop < R_limit; loop++)
	{
		for (int loop1 = 0; loop1 < col; loop1++)
		{
			for (int loop3 = 0; loop3 < C_limit; loop3++)
			{
				mult[loop][loop1] += matrix_array1[loop][loop3] *list[loop3][loop1];
				
			}
		}
	}
	Printing_matrix(mult, R_limit, C_limit);
}

void Matrix::transpose(int** matrix1, int& R_limit, int& C_limit)
{
	int** transpose = new int* [R_limit];
	for (int loop = 0; loop < R_limit; loop++)
	{
		transpose[loop] = new int[C_limit];
	}

	for (int loop = 0; loop < R_limit; loop++)//4
	{
		for (int loop1 = 0; loop1 < C_limit; loop1++)//3
		{
			transpose[loop1][loop] = matrix1[loop][loop1];
			
		}
		cout << endl;
	}
	Printing_matrix(transpose, C_limit, R_limit);
}
void Matrix::Menu_driven_funcion(int** matrix_array1, int** matrix_array2, int& R_limit, int& C_limit)
{
	Matrix s;
	while (true)
	{
		int op;
		cout << "\n._._._._._._._._._._.MATRIX_CALCULATOR._._._._._._._._._._.\n";
		cout << "PRESS 1 FOR ADDITION\n";
		cout << "PRESS 2 FOR SUBTRACTION\n";
		cout << "PRESS 3 FOR MULTIPLICATION\n";
		cout << "PRESS 4 FOR TRNASPOSE OF MATRIX 1\n";
		cout << "PRESS 5 FOR TRNASPOSE OF MATRIX 2\n";
		cout << "PRESS 6 FOR EXIT\n";
		cin >> op;
		if (op == 1)
		{
			cout << "\nMatrix After Addition\n";
			s.add(matrix_array1, matrix_array2, R_limit, C_limit);
			cout << endl;

		}
		else if (op == 2)
		{
			cout << "\nMatrix After Subtraction\n";
			s.sub_marix(matrix_array1, matrix_array2, R_limit, C_limit);
			cout << endl;
		}
		else if (op == 3)
		{
			cout << "\nMatrix After Multiplication\n";
			s.mult_matrix(matrix_array1,  R_limit, C_limit);

		}
		else if (op == 4)
		{
			cout << "\nTranspose Of Matrix:1\n";
			s.transpose(matrix_array1, R_limit, C_limit);
			cout << endl;

		}
		else if (op == 5)
		{
			cout << "\nTranspose Of Matrix:2\n";
			s.transpose(matrix_array2, R_limit, C_limit);

		}
		else
		{
			
			false;
			break;
		}

	}
}

int main()
{
	Matrix s;
	int row ;
	int col ;
	char File_name[20];
	cout << "ENTER  THE FILE NAME FOR ACCESSING ROWS ANS  COLUMN \n";
	cin.getline(File_name, 20);
	s.read_from_file(File_name,row,col);
	s.set_rows_no(row);		//4
	s.set_column_no(col);	//3
	cout << endl;
	cout << "THE ROW NUMBER IS" << s.get_rows_no();
	cout << endl;
	cout << "THE COLUMN NUMBER IS" << s.get_column_no();
	cout << endl;
	//________DYNAMIC_ALLOCATION_OF_TWO-D_ARRAY_________
	//INTIALIZING  MATRIX #1
	int** matrix_array1 =new int* [s.get_rows_no()];
	for (int loop = 0; loop < s.get_rows_no(); loop++)
	{
		matrix_array1[loop] =new int [s.get_column_no()];
	}
	//INTIALIZING  MATRIX #2
	int** matrix_array2 = new int* [s.get_rows_no()];
	for (int loop = 0; loop < s.get_rows_no(); loop++)
	{
		matrix_array2[loop]  = new int[s.get_column_no()];
	}

	int R_limit = s.get_rows_no();
	int C_limit = s.get_column_no();	
	//FOR MATRIX 1
	s.getting_values_randomly(matrix_array2, R_limit, C_limit);
	//FOR MATRIX 2
	s.getting_values_from_file(matrix_array1, R_limit, C_limit);//Num_file.txt
	//________________________MENU____________________________

	s.Menu_driven_funcion(matrix_array1, matrix_array2, R_limit, C_limit);
	delete[]matrix_array1;
	delete[]matrix_array2;
	return 0;
}
	
