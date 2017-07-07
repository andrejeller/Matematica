#pragma once

#include "ofMain.h"
#include "Astro.h"
#include "Cometa.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
			
		vector<Cometa*> cometas;
		
		Astro* Sol = new Astro(320, 320, 0, 320, 400000.000f);
		Astro* Terra = new Astro(220, 0, 0.1, 80, 1.0f);
		Astro* Lua = new Astro(0, 70, 0.25, 50, 0.0123f);

};
