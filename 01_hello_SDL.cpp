/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool loadMedia(){
	bool success = true;

	helloWorld = SDL_LoadBMP( "C:\Users\trangdo\Documents\learnGit\MyFirstProject\capsule_616x353-7.jpg" );
    if(helloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "C:\Users\trangdo\Documents\learnGit\MyFirstProject\capsule_616x353-7.jpg", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( helloWorld );
    helloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			if(!loadMedia()){
				printf( "Failed to load media!\n" );
			}
			else{
				//Get window surface
				screenSurface = SDL_GetWindowSurface( window );

				//Fill the surface white
				//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
				
				//Apply the image
            	SDL_BlitSurface( helloWorld, NULL, screenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( window );
				
				//Hack to get window to stay up
				SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
