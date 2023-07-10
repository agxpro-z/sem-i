/*
    Q4. Write a program to perform matrix addition using operator overloading concept.
*/

#include <iostream>

using namespace std;

class Matrix {
    int m_row, m_col;
    int** m_data;

  public:
    Matrix(int row = 0, int col = 0) : m_row(row), m_col(col), m_data(NULL) {
        // Create matrix of user defined length
        m_data = new int*[row];
        for (int i = 0; i < row; ++i) {
            m_data[i] = new int[col];
        }
    }

    // Copy constructor
    Matrix(const Matrix& m);

    ~Matrix() {
        for (int i = 0; i < m_row; ++i)
            delete[] m_data[i];
        delete[] m_data;
    }

    void getData();
    void show();
    Matrix operator+(const Matrix& m);
};

// Copy constructor
Matrix::Matrix(const Matrix& m) {
    m_row = m.m_row;
    m_col = m.m_col;

    // Create matrix of user defined length
    m_data = new int*[m_row];
    for (int i = 0; i < m_row; ++i) {
        m_data[i] = new int[m_col];
    }

    // Copy matrix values
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            m_data[i][j] = m.m_data[i][j];
        }
    }
}

void Matrix::getData() {
    for (int i = 0; i < m_row; ++i) {
        cout << "Enter row " << i + 1 << '\n';
        for (int j = 0; j < m_col; ++j) {
            cin >> m_data[i][j];
        }
    }
}

void Matrix::show() {
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            cout << m_data[i][j] << ' ';
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix& m) {
    Matrix mat(m_row, m_col);

    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j)
            mat.m_data[i][j] = m_data[i][j] + m.m_data[i][j];
    }
    return mat;
}

int main() {
    cout << "Enter no. of rows: ";
    int row;
    cin >> row;

    cout << "Enter no. of columns: ";
    int col;
    cin >> col;

    Matrix m1(row, col), m2(row, col);
    cout << "\nMatrix 1\n";
    m1.getData();
    cout << "\nMatrix 2\n";
    m2.getData();
    Matrix m3(m1 + m2);

    cout << "\n\nMatrix 1:\n\n";
    m1.show();
    cout << "\n\nMatrix 2:\n\n";
    m2.show();
    cout << "\n\nMatrix 1 + Matrix 2: \n\n";
    m3.show();
    cout << "\n\n";

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter no. of rows: 4
Enter no. of columns: 4

Matrix 1
Enter row 1
1 2 3 4
Enter row 2
1 2 3 4
Enter row 3
1 2 3 4
Enter row 4
1 2 3 4

Matrix 2
Enter row 1
4 3 2 1
Enter row 2
4 3 2 1
Enter row 3
4 3 2 1
Enter row 4
4 3 2 1


Matrix 1:

1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 


Matrix 2:

4 3 2 1 
4 3 2 1 
4 3 2 1 
4 3 2 1 


Matrix 1 + Matrix 2: 

5 5 5 5 
5 5 5 5 
5 5 5 5 
5 5 5 5 

*/