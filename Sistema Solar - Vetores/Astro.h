#pragma once

#include "ofMain.h"

class Astro {
public:	
	ofImage img;

	ofVec2f m_posicao, m_Ancora;
	float _period, m_tamanho, m_massa;
	
	Astro(float x, float y, float tempo, float r, float m);
	
	void SetImage(string nome);
	void Update(Astro* astro);
	void Draw();
};
