struct Params {
	int width;
	int height;
	int gameOver;
	int dir;
	int x;
	int y;
	int fruitX;
	int fruitY;
	int score;
	int nTail;
	int tailX[100];
	int tailY[100];
};
int gameInput();
int setParams(struct Params *snake);
void newCoordinates (struct Params *snake);
void gameOver(struct Params *snake);
int finalRecord(struct Params *snake);
