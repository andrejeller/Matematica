#include "Astro.h"

Astro::Astro(float x, float y, float tempo, float r, float m) {
	
	m_posicao.set(x, y);
	m_Ancora.set(x, y);
	_period = tempo;
	m_tamanho = r;
	m_massa = m;	
}

void Astro::SetImage(string nome)
{
	img.load(nome);
}

void Astro::Update(Astro* astro) {	
		
	m_Ancora.rotate(_period);
	m_posicao = m_Ancora;
	m_posicao += astro->m_posicao;
}

void Astro::Draw() {
	ofSetColor(255, 255, 255);
	img.draw(m_posicao.x - m_tamanho / 2, m_posicao.y - m_tamanho / 2, 0, m_tamanho, m_tamanho);
}
