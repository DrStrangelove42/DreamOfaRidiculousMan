#ifndef VWEARABLE_H
#define VWEARABLE_H

#include "Wearable.h"


/// <summary>
/// 
/// </summary>
class VisibleWearable : public Wearable
{
protected:
	RenderContext& renderer;
	string tag;
public:
	virtual ~VisibleWearable();

	VisibleWearable(const VisibleWearable& other) : Wearable(other), renderer(other.renderer), tag(other.tag) {}

	virtual VisibleWearable* clone() const {
		return new VisibleWearable(*this);
	}

	VisibleWearable(string identifier, int posx, int posy, string tag, RenderContext& renderer);

	virtual void equip(Player* p)const;

	virtual void remove(Player* p)const;

	/// <summary>
	/// The visible wearable objects have a specific place when they are equipped on the player.
	/// This function tells if this place is taken by the current object.
	/// </summary>
	/// <param name="p"></param>
	/// <returns></returns>
	virtual bool isWorn(Player* p)const;
	/// <summary>
	/// Called when the object is picked up.
	/// </summary>
	virtual void onPickup(Player* p) const;
};

#endif
