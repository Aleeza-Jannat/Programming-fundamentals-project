#include <iostream>

using namespace std;

// Function to take matrix dimensions and elements from the user
void matrix_input(double** matrix, int M, int N, string prompt) {
    cout << "\n==========================\n";
    cout << "Enter the elements of the matrix " << prompt << ":\n";
    cout << "==========================\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            // Validate the input for each matrix element
            while (!(cin >> matrix[i][j])) {
                cout << "Invalid input. Please enter a numeric value for element [" << i + 1 << "][" << j + 1 << "]: ";
                cin.clear();            // clear error flags
                cin.ignore(1000, '\n'); // discard invalid input
            }
        }
    }
}

// Function to add two matrices
void matrix_addition(double** matrix1, double** matrix2, double** result, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void matrix_subtraction(double** matrix1, double** matrix2, double** result, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void matrix_multiplication(double** matrix1, double** matrix2, double** result, int M1, int N1, int M2, int N2) {
    // Check if matrices can be multiplied
    if (N1 != M2) {
        cout << "Matrix multiplication is not possible due to incompatible dimensions.\n";
        return;
    }

    for (int i = 0; i < M1; ++i) {
        for (int j = 0; j < N2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to display a matrix
void display_matrix(double** matrix, int M, int N, string matrix_name) {
    cout << "\n=====================================\n";
    cout << "Matrix " << matrix_name << ":\n";
    cout << "=====================================\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n=====================================\n";
}

int main() {
    int M1, N1, M2, N2;

    // Input matrix dimensions and elements for matrix 1
    cout << "\n==============================\n";
    cout << "Enter dimensions of matrix 1 (M1 x N1):\n";
    cout << "==============================\n";
    while (!(cin >> M1) || M1 <= 0) {
        cout << "Invalid input. Enter a positive integer for M1: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    while (!(cin >> N1) || N1 <= 0) {
        cout << "Invalid input. Enter a positive integer for N1: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    double** matrix1 = new double* [M1];
    for (int i = 0; i < M1; ++i) {
        matrix1[i] = new double[N1];
    }
    matrix_input(matrix1, M1, N1, "1");

    // Input matrix dimensions and elements for matrix 2
    cout << "\n==============================\n";
    cout << "Enter dimensions of matrix 2 (M2 x N2):\n";
    cout << "==============================\n";
    while (!(cin >> M2) || M2 <= 0) {
        cout << "Invalid input. Enter a positive integer for M2: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    while (!(cin >> N2) || N2 <= 0) {
        cout << "Invalid input. Enter a positive integer for N2: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    double** matrix2 = new double* [M2];
    for (int i = 0; i < M2; ++i) {
        matrix2[i] = new double[N2];
    }
    matrix_input(matrix2, M2, N2, "2");

    // Check if matrices can be added and subtracted
    if (M1 != M2 || N1 != N2) {
        cout << "Matrices cannot be added or subtracted due to different dimensions.\n";
    }
    else {
        // Perform addition
        double** add_result = new double* [M1];
        for (int i = 0; i < M1; ++i) {
            add_result[i] = new double[N1];
        }
        matrix_addition(matrix1, matrix2, add_result, M1, N1);

        display_matrix(add_result, M1, N1, "Addition");

        // Perform subtraction
        double** sub_result = new double* [M1];
        for (int i = 0; i < M1; ++i) {
            sub_result[i] = new double[N1];
        }
        matrix_subtraction(matrix1, matrix2, sub_result, M1, N1);

        display_matrix(sub_result, M1, N1, "Subtraction");
    }

    // Check if matrices can be multiplied
    if (N1 != M2) {
        cout << "Matrix multiplication is not possible due to incompatible dimensions.\n";
    }
    else {
        // Perform multiplication
        double** mul_result = new double* [M1];
        for (int i = 0; i < M1; ++i) {
            mul_result[i] = new double[N2];
        }
        matrix_multiplication(matrix1, matrix2, mul_result, M1, N1, M2, N2);

        display_matrix(mul_result, M1, N2, "Multiplication");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < M1; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < M2; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}
