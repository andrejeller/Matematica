#pragma once

#include "ofMain.h"

class ajMatrix3x3: public ofBaseApp{

public:
	/*  | a b c| 
		| d e f| 
		| g h i|*/
	float a, b, c, d, e, f, g, h, i;
	float myMatirx[3][3] = {a, b, c, d, e, f, g, h, i};
	
	
	//Construtor Identidade
	ajMatrix3x3();
	
	//Construtor 9 floats
	ajMatrix3x3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);
	

	//Construtor de Cópia
	ajMatrix3x3(float m[3][3]);
	ajMatrix3x3(ajMatrix3x3* matrix);

	//Set Position
	void SetPosition(ofVec2f position);

	//Cópia de matriz: operador =
	void Copy(ajMatrix3x3 matrix);

	// Calculo do determinante
	float Determinant();

	//Calculo da inversa
	ajMatrix3x3 Invert();

	//multiplicação de vetor pela matriz ****** VER
	ofVec2f transform(const ofVec2f& vector, float z=1.0f) const;

	//Métodos fábrica estáticos para:
	//	-- Construção das matrizes de rotação, translação e escala
	ajMatrix3x3 rotate(float angle);
	void rotateMe(float angle);
	
	ajMatrix3x3 scale(float sx, float sy);
	ajMatrix3x3 translate(float x, float y);
	ajMatrix3x3 transposeMe();

	//Soma de matrizes: operador + e +=
	ajMatrix3x3 operator+(ajMatrix3x3 matrix);
	void operator+=(ajMatrix3x3 matrix);

	//Subtração de matrizes: operadores - e -=
	ajMatrix3x3 operator-(ajMatrix3x3 matrix);
	void operator-=(ajMatrix3x3 matrix);

	//Acesso aos elementos da matriz pelo operador (xy);
	float getElement(int x, int y);

	// Multiplicação de matrizes: operador *
	ajMatrix3x3 multiply(ajMatrix3x3 matrix);
	void multiplyMe(ajMatrix3x3 matrix);

	// Acesso aos elementos pelos métodos a(), b(), c(), d(), e(), f(), g(), h() e k() no formato:
	// -- alterando K por i

	float A();
	float B();
	float C();

	float D();
	float E();
	float F();

	float G();
	float H();
	float I();

	ofMatrix4x4 to4x4();
			
};
