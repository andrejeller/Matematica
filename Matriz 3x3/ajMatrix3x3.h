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
	

	//Construtor de C�pia
	ajMatrix3x3(float m[3][3]);
	ajMatrix3x3(ajMatrix3x3* matrix);

	//Set Position
	void SetPosition(ofVec2f position);

	//C�pia de matriz: operador =
	void Copy(ajMatrix3x3 matrix);

	// Calculo do determinante
	float Determinant();

	//Calculo da inversa
	ajMatrix3x3 Invert();

	//multiplica��o de vetor pela matriz ****** VER
	ofVec2f transform(const ofVec2f& vector, float z=1.0f) const;

	//M�todos f�brica est�ticos para:
	//	-- Constru��o das matrizes de rota��o, transla��o e escala
	ajMatrix3x3 rotate(float angle);
	void rotateMe(float angle);
	
	ajMatrix3x3 scale(float sx, float sy);
	ajMatrix3x3 translate(float x, float y);
	ajMatrix3x3 transposeMe();

	//Soma de matrizes: operador + e +=
	ajMatrix3x3 operator+(ajMatrix3x3 matrix);
	void operator+=(ajMatrix3x3 matrix);

	//Subtra��o de matrizes: operadores - e -=
	ajMatrix3x3 operator-(ajMatrix3x3 matrix);
	void operator-=(ajMatrix3x3 matrix);

	//Acesso aos elementos da matriz pelo operador (xy);
	float getElement(int x, int y);

	// Multiplica��o de matrizes: operador *
	ajMatrix3x3 multiply(ajMatrix3x3 matrix);
	void multiplyMe(ajMatrix3x3 matrix);

	// Acesso aos elementos pelos m�todos a(), b(), c(), d(), e(), f(), g(), h() e k() no formato:
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
