#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

/*************************************************************************
Two-Dimensional Matrix

Current Public Operations
1. operator[]
2. row()
3. col()
4. setRow()
5. setCol()
6. operator* - Matrix Multiplication

Construction
1. No Arguments
2. int rows , int columns
3. Brace-Enclosed Initialization List
*************************************************************************/
template <typename Object>
class Matrix
{
public:
    // Default Constructor
    Matrix();

    Matrix( int rows , int cols );

    Matrix( std::initializer_list< std::initializer_list<Object> > initList );

    // Read-Only operator[]
    const std::vector<Object> & operator[] ( int row ) const;

    // Read-Write operator[]
    std::vector<Object> & operator[] ( int row );

    // Matrix Multiplication
    Matrix operator* ( const Matrix &rhs ) const;

    int row() const;

    int col() const;ub


    void setRow( int row );

    void setCol( int col );

private:
    std::vector< std::vector<Object> > arr;
};


/*************************************************************************
                              Implementation
*************************************************************************/
template <typename Object>
Matrix<Object>::Matrix() {}

template <typename Object>
Matrix<Object>::Matrix( int rows , int cols ): arr( rows )
{
    for( auto& thisRow : arr ) {
        thisRow.resize( cols );
    }
}

template <typename Object>
Matrix<Object>::Matrix( std::initializer_list< std::initializer_list<Object> > initList )
: arr( initList.begin() , initList.end() )
{
    std::size_t sz = 0;

    for( const auto &row : arr ) {
        if( sz < row.size() ) {
            sz = row.size();
        }
    }

    for( auto &row : arr ) {
        row.resize( sz );
    }
}


template <typename Object>
const std::vector<Object> & Matrix<Object>::operator[] ( int row ) const
{
    return arr[row];
}

template <typename Object>
std::vector<Object> & Matrix<Object>::operator[] ( int row )
{
    return arr[row];
}

template <typename Object>
int Matrix<Object>::row() const
{
    return arr.size();
}

template <typename Object>
void Matrix<Object>::setRow( int row )
{
    arr.resize( row );
}

template <typename Object>
void Matrix<Object>::setCol( int col )
{
    for( auto &s : arr ) {
        s.resize( col );
    }
}

template <typename Object>
int Matrix<Object>::col() const
{
    return row() ? arr[0].size() : 0;
}

template <typename Object>
Matrix<Object> Matrix<Object>::operator* ( const Matrix &rhs ) const
{
    // Check for compatible dimensions
    if( this->col() == rhs.row() ) {
        Matrix result{ this->row() , rhs.col() };

        // Initialize all cells to 0
        for( int row = 0 ; row < result.row() ; row++ ) {
            for( int col = 0 ; col < result.col() ; col++ ) {
                result[row][col] = 0;
            }
        }

        // Perform multiplication
        for( int row = 0 ; row < result.row() ; row++ ) {
            for( int col = 0 ; col < result.col() ; col++ ) {
                for( int i = 0 ; i < this->col() ; i++ ) {
                    result[row][col] += this->arr[row][i] * rhs[i][col];
                }
            }
        }

        return result;
    }
    else {
        throw std::invalid_argument
        ( "The given matrices do not have compatible dimensions for multiplication.\n" );
    }
}

// Overload operator<< for Matrix Objects
template <typename Object>
std::ostream & operator<< ( std::ostream &out , Matrix<Object> matrix ) {

    for( int row = 0 ; row < matrix.row() ; row++ ) {
        out << "[ ";

        for( int col = 0 ; col < matrix.col() ; col++ ) {
            out << matrix[row][col] << " ";
        }
        out << ']' << std::endl;
    }

    return out;
}

#endif // MATRIX_H_INCLUDED
