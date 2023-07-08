#include <math.h>
#include <stdio.h>

#include "vector4.h"


void Vector4_print(Vector4 *vect) {
	printf("Vector4 {\n");
	printf("    %lf,\n", vect->x);
	printf("    %lf,\n", vect->y);
	printf("    %lf,\n", vect->z);
	printf("    %lf\n", vect->w);
	printf("}\n");
}

void Vector4_summation(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3) {
	vect3->x = vect1->x + vect2->x;
	vect3->y = vect1->y + vect2->y;
	vect3->z = vect1->z + vect2->z;
	vect3->w = vect1->w + vect2->w;
}

void Vector4_summation_scalar(Vector4 *vect1, double scalar, Vector4 *vect3) {
	vect3->x = vect1->x + scalar;
	vect3->y = vect1->y + scalar;
	vect3->z = vect1->z + scalar;
	vect3->w = vect1->w + scalar;
}

void Vector4_subtracting(Vector4 *vect1, Vector4 *vect2, Vector4 *vect3) {
	vect3->x = vect1->x - vect2->x;
	vect3->y = vect1->y - vect2->y;
	vect3->z = vect1->z - vect2->z;
	vect3->w = vect1->w - vect2->w;
}

void Vector4_subtracting_scalar(Vector4 *vect1, double scalar, Vector4 *vect3) {
	vect3->x = vect1->x - scalar;
	vect3->y = vect1->y - scalar;
	vect3->z = vect1->z - scalar;
	vect3->w = vect1->w - scalar;
}

void Vector4_inverting(Vector4 *vect1, Vector4 *vect3) {
	vect3->x = -vect1->x;
	vect3->y = -vect1->y;
	vect3->z = -vect1->z;
	vect3->w = -vect1->w;
}


void Vector4_normalize(Vector4 *vect1, Vector4 *vect3) {
	vect3->x = vect1->x / vect3->w;
	vect3->y = vect1->y / vect3->w;
	vect3->z = vect1->z / vect3->w;
	vect3->w = 1;
}

void Matrix_multiplication_Vector4(Matrix *matrix, Vector4 *vect2, Vector4 *vect3) {
	double x, y, z, w;
	x = matrix->a[0][0] * vect2->x + matrix->a[0][1] * vect2->y + matrix->a[0][2] * vect2->z + matrix->a[0][3] * vect2->w;
	y = matrix->a[1][0] * vect2->x + matrix->a[1][1] * vect2->y + matrix->a[1][2] * vect2->z + matrix->a[1][3] * vect2->w;
	z = matrix->a[2][0] * vect2->x + matrix->a[2][1] * vect2->y + matrix->a[2][2] * vect2->z + matrix->a[2][3] * vect2->w;
	w = matrix->a[3][0] * vect2->x + matrix->a[3][1] * vect2->y + matrix->a[3][2] * vect2->z + matrix->a[3][3] * vect2->w;
	vect3->x = x;
	vect3->y = y;
	vect3->z = z;
	vect3->w = w;
}

void Vector3_to_Vector4(Vector3 *vect1, Vector4 *vect2) {
	vect2->x = vect1->x;
	vect2->y = vect1->y;
	vect2->z = vect1->z;
	vect2->w = 1;
}

void Vector4_to_Vector3(Vector4 *vect1, Vector3 *vect2) {
	vect2->x = vect1->x / vect1->w;
	vect2->y = vect1->y / vect1->w;
	vect2->z = vect1->z / vect1->w;
}