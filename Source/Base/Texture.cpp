#include "Texture.h"

Texture::Texture(RenderContext& context, string id)
{
	texture = internalLoadTexture(context, id, w, h);
}

SDL_Texture* Texture::internalLoadTexture(RenderContext& context, string id, int& w, int& h, bool ignoreErrors)
{
	SDL_Texture* tx = NULL;

	SDL_Surface* bmp = internalLoadBitmapSurface(id, ignoreErrors);

	if (NULL == bmp)
	{
		if (!ignoreErrors)
			cout << "Unable to load surface from file #" + id + " : " + string(SDL_GetError()) << endl;
		return NULL;
	}

	tx = context.fromSurface(bmp);
	SDL_FreeSurface(bmp);

	if (NULL == tx)
	{
		if (!ignoreErrors)
			cout << "Unable to create texture #" + id + " : " + string(SDL_GetError()) << endl;
		return NULL;
	}

	SDL_QueryTexture(tx, NULL, NULL, &w, &h);

	return tx;
}


Texture::Texture(SDL_Texture* texture, int w, int h) : texture(texture), w(w), h(h)
{

}

Texture::~Texture()
{
	if (NULL != texture)
		SDL_DestroyTexture(texture);
}

void Texture::renderUnscaled(RenderContext& context, int x, int y, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	internalRenderUnscaled(texture, context, x, y, angle, center, flip);
}

void Texture::render(RenderContext& context, int x, int y, int width, int height, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	internalRender(texture, context, x, y, width, height, angle, center, flip);
}

int Texture::getWidth() { return w; }
int Texture::getHeight() { return h; }
