/* Entry point */

#include "main.h"

using namespace std;

/// <summary>
/// 
/// Main entry point of DOARM.
/// 
/// No command line options.
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char** argv)
{
	int status = 0;

	if (!RenderInit())
		return DumpError("Init error.");

	GAME* game = initGame();

	if (NULL == game)
		return EXIT_FAILURE;

	status = playDoarm(game);

	quitGame(game);
	
	RenderQuit();
	return status;
}

int playDoarm(GAME* game)
{
	RenderContext& renderer = *(game->renderer);
	Player* me = new Player(renderer, SAVES_CURRENT);

	game->player = me;
	game->currentMap = new MainMenu(*me, game);
	game->worldName = "Main menu";
	addMapToCache(game->worldName, 0, game->currentMap);
	addMapToCache("EndCredits", -1, new EndCredits(*me, game));
	
	int currentTime;

	while (!(game->quit))
	{
		game->renderer->clear();

		manageEvents(game);

		currentTime = GetTime();
		game->currentMap->tick(currentTime, game);
		game->player->tick(currentTime, game);

		game->currentMap->render(renderer);

		game->renderer->update();

		game->renderer->RenderSleep(WAIT_TIME);
	}

	return EXIT_SUCCESS;
}

GAME* initGame()
{
	InitUtils();
	
	GAME* game = new GAME();

	game->quit = false;
	game->window = new Window("DOARM", SZ_SCREENWIDTH, SZ_SCREENHEIGHT);
	game->key = KEY::Other;
	game->currentMapId = new int(0);
	game->keyLetter = '\0';

	if (NULL == game->window)
	{
		DumpError("Window error.");
		return NULL;
	}

	game->renderer = new SDLRenderContext(*(game->window));
	
	SoundInit();

	return game;
}
