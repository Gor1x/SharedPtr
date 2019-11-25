#include <cstring>
#include <algorithm>
#include "matrix.h"

void Matrix::initDataArray(size_t r, size_t c)
{
    _data = new int* [r];
    _data[0] = new int [r * c];
    for (size_t i = 1; i < r; i++)
        _data[i] = _data[i - 1] + c;
    memset(_data[0], 0, r * c * sizeof(int));
}

Matrix::Matrix(size_t r, size_t c) : _rows(r), _cols(c)
{
    initDataArray(_rows, _cols);
}

Matrix::Matrix(const Matrix &other) : _rows(other._rows), _cols(other._cols)
{
    initDataArray(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            _data[i][j] = other._data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    delete[] _data[0];
    delete[] _data;
}

size_t Matrix::get_rows() const
{
    return _rows;
}

size_t Matrix::get_cols() const
{
    return _cols;
}

void Matrix::set(size_t i, size_t j, int val)
{
    _data[i][j] = val;
}

int Matrix::get(size_t i, size_t j) const
{
    return _data[i][j];
}

void Matrix::print(FILE* f) const
{
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            fprintf(f, "%d ", _data[i][j]);
        }
        fprintf(f, "\n");
    }
}

bool Matrix::operator==(const Matrix& m) const
{
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            if (_data[i][j] != m.get(i, j))
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const
{
    return !(*this == m);
}

Matrix& Matrix::operator+=(const Matrix& m) {
    *this = *this + m;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
    *this = *this - m;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    *this = *this * m;
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const
{
    return plusWithMultipliedOnConstant(m, 1);
}

Matrix Matrix::operator-(const Matrix& m) const
{
    return plusWithMultipliedOnConstant(m, -1);
}

Matrix Matrix::operator*(const Matrix& m) const {
    Matrix result = Matrix(_rows, m._cols);

    size_t width = _cols;

    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < m._cols; j++)
        {
            int sum = 0;
            for (size_t ptr = 0; ptr < width; ptr++)
            {
                sum += get(i, ptr) * m.get(ptr, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other)
    {
        Matrix(other).swapWith(*this);
    }
    return *this;
}

void Matrix::swapWith(Matrix &other) {
    std::swap(_data, other._data);
    std::swap(_rows, other._rows);
    std::swap(_cols, other._cols);
}

Matrix Matrix::plusWithMultipliedOnConstant(const Matrix &matrix, int constant) const {

    Matrix result = Matrix(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            int value = get(i, j) + matrix.get(i, j) * constant;
            result.set(i, j, value);
        }
    }
    return result;
}


