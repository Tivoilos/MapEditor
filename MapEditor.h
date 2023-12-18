#pragma once
#include "Init.h"
#include "Events.h"
#include <vector>
#include "Camera.h"
#include <string>
class MapEditor
{
public:

	//Constructor and Deconstructor may not be used or nessicary but will add them
	MapEditor();
	~MapEditor();
	struct Tile {
		SDL_Texture* texture;
		int ID;
		int width;
		int height;
	};


	//Map struct
	struct Map
	{
		std::string MapName; //name of map
		int MapID; //map ID
		int Map_Height; //Map height
		int Map_Width; //Map Width
		int Rev_num; //Revision number (might be used might not be used for client updates)

		//Layers ground, wall, object, spec(blocks, warps, doors chest etc.)
		std::vector<std::vector<int>> GroundLayer; 
		std::vector<std::vector<int>> WallLayer;
		std::vector<std::vector<int>> ObjectLayer;
		std::vector<std::vector<int>> Spec;

		//Lighting for day night etc
		struct Lighting
		{
			int r;
			int g;
			int b;
			int a;
		};

		//clickable signs 
		struct Signs
		{
			std::string SignText; //what the sign says
			int SignID; //ID of the sign that will go into spec
			int x; //location of the sign in X coords
			int y; //location of the sign in y coords
		};

		struct Chest
		{
			int ChestID;
			int Keyed; //0 = no Key after that Key ID would be needed
			std::vector<std::vector<int>> ItemID; //what item is being spawned
		};
	};

	//constants
	static const int TILE_WIDTH = 64;
	static const int TILE_HEIGHT = 32;
	static const int NUM_TILE_TYPES = 7;
	static const int NUM_OBJECT_TYPES = 3;
	static const int NUM_WALL_TYPES = 2;
	static const int NUM_WALL2_TYPES = 2;

	
	
	SDL_Texture* loadTexture(const std::string& path);



	bool LoadTiles(Init& init);
	void PrintLoadedTiles() const;

	const std::vector<Tile>& getGroundTileTextures() const {
		return groundTileTextures;
	}

	const std::vector<Tile>& getWallTextures() const {
		return wallTextures;
	}

	const std::vector<Tile>& getObjectTextures() const {
		return objectTextures;
	}


	std::vector<Tile> groundTileTextures;
	std::vector<Tile> wallTextures;
	std::vector<Tile> objectTextures;

	SDL_Texture* LoadTileTexture(Init& init, const std::string& path, int ID, int width, int height);
};