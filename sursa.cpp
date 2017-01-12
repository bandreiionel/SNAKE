#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <dos.h>


using namespace std;

void runAI();
void inceputAI();
void runSolo();
void vec0(unsigned a[], int);
void sort(unsigned a[], int);
void scoruri();
void adaugScor(unsigned,int);
void afisHarta();
void inceput();
void move(int dx, int dy);
void update();
void schimbaDirectia(char key);
void mancare();
char valoareHarta(int value);


enum directie { SUS, JOS, STANGA, DREAPTA };
struct coordonate {

	int x;
	int y;

};
struct sarpe {

	coordonate cap;
	directie di;
	unsigned lungime;
	unsigned score;
	bool inViata;

}s1, s2;
unsigned top[50];
bool afara = false;
int P[20][20];
int A[20][20];
coordonate cont;
bool running;
unsigned  viteza;
int harta[21][21];
int nrharta;
char meniu[100][100];
int superscore;
int superlungime;
int k;

void copie(char  a[], char b[]){
	int i = 0;
	int n = strlen(b);

	while (i<n)
	{ 
		a[i] = b[i];
		i++;

	}


}

int nrcifre(int nr) {
	int cifre=0;
	do {
		cifre++;
		nr /= 10;

	} while (nr != 0);
	return cifre;

}
void vec0(unsigned vec[],int n)
{
	for (int i = 0; i < n; i++)
		vec[i] = 0;


}
void afisaremeniu(int vec[],int k) {
	int l;

	if ((P[cont.x][cont.y] == 3 || P[cont.x][cont.y] == 14)) {
		fstream f("solo.txt"); 
		l = 0;
		vec0(top,19);
		while (f >> top[l] && l <= 10) {
				l++;
			}
		
		f.close();
	}
	else if ((P[cont.x][cont.y] == 15 || P[cont.x][cont.y] == 25)) {
		fstream f("AI.txt");
		 l = 0;
		 vec0(top,19);
		if (f.is_open()) {
			while (!f.eof() && l <= 10) {


				f >> top[l];
				l++;
			}
		}
		f.close();
	}

	
	system("cls");
	
	int i, j, ok;
	for (i = 0; i < k; i++)
	{
		ok = 1;
		for (j = 1; j <= vec[0] && ok; j++)
			if (i == vec[j]) ok = 0;


		cout << endl << "\t\t";
		for (j = 0; j < 31 ; j++)

			if ((P[cont.x][cont.y] == 3 || (P[cont.x][cont.y] == 14 && cont.x!=10 )) && i > 4 && i < 14 && j == 10) {
				cout << i - 4 << ". " << top[i - 5];
		        j += nrcifre(top[i - 5])+2 ; 
			}
			else if ((P[cont.x][cont.y] == 15 || P[cont.x][cont.y] == 25) && i > 15 && i < 25 && j == 10) {
				cout << i - 15 << ". " << top[i - 16];
				j += nrcifre(top[i - 15]) +2; 
			}
		    else if (meniu[i][j] != '\#' && ok == 0) cout << ' ';
			else cout << meniu[i][j];
	}

}

void _pa() {

	P[0][0] = 4;
	P[0][1] = 2;
	P[0][2] = 5;
	P[0][3] = 8;
	P[0][4] = 22;

	A[0][0] = 12;
	A[0][1] = 4; 
	A[0][2] = 6; 
	A[0][3] = 7; 
	A[0][4] = 9; 
	A[0][5] = 10; 
	A[0][6] = 12; 
	A[0][7] = 13; 
	A[0][8] = 14; 
	A[0][9] = 16; 
	A[0][10] = 17; 
	A[0][11] = 18; 
	A[0][12] = 19;
	
	P[2][0] = 2;
	P[2][1] = 4;
	P[2][2] = 6;

	A[2][0] = 11;
	A[2][1] = 5;
	A[2][2] = 7;
	A[2][3] = 9;
	A[2][4] = 10;
	A[2][5] = 12;
	A[2][6] = 13;
	A[2][7] = 14;
	A[2][8] = 16;
	A[2][9] = 17;
	A[2][10] = 18;
	A[2][11] = 19;

	P[8][0] = 2;
	P[8][1] = 10;
	P[8][2] = 16;

	A[8][0] = 10;
	A[8][1] = 4;
	A[8][2] = 6;
	A[8][3] = 7;
	A[8][4] = 9;
	A[8][5] = 12;
	A[8][6] = 13;
	A[8][7] = 14;
	A[8][8] = 17;
	A[8][9] = 18;
	A[8][10] = 19;

	P[10][0] = 3;
	P[10][1] = 12;
	P[10][2] = 13;
	P[10][3] = 14;

	A[10][0] = 7;
	A[10][1] = 4;
	A[10][2] = 6;
	A[10][3] = 7;
	A[10][4] = 9;
	A[10][5] = 17;
	A[10][6] = 18;
	A[10][7] = 19;

	P[16][0] = 3;
	P[16][1] = 17;
	P[16][2] = 18;
	P[16][3] = 19;

	A[16][0] = 7;
	A[16][1] = 4;
	A[16][2] = 6;
	A[16][3] = 7;
	A[16][4] = 9;
	A[16][5] = 12;
	A[16][6] = 13;
	A[16][7] = 14;

	A[5][0] = 2;
	A[5][1] = 14; 
	A[5][2] = 25;
	P[5][0] = 2;
	P[5][1] = 3;
	P[5][2] = 15;

	A[3][0] = 1;
	A[3][1] = 25;
	P[3][0] = 1;
	P[3][1] = 14;

	A[15][0] = 1;
	A[15][1] = 14;
	P[15][0] = 1;
	P[15][1] = 25;

}
void initializare(){
	cont.x = 0;
	cont.y = 1;
	k = 25;
	copie(meniu[0],"##############################");
	copie(meniu[1],"#                            #");
	copie(meniu[2],"#          > START           #");
	copie(meniu[3],"#                            #");
	copie(meniu[4],"#            SOLO            #");
	copie(meniu[5], "#            SCORURI         #");
	copie(meniu[6],"#            VS AI           #");
	copie(meniu[7], "#                            #");
	copie(meniu[8],"#            OPTION          #");
	copie(meniu[9], "#                            #");
	copie(meniu[10],"#            Viteza          #");
	copie(meniu[11], "#                            #");
	copie(meniu[12],"#            Slow            #");
	copie(meniu[13],"#            Medium          #");
	copie(meniu[14],"#            Fast            #");
	copie(meniu[15], "#                            #");
	copie(meniu[16], "#            HARTA           #");
	copie(meniu[17], "#            Easy            #");
	copie(meniu[18], "#            Medium          #");
	copie(meniu[19], "#            Hard            #");
	copie(meniu[20], "#                            #");
	copie(meniu[21], "#                            #");
    copie(meniu[22],"#            QUIT            #");
    copie(meniu[23], "#                            #");
    copie(meniu[24], "##############################");

	
    afisaremeniu(A[0],k);

}

void scoruri() {
	k = 28;
	copie(meniu[0], "##############################");
	copie(meniu[1], "#                            #");
	copie(meniu[2], "#          SCORURI           #");
	copie(meniu[3], "#            Solo            #");
	copie(meniu[4], "#                            #");
	copie(meniu[5], "#                            #");
	copie(meniu[6], "#                            #");
	copie(meniu[7], "#                            #");
	copie(meniu[8], "#                            #");
	copie(meniu[9], "#                            #");
	copie(meniu[10], "#                            #");
	copie(meniu[11], "#                            #");
	copie(meniu[12], "#                            #");
	copie(meniu[13], "#                            #");
	copie(meniu[14], "#            RESET           #");
	copie(meniu[15], "#            VS AI           #");
	copie(meniu[16], "#                            #");
	copie(meniu[17], "#                            #");
	copie(meniu[18], "#                            #");
	copie(meniu[19], "#                            #");
	copie(meniu[20], "#                            #");
	copie(meniu[21], "#                            #");
	copie(meniu[22], "#                            #");
	copie(meniu[23], "#                            #");
	copie(meniu[24], "#                            #");
	copie(meniu[25], "#            RESET           #");
	copie(meniu[26], "##############################");

	
	afisaremeniu(A[0],k);


}

void resetfis(int fis) {

	if (fis == 1) {
		remove("solo.txt");
	}
	else if (fis == 2) {
		remove("AI.txt");
	}

}

bool pauza;
void adaugScor(unsigned x, int fis) {

	if (fis == 1) {
		fstream f("solo.txt");
		int i = 0;

		if (f.is_open()) {
			while (!f.eof() && i <= 10) {


				f >> top[i];
				i++;
			}
		}

		top[i] = x;

		sort(top, i + 1);
		f.close();

		f.open("solo.txt", ios::trunc | ios::out);
		for (int k = 0; k <= i; k++)
		{
			f << top[k] << " ";
		}

		f.close();
	}

	else {

		fstream f("AI.txt");
		int i = 0;

		if (f.is_open()) {
			while (!f.eof() && i <= 10) {


				f >> top[i];
				i++;
			}
		}

		top[i] = x;

		sort(top, i + 1);
		f.close();

		f.open("AI.txt", ios::trunc | ios::out);
		for (int k = 0; k <= i; k++)
		{
			f << top[k] << " ";
		}

		f.close();



	}
}


void inceputAI() {
	
	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 19; j++)
			harta[i][j] = 0;

	s2.inViata = true;
	s1.score = 0;
	s1.di = DREAPTA;
	s2.cap.x= s1.cap.x = 10;
	s1.cap.y = 12;
	s2.cap.y = 8;
	s2.di = STANGA;
	harta[s1.cap.x][s1.cap.y] =harta[s2.cap.x][s2.cap.y] = 1;
	s2.lungime=s1.lungime = 3;


	if (nrharta == 2) {
		for (int x = 0; x < 20; x++) {
			harta[0][x] = -1;
			harta[x][19] = -1;
			harta[x][0] = -1;
			harta[19][x] = -1;
		}
	}
	else if (nrharta == 1) {
		for (int x = 0; x < 20; x++) {
			harta[0][x] = -2;
			harta[x][19] = -2;
			harta[x][0] = -2;
			harta[19][x] = -2;
		}
	}
	else if (nrharta == 3) {
		for (int x = 0; x < 20; x++) {
			if (x % 2) {
				harta[0][x] = -2;
				harta[x][19] = -2;
				harta[x][0] = -2;
				harta[19][x] = -2;
			}
			else {
				harta[0][x] = -3;
				harta[x][19] = -3;
				harta[x][0] = -3;
				harta[19][x] = -3;

			}

		}
	}

       mancare();

}

void updateAI() {

	if (s1.di == STANGA) move(0, -1);
	else if (s1.di == DREAPTA) move(0, 1);
	else if (s1.di == SUS) move(-1, 0);
	else if (s1.di == JOS) move(1, 0);

	if (s2.di == STANGA) move(0, -1);
	else if (s1.di == DREAPTA) move(0, 1);
	else if (s1.di == SUS) move(-1, 0);
	else if (s1.di == JOS) move(1, 0);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (harta[i][j] > 0) harta[i][j]--;
		}

	if (superlungime != 0) {
		s1.lungime--;
		superlungime--;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				if (harta[i][j] > 1) harta[i][j]--;
			}



	}
}

void runAI() {

	inceputAI();

	running = true;
	while (running) {

		if (_kbhit()) {

			schimbaDirectia(_getch());
		}

		updateAI();
		system("cls");
		afisHarta();
		if (viteza == 1) Sleep(300);
		else if (viteza == 2) Sleep(150);
		else Sleep(10);
	}
	cout << endl << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << s1.score;
	adaugScor(s1.score, 2);
}

void muta(char caract) {
 if ((caract == 'w' || caract == 'W') && cont.y > 1) {
		meniu[P[cont.x][cont.y]][11] = ' ';
		cont.y--;
		meniu[P[cont.x][cont.y]][11] = '\>';
		
		afisaremeniu(A[cont.x], k);
	}
	else if ((caract == 's' || caract == 'S') && cont.y < P[cont.x][0]) {
		meniu[P[cont.x][cont.y]][11] = ' ';
		cont.y++;
		meniu[P[cont.x][cont.y]][11] = '\>';
		
		afisaremeniu(A[cont.x], k);
	}
	else if ((caract == 'a' || caract == 'A') && cont.x != 0) {
		if (cont.x == 10 || cont.x == 16) {
			meniu[P[cont.x][cont.y]][11] = ' ';
			cont.x = 8;
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			
			afisaremeniu(A[cont.x], k);

		}
		else if (cont.x == 15 || cont.x==3) {
			meniu[P[cont.x][cont.y]][11] = ' ';
			cont.x = 5;
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			
			afisaremeniu(A[cont.x], k);
		}
		else initializare();
	}
    else if ((caract == 'd' || caract == 'D')) {
		if (P[cont.x][cont.y] == 2 || P[cont.x][cont.y] == 8 || P[cont.x][cont.y] == 10 || P[cont.x][cont.y] == 16 || P[cont.x][cont.y] == 15 || P[cont.x][cont.y] == 3) {
			meniu[P[cont.x][cont.y]][11] = ' ';
			cont.x = P[cont.x][cont.y];
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			
			afisaremeniu(A[cont.x],k);
		}
		else if (P[cont.x][cont.y] == 5) {
			scoruri();
			cont.x = P[cont.x][cont.y];
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			
			afisaremeniu(A[cont.x], k);
		}
		else if (P[cont.x][cont.y] == 14  && cont.x==3) {
			meniu[P[cont.x][cont.y]][11] = ' ';
			cont.x = 5;
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			resetfis(1);
			afisaremeniu(A[cont.x], k);
			
		}
		else if (P[cont.x][cont.y] == 25) {
			meniu[P[cont.x][cont.y]][11] = ' ';
			cont.x = 5;
			cont.y = 1;
			meniu[P[cont.x][cont.y]][11] = '\>';
			resetfis(2);
			afisaremeniu(A[cont.x], k);
		}
		else if (P[cont.x][cont.y] == 12 || P[cont.x][cont.y] == 13 || P[cont.x][cont.y] == 14 ) {
			viteza = -11 + P[cont.x][cont.y];
			muta('a');
		}
		else if (P[cont.x][cont.y] == 22) {

			Sleep(500);
			afara = true;
		}
		else if (P[cont.x][cont.y] == 4) {

			runSolo();
			Sleep(5000);
			initializare();
		}
/*		else if (P[cont.x][cont.y] == 6) {

			runAI();
			Sleep(5000);
			initializare();
		}
*/
		else if (P[cont.x][cont.y] == 17|| P[cont.x][cont.y] == 18 || P[cont.x][cont.y] == 19 ) {
			nrharta = -16 + P[cont.x][cont.y];
			muta('a');
		}
		else if (P[cont.x][cont.y] == 3 || P[cont.x][cont.y] == 15) {

			afisaremeniu(A[cont.x], k);

		}
	}

}
void menu() {

	viteza = nrharta = 2;
	_pa();
   initializare();
   

   while (!afara) {
	   if (_kbhit()) {
		   muta(_getch());

		   
	   }
   }


}

int main()
{
    menu();

	return 0;
}



void sort(unsigned vec[],int n) {
	int i,j,aux;

	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if (vec[i] < vec[j]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}

}



void runSolo()
{
	
	inceput();
	running = true;
	while (running) {
		
		if (_kbhit()) {
			
			schimbaDirectia(_getch());
		}
		
		update();
		system("cls");
        afisHarta();
		if(viteza == 1) Sleep(120);
		else if (viteza == 2) Sleep(40);

	}


	cout <<endl<< "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << s1.score;
	adaugScor(s1.score,1);





}

void schimbaDirectia(char key) {

	if ((key == 'w' || key == 'W') && s1.di != JOS) s1.di = SUS;
    else if ((key == 'd' || key == 'D') && s1.di != STANGA) s1.di = DREAPTA;
    else if ((key == 's' || key == 'S') && s1.di != SUS) s1.di = JOS;
    else if ((key == 'a' || key == 'a') && s1.di != DREAPTA) s1.di = STANGA;
	else if (key == 'p' || key == 'P') { system("pause"); }
	
}

void move(int dx, int dy) {

	int noux = s1.cap.x + dx;
	int nouy = s1.cap.y + dy;

	if (harta[noux][nouy] == -5) {				
		s1.lungime++;
		if (superscore > 0) { 
			superscore--; 
			if (viteza == 1) s1.score += 5;
			else if (viteza == 2) s1.score += 10;
			else s1.score += 30;
		}
		if(viteza==1) s1.score += 5;
		else if (viteza == 2) s1.score += 10;
		else s1.score += 30;
		mancare();

	}
	else if (harta[noux][nouy] == -2) {

		if (s1.di == SUS) noux = 18;
		else if (s1.di == JOS) noux = 1;
		else if (s1.di == DREAPTA) nouy = 1;
		else if (s1.di == STANGA) nouy = 18;


	}
	else if (harta[noux][nouy] == -6) { superscore += 5; }
	else if (harta[noux][nouy] == -7) { superlungime += 5; }



	else if (harta[noux][nouy] != 0) running = false;
		
	s1.cap.x = noux;
	s1.cap.y = nouy;
	harta[s1.cap.x][s1.cap.y] = s1.lungime + 1;

}
void mancare() {
		int x = 0;
		int y = 0;

		do {
		
			x = rand() % 18 + 1;
			y = rand() % 18 + 1;


		} while (harta[x][y] != 0);


	harta[x][y] = -5;
	if (s1.lungime % 6 == 0 && s1.lungime > 5) {
		do {

			x = rand() % 18 + 1;
			y = rand() % 18 + 1;


		} while (harta[x][y] != 0);

		harta[x][y] = (rand() % 2) - 7;
	}
}

void update() {

	if (s1.di == STANGA) move(0, -1);
	else if (s1.di == DREAPTA) move(0, 1);
	else if (s1.di == SUS) move(-1, 0);
	else if (s1.di == JOS) move(1, 0);

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (harta[i][j] > 0) harta[i][j]--;
		}

	if (superlungime != 0) {
		int ok = 1;

		for (int i = 1; i < 19; i++)
			for (int j = 1; j < 19; j++)
			{
				if (harta[i][j] > 1) {
					harta[i][j]--; ok = 0;
				}
			}

		if (!ok) {
			s1.lungime--;
			superlungime--;
		}

	}
}
void inceput()
{   
	s1.score = 0;
	s1.di = DREAPTA;
	s1.cap.x = 10;
	s1.cap.y = 10;
	harta[s1.cap.x][s1.cap.y]  = 1;
	s1.lungime = 3;

	if (nrharta == 2) {
		for (int x = 0; x < 20; x++) {
			harta[0][x] = -1;
			harta[x][19] = -1;
			harta[x][0] = -1;
			harta[19][x] = -1;
		}
	}
	else if (nrharta == 1) {
		for (int x = 0; x < 20; x++) {
			harta[0][x] = -2;
			harta[x][19] = -2;
			harta[x][0] = -2;
			harta[19][x] = -2;
		}
	}
	else if (nrharta == 3) {
		for (int x = 0; x < 20; x++) {
			if (x % 2) {
				harta[0][x] = -2;
				harta[x][19] = -2;
				harta[x][0] = -2;
				harta[19][x] = -2;
			}
			else {
				harta[0][x] = -3;
				harta[x][19] = -3;
				harta[x][0] = -3;
				harta[19][x] = -3;

			}

		}
	}

	for (int i = 1; i < 19; i++)
		for (int j = 1; j < 19; j++)
			harta[i][j] = 0;

	
	mancare();
}
void afisHarta()
{
	cout << endl<<endl << "\t\tSCORUL:" <<s1.score<<endl<<"\t\t" ;
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			
			cout << valoareHarta(harta[x][y]);
		}
		
		cout << endl<<"\t\t";
	}
}

char valoareHarta(int value)
{

/*	if (value == s1.lungime && s1.di== SUS) return '^';
	else if (value == s1.lungime && s1.di == DREAPTA) return '>';
	else if (value == s1.lungime && s1.di == JOS) return char (251);
	else if (value == s1.lungime && s1.di == STANGA) return '<';
*/	
	if (value == s1.lungime) return char(219);
    else if (value > 0) return char(254);
	else if (value == -1) return char(219);
	else if (value == -2) return char(176);
	else if (value == -3) return char(254);
	else if (value == -5) return 'O';
	else if (value == -6) return 'S';
	else if (value == -7) return 'L';



}