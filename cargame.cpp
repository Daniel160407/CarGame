#include <iostream>
#include <conio.h>
#include <dos.h> 
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <bits/stdc++.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 
using namespace std;
bool gameover;
const int width=76;
const int height=40;
enum gilaki{stop=0, LEFT, RIGHT, MIDDLE};
gilaki gl;
enum Toggle{ON, OFF};
Toggle cht;
void setup(){
	cht=ON;
	gameover=false;
}
void draw(vector<string>vec2, int random, int &score, int &a){
	int b=0;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(i==0||i==height-1){
				cout<<"#";
			}
			
		}
		if(b==0){
				cout<<endl;
			}
		b++;
		//////////
		if(gl!=LEFT&&gl!=RIGHT&&gl!=MIDDLE){ 
		if(i>2&&i<height-1){
			cout<<"##################                                        ##################"<<endl;
		}else if(i==1){
			cout<<"##################         Tap to start the game          ##################"<<endl;
		}else if(i==2){
			cout<<"##################     Press 'p' to show key buttons      ##################"<<endl;
		}
		if(_kbhit()){
			switch(_getch()){
			case 'p':
				int m=0;
				system("cls");
				while(m==0){
					cout<<"#####################################"<<endl;
					cout<<"#### Right: 'd', Left: 'a'       ####"<<endl;
					cout<<"#### Middle: 's', Game over: 'x' ####"<<endl;
					cout<<"#### Return game: 'r'            ####"<<endl;
					cout<<"#####################################"<<endl;
					switch(_getch()){
						case 'r':
							m=1;
							break;
					system("cls");
				}
					
				}
				
				
				
				
		}	
		}
		
	 }
	}
	if(gl==LEFT||gl==RIGHT||gl==MIDDLE){
		a=1;
	for(int g=2; g<38; g++){
	system("cls");
	if(g<35){
			swap(vec2[g-1],vec2[g]);
		for(int r=0; r<35; r++){
			for(int j=0; j<width; j++){
			if(r==0){
				cout<<"#";
			}
			
		}
		if(b==0){
				cout<<endl;
			}
		b++;
		
			cout<<vec2[r]<<endl;
	 if(random==17&&gl==LEFT&&r==33){
		gameover=true;
	}else if(random==18&&gl==MIDDLE&&r==33){
		gameover=true;
	}else if(random==19&&gl==RIGHT&&r==33){
		gameover=true;
	}else if(random==17&&gl!=LEFT&&r==33){
		gameover=false;
	}else if(random==18&&gl!=MIDDLE&&r==33){
		gameover=false;
	}else if(random==19&&gl!=RIGHT&&r==33){
		gameover=false;
	}
	if(r==33&&gameover==false){
		score++;
		if(score%500==0){
			system("Color 57");
			Beep(500,250);
			system("Color 01");
		}
	}
			
			if(_kbhit()){
		switch(_getch()){
			case 'a': gl=LEFT;
			
			break;
			case 'd': gl=RIGHT;
			
			break;
			case 's': gl=MIDDLE;
			
			break;
			case 'x': gameover=true;
			break;
		}
		
	}
	}
	for(int w=0; w<=40; w++){
		if(gl==LEFT){
		if(w==35){
				cout<<"##################         $                              ##################"<<endl;
			}else if(w==36||w==38){
				cout<<"##################        $$$                             ##################"<<endl;
			}else if(w==37){
				cout<<"##################        $ $                             ##################"<<endl;
			}else if(w==39){
				cout<<"############################################################################"<<endl;
			}else if(w==40){
				cout<<"Score: "<<score<<endl;
			}
		}else if(gl==RIGHT){
			if(w==35){
				cout<<"##################                             $          ##################"<<endl;
			}else if(w==36||w==38){
				cout<<"##################                            $$$         ##################"<<endl;
			}else if(w==37){
				cout<<"##################                            $ $         ##################"<<endl;
			}else if(w==39){
				cout<<"############################################################################"<<endl;
			}else if(w==40){
				cout<<"Score: "<<score<<endl;
			}
		}else if(gl==MIDDLE){
		if(w==35){
				cout<<"##################                   $                    ##################"<<endl;
			}else if(w==36||w==38){
				cout<<"##################                  $$$                   ##################"<<endl;
			}else if(w==37){
				cout<<"##################                  $ $                   ##################"<<endl;
			}else if(w==39){
				cout<<"############################################################################"<<endl;
			}else if(w==40){
				cout<<"Score: "<<score<<endl;
			}
		}	
	}
	}
	}
}
}

void input(int &score, int &l){
	if(_kbhit()){
		switch(_getch()){
			case 'a': gl=LEFT;
			
			break;
			case 'd': gl=RIGHT;
			
			break;
			case 's': gl=MIDDLE;
			
			break;
			case 'x': gameover=true;
			break;
			case 'r': gameover=false;
			score=0;
			system("Color 01");
			l=0;
			break;
			
		}
	}
}

int main(){
	system("Color 01");
int score=0,random,a=0,l=0,highscore;
vector<int>score2;
int kk;
ifstream ifs("HighScore.txt");
ofstream ofs;
ofs.open("HighScore.txt",ofstream::app);
	vector<string>vec(20);
	for(int h=0; h<3; h++){
		if(h==0){
			vec[h]="##################        ###                             ##################";
		}else if(h==1){
			vec[h]="##################                  ###                   ##################";
		}else if(h==2){
			vec[h]="##################                            ###         ##################";
		}
	}
	vector<string>vec2(35);
while(cht==ON){
	while(!gameover){
		random=17+rand()%(3);
	for(int i=0; i<35; i++){
		if(i==1){
			if(random==17){
				vec2[i]=vec[0];
			}else if(random==18){
				vec2[i]=vec[1];
			}else if(random==19){
				vec2[i]=vec[2];
			}
			
		}else if(i>1){
			vec2[i]="##################                                        ##################";
		}
	}
	setup();
	input(score,l);
	draw(vec2,random,score,a);
	
	if(a==0)	
system("cls");
	}
	if(gameover&&l==0){
		int e;
		while(ifs>>e){
			ifs>>kk;
			score2.push_back(kk);
		}
		sort(score2.begin(),score2.end());
		score2.erase(score2.begin(),score2.end()-1);
		do{
	cout<<endl;
	cout<<"GAME OVER!"<<endl;
	cout<<"Your high score is: "<<score2[0]<<endl;
	cout<<"Your score: "<<score<<endl;
	system("Color 4F");
	l=1;
	input(score,l);
	system("cls");
		}
		while(l==1);
	
	ofs<<score<<endl;
}

}

}
