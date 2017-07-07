#include "ajMatrix3x3.h"

ajMatrix3x3::ajMatrix3x3() {
	a = 1; b = 0; c = 0;
	d = 0; e = 1; f = 0;
	g = 0; h = 0; i = 1;
}

ajMatrix3x3::ajMatrix3x3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) {
	a = a11; b = a12; c = a13;
	d = a21; e = a22; f = a23;
	g = a31; h = a32; i = a33;
}

ajMatrix3x3::ajMatrix3x3(float m[3][3]) {
	a = m[0][0]; b = m[1][0]; c = m[2][0];
	d = m[0][1]; e = m[1][1]; f = m[2][1];
	g = m[0][2]; h = m[1][2]; i = m[2][2];
}

ajMatrix3x3::ajMatrix3x3(ajMatrix3x3* matrix) {
	a = matrix->a; b = matrix->b; c = matrix->c;
	d = matrix->d; e = matrix->e; f = matrix->f;
	g = matrix->g; h = matrix->h; i = matrix->i;
}

void ajMatrix3x3::SetPosition(ofVec2f position) {
	a = 1; b = 0; c = position.x;
	d = 0; e = 1; f = position.y;
	g = 0; h = 0; i = 1;
}

void ajMatrix3x3::Copy(ajMatrix3x3 matrix) {
	a = matrix.a; b = matrix.b; c = matrix.c;
	d = matrix.d; e = matrix.e; f = matrix.f;
	g = matrix.g; h = matrix.h; i = matrix.i;
}

float ajMatrix3x3::Determinant() {
	  /*| a b c|
		| d e f|
		| g h i|*/
	float det = (a * e * i) + (b * f * g) + (d * h * c)
		- (g * e * c) - (d * b * i) - (h * f * a);
	return det;
}

ajMatrix3x3 ajMatrix3x3::Invert() {
	ajMatrix3x3 invr;
	float det = Determinant();

	/*  |a b c|			|+ - +|		| a -d  g|?
		|d e f| 		|- + -| =	|-b  e -h|? == invers = adj(A)/Det(A)
		|g h i|			|+ - +|		| c -f  i|?
	*/

	//adj.a = (-1)^1x1 x (e*i - (f*h))
	//adj.b = (-1)^1x2 x (e*i - (f*h))

	invr.a = (e * i - (f * h)) / det;
	invr.b = -(d * i - (f * g)) / det;
	invr.c = (d * h - (e * g)) / det;

	invr.d = -(b * i - (c * h)) / det;
	invr.e = (a * i - (c * g)) / det;
	invr.f = -(a * h - (b * g)) / det;

	invr.g = -(b * f - (c * e)) / det;
	invr.h = (a * f - (c * d)) / det;
	invr.i = -(a * e - (b * d)) / det;


	return invr;
}

ofVec2f ajMatrix3x3::transform(const ofVec2f & vector, float z) const {

	/*
	| a b c| * |x|
	| d e f| * |y|
	| g h i| * |z|

	| a*x + b*y + c*z |
	| d*a + e*y + f*z |
	| g*x + h*y + i*z |	
	*/

	ofVec2f result;
	result.x = a * vector.x + b * vector.y + c * z;
	result.y = d * vector.x + e * vector.y + f * z;
//	float z = g * vector.x + h * vector.y + i * z; // só pra ter

	return result;
}

ajMatrix3x3 ajMatrix3x3::rotate(float angle) {
	ajMatrix3x3 rot;
	/*  |x'|	|cosO -senO 0|	 |x| = |x * cosO + y * -senO |   
		|y'| =  |senO  cosO 0| * |y| = |x* senO + y * cosO|
		|z'|    | 0      0  1|	 |1| = | 1 |
		*/
	
	/*	|cos -sen 0|	|1 0 0|		|c -s 0|
		|sen  cos 0| *	|0 1 0| =	|s  c 0|
		|0     0  1|	|0 0 1|		|0  0 1|
	*/

	rot.a = cos(angle);   rot.b = - sin(angle);   rot.c = c; 
	rot.d = sin(angle);   rot.e =   cos(angle);   rot.f = f;
	rot.g = 0;			      rot.h = 0;			      rot.i = 1;
	
	
	return rot;	
}

void ajMatrix3x3::rotateMe(float angle) {
	// USAR MAO ESQUERDA NAO A DIREITA 
	a = cos(angle);   b = - sin(angle);   c = 0; 
	d = sin(angle);   e =   cos(angle);   f = 0; 
	g = 0;			  h = 0;			  i = 1;	
}

ajMatrix3x3 ajMatrix3x3::scale(float sx, float sy) {
	ajMatrix3x3 trs;
	/*  |sx  0 0|	  
		|0  sy 0|  
		|0  0  1|	
	*/

	trs.a = sx; trs.b = 0;  trs.c = 0; 
	trs.d = 0;  trs.e = sy; trs.f = 0; 
	trs.g = 0;  trs.h = 0;  trs.i = 1;

	return trs;	
}

ajMatrix3x3 ajMatrix3x3::translate(float x, float y) {
	ajMatrix3x3 trs;
	/*   |1  0 x|	  
		 |0  1 y|  
		 |0  0 1|	
	*/

	trs.a = 1; trs.b = 0; trs.c = x; 
	trs.d = 0; trs.e = 1; trs.f = y; 
	trs.g = 0; trs.h = 0; trs.i = 1;

	return trs;	
}

ajMatrix3x3 ajMatrix3x3::transposeMe() {
	ajMatrix3x3 transpose;
	/*
	| a b c| |a d g|
	| d e f| |b e h|
	| g h i| |c f i|
	*/
	transpose.a = a; transpose.b = d; transpose.c = g; 
	transpose.d = b; transpose.e = e; transpose.f = h; 
	transpose.g = c; transpose.h = f; transpose.i = i;

	return transpose;
}

ajMatrix3x3 ajMatrix3x3::operator+(ajMatrix3x3 matrix) {

	ajMatrix3x3 soma;
	soma.a = a + matrix.a;
	soma.b = b + matrix.b;
	soma.c = c + matrix.c;

	soma.d = d + matrix.d;
	soma.e = e + matrix.e;
	soma.f = f + matrix.f;

	soma.g = g + matrix.g;
	soma.h = h + matrix.h;
	soma.i = i + matrix.i;

	return soma;
}

void ajMatrix3x3::operator+=(ajMatrix3x3 matrix) {

	a += matrix.a;
	b += matrix.b;
	c += matrix.c;

	d += matrix.d;
	e += matrix.e;
	f += matrix.f;

	g += matrix.g;
	h += matrix.h;
	i += matrix.i;
}

ajMatrix3x3 ajMatrix3x3::operator-(ajMatrix3x3 matrix) {
	ajMatrix3x3 soma;
	soma.a = a - matrix.a;
	soma.b = b - matrix.b;
	soma.c = c - matrix.c;

	soma.d = d - matrix.d;
	soma.e = e - matrix.e;
	soma.f = f - matrix.f;

	soma.g = g - matrix.g;
	soma.h = h - matrix.h;
	soma.i = i - matrix.i;

	return soma;
}

void ajMatrix3x3::operator-=(ajMatrix3x3 matrix) {
	a -= matrix.a;
	b -= matrix.b;
	c -= matrix.c;

	d -= matrix.d;
	e -= matrix.e;
	f -= matrix.f;

	g -= matrix.g;
	h -= matrix.h;
	i -= matrix.i;
}

float ajMatrix3x3::getElement(int x, int y) {
	return myMatirx[x][y];
}

ajMatrix3x3 ajMatrix3x3::multiply(ajMatrix3x3 matrix) {
	ajMatrix3x3 C;

	/*
	| a b c| * | 1 2 3|
	| d e f| * | 4 5 6|
	| g h i| * | 7 8 9|

	| a*1 + b*4 + c*7  --  a*2 + b*5 + c*8 -- a*3 + b*6 + c*9 |
	| d*1 + e*4 + f*7  --  d*2 + e*5 + f*8 -- d*3 + e*6 + f*9 |
	| g*1 + h*4 + i*7  --  g*2 + h*5 + i*8 -- g*3 + h*6 + i*9 |

	|00, 10, 20|
	|01, 11, 21|
	|02, 12, 22|
	*/

	C.a = (a * matrix.a) + (b * matrix.d) + (c * matrix.g);
	C.b = (a * matrix.b) + (b * matrix.e) + (c * matrix.h);
	C.c = (a * matrix.c) + (b * matrix.f) + (c * matrix.i);

	C.d = (d * matrix.a) + (e * matrix.d) + (f * matrix.g);
	C.e = (d * matrix.b) + (e * matrix.e) + (f * matrix.h);
	C.f = (d * matrix.c) + (e * matrix.f) + (f * matrix.i);

	C.g = (g * matrix.a) + (h * matrix.d) + (i * matrix.g);
	C.h = (g * matrix.b) + (h * matrix.e) + (i * matrix.h);
	C.i = (g * matrix.c) + (h * matrix.f) + (i * matrix.i);


	return C;
}

void ajMatrix3x3::multiplyMe(ajMatrix3x3 matrix) {
	a = (a * matrix.a) + (b * matrix.d) + (c * matrix.g);
	b = (a * matrix.b) + (b * matrix.e) + (c * matrix.h);
	c = (a * matrix.c) + (b * matrix.f) + (c * matrix.i);

	d = (d * matrix.a) + (e * matrix.d) + (f * matrix.g);
	e = (d * matrix.b) + (e * matrix.e) + (f * matrix.h);
	f = (d * matrix.c) + (e * matrix.f) + (f * matrix.i);

	g = (g * matrix.a) + (h * matrix.d) + (i * matrix.g);
	h = (g * matrix.b) + (h * matrix.e) + (i * matrix.h);
	i = (g * matrix.c) + (h * matrix.f) + (i * matrix.i);
}

float ajMatrix3x3::A() {
	return a;
}

float ajMatrix3x3::B() {
	return b;
}

float ajMatrix3x3::C() {
	return c;
}

float ajMatrix3x3::D() {
	return d;
}

float ajMatrix3x3::E() {
	return e;
}

float ajMatrix3x3::F() {
	return f;
}

float ajMatrix3x3::G() {
	return g;
}

float ajMatrix3x3::H() {
	return h;
}

float ajMatrix3x3::I() {
	return i;
}

ofMatrix4x4 ajMatrix3x3::to4x4() {

	ajMatrix3x3 nova = new ajMatrix3x3(a, b, c, d, e, f, g, h, i);
	
	ofMatrix4x4 m4x4(
		nova.transposeMe().a, nova.transposeMe().b, nova.transposeMe().c, 0.0f,
		nova.transposeMe().d, nova.transposeMe().e, nova.transposeMe().f, 0.0f,		
		0.0,				  0.0f,					1.0f,				  0.0f,
		nova.transposeMe().g, nova.transposeMe().h, nova.transposeMe().i, 1.0f	
	);

	return m4x4;
}
