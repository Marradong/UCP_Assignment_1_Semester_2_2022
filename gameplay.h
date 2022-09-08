#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define UP_KEY 'w'
#define DOWN_KEY 's'
#define LEFT_KEY 'a'
#define RIGHT_KEY 'd'

char readMove(void);
void movePlayer(char** canvas, char* usrKey, int* playerCoords, int* usrIns);
void collapseFloor(int* usrIns, char** canvas);
void moveBorderless(char** canvas, char* usrKey, int* playerCoords, int* usrIns);

#endif