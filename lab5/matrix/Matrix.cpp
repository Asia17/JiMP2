//
// Created by Asia on 2018-04-11.
//


#include "Matrix.h"
using algebra::Matrix;

std::complex<double> funkcja(string value_s)
{
    string real = value_s.substr(0,value_s.find('i'));
    string imaginary = value_s.substr(value_s.find('i')+1,value_s.length());
    double r = std::stod(real);
    double i = std::stod(imaginary);
    std::complex<double> o;
    o.real(r);
    o.imag(i);
    return o;
}

Matrix::Matrix(string matrix_str) {

    long srednik = std::count(matrix_str.begin(), matrix_str.end(), ';');
    n_rows = int(srednik + 1);
    string tmp = matrix_str.substr(0, matrix_str.find(';'));
    long odstepy = std::count(tmp.begin(), tmp.end(), ' ');
    n_cols = int(odstepy + 1);

    std::complex<double> **tablica = new std::complex<double>  *[n_rows];
    for (int i=0; i< n_rows; i++)
        tablica[i]=new std::complex<double>  [n_cols];
    array = tablica;

    string line;
    line = matrix_str.substr(1, matrix_str.length() - 2);
    regex pattern {R"(\w+\.*\w+\.*\w+)"};
    string rendered="";
    smatch matches;
    int row = 0;
    int col =0;

    while (std::regex_search (line,matches, pattern)) {
        for (auto match: matches)
        {

            string znalezione = match.str();
            array[row][col] = funkcja(znalezione);
            col++;
            if(col > n_cols - 1) {
                col = 0;
                row++;
            }
        }
        line = matches.suffix().str();
    }
}

Matrix::Matrix(int rows, int cols) {
    n_rows = rows;
    n_cols = cols;
    if ((rows<0)||(cols<0))
        std::cout<<"Bledne wartosci!";

    std::complex<double> **tablica = new std::complex<double>  *[rows];
    for (int i=0; i< rows; i++)
        tablica[i]=new std::complex<double>  [cols];
    array = tablica;
}

Matrix::Matrix(const Matrix &matrix)
{
    n_cols = matrix.n_cols;
    n_rows = matrix.n_rows;
    std::complex<double> **new_array = new std::complex<double>  *[n_rows];
    for (int i=0; i< n_rows; i++)
        new_array[i]=new std::complex<double>  [n_cols];

    for (int i=0; i<n_rows; i++)
    {
        for (int j=0;j<n_cols; j++)
        {
            new_array[i][j]=matrix.array[i][j];
        }
    }
    array = new_array;
}

Matrix & Matrix::operator=(const Matrix& matrix) {
    if (this == &matrix)
    {
        return *this;
    }
    for (int i=0; i<n_rows; i++)
    {
        delete [] array [i];
    }
    delete [] array;
    n_cols = matrix.n_cols;
    n_rows = matrix.n_rows;
    std::complex<double> **new_array = new std::complex<double>  *[n_rows];
    for (int i=0; i< n_rows; i++)
        new_array[i]=new std::complex<double>  [n_cols];

    for (int i=0; i<n_rows; i++)
    {
        for (int j=0;j<n_cols; j++)
        {
            new_array[i][j]=matrix.array[i][j];
        }
    }
    array = new_array;

}


Matrix Matrix::Sub(const Matrix &matrix) {
    if ((n_rows ==matrix.n_rows)&&(n_cols == matrix.n_cols))
    {
        Matrix new_matrix(n_rows, n_cols);
        for(int i= 0; i<n_rows; i++)
        {
            for(int j=0; j<n_cols;j++)
            {
                new_matrix.array[i][j] = array[i][j] - matrix.array[i][j];
            }
        }
        return new_matrix;
    }
    else
        return Matrix();
}

Matrix Matrix::Add(const Matrix &matrix) const {
    if ((n_rows ==matrix.n_rows)&&(n_cols == matrix.n_cols))
    {
        Matrix new_matrix(n_rows, n_cols);
        for(int i= 0; i<n_rows; i++)
        {
            for(int j=0; j<n_cols;j++)
            {
                new_matrix.array[i][j] = array[i][j] + matrix.array[i][j];
            }
        }
        return new_matrix;
    }
    else
        return Matrix();
}


Matrix Matrix::Mul(const Matrix &matrix) {
    if (n_cols == matrix.n_rows)
    {   std::complex<double> zmienna_pomocnicza = 0i;
        Matrix new_matrix(n_rows, matrix.n_cols);
        for(int i= 0; i<n_rows; i++)
        {
            for(int j=0; j<matrix.n_cols;j++)
            {
                zmienna_pomocnicza = 0i;
                for(int k=0; k<n_cols; k++)
                {
                    zmienna_pomocnicza+=array[i][k]*matrix.array[k][j];
                }
                new_matrix.array[i][j] = zmienna_pomocnicza;
            }
        }
        return new_matrix;
    }
    else
    {
        Matrix poz(0,0);
        return poz;
    }

}

Matrix Matrix::Pow(int potega) {

    if(potega==0)
    {
        Matrix new_matrix(n_rows, n_cols);
        for(int i=0; i<n_rows; i++)
        {
            for(int j=0; j<n_cols; j++)
            {
                if(i==j)
                    new_matrix.array[i][j] = 1;
                else
                    new_matrix.array[i][j] = 0;
            }
        }
        return new_matrix;
    }
    else
    {
        Matrix new_matrix(*this);
        Matrix first_matrix(*this);

        while(potega > 1)
        {
            new_matrix = new_matrix.Mul(first_matrix);
            potega--;
        }
        return new_matrix;
    }
}



std::pair<size_t, size_t> Matrix::Size() {
    return std::pair<size_t, size_t>{n_rows,n_cols};
}

Matrix::Matrix() {
    n_rows = n_cols = 0;
}

string transfer_danych(double objekt) {
    string objekt1 = std::to_string(objekt);
    for(int i=int(objekt1.length())-1; i>=0; i--)
    {
        if (objekt1[i] != '0')
        {
            break;
        }
        else
        {
            objekt1 = objekt1.substr(0, objekt1.length()-1);
        }
    }
    if (objekt1[objekt1.length()-1]=='.')
        objekt1 = objekt1.substr(0, objekt1.length()-1);
    return objekt1;
}

string Matrix::Print() const {
    if (n_cols == 0)
    {
        return "[]";
    }
    string ret ="[";
    for(int i=0; i<n_rows; i++)
    {
        for( int j=0; j<n_cols; j++)
        {
            ret += transfer_danych(array[i][j].real());
            ret += "i";
            ret+= transfer_danych(array[i][j].imag());

            if(j!=n_cols-1)
                ret += ", ";
        }
        if(i!=n_rows-1)
            ret += "; ";
    }
    ret += "]";
    return ret;
}

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list) {

    int num_row = int(matrix_list.size());
    unsigned long num_col =0;
    for(auto row : matrix_list)
    {
        num_col = row.size();
        break;
    }

    n_cols = int(num_col);
    n_rows = num_row;

    std::complex<double> **tablica = new std::complex<double>  *[n_rows];
    for (int i=0; i< n_rows; i++)
        tablica[i]=new std::complex<double>  [n_cols];
    array = tablica;
    array[0][0] = 1.0 + 1.0i;


    int i=0;
    int j=0;
    for(std::vector<std::complex<double>> row : matrix_list)
    {
        j=0;
        for(std::complex<double> element : row)
        {
            array[i][j] = element;
            j++;
        }
        i++;
    }


}

Matrix::~Matrix() {
    for (int i=0; i<n_rows; i++)
    {
        delete [] array [i];
    }
    delete [] array;

}