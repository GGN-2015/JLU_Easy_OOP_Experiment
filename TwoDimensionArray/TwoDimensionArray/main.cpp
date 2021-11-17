//
//  main.cpp
//  TwoDimensionArray
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <iostream>

void f(int n, int m) {
    // ask for a 2 dimension array (n * m)
    int** A = new int*[n];
    for(int i = 0; i < n; i ++) {
        A[i] = new int[m];
    }
    
    // set value of the array
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int val = i * m + j + 1;
            A[i][j] = val;
        }
    }
    
    int* rows = new int[n];
    int* cols = new int[m]; // the sum of rows and columns
    
    // init the value of the sum array
    for(int i = 0; i < n; i ++) {
        rows[i] = 0;
    }
    for(int j = 0; j < m; j ++) {
        cols[j] = 0;
    }
    
    // get the sum of all rows and columns
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            rows[i] += A[i][j];
            cols[j] += A[i][j];
        }
    }
    
    // output the matrix
    std::cout << "Matrix: " << n << " * " << m << std::endl;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // output the sum of the rows
    std::cout << "Sum of rows: ";
    for(int i = 0; i < n; i ++) {
        std::cout << rows[i] << "\t";
    }
    std::cout << std::endl;
    
    // output the sum of columns
    std::cout << "Sum of cols: ";
    for(int i = 0; i < m; i ++) {
        std::cout << cols[i] << "\t";
    }
    std::cout << std::endl;
    
    // delete array: rows and cols
    delete[] rows;
    delete[] cols;
    
    // free the memory of the array
    for(int i = 0; i < n; i ++) {
        delete[] A[i];
    }
    delete[] A;
}

int main(int argc, const char * argv[]) {
    f(4, 5);
    return 0;
}
