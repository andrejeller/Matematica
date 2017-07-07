#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Inicializando tempo
	updateTime = ofGetElapsedTimeMillis();
	//Inicializando pos e Trns P1
	//Para pos random acho que é isso -- Tamanho tela / 2, pq se nao acabava indo para fora mto rapido.
	posPlayer1.set(rand() % ofGetWidth() / 2 , rand() % ofGetHeight() / 2);
	//posPlayer1.set(-100, 0);
	trsP1.SetPosition(posPlayer1);


	//Inicializando pos e Trns P2
	posPlayer2.set(rand() % ofGetWidth() / 2 , rand() % ofGetHeight() / 2);
	posPlayer2.set(100, 0);
	trsP2.SetPosition(posPlayer2);
	rotTorre2.rotateMe(110);
}

//--------------------------------------------------------------
void ofApp::update() {
	//Multiplica as matrizes de rotacao conforme o angulo desejado
	rotP1.rotateMe(anglePlayer1);
	rotTorre1.rotateMe(angTorreP1);

	rotP2.rotateMe(anglePlayer2);
	rotTorre2.rotateMe(angTorreP2);

	//"FireRate & MoveRate" 
	if (ofGetElapsedTimeMillis() - updateTime >= 200) {
		updateTime = ofGetElapsedTimeMillis();
		movePlayers();
		tirosP1.push_back(Tiro(P1.c, P1.f));
		tirosP2.push_back(Tiro(P2.c, P2.f));
	}

	//Faz os tiros sairem do lugar
	for (int i = 0; i < tirosP1.size(); i++)
		tirosP1[i].update();
	for (int i = 0; i < tirosP2.size(); i++)
		tirosP2[i].update();

	//Faz os tiros serem destruidos dps de uma distancia
	for (int i = 0; i < tirosP1.size(); i++)
		if (VerificaPos(posPlayer1, tirosP1[i].m_pos, ofGetWidth() / 4)) {
			tirosP1.erase(tirosP1.begin() + i);
		}

	for (int i = 0; i < tirosP2.size(); i++)
		if (VerificaPos(posPlayer2, tirosP2[i].m_pos, ofGetWidth() / 4)) {
			tirosP2.erase(tirosP2.begin() + i);
		}


	//Verificando colisao de tiro com player
	///Tiros P1 com o Player2
	for (int i = 0; i < tirosP1.size(); i++)
		if (VerificaPos(posPlayer2, tirosP1[i].m_pos, P1.a / 1.4f)) {
			//tirosP1.erase(tirosP1.begin() + i);
			//Ativa P1 WINS
		}
	///Tiros P2 com o Player1
	for (int i = 0; i < tirosP2.size(); i++)
		if (VerificaPos(posPlayer1, tirosP2[i].m_pos, P2.a / 1.4f)) {
			//tirosP2.erase(tirosP2.begin() + i);
			//Ativa P2 WINS
		}

	///Verificar se o Player saiu da tela -- Nao esqucer da escala
	if (P1.c + P1.a > ofGetWidth() || P1.c - P1.a < 0 || P1.f + P1.b < 0 || P1.f - P1.b> ofGetHeight()) {
		///SAIU DA TELA
	}
	if (P2.c + P2.a > ofGetWidth() || P2.c - P2.a < 0 || P2.f + P2.b < 0 || P2.f - P2.b> ofGetHeight()) {
		///SAIU DA TELA
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//Translate global para o centro
	ofTranslate(500, 300);

	//Desenha linhas XY
	ofSetColor(0, 0, 0);
	ofDrawLine(-500, 0, 500, 0);
	ofDrawLine(0, -500, 0, 500);

	//Player1
	ofSetColor(255, 0, 0); //Cor P1
	ofPushMatrix();
	ofMultMatrix(trsP1.to4x4()); //Translada P1
	ofPushMatrix();
	ofMultMatrix(rotP1.to4x4()); //Rotaciona Tanque P1	
	ofDrawRectangle(P1.c - P1.a / 2, P1.f - P1.e / 2, P1.a, P1.e); //Desenha P1
	ofSetColor(255, 0, 0, 125);
	ofDrawCircle(P1.c, P1.f, P1.a / 1.4f); // area de colisao
	ofPushMatrix();
	ofMultMatrix(rotTorre1.to4x4()); //Rotaciona torre p1
	ofSetColor(255, 255, 0); //Cor torre P1
	ofMultMatrix(rotTorre1.to4x4()); //Rotaciona torre p1
	ofDrawRectangle(P1.c - P1.a / 4, P1.f - P1.e / 4, P1.a / 2, P1.e / 2);
	ofSetColor(0, 0, 0); //Cor Linha de tiro P1
	ofDrawLine(0, 0, P1.a / 4, 0); //Linha de tiro P1
	for (int i = 0; i < tirosP1.size(); i++)
		tirosP1[i].draw(); //desenha tiros do Vector
	ofPopMatrix();
	ofPopMatrix();
	ofPopMatrix();

	//Player2
	ofSetColor(0, 255, 0); //Cor P1
	ofPushMatrix();
	ofMultMatrix(trsP2.to4x4()); //Translada P1
	ofPushMatrix();
	ofMultMatrix(rotP2.to4x4()); //Rotaciona Tanque P1	
	ofDrawRectangle(P2.c - P2.a / 2, P2.f - P2.e / 2, P2.a, P2.e); //Desenha P1
	ofSetColor(0, 255, 0, 125);
	ofDrawCircle(P2.c, P2.f, P2.a / 1.4f); // area de colisao
	ofPushMatrix();
	ofMultMatrix(rotTorre2.to4x4()); //Rotaciona torre p1
	ofSetColor(255, 0, 255); //Cor torre P1
	ofDrawRectangle(P2.c - P2.a / 4, P2.f - P2.e / 4, P2.a / 2, P2.e / 2);
	ofSetColor(0, 0, 0); //Cor Linha de tiro P1
	ofDrawLine(0, 0, P2.a / 4, 0); //Linha de tiro P1
	for (int i = 0; i < tirosP2.size(); i++)
		tirosP2[i].draw(); //desenha tiros do Vector
	ofPopMatrix();
	ofPopMatrix();
	ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (turno) {
		case 0:
			//Player 1
		if (key == 356 && anglePlayer1 >= -30) //Direita - Gira Player (tanque)
			anglePlayer1 -= 1;
		if (key == 358 && anglePlayer1 <= 30) //Esquerda - Gira Player (tanque)
			anglePlayer1 += 1;
		if (key == 357 && angTorreP1 <= 90)   //Cima - Gira Torre -- 90 = limite 
			angTorreP1 += 0.1f;
		if (key == 359 && angTorreP1 >= -90)  //Baixo - Gira Torre
			angTorreP1 -= 0.1f;
		if (key == 49) //1
			velP1 = 10.0f;
		if (key == 50) //2
			velP1 = 20.0f;
		if (key == 51) //3
			velP1 = 30.0f;
		break;

		case 1:
			//Player 2
		if (key == 356 && anglePlayer1 >= -30) //Direita - Gira Player (tanque)
			anglePlayer2 -= 1;
		if (key == 358 && anglePlayer1 <= 30) //Esquerda - Gira Player (tanque)
			anglePlayer2 += 1;
		if (key == 357 && angTorreP1 <= 90)   //Cima - Gira Torre -- 90 = limite 
			angTorreP2 += 0.1f;
		if (key == 359 && angTorreP1 >= -90)  //Baixo - Gira Torre
			angTorreP2 -= 0.1f;
		if (key == 49) //1
			velP2 = 10.0f;
		if (key == 50) //2
			velP2 = 20.0f;
		if (key == 51) //3
			velP2 = 30.0f;
		break;
		case 2:
			//nada
		break;
	}

	if (key == 32) { // Espaco = 32
		//turno++; // Se apertar Espaco turno ++ ?
		if (turno > 2) turno = 0;
	}

	std::cout << key << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
