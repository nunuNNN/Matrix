#include "test_macros.hpp"

#include <matrix/math.hpp>

using namespace matrix;

int main()
{
    float data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3f A(data);
    A = A * 2;
    float data_check[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    Matrix3f A_check(data_check);
    TEST(isEqual(A, A_check));

    // test eigenvalues
    /*********************************************************************/
    float eigenmatrix[9] = {1.23f, 2.12f, -4.2f, 
                            2.12f, -5.6f, 8.79f, 
                            -4.2f, 8.79f, 7.3f};
    const int N{ 3 };

    fprintf(stderr, "source matrix:\n");
	int count{ 0 };
    for (const auto& value : eigenmatrix)
    {
        if (count++ % N == 0) fprintf(stderr, "\n");

        fprintf(stderr, "  %f  ", value);
    }
    fprintf(stderr, "\n\n");

    /*********************************************************************/
    fprintf(stderr, "c++ compute eigenvalues and eigenvectors, sort:\n");
    SquareMatrix<float, N> eigen_vectors1, mat1;
    Vector<float, N> eigen_values1;
    for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			mat1(i, j) = eigenmatrix[i * N + j];
		}
	}

    if (eigenvalues(mat1, eigen_values1, eigen_vectors1) != 0)
    {
        fprintf(stderr, "campute eigenvalues and eigenvector fail\n");
		return -1;
    }

    fprintf(stderr, "eigenvalues:\n");
    for (int i = 0; i < N; ++i)
    {
        fprintf(stderr, "  %f  ", eigen_values1(i));
    }
    fprintf(stderr, "\n\n");

    fprintf(stderr, "eigenvectors:\n");
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            fprintf(stderr, "  %f  ", eigen_vectors1(i, j));
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n\n");

    /*********************************************************************/
    fprintf(stderr, "c++ compute eigenvalues and eigenvectors, no sort:\n");
    if (eigenvalues(mat1, eigen_values1, eigen_vectors1, false) != 0)
    {
        fprintf(stderr, "campute eigenvalues and eigenvector fail\n");
		return -1;
    }

        fprintf(stderr, "eigenvalues:\n");
    for (int i = 0; i < N; ++i)
    {
        fprintf(stderr, "  %f  ", eigen_values1(i));
    }
    fprintf(stderr, "\n\n");

    fprintf(stderr, "eigenvectors:\n");
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            fprintf(stderr, "  %f  ", eigen_vectors1(i, j));
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n\n");

    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
