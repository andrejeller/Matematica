#pragma once

#include "ofMain.h"
#include "Astro.h"

class Cometa {
public:

	ofVec2f m_posicao, m_velocidade;
	float m_raio, m_masa;
		
	Cometa(float x, float y, float r, float m);
	
	void Update(Astro* astro);
	void Update(Cometa* cometa);
	void Draw();
};