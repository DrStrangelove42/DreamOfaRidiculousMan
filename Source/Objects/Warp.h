#ifndef WARP_H
#define WARP_H

#include "Object.h"

class Warp : public Object
{
private:
  int destMap;
  int destRoom;
  int destX;
  int destY;
public:
	/*Destructor*/
	~Warp()
	
	/*Constructor*/
	Warp(int destMap, int destRoom, int destX, int destY, int posx, int posy, Player& p, RenderContext& renderer);

	/* How does a warp interact with the player? */
	void updateObject(Player& p, RenderContext& renderer, EVENT_ARGS* ea);
};

#endif