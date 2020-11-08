/* Entry point */

#include "main.h"

using namespace std;

int main(int argc, char** argv)
{
	int status = 0;

	if (!renderInit())
		return DumpError("Init error.");
	
	GAME* game = initGame();

	if (NULL == game)
		return EXIT_FAILURE;

	status = playDoarm(game);

	/*Free the memory*/
	FreeTextures();
	
	quitGame(game);
	return status;
}

/*Main loop*/
int playDoarm(GAME* game)
{
	RenderContext& renderer = *(game->renderer);
	Player me(renderer);

	game->currentMap = new DummyMap(me, renderer); //POC

	while (!(game->quit))
	{
		game->renderer->clear();
		
		manageEvents(game);

		game->currentMap->render(renderer);

		game->renderer->update();

		renderSleep(50);
	}

	return EXIT_SUCCESS;
}

GAME* initGame()
{
	InitUtils();

	GAME* game = new GAME();

	game->quit = false;
	game->window = renderCreateWindow();

	if (NULL == game->window)
	{
		DumpError("Window error.");
		return NULL;
	}

	game->renderer = new RenderContext(game->window);

	return game;
}

