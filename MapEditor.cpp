#include "MapEditor.h"

MapEditor::MapEditor()
{

}

MapEditor::~MapEditor()
{

}

bool MapEditor::LoadTiles(Init& init) {
    groundTileTextures.clear();
    wallTextures.clear();
    objectTextures.clear();

    // Load ground tiles
    for (int i = 0; i < 7; ++i) {
        groundTileTextures.push_back({ LoadTileTexture(init, "Assets/Tiles/" + std::to_string(i) + ".png", i, 64, 32), i, 64, 32 });
    }

    // Load wall tiles
    for (int i = 0; i < 2; ++i) {
        wallTextures.push_back({ LoadTileTexture(init, "Assets/Walls/" + std::to_string(i) + ".png", i, 64, 32), i, 64, 32 });
    }

    // Load object tiles
    for (int i = 0; i < 3; ++i) {
        objectTextures.push_back({ LoadTileTexture(init, "Assets/Objects/" + std::to_string(i) + ".png", i, 64, 32), i, 64, 32 });
    }

    return true;
}

SDL_Texture* MapEditor::LoadTileTexture(Init& init, const std::string& path, int ID, int width, int height) {
    SDL_Surface* tileSurface = IMG_Load(path.c_str());

    if (tileSurface == nullptr) {
        std::cerr << "Failed to load tile image " << ID << "! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* tileTexture = SDL_CreateTextureFromSurface(init.gRenderer, tileSurface);
    SDL_FreeSurface(tileSurface);

    if (tileTexture == nullptr) {
        std::cerr << "Failed to create texture for tile image " << ID << "! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return tileTexture;
}

void MapEditor::PrintLoadedTiles() const {
    std::cout << "Ground Tiles:" << std::endl;
    for (const auto& tile : groundTileTextures) {
        std::cout << "ID: " << tile.ID << ", Width: " << tile.width << ", Height: " << tile.height << std::endl;
    }

    std::cout << "Wall Tiles:" << std::endl;
    for (const auto& tile : wallTextures) {
        std::cout << "ID: " << tile.ID << ", Width: " << tile.width << ", Height: " << tile.height << std::endl;
    }

    std::cout << "Object Tiles:" << std::endl;
    for (const auto& tile : objectTextures) {
        std::cout << "ID: " << tile.ID << ", Width: " << tile.width << ", Height: " << tile.height << std::endl;
    }
}