#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "config.h"

extern TTF_Font* FONT;
extern int FONTSIZE;

/// <summary>
/// Stops during ms milliseconds.
/// </summary>
/// <param name="ms">The delay</param>
void renderSleep(unsigned int ms);

/// <summary>
/// Initialisation of the rendering module
/// </summary>
/// <returns></returns>
bool renderInit();

/// <summary>
/// Dump errors in the console.
/// </summary>
/// <returns></returns>
std::string renderErrorDetails();

/// <summary>
/// Creates a window
/// </summary>
/// <returns></returns>
SDL_Window* renderCreateWindow();

/// <summary>
/// Exits rendering module
/// </summary>
void renderQuit();
#endif