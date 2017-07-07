#pragma once

#include "ofMain.h"
#include "ajMatrix3x3.h"
#include "square.h"
#include <vector>
#include "tiro.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);



	float updateTime; // Controle de tempo para FireRate
	int turno = 1; //Controle para utilizacao dos imputs em cada turno

	//Player 1
	float anglePlayer1 = 0; // Angulo do player 1 para multiplicar a matriz de rotacao do tanque
	float angTorreP1 = 0;   // Angulo do player 1 para multiplicar a matriz de rotacao da torre
	float velP1 = 10.0f;    // Velocidade de movimentacao do player 1 
	ofVec2f posPlayer1;		// Vetor de posicao do player 1 para multiplicar sua matriz de pos
	vector<Tiro> tirosP1;   // Vector contendo seus tiros

	//Matix de posicao player 1
	ajMatrix3x3 P1 = new ajMatrix3x3(50, 0, posPlayer1.x,
									 0, 50, posPlayer1.y,
									 0, 0, 1);
	//Matix de ratacao player 1
	ajMatrix3x3 rotP1 = new ajMatrix3x3(1, 0, P1.c,
										0, 1, P1.f,
										0, 0, 1);
	//Matix de transladacao player 1
	ajMatrix3x3 trsP1 = new ajMatrix3x3(1, 0, 0,
										0, 1, 0,
										0, 0, 1);

	//Matix de ratacao da torre do player 1
	ajMatrix3x3 rotTorre1 = new ajMatrix3x3(1, 0, P1.c,
											0, 1, P1.f,
											0, 0, 1);

	//Player 2
	float anglePlayer2 = 0; // Angulo do player 2 para multiplicar a matriz de rotacao do tanque
	float angTorreP2 = 0;   // Angulo do player 2 para multiplicar a matriz de rotacao da torre
	float velP2 = 10.0f;    // Velocidade de movimentacao do player 2 
	ofVec2f posPlayer2;     // Vetor de posicao do player 2 para multiplicar sua matriz de pos
	vector<Tiro> tirosP2;   // Vector contendo seus tiros

	//Matix de posicao player 2
	ajMatrix3x3 P2 = new ajMatrix3x3(50, 0, posPlayer2.x,
									 0, 50, posPlayer2.y,
									 0, 0, 1);
	//Matix de ratacao player 2
	ajMatrix3x3 rotP2 = new ajMatrix3x3(1, 0, P2.c,
										0, 1, P2.f,
										0, 0, 1);
	//Matix de transladacao player 2
	ajMatrix3x3 trsP2 = new ajMatrix3x3(1, 0, 0,
										0, 1, 0,
										0, 0, 1);

	//Matix de ratacao da torre do player 2
	ajMatrix3x3 rotTorre2 = new ajMatrix3x3(1, 0, P2.c,
											0, 1, P2.f,
											0, 0, 1);



	//Varificador de distancias para tos, se estiver a mais que uma distancia retorna verdadeiro
	///Distancia = Raio;
	bool VerificaPos(ofVec2f myXY, ofVec2f otherXY, int distPermit) {
		ofVec2f raioPermit = (otherXY - myXY);
		float dist = raioPermit.length();
		if (dist >= distPermit) {
			return true;
		}
		return false;
	}
	

	void movePlayers() {
		//ofVec2f novaPos = ofVec2f(posPlayer1.x + 10, posPlayer1.y + rand() % 10);
		ofVec2f novaPos = ofVec2f(posPlayer1.x + 10, posPlayer1.y);
		posPlayer1 -= ((posPlayer1 - novaPos).normalize() * 1) * ofGetLastFrameTime() * 200 * velP1;
		trsP1.SetPosition(posPlayer1);


		//ofVec2f novaPos2 = ofVec2f(posPlayer2.x + 10, posPlayer2.y + rand() % 10);
		ofVec2f novaPos2 = ofVec2f(posPlayer2.x + 10, posPlayer2.y);
		posPlayer2 -= ((posPlayer2 - novaPos2).normalize() * 1) * ofGetLastFrameTime() * 200 * velP2;
		trsP2.SetPosition(posPlayer2);
	}

};
