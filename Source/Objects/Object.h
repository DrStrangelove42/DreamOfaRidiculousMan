#ifndef OBJECT_H
#define OBJECT_H

#include "../Characters/MovingEntity.h"
#include "../Base/utils.h"
#include "../Base/game.h"

/// <summary>
/// An Object is an Entity that can be found in a Room, for the Player to interact with, in a Chest (which is an Object in and of itself), for the Player to collect, or in a Player's inventory, for the Player to use.
/// </summary>
class Object : public MovingEntity
{
protected:
	/// <summary>
	/// Identifier of the object.
	/// </summary>
	string id;

	/// <summary>
	/// Infotip text of the object.
	/// </summary>
	string info;

	/// <summary>
	/// 
	/// </summary>
	bool ismutable;
public:
	virtual ~Object();

	/// <summary>
	/// Initialises a new Object with the specified informations.
	/// </summary>
	/// <param name="identifier"></param>
	/// <param name="posx"></param>
	/// <param name="posy"></param>
	/// <param name="tx"></param>
	/// <param name="renderer"></param>
	/// <param name="trav"></param>
	/// <param name="attack"></param>
	/// <param name="defense"></param>
	Object(string identifier, int posx, int posy, string tx, RenderContext& renderer, bool trav, string info = "", bool save = false);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	Object(const Object& other);

	/// <summary>
	/// 
	/// </summary>
	bool traversable;

	string getId() const;
	bool getTrav() const;


	/// <summary>
	/// Change the object position. 
	/// </summary>
	/// <param name="px"></param>
	/// <param name="py"></param>
	void move(int px, int py);

	/// <summary>
	/// The following function describes how each type of object interacts with the player.
	/// Returns true if the object has been picked up (thus informing that we should remove it from the room)
	/// </summary>
	/// <param name="game"></param>
	virtual bool updateObject(GAME* game);

	/// <summary>
	/// Time management
	/// </summary>
	/// <param name="time"></param>
	/// <param name="renderer"></param>
	virtual void tick(int time, GAME* game);

	/// <summary>
	/// Encodes the object into a string in the correct format (the same one used when creating maps, without the position)
	/// </summary>
	virtual string objectToString() const;

	bool operator== (const Object& otherObj) const
	{
		return otherObj.id == id;
	}

	virtual string getInfo() const;

	/// <summary>
	/// Tells the map constructor if the object is to be considered as mutable in the player progress (thus to be saved
	/// and loaded as a map opens) or not. 
	/// The mutable objects will be taken exclusively from save files (if such files exist), whereas immutable ones will
	/// always be read from world data. False by default.
	/// </summary>
	/// <returns></returns>
	virtual bool isMutable() const;
};

#endif
