#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>
#include <string>
#include "../Maps/Map.h"

using namespace std;

typedef struct
{
	SDL_Window* window;
	RenderContext* renderer;
	Map* currentMap;
	bool quit;
} GAME;

/* Events */
void manageEvents(GAME* game);
void onKeyDown(SDL_Event event, GAME* game);
void onWindowEvent(SDL_Event, GAME*);
/* Destroy the game structure and quits the program. */
void quitGame(GAME* game);
#endif