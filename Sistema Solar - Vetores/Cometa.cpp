#include "Cometa.h"

Cometa::Cometa(float x, float y, float r, float m) {
	m_posicao.set(x, y);
	m_velocidade.set(0, 0);
	m_raio = r;
	m_masa = m;
}

void Cometa::Update(Astro* astro) {
		
	float distancia = sqrt(pow(astro->m_posicao.x - m_posicao.x, 2) + pow(astro->m_posicao.y - m_posicao.y, 2));

	if (distancia > (m_raio + astro->m_tamanho))
		m_velocidade += astro->m_massa / pow(distancia, 2) * (astro->m_posicao - m_posicao) / distancia;

	m_posicao += m_velocidade;
	
}

void Cometa::Update(Cometa* cometa) {

	float distancia = sqrt(pow(cometa->m_posicao.x - m_posicao.x, 2) + pow(cometa->m_posicao.y - m_posicao.y, 2));

	if (distancia > (m_raio + cometa->m_raio))
		m_velocidade += 3.0f * cometa->m_masa / pow(distancia, 2) * (cometa->m_posicao - m_posicao) / distancia;

	m_posicao += m_velocidade;

}

void Cometa::Draw() {
	ofSetColor(255, 0, 0);
	ofDrawCircle(m_posicao, m_raio);
}

