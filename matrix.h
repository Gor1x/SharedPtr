#ifndef MATRIX_H
#define MATRIX_H


#include <cstdio>
#include <cstddef>


using std::size_t;

class Matrix {
public:
    Matrix(size_t r, size_t c);

    Matrix(const Matrix &other);

    size_t get_rows() const;
    size_t get_cols() const;

    void set(size_t i, size_t j, int val);
    int get(size_t i, size_t j) const;
    void print(FILE *f) const;


    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;

    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    Matrix& operator*=(const Matrix& m);

    Matrix& operator=(const Matrix &other);

    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;

    ~Matrix();

    void swapWith(Matrix &m);

private:

    Matrix plusWithMultipliedOnConstant(const Matrix &matrix, int value) const;
    void initDataArray(size_t r, size_t c);

    size_t _rows;
    size_t _cols;
    int **_data;

};


#endif //MATRIX_H
