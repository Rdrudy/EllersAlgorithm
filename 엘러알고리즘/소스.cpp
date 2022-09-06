#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 51);

int randnum(int n, int k) {
		return rand() % (k - n + 1) + n;
}

class Maze {
private:
	int mazearr[50][50];
	int mazecheck[50][50];
	int mazevertcheck[50];

public:
	void firstline(int n) { // 열 개수
		for (int i = 0; i < n; i++) {
			mazearr[0][i] = i;
		}
	}

	void linecheck(int n) { // n번째 행 체크
		for (int i = 0; i < 40; i++) {
			if (mazearr[n][i] != mazearr[n][i + 1]) {
				mazecheck[n][i] = 50*n + i;
			}
		}
	}

	void erasewall(int n) { // n번째 행 체크
		for (int i = 0; i < 40; i++) {
				if (mazecheck[n][i] == 50*n + i) {
					if (rand() % 2 == 1) {
						mazearr[n][i + 1] = mazearr[n][i];
					}
				}
			
		}
	}

	void make_leastvertwall(int n) {// n번째 행 체크
		int count = 0;
		for (int i = 0; i < 40; i++) {
			if(mazearr[n][i] != mazearr[n][i+1]){
				int d = randnum(count, i);
				mazearr[n + 1][d] = mazearr[n][d];
				count = i+1;
			}
		}	
	}

	void make_vertwall(int n) { //n번째 행 체크
		for (int i = 0; i < 40; i++) {
			if (rand()%2 == 1) {
				mazearr[n + 1][i] = mazearr[n][i];
			}
		}
	}

	void nextline(int n) { //n번째 행 체크
		for (int i = 0; i < 40; i++) {
			if (mazearr[n][i] == 0) {
				mazearr[n][i] = 50*n + i;
			}
		}
	}

	void drawmaze(int n1, int n2) {
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				cout << mazearr[i][j] << ".";
			}
			cout << endl;
		}
	}

};



int main() {

	srand((unsigned int)time(NULL));

	Maze maze = Maze();

	int a, b;
	
	cin >> a;
	cin >> b;

	maze.firstline(a);

	for (int i = 0; i < b; i++) {
		maze.linecheck(i);
		maze.erasewall(i);
		maze.make_leastvertwall(i);
		maze.make_vertwall(i);
		maze.nextline(i + 1);
	}

	maze.drawmaze(a, b);

	return 0;
}