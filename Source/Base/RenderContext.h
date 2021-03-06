#ifndef RENDERCTXT_H
#define RENDERCTXT_H

#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <list>
#include "config.h"
 
#include <stdexcept>
#include <iostream>
#include <unordered_map>

using namespace std;

class Texture;

/// <summary>
/// RenderContext encapsulates a rendering context, that is used as an interface
/// with the graphics library to render the game. This class is the abstract base class.
/// </summary>
class RenderContext
{
public:
	/// <summary>
	/// Render context destructor.
	/// </summary>
	virtual ~RenderContext();

	/// <summary>
	/// Erases the entire canvas.
	/// </summary>
	virtual void clear() = 0;

	/// <summary>
	/// Flushes the graphical modifications to appear on the screen.
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// Internal SDL-specific function.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual SDL_Texture* fromSurface(SDL_Surface*) = 0;

	/// <summary>
	/// Does the actual rendering with low-level call to the graphics library (for now, SDL is here).
	/// </summary>
	/// <param name="t">The SDL Texture structure</param>
	/// <param name="srcrect">The SDL rect structure to crop from the image (NULL to take everything).</param>
	/// <param name="dstrect">The SDL destination rectangle structure.</param>
	/// <param name="angle">Rotating angle, in degrees</param>
	/// <param name="center">Center of rotation.</param>
	/// <param name="flip">If the image is flipped.</param>
	virtual void doRender(SDL_Texture* t,
		const SDL_Rect* srcrect,
		const SDL_Rect* dstrect,
		const double angle,
		const SDL_Point* center,
		const SDL_RendererFlip flip) = 0;

	/// <summary>
	/// Draws a rectangle at the specified position, and with the specified dimensions, with the possibility to fill it or not.
	/// </summary>
	/// <param name="x">X coordinate</param>
	/// <param name="y">Y coordinate</param>
	/// <param name="w">Width</param>
	/// <param name="h">Height</param>
	/// <param name="fill">If the rectangle is filled with colour.</param>
	virtual void drawRectangle(int x, int y, int w, int h, bool fill = false) = 0;

	/// <summary>
	/// Draws a line from one point to another.
	/// </summary>
	/// <param name="x1">Start X coordinate</param>
	/// <param name="y1">Start Y coordinate</param>
	/// <param name="x2">End X coordinate</param>
	/// <param name="y2">End Y coordinate</param>
	virtual void drawLine(int x1, int y1, int x2, int y2) = 0;

	/// <summary>
	/// Sets the current colour, in the format 0xRRGGBBAA. 
	/// </summary>
	/// <param name="color">Colour code</param>
	virtual void changeColor(int color) = 0;


	/// <summary>
	/// Stops during ms milliseconds.
	/// </summary>
	/// <param name="ms">The delay</param>
	virtual void RenderSleep(unsigned int ms) = 0;

	/// <summary>
	/// Use this function to load a Texture from a BMP file. If it succeeds,
	/// the Texture is saved in <textures> and will be loaded from memory next
	/// time this function is called for the same Texture ID.
	/// To load an AnimatedTexture (from files id0, ..., idN), prefix id with '*'.
	/// </summary>
	virtual Texture* LoadTexture(string id) = 0;

	/// <summary>
	/// Builds a Texture with the text inside (on a single line).
	/// </summary>
	/// <param name="text"></param> 
	/// <param name="color"></param>
	/// <returns></returns>
	virtual Texture* LoadString(string text, int color = 0xffffffff, int backcolor = 0) = 0;

	/// <summary>
	/// Loads a temporary Texture used to draw ever-changing text on screen.
	/// This way, we do not fill the RAM with every string possible.
	/// </summary>
	/// <param name="text"></param> 
	/// <param name="color"></param>
	/// <returns></returns>
	virtual Texture* LoadVolatileString(string text, int color, int backColor = 0) = 0;

	/// <summary>
	/// Loads a multiline text designed to fit in the specified width (in pixels).
	/// </summary>
	virtual Texture* LoadText(string text, int color, int width) = 0;

	/// <summary>
	/// Loads a single line of text
	/// </summary>
	/// <param name="text">The text to be displayed.</param>
	/// <param name="colors">The list of colours defining the animation.</param>
	/// <param name="interval">Time delay, in ms, between each colour.</param>
	/// <param name="loop">Tells whether the animations keeps on going after the last color.</param>
	/// <returns></returns>
	virtual Texture* LoadAnimatedString(string text, list<int> colors, int interval, bool loop = true) = 0;

	/// <summary>
	/// Loads a single line of text with an animation on the background.
	/// </summary>
	/// <param name="text">The text to be displayed.</param>
	/// <param name="colors">The list of colours defining the animation.</param>
	/// <param name="bgcolors">The list of background colours of the animation. It must have the same size as the colors list.</param>
	/// <param name="interval">Time delay, in ms, between each colour.</param>
	/// <param name="loop">Tells whether the animations keeps on going after the last color.</param>
	/// <returns></returns>
	virtual Texture* LoadAnimatedBoxedString(string text, list<int> colors, list<int> bgcolors, int interval, bool loop = true) = 0;

	/// <summary>
	/// Loads a multiline text designed to fit in the specified width (in pixels).
	/// </summary>
	/// <param name="text"></param>
	/// <param name="color"></param>
	/// <param name="backColor"></param>
	/// <param name="width"></param>
	/// <returns></returns>
	virtual Texture* LoadText(string text, int color, int backColor, int width, int padding = 0) = 0;

	/// <summary>
	/// Loads a string with an icon on the left.
	/// </summary>
	/// <param name="text"></param>
	/// <param name="textureId"></param>
	/// <param name="color"></param>
	/// <param name="backColor"></param>
	/// <returns></returns>
	virtual Texture* LoadStringWithIcon(string text, string textureId, int color, int padding = 5, int backColor = 0) = 0;
};

#endif
