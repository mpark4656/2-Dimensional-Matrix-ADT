#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <algorithm>

template <typename Object>
class Matrix
{
public:
    Matrix( int rows , int cols );

    Matrix( const std::vector< std::vector<Object> > &copyVector );

    Matrix( std::vector< std::vector<Object> > &&copyVector );

    const std::vector<Object> & operator[] ( int row ) const;

    std::vector<Object> & operator[] ( int row );

    int row() const;

    int col() const;

private:
    std::vector< std::vector<Object> > arr;
};

template <typename Object>
Matrix<Object>::Matrix( int rows , int cols ): arr( rows ) {

    for( auto& thisRow : arr ) {
        thisRow.resize( cols );
    }
}

template <typename Object>
Matrix<Object>::Matrix( const std::vector< std::vector<Object> > &copyVector ): arr{ copyVector } {}

template <typename Object>
Matrix<Object>::Matrix( std::vector< std::vector<Object> > &&copyVector ): arr{ std::move( copyVector ) } {}

template <typename Object>
const std::vector<Object> & Matrix<Object>::operator[] ( int row ) const {

    return arr[row];
}

template <typename Object>
std::vector<Object> & Matrix<Object>::operator[] ( int row ) {

    return arr[row];
}

template <typename Object>
int Matrix<Object>::row() const {

    return arr.size();
}

template <typename Object>
int Matrix<Object>::col() const {

    return row() ? arr[0].size() : 0;
}

#endif // MATRIX_H_INCLUDED
