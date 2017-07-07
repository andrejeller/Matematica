#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	
	Sol->SetImage("Sol.jpg");
	Terra->SetImage("Terra.png");
	Lua->SetImage("Lua.png");
	
}

//---------------------------------------------------------------
void ofApp::update(){

	Terra->Update(Sol);
	Lua->Update(Terra);

	for (int i = 0; i < cometas.size(); i++) {
		cometas.at(i)->Update(Sol);
		cometas.at(i)->Update(Terra);
		cometas.at(i)->Update(Lua);
		/*for (int j = 0; j < cometas.size(); j++){
			cometas.at(i)->Update(cometas.at(j));
		}*/
	}
}

//--------------------------------------------------------------
void ofApp::draw(){	

	Sol->Draw();
	Terra->Draw();
	Lua->Draw();

	for (int i = 0; i < cometas.size(); i++) {
		cometas.at(i)->Draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
			
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0){
		float raio = 3 + rand() % 6;
		cometas.push_back(new Cometa(x, y, raio, 100 * raio));
	}
	else 
		cometas.clear();

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
