#include <iostream>
#include <stdexcept>
#include "Matrix.h"

// Test Driver
int main()
{
    Matrix<int> matrix1 = { {-4} ,
                            {1} ,
                            {5} };

    std::cout << "Matrix1:\n" << matrix1;

    Matrix<int> matrix2 = { {1 , 2 , 3} ,
                            {4 , 5 , 6} ,
                            {7 , 8 , 9} };


    std::cout << "\nMatrix2:\n" << matrix2;

    std::cout << "\nmatrix1 * matrix2 = \n";
    try {
        std::cout << matrix1 * matrix2;
    }
    catch( std::invalid_argument invalidArg ) {
        std::cerr << "Error: " << invalidArg.what();
    }

    Matrix<int> matrix3 = { {-4 , 2 , 4} ,
                            {1 , 0 , 6} ,
                            {5 , 8 , 5} };

    std::cout << "\nMatrix3:\n" << matrix3;

    std::cout << "\nMatrix2 * Matrix3 = \n";
    try {
         std::cout << matrix2 * matrix3;
    }
    catch( std::invalid_argument invalidArg ) {
        std::cerr << "Error: " << invalidArg.what();
    }


    // Is there a way to use brace-enclosed initialization list like this?
    Matrix<int> matrix4 = { {1 , 2 , 3} ,
                            {4 , 5 , 6} ,
                            {7 , 8 , 9} };

    std::cout << "\nMatrix4:\n";
    std::cout << matrix4;

    return 0;
}
