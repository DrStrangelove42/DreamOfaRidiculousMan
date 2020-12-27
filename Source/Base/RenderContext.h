#ifndef RENDERCTXT_H
#define RENDERCTXT_H

#include "utilsSDL.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#ifdef WIN6
#include <Windows.h>
#undef LoadString
#endif
#include <stdexcept>
#include <iostream>
#include <unordered_map>

using namespace std;

/*Forward decl*/
class Texture;

/// <summary>
/// A class encapsulating a rendering context, that is an object used as an interface
/// with the graphics library to render the game.
/// </summary>
class RenderContext
{
protected:
	/// <summary>
	/// The native renderer.
	/// </summary>
	SDL_Renderer* renderer;

	static TTF_Font* FONT;
	static int FONTSIZE;
	/// <summary>
	/// The hashmap where textures are stored.
	/// Textures beginning with 'text/' are reserved for text rendering.
	/// </summary>
	static unordered_map<string, Texture*> textures;
public:
	/// <summary>
	/// Creates a new render context from the specified window.
	/// </summary>
	/// <param name="window"></param>
	RenderContext(Window& window);
	~RenderContext();

	/// <summary>
	/// Erases the entire canevas.
	/// </summary>
	void clear();

	/// <summary>
	/// Flushes the graphical modifications to appear on the screen.
	/// </summary>
	void update();

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	SDL_Texture* fromSurface(SDL_Surface*);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="t"></param>
	/// <param name="srcrect"></param>
	/// <param name="dstrect"></param>
	/// <param name="angle"></param>
	/// <param name="center"></param>
	/// <param name="flip"></param>
	void doRender(SDL_Texture* t,
		const SDL_Rect* srcrect,
		const SDL_Rect* dstrect,
		const double angle,
		const SDL_Point* center,
		const SDL_RendererFlip flip);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="h"></param>
	/// <param name="fill"></param>
	void drawRectangle(int x, int y, int w, int h, bool fill = false);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x1"></param>
	/// <param name="y1"></param>
	/// <param name="x2"></param>
	/// <param name="y2"></param>
	void drawLine(int x1, int y1, int x2, int y2);

	/// <summary>
	/// Sets the current color, in the format 0xRRGGBBAA 
	/// </summary>
	/// <param name="color"></param>
	void changeColor(int color);

	/*Static functions*/
	/// <summary>
	/// Stops during ms milliseconds.
	/// </summary>
	/// <param name="ms">The delay</param>
	static void RenderSleep(unsigned int ms);

	/// <summary>
	/// Initialisation of the rendering module
	/// </summary>
	/// <returns></returns>
	static bool RenderInit();

	/// <summary>
	/// Dump errors in the console.
	/// </summary>
	/// <returns></returns>
	static string RenderErrorDetails();

	/// <summary>
	/// Exits rendering module
	/// </summary>
	static void RenderQuit();

	/*Static functions from SDL-specific part of the Utils module*/
	

	/// <summary>
	/// Use this function to load a texture from a BMP file. If it succeeds,
	/// the texture is saved in <textures> and will be loaded from memory next
	/// time this function is called for the same texture ID.
	/// </summary>
	Texture* LoadTexture(string id);

	/// <summary>
	/// Builds a texture with the text inside.
	/// </summary>
	/// <param name="text"></param> 
	/// <param name="color"></param>
	/// <returns></returns>
	Texture* LoadString(string text, int color = 0xffffffff);

	/// <summary>
	/// Loads a temporary texture used to draw ever-changing text on screen.
	/// This way, we do not fill the RAM with every string possible.
	/// </summary>
	/// <param name="text"></param> 
	/// <param name="color"></param>
	/// <returns></returns>
	Texture* LoadVolatileString(string text, int color);

	/// <summary>
	/// Frees memory.
	/// </summary>
	static void FreeTextures();
};

#endif