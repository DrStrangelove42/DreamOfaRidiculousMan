#ifndef DRAWABLE_ENTITY_H
#define DRAWABLE_ENTITY_H

#include "Entity.h"
#include "../Base/utils.h"
#include "Texture.h"

class DrawableEntity : Entity
{
protected:
	/* Position coordinates */
	int x;
	int y;

	/// <summary>
	/// The texture ID
	/// </summary>
	string texture;
	/// <summary>
	/// The loaded texture
	/// </summary>
	Texture* loadedTx;

public:
	DrawableEntity(int x, int y, RenderContext& renderer, string tx);
	DrawableEntity(int x, int y, Texture* tx);
	
	/// <summary>
	/// Forces the object to reload the texture corresponding to the current ID in <texture>.
	/// Note that there is no function to change the texture from the outside of the object, because we
	/// don't want to, for now.
	/// </summary>
	/// <param name="renderer"></param>
	virtual void updateTexture(RenderContext& renderer);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="texture"></param>
	void setTexture(Texture* texture);

	/// <summary>
	/// Rendering method, enabling the renderer to take the offset (in blocks) into account.
	/// </summary>
	/// <param name="renderer"></param>
	/// <param name="offsetX">X Offset, in blocks.</param>
	/// <param name="offsetY">Y Offset, in blocks.</param>
	virtual void render(RenderContext& renderer, int offsetX = 0, int offsetY = 0) const;

	/// <summary>
	/// Absolute rendering of the drawable entity (useful to draw it somewhere else outside a map)
	/// </summary>
	/// <param name="renderer"></param>
	/// <param name="xx"></param>
	/// <param name="yy"></param>
	void sideRender(RenderContext& renderer, int xx, int yy) const;

	string& getTextureID();
};

#endif // !DRAWABLE_ENTITY_H
