#include "matrix.h"
#include "vector3.h"


typedef struct Vector4 {
	double x, y, z, w;
} Vector4;


void Vector4_print(Vector4 *vect);


void Vector4_summation(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3);
void Vector4_summation_scalar(Vector4 *vect1, double scalar, Vector4 *vect3);
void Vector4_subtracting(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3);
void Vector4_subtracting_scalar(Vector4 *vect1, double scalar, Vector4 *vect3);
void Vector4_inverting(Vector4 *vect1, Vector4 *vect3);


void Vector4_normalize(Vector4 *vect1, Vector4 *vect3);
void Matrix_multiplication_Vector4(Matrix *matrix, Vector4 *vect2, Vector4 *vect3);
void Vector3_to_Vector4(Vector3 *vect1, Vector4 *vect2);
void Vector4_to_Vector3(Vector4 *vect1, Vector3 *vect2);