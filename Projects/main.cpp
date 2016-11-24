#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Screen Dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Level constants
const int LEVEL_WIDTH = 650;
const int LEVEL_HEIGHT = 494;

//Tile constants
const int TILE_WIDTH = 26;
const int TILE_HEIGHT = 26;
const int TOTAL_TILES = 475;
const int TOTAL_TILE_SPRITES = 16;
enum Tiles{
	TILE_TOPLEFT,
	TILE_LEFT,
	TILE_BOTTOMLEFT,
	TILE_TOP,
	TILE_CENTER,
	TILE_BOTTOM,
	TILE_TOPRIGHT,
	TILE_RIGHT,
	TILE_BOTTOMRIGHT,
	TILE_START,
	TILE_SWITCH,
	TILE_FLOOR,
	TILE_EXITCLOSED,
	TILE_EXITOPEN,
	TILE_WALL,
	TILE_TRAP,
};

//Button constants
const int BUTTON_WIDTH = 116;
const int BUTTON_HEIGHT = 56;
enum LButtonSprite{
	//Enumerates values to variables
	MOUSE_SPRITE_OUT,
	MOUSE_SPRITE_OVER,
	MOUSE_SPRITE_DOWN,
	MOUSE_SPRITE_UP,
	MOUSE_SPRITE_TOTAL
};


//Game classes 
class LTexture{
	public:
		LTexture();
		~LTexture();

		bool loadFromFile(string path);
		#ifdef _SDL_TTF_H
		bool loadFromRenderedText(string textTexture, SDL_Color textColor);
		#endif
		void free();

		void setColor(Uint8 red, Uint8 green, Uint8 blue);
		void setBlendMode(SDL_BlendMode blend);
		void setAlpha(Uint8 alpha);
		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		int getWidth();
		int getHeight();
		
	private:
		SDL_Texture* mTexture;
		TTF_Font* gFont;
		int mWidth;
		int mHeight;
};
class LButton{
public:
	//constructor
	LButton();

	//Sets position of button
	void setPosition(int x, int y);
	//Handles Start button
	void handleStartEvents(SDL_Event* e);
	//Handles Quit button
	void handleQuitEvents(SDL_Event* e);
	void renderStart();
	void renderQuit();
	bool isStarted();
	bool isStopped();

private:
	//Position of button
	SDL_Point mPosition;
	//Currently renderered sprite
	LButtonSprite mCurrentSprite;
	//Records whether the game has started
	bool mStarted;
	//Records whether the user quits
	bool mStopped;

};
class Tile{
public:
	//Initializes the position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	void render();

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();

private:
	//Attributes of the tile
	//Normally its best to hold the position and collision box in separate classes, but this is for the sake of simplicity
	SDL_Rect mBox;

	//Tile type
	int mType;
};
class Player{
public:
	//Dimensions of the dot
	static const int PLAYER_WIDTH = 23;
	static const int PLAYER_HEIGHT = 26;

	//Maximum axis velocity of the dot
	static const int PLAYER_VEL = 3;

	//Constructor
	Player(int x, int y);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move(Tile* tiles[]);

	//Shows the dot on the screen
	void render();

	//Sets the player spawn
	void setSpawn(Tile* tiles[]);

	//Returns the player's movement status
	bool isStopped();

	SDL_Rect getHitbox();

private:
	//Collision box
	SDL_Rect mBox;

	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;

	//Starting frame for clip
	int startingClip;

	//Min frame for clip
	int minClip;

	//Max frame for clip
	int maxClip;

	//Checks if the player is in motion
	bool mStopped;

};
class Exit{
public:
	Exit();

	void loadExit(Tile* tile[],int currentTile, bool switchPressed);

	SDL_Rect getHBox();

private:
	int mPosX;
	int mPosY;

	SDL_Rect mBox;


};
class SpikeTrap{
public:
	//Constructor for traps
	SpikeTrap();
	//set traps on set trap tiles
	void setTrap(Tile* tiles[], int currentTile);
	//Renders the trap animation
	void animate();
	//Returns the spike's hitbox
	SDL_Rect getHBox();
	//Returns active bool
	bool getActiveBox();

private:
	//Rendering position
	int mPosX, mPosY;
	//Hitbox
	SDL_Rect mBox;

	//Checks if spikes are on active frames for damage hitbox
	bool mActiveBox;

	//Animation frames
	int mframe;
	//Flag for the status of the spikes(True/False for Up/Down) for animation
	bool mSpikesUp;
	//Delays the up spike animation
	int mDelay;

};

//*** Level functions ***
void gameLevel(Player user, Tile* tiles[], Exit&levelExit, bool&exit, SpikeTrap&spikes);
void setSpikeHbox(Tile* tiles[]);

//*** Game functions ***
bool pressSwitch(SDL_Rect box, Tile* tiles[]);
bool playerExit(bool exit, SDL_Rect a, SDL_Rect b);
void resetValues(bool&isStarted, bool&exit, bool&level, bool&nextlevel);

//*** Life functions **
void renderLives(int lives);
void checkSpikes(Player&player, int&lives, SpikeTrap&spikes, Tile* tiles[]);

//*** System Functions ***
bool init();
bool loadMedia(Tile* tiles[], string path);
void close(Tile* tiles[]);
bool checkCollision(SDL_Rect a, SDL_Rect b);
bool touchesWall(SDL_Rect box, Tile* tiles[]);
bool setTiles(Tile* tiles[], string path);

//*** System Variables ***
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gTitleBackground;
LTexture gCongrats;
LTexture gGameOver;

//Mouse Button Sprite
SDL_Rect gSpriteClips[MOUSE_SPRITE_TOTAL];
LTexture gStartSpriteSheet;
LTexture gQuitSpriteSheet;
LButton gStartButton;
LButton gQuitButton;

//Character Sprites 
const int WALKING_FRAMES = 12;
SDL_Rect gCharSpriteClips[WALKING_FRAMES];
LTexture gCharSpriteSheetTexture;
LTexture gCharLives;

//Dungeon Textures 
LTexture gDungeonTexture;
SDL_Rect gDungeonClips[TOTAL_TILE_SPRITES];
LTexture gDungeonExit;

//Spike Texture
const int SPIKE_ANIMATION_FRAMES = 4;
LTexture gSpikeTexture;
SDL_Rect gSpikeClips[SPIKE_ANIMATION_FRAMES];
vector<SDL_Rect> gSpikeHboxes;


//***  Main Function  ***
int main(int argc, char* argv[]){
	//Tiles variable for maps
	Tile* dungeonTiles[TOTAL_TILES];

	init();

	if (!init){
		cout << "Failed to initialize!" << endl;
	}
	else{
		loadMedia(dungeonTiles, "deps/levels/floor00.map");

		if (!loadMedia){
			cout << "Failed to load media!" << endl;
		}
		else{
			//System variables
			bool quit = false;
			SDL_Event e;
			
			//Game variables
			Player player1(0,0);
			int lives = 3;
			Exit levelExit;
			bool gameStarted = false;
			bool gameOver = false;
			bool exit = false;
			SpikeTrap spikes;


			//Level bools
			bool lv0Complete = false;
			bool lv1Complete = true;
			bool lv2Complete = true;
			bool lv3Complete = true;

			while (!quit){
				while (SDL_PollEvent(&e) != 0){
					gQuitButton.handleQuitEvents(&e);
					if (e.type == SDL_QUIT || gQuitButton.isStopped() && !gStartButton.isStarted()){
						//Includes start button as condition to prevent the quit button from activating
						quit = true;
					}
					else if (!gStartButton.isStarted()){
						gStartButton.handleStartEvents(&e);
					}
					else if(gStartButton.isStarted()){
						player1.handleEvent(e);
					}
				
				}
				SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
				SDL_RenderClear(gRenderer);

				//If the game has not started
				if (!gStartButton.isStarted()){
					//Render title screen and buttons
					gTitleBackground.render(0, 0);
					gStartButton.renderStart();
					gQuitButton.renderQuit();
				}
				else if(!lv0Complete && !gameOver){

					//Floor 00
					if (!gameStarted){
						//Sets player spawn
						player1.setSpawn(dungeonTiles);
					}
					gameStarted = true;

					//Move player
					player1.move(dungeonTiles);

					//Renders the game level
					gameLevel(player1, dungeonTiles, levelExit,exit, spikes);

					//Set spike hit boxes
					setSpikeHbox(dungeonTiles);
					//Checks player collision with traps
					checkSpikes(player1, lives, spikes,dungeonTiles);

					//Renders player and lives
					player1.render();
					renderLives(lives);


					//Enables the next level when the player exits
					if (playerExit(exit, player1.getHitbox(), levelExit.getHBox())){
						resetValues(gameStarted, exit, lv0Complete, lv1Complete);
					}

					//Game over check
					if (lives <= 0){
						gameOver = true;
					}


				}
				else if (!lv1Complete && !gameOver){

					//Floor 01
					if (!gameStarted){
						//Sets new tiles
						setTiles(dungeonTiles, "deps/levels/floor01.map");
						//Sets player spawn
						player1.setSpawn(dungeonTiles);
					}
					gameStarted = true;
					
					//Move player
					player1.move(dungeonTiles);

					//Renders the game level
					gameLevel(player1, dungeonTiles, levelExit, exit, spikes);

					//Set spike hitboxes
					setSpikeHbox(dungeonTiles);
					//Checks player collision with traps
					checkSpikes(player1, lives, spikes, dungeonTiles);
					

					//Render player and lives
					player1.render();
					renderLives(lives);
					
					//Enables the next level when the player exits
					if (playerExit(exit, player1.getHitbox(), levelExit.getHBox())){
						resetValues(gameStarted, exit, lv1Complete, lv2Complete);
					}

					//Game over check
					if (lives <= 0){
						gameOver = true;
					}
				}
				else if (gameOver){
					gGameOver.render(0, 0);
				}
				else{
					gCongrats.render(0, 0);
				}
				

				SDL_RenderPresent(gRenderer);
			}
		}
	}
	//Closes all media and SDL
	close(dungeonTiles);
	return 0;
}


//Level functions
void gameLevel(Player user, Tile* tiles[], Exit&levelExit, bool&exit, SpikeTrap&spikes){
	//Renders level and checks tiles
	for (int i = 0; i < TOTAL_TILES; i++){
		//Checks if the player hits the switch
		if (pressSwitch(user.getHitbox(), tiles) && tiles[i]->getType() == TILE_EXITCLOSED){
			exit = true;
		}
		//Changes the tile if he does
		if (exit && tiles[i]->getType() == TILE_EXITCLOSED){
			levelExit.loadExit(tiles,i,exit);
		}
		//Renders the tiles normally if he doesnt
		else{
			tiles[i]->render();
		}

		//If the tile is a tile trap
		if (tiles[i]->getType() == TILE_TRAP){
			//Set and animate the trap on the tile
			spikes.setTrap(tiles, i);
			spikes.animate();
		
		}
	}
}
void setSpikeHbox(Tile* tiles[]){
	//Counter for spikes
	int j = 0;

	//Checks all tiles
	for (int i = 0; i < TOTAL_TILES; i++){
		//If the tile is a tile trap
		if (tiles[i]->getType() == TILE_TRAP){
			//Resize the vector to accomidate the number of traps
			gSpikeHboxes.resize(j + 1);

			//Set the hitboxes 
			gSpikeHboxes[j].x = tiles[i]->getBox().x + 3;
			gSpikeHboxes[j].y = tiles[i]->getBox().y + 2;
			gSpikeHboxes[j].w = TILE_WIDTH - 6;
			gSpikeHboxes[j].h = TILE_HEIGHT - 5;

			//Increments j for the next possible trap
			j++;
		}
	}

	//If no spikes were found
	if (j == 0){
		gSpikeHboxes.resize(j);
	}
}

//Game functions
bool pressSwitch(SDL_Rect box, Tile* tiles[]){
	//Go through the tiles
	for (int i = 0; i < TOTAL_TILES; i++){
		//If the tile is a wall type(ie. the black tiles)
		if (tiles[i]->getType() == TILE_SWITCH){
			if (checkCollision(box, tiles[i]->getBox())){
				return true;
			}
		}
	}
	//No switch was triggered
	return  false;
}
bool playerExit(bool exit, SDL_Rect a, SDL_Rect b){
	if (exit && checkCollision(a, b)){
		return true;
	}
	return false;
}
void resetValues(bool&isStarted, bool&exit, bool&level, bool&nextlevel){
	//Resets the game started value
	isStarted = false;
	//Disable the level
	level = true;
	//Reset the exit
	exit = false;
	//Enable the next level
	nextlevel = false;
}

bool checkCollision(SDL_Rect a, SDL_Rect b){
	//Checks rectangles for collision

	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of the rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of the rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside B
	if (bottomA <= topB){
		return false;
	}

	if (topA >= bottomB){
		return false;
	}

	if (leftA >= rightB){
		return false;
	}

	if (rightA <= leftB){
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
bool setTiles(Tile* tiles[], string path){
	//Sets textured tiles
	bool tilesLoaded = true;

	//Tile offsets
	int x = 0, y = 0;

	//Open the map
	ifstream map(path.c_str());

	//If the map cannot be loaded
	if (!map){
		cout << "Unable to load " << path.c_str() << "!" << endl;
		tilesLoaded = false;
	}
	else{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; i++){
			//Determines the type of tile
			int tileType = -1;

			//Read tile from map
			map >> tileType;

			//If a problem occurs with the map
			if (map.fail()){
				//Stop loading map
				cout << "Error loading map: Unexpected end of file!" << endl;
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType <= TOTAL_TILE_SPRITES)){
				tiles[i] = new Tile(x, y, tileType);
			}
			else{
				//Abort if fails
				cout << "Error loading map: Invalid tile type!" << endl;
				tilesLoaded = false;
				break;
			}

			//Move to the next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if (x >= LEVEL_WIDTH){
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}

		//Clips sprite sheet
		if (tilesLoaded){
			//Sets clips
			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 3; j++){
					gDungeonClips[i * 3 + j].x = i * 26;
					gDungeonClips[i * 3 + j].y = j * 26;
					gDungeonClips[i * 3 + j].w = TILE_WIDTH;
					gDungeonClips[i * 3 + j].h = TILE_HEIGHT;
				}
			}

			gDungeonClips[TILE_TRAP].x = 130;
			gDungeonClips[TILE_TRAP].y = 0;
			gDungeonClips[TILE_TRAP].w = TILE_WIDTH;
			gDungeonClips[TILE_TRAP].h = TILE_HEIGHT;

			//Old sprite clip code
			/*
			gDungeonClips[TILE_TOPLEFT].x = 0;
			gDungeonClips[TILE_TOPLEFT].y = 0;
			gDungeonClips[TILE_TOPLEFT].w = TILE_WIDTH;
			gDungeonClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			gDungeonClips[TILE_LEFT].x = 0;
			gDungeonClips[TILE_LEFT].y = 26;
			gDungeonClips[TILE_LEFT].w = TILE_WIDTH;
			gDungeonClips[TILE_LEFT].h = TILE_HEIGHT;

			gDungeonClips[TILE_BOTTOMLEFT].x = 0;
			gDungeonClips[TILE_BOTTOMLEFT].y = 52;
			gDungeonClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
			gDungeonClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

			gDungeonClips[TILE_TOP].x = 26;
			gDungeonClips[TILE_TOP].y = 0;
			gDungeonClips[TILE_TOP].w = TILE_WIDTH;
			gDungeonClips[TILE_TOP].h = TILE_HEIGHT;

			gDungeonClips[TILE_CENTER].x = 26;
			gDungeonClips[TILE_CENTER].y = 26;
			gDungeonClips[TILE_CENTER].w = TILE_WIDTH;
			gDungeonClips[TILE_CENTER].h = TILE_HEIGHT;

			gDungeonClips[TILE_BOTTOM].x = 26;
			gDungeonClips[TILE_BOTTOM].y = 52;
			gDungeonClips[TILE_BOTTOM].w = TILE_WIDTH;
			gDungeonClips[TILE_BOTTOM].h = TILE_HEIGHT;

			gDungeonClips[TILE_TOPRIGHT].x = 52;
			gDungeonClips[TILE_TOPRIGHT].y = 0;
			gDungeonClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			gDungeonClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			gDungeonClips[TILE_RIGHT].x = 52;
			gDungeonClips[TILE_RIGHT].y = 26;
			gDungeonClips[TILE_RIGHT].w = TILE_WIDTH;
			gDungeonClips[TILE_RIGHT].h = TILE_HEIGHT;

			gDungeonClips[TILE_BOTTOMRIGHT].x = 52;
			gDungeonClips[TILE_BOTTOMRIGHT].y = 52;
			gDungeonClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
			gDungeonClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;

			gDungeonClips[TILE_START].x = 78;
			gDungeonClips[TILE_START].y = 0;
			gDungeonClips[TILE_START].w = TILE_WIDTH;
			gDungeonClips[TILE_START].h = TILE_HEIGHT;

			gDungeonClips[TILE_SWITCH].x = 78;
			gDungeonClips[TILE_SWITCH].y = 26;
			gDungeonClips[TILE_SWITCH].w = TILE_WIDTH;
			gDungeonClips[TILE_SWITCH].h = TILE_HEIGHT;

			gDungeonClips[TILE_FLOOR].x = 78;
			gDungeonClips[TILE_FLOOR].y = 52;
			gDungeonClips[TILE_FLOOR].w = TILE_WIDTH;
			gDungeonClips[TILE_FLOOR].h = TILE_HEIGHT;

			gDungeonClips[TILE_EXITCLOSED].x = 104;
			gDungeonClips[TILE_EXITCLOSED].y = 0;
			gDungeonClips[TILE_EXITCLOSED].w = TILE_WIDTH;
			gDungeonClips[TILE_EXITCLOSED].h = TILE_HEIGHT;

			gDungeonClips[TILE_EXITOPEN].x = 104;
			gDungeonClips[TILE_EXITOPEN].y = 26;
			gDungeonClips[TILE_EXITOPEN].w = TILE_WIDTH;
			gDungeonClips[TILE_EXITOPEN].h = TILE_HEIGHT;

			gDungeonClips[TILE_WALL].x = 104;
			gDungeonClips[TILE_WALL].y = 56;
			gDungeonClips[TILE_WALL].w = TILE_WIDTH;
			gDungeonClips[TILE_WALL].h = TILE_HEIGHT;
			*/
		}
	}
	//Close the file
	map.close();

	return tilesLoaded;
}
bool touchesWall(SDL_Rect box, Tile* tiles[]){
	//Checks if player touches wall
	//Go through the tiles
	for (int i = 0; i < TOTAL_TILES; i++){
		//If the tile is a wall type(ie. the black tiles)
		if ((tiles[i]->getType() >= TILE_TOPLEFT) && (tiles[i]->getType() <= TILE_BOTTOMRIGHT) || tiles[i]->getType() == TILE_WALL){
			if (checkCollision(box, tiles[i]->getBox())){
				return true;
			}
		}
	}
	//if no wall tiles were touched
	return  false;
}


//Life functions
void renderLives(int lives){
	for (int i = 0; i < lives; i++){
		//Renders a character life texture for every life.
		gCharLives.render(i * 26, 0);
	}
}
void checkSpikes(Player&player, int&lives,SpikeTrap&spikes, Tile* tiles[]){
	//Checks all spike hitboxes
	for (int i = 0; i < gSpikeHboxes.size(); i++){
		//If the traps are active
		if (spikes.getActiveBox()){
			//If the player and traps collide
			if (checkCollision(player.getHitbox(), gSpikeHboxes[i])){
				player.setSpawn(tiles);
				lives--;
			}
		}
	}
}


//System functions 
bool init(){
	//Initiates window and SDL systems
	bool success = true;

	//Initiates SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "Failed to initialize SDL! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else{
		//Enable linear texture filtering
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}
		
		//Creates Window
		gWindow = SDL_CreateWindow("Dungeon Adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL){
			cout << "Failed to create window! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else{
			//Creates Renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL){
				cout << "Failed to create renderer! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else{
				SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);

				//Initialize SDL image
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)){
					cout << "SDL image failed to initiate! IMG Error: " << IMG_GetError() << endl;
					success = false;
				}

				//Initialize SDL true type fonts if it exists
				#ifdef _SDL_TTF_H
				if (TTF_Init() == -1){
					cout << "SDL TTF failed to initiate! TTF Error: " << TTF_GetError() << endl;
				}
				#endif
			}
		}
	}
	return success;
}
bool loadMedia(Tile* tiles[], string path){
	//Loads media and tiles
	bool success = true;

	//Load Background image
	if (!gTitleBackground.loadFromFile("deps/titlebg2.png")){
		cout << "Failed to load title image!" << endl;
		success = false;
	}

	//Load Congrats image
	if (!gCongrats.loadFromFile("deps/win.png")){
		cout << "Failed to load congrats image!" << endl;
		success = false;
	}

	if (!gGameOver.loadFromFile("deps/lose.png")){
		cout << "Failed to load game over image!" << endl;
		success = false;
	}
	
	//Load start button sprite sheet
	if (!gStartSpriteSheet.loadFromFile("deps/start2.png")){
		cout << "Failed to load start button!" << endl;
		success = false;
	}
	else{
		for (int i = 0; i < MOUSE_SPRITE_TOTAL; i++){
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * 57;
			gSpriteClips[i].w = BUTTON_WIDTH;
			gSpriteClips[i].h = BUTTON_HEIGHT;
		}
		gStartButton.setPosition((SCREEN_WIDTH - BUTTON_WIDTH) / 2, (SCREEN_HEIGHT - BUTTON_HEIGHT + 100) / 2);
	}

	//Load quit button sprite sheet
	if (!gQuitSpriteSheet.loadFromFile("deps/quit.png")){
		cout << "Failed to load quit button!" << endl;
		success = false;
	}
	else{
		for (int i = 0; i < MOUSE_SPRITE_TOTAL; i++){
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * 57;
			gSpriteClips[i].w = BUTTON_WIDTH;
			gSpriteClips[i].h = BUTTON_HEIGHT;
		}
		gQuitButton.setPosition((SCREEN_WIDTH - BUTTON_WIDTH) / 2, (SCREEN_HEIGHT - BUTTON_HEIGHT + 250) / 2);

	}

	//Load Tiles
	if (!gDungeonTexture.loadFromFile("deps/DungeonTiles2.png")){
		cout << "Unable to load dungeon tiles!" << endl;
		success = false;
	}
	//Set tiles
	if (!setTiles(tiles, path)){
		cout << "Unable to load tiles!" << endl;
		success = false;
	}

	//Load character
	if (!gCharSpriteSheetTexture.loadFromFile("deps/Char.png")){
		cout << "Unable to load character!" << endl;
		success = false;
	}
	else{
		//Renders sprite clip dimensions
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 3; j++){
				gCharSpriteClips[i * 3 + j].x = i * 23;
				gCharSpriteClips[i * 3 + j].y = j * 26;
				gCharSpriteClips[i * 3 + j].w = 23;
				gCharSpriteClips[i * 3 + j].h = 26;
			}
		}
	}

	//Load life sprite
	if (!gCharLives.loadFromFile("deps/lives.png")){
		cout << "Unable to load life image!" << endl;
		success = false;
	}

	//Load spike trap texture
	if (!gSpikeTexture.loadFromFile("deps/spikes2.png")){
		cout << "Unable to load spike traps!" << endl;
		success = false;
	}
	else{
		//Renders spike trap clips
		for (int i = 0; i < SPIKE_ANIMATION_FRAMES; i++){
			gSpikeClips[i].x = 0;
			gSpikeClips[i].y = i * 26;
			gSpikeClips[i].w = TILE_WIDTH;
			gSpikeClips[i].h = TILE_HEIGHT;
		}
	}

	return success;
}
void close(Tile* tiles[]){
	//Closes all media and tiles

	//Deallocate tiles
	for (int i = 0; i < TOTAL_TILES; i++){
		if (tiles[i] != NULL){
			delete tiles[i];
			tiles[i] = NULL;
		}
	}
	
	//Free Textures
	//Title Textures
	gTitleBackground.free();
	gStartSpriteSheet.free();
	gQuitSpriteSheet.free();
	//Character Textures
	gCharSpriteSheetTexture.free();
	gCharLives.free();
	//Endgame Textures
	gCongrats.free();
	gGameOver.free();
	//Dungeon Textures
	gDungeonTexture.free();
	gDungeonExit.free();
	gSpikeTexture.free();

	//Destroy SDL objects
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	//Exit SDL systems
	#ifdef _SDL_TTF_H
	TTF_Quit();
	#endif
	IMG_Quit();
	SDL_Quit();
}


//Texture functions 
LTexture::LTexture(){
	mTexture = NULL; 
	mWidth = 0;
	mHeight = 0;
}
LTexture::~LTexture(){
	free();
}
bool LTexture::loadFromFile(string path){
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		cout << "Failed to load image! IMG Error: " << IMG_GetError() << endl;
	}
	else{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xff, 0xff));

		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL){
			cout << "Failed to create texture! SDL Error: " << SDL_GetError() << endl;
		}
		else{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}
#ifdef _SDL_TTF_H
bool LTexture::loadFromRenderedText(string textTexture, SDL_Color colorTexture){
	free();
	
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textTexture.c_str(), colorTexture);
	if (textSurface == NULL){
		cout << "Failed to render text surface! TTF Error: " << TTF_GetError() << endl;
	}
	else{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL){
			cout << "Failed to create texture from surface! SDL Error: " << SDL_GetError() << endl;
		}
		else{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return mTexture != NULL;
}
#endif
void LTexture::free(){
	if (mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue){
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}
void LTexture::setBlendMode(SDL_BlendMode blend){
	SDL_SetTextureBlendMode(mTexture, blend);
}
void LTexture::setAlpha(Uint8 alpha){
	SDL_SetTextureAlphaMod(mTexture, alpha);
}
void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}
int LTexture::getWidth(){
	return mWidth;
}
int LTexture::getHeight(){
	return mHeight;
}

//Button functions ====================================================
//*** Title Buttons ***
LButton::LButton(){
	//Constructor for button
	mPosition.x = 0;
	mPosition.y = 0;

	mStarted = false;
	mStopped = false;

	mCurrentSprite = MOUSE_SPRITE_OUT;
}
void LButton::setPosition(int x, int y){
	//Sets position of button
	mPosition.x = x;
	mPosition.y = y;
}
void LButton::handleStartEvents(SDL_Event* e){
	//Handles mouse events
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < mPosition.x){
			inside = false;
		}
		else if (x > mPosition.x + BUTTON_WIDTH){
			inside = false;
		}
		else if (y < mPosition.y){
			inside = false;
		}
		else if (y > mPosition.y + BUTTON_HEIGHT){
			inside = false;
		}

		if (!inside){
			mCurrentSprite = MOUSE_SPRITE_OUT;
		}
		else{
			switch (e->type){
				case SDL_MOUSEMOTION:
					mCurrentSprite = MOUSE_SPRITE_OVER;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = MOUSE_SPRITE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					//Starts game
					mCurrentSprite = MOUSE_SPRITE_UP;
					mStarted = true;
					break;
			}
		}
	}
}
void LButton::handleQuitEvents(SDL_Event* e){
	//Handles mouse events
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < mPosition.x){
			inside = false;
		}
		else if (x > mPosition.x + BUTTON_WIDTH){
			inside = false;
		}
		else if (y < mPosition.y){
			inside = false;
		}
		else if (y > mPosition.y + BUTTON_HEIGHT){
			inside = false;
		}

		if (!inside){
			mCurrentSprite = MOUSE_SPRITE_OUT;
		}
		else{
			switch (e->type){
			case SDL_MOUSEMOTION:
				mCurrentSprite = MOUSE_SPRITE_OVER;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = MOUSE_SPRITE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				//Quits game
				mCurrentSprite = MOUSE_SPRITE_UP;
				mStopped = true;
				break;
			}
		}
	}
}
void LButton::renderStart(){
	//Renders Button at location x, y, with clip[currentsprite]
	gStartSpriteSheet.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}
void LButton::renderQuit(){
	//Renders Button at location x, y, with clip[currentsprite]
	gQuitSpriteSheet.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}
bool LButton::isStarted(){
	//Checks if the start button is pressed
	return mStarted;
}
bool LButton::isStopped(){
	//Checks if the quit button is pressed
	return mStopped;
}

//*** Player functions ***
Player::Player(int x, int y){
	//Initialize the offsets
	mPosX = x;
	mPosY = y;

	//Collision box
	mBox.x = mPosX+4;
	mBox.y = mPosY+13;
	mBox.w = PLAYER_WIDTH-8;
	mBox.h = PLAYER_HEIGHT-15;

	//Initializes the velocity
	mVelX = 0;
	mVelY = 0;

	//Initialized clips
	startingClip = 3;
	minClip = 0;
	maxClip = 0;

	mStopped = false;
}
void Player::handleEvent(SDL_Event& e){
	//If a key is pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
		//Adjust the velocity
		switch (e.key.keysym.sym){
			case SDLK_w:
				mVelY -= PLAYER_VEL;
				minClip = 3;
				maxClip = 6;
				mStopped = false;
				break;
			case SDLK_s:
				mVelY += PLAYER_VEL;
				minClip = 0;
				maxClip = 3;
				mStopped = false;
				break;
			case SDLK_a:
				mVelX -= PLAYER_VEL;
				minClip = 9;
				maxClip = 12;
				mStopped = false;
				break;
			case SDLK_d:
				mVelX += PLAYER_VEL;
				minClip = 6;
				maxClip = 9;
				mStopped = false;
				break;
		}
		//Store starting clip
		startingClip = minClip;
	}
	//else the key is released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0){
		//Adjust the velocity
		switch (e.key.keysym.sym){
		case SDLK_w:
			mVelY += PLAYER_VEL;
			mStopped = true;
			break;
		case SDLK_s:
			mVelY -= PLAYER_VEL;
			mStopped = true;
			break;
		case SDLK_a:
			mVelX += PLAYER_VEL;
			mStopped = true;
			break;
		case SDLK_d:
			mVelX -= PLAYER_VEL;
			mStopped = true;
			break;
		}
		//Undoes the velocity changes
	}
}
void Player::move(Tile* tiles[]){
	//Move the dot left or right
	mPosX += mVelX;
	mBox.x = mPosX+4;
	

	//If the dot went too far to the left or right
	if ((mPosX < 0) || (mPosX + PLAYER_WIDTH > SCREEN_WIDTH) || touchesWall(mBox,tiles)){
		//Moves the dot back
		mPosX -= mVelX;
		mBox.x = mPosX+4;
	}

	//Move the dot up or down
	mPosY += mVelY;
	mBox.y = mPosY+13;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + PLAYER_HEIGHT > SCREEN_HEIGHT) || touchesWall(mBox, tiles)){
		//Move back
		mPosY -= mVelY;
		mBox.y = mPosY+13;
	
	}
}
void Player::render(){
	SDL_Rect* currentClip = NULL;
	//Checks the player movement state
	if (!mStopped){
		currentClip = &gCharSpriteClips[minClip];
		gCharSpriteSheetTexture.render(mPosX, mPosY, currentClip);
		
		minClip++;

		if (minClip >= maxClip){
			minClip = startingClip;
		}
	}
	//If the player has stopped moving
	else{
		//Sets the sprite clip to the still image
		currentClip = &gCharSpriteClips[startingClip];
		gCharSpriteSheetTexture.render(mPosX, mPosY, currentClip);
	}
	
}
void Player::setSpawn(Tile* tiles[]){
	//Searches the tiles for the starting tile
	for (int i = 0; i < TOTAL_TILES; i++){
		if (tiles[i]->getType() == TILE_START){
			//Sets the spawn to the start tile
			mPosX = tiles[i]->getBox().x;
			mPosY = tiles[i]->getBox().y;
		}
	}
}
SDL_Rect Player::getHitbox(){
	return mBox;
}

//*** Exit functions ***
Exit::Exit(){
	mPosX = 0;
	mPosY = 0;

	mBox.x = mPosX;
	mBox.y = mPosY;
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_WIDTH;
}
void Exit::loadExit(Tile* tile[], int currentTile, bool switchPressed){
	//Only loads exit if switch is pressed
	if (switchPressed){
		
		//Set position of open exit to closed exit tile
		mPosX = tile[currentTile]->getBox().x;
		mPosY = tile[currentTile]->getBox().y;

		//Adjust hitbox
		mBox.x = mPosX;
		mBox.y = mPosY;
		mBox.w = tile[currentTile]->getBox().w;
		mBox.h = tile[currentTile]->getBox().h;
	
		//Renders the opened exit
		tile[currentTile] = new Tile(mPosX, mPosY, TILE_EXITOPEN);
	}
}
SDL_Rect Exit::getHBox(){
	return mBox;
}

//*** Spike Trap Functions ***
SpikeTrap::SpikeTrap(){
	//Position of spikes
	mPosX = 0;
	mPosY = 0;

	//Spike hitbox
	mBox.x = mPosX;
	mBox.y = mPosY;
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Initally disable box
	mActiveBox = false;

	//Frame for animation
	mframe = 0;
	//Spikes initially set to down
	mSpikesUp = false;
	//Delay is set to 0
	mDelay = 0;
}
void SpikeTrap::setTrap(Tile* tiles[], int currentTile){
	//Set position of traps on trap tiles
	mPosX = tiles[currentTile]->getBox().x;
	mPosY = tiles[currentTile]->getBox().y;

	//Adjust hitbox position
	mBox.x = mPosX+3;
	mBox.y = mPosY+3;
	mBox.w = TILE_WIDTH-6;
	mBox.h = TILE_HEIGHT-6;
}
void SpikeTrap::animate(){
	SDL_Rect* currentclip = NULL;
	//Variable for frame delay
	int fDelay =64;
	

	//Renders spikes moving up or down
	if (!mSpikesUp){
		//Delay timer for spikes down
		if (mDelay > 80){
			//Decrement delay timer
			mDelay--;
			//Render spikes down
			gSpikeTexture.render(mPosX, mPosY, &gSpikeClips[0]);
		}
		else{
			//Renders the spike animation
			currentclip = &gSpikeClips[mframe / fDelay];
			gSpikeTexture.render(mPosX, mPosY, currentclip);

			//Increment to next frame
			mframe++;

			//Cycle animation
			if ((mframe / fDelay) >= SPIKE_ANIMATION_FRAMES){
				mSpikesUp = true;
				mDelay = 0;
			}
		}
	}
	else{
		//Delay timer for spikes up
		if (mDelay < 100){
			//Increment delay timer
			mDelay++;
			//Render the spikes in the up position
			gSpikeTexture.render(mPosX, mPosY, &gSpikeClips[3]);
		}
		else{
			//Renders the spike animation
			currentclip = &gSpikeClips[mframe / fDelay];
			gSpikeTexture.render(mPosX, mPosY, currentclip);

			//Decrement to next frame
			mframe--;

			//Cycle animation
			if ((mframe / fDelay) <= -1){
				//Spikes are down
				mSpikesUp = false;
			}
		}
	}

	if ((mframe / fDelay >= 2)){
		mActiveBox = true;
	}
	else{
		mActiveBox = false;
	}
}
SDL_Rect SpikeTrap::getHBox(){
	return mBox;
}
bool SpikeTrap::getActiveBox(){
	return mActiveBox;
}

//*** Tiles ***
Tile::Tile(int x, int y, int tileType){
	//Initializes position, dimensions, and tile type

	//Get the offset
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}
void Tile::render(){
		gDungeonTexture.render(mBox.x, mBox.y, &gDungeonClips[mType]);
}
int Tile::getType(){
	return mType;
}
SDL_Rect Tile::getBox(){
	return mBox;
}