#include "Renderer.h"


void Renderer::renderer(Init& init) {
    // Create an instance of MapEditor
    MapEditor editor;

    // Load tiles
    if (!editor.LoadTiles(init)) {
        std::cerr << "Failed to load tiles!" << std::endl;
        return;
    }

    SDL_RenderClear(init.gRenderer);

    // Update screen dimensions
    init.SCREEN_HEIGHT = SDL_GetWindowSurface(init.window)->w;
    init.SCREEN_WIDTH = SDL_GetWindowSurface(init.window)->h;

    // Set background color
    SDL_SetRenderDrawColor(init.gRenderer, 0, 22, 15, 244);

    // Render the background color
    SDL_RenderClear(init.gRenderer);

    // Get the loaded textures from the MapEditor
    const std::vector<MapEditor::Tile>& groundTileTextures = editor.getGroundTileTextures();
    const std::vector<MapEditor::Tile>& wallTextures = editor.getWallTextures();
    const std::vector<MapEditor::Tile>& objectTextures = editor.getObjectTextures();

    // Render the ground textures
    for (const auto& tile : groundTileTextures) {
        SDL_Rect destRect = { /* Set your destination coordinates here */ };
        SDL_RenderCopy(init.gRenderer, tile.texture, nullptr, &destRect);
    }

    // Render the wall textures
    for (const auto& tile : wallTextures) {
        SDL_Rect destRect = { /* Set your destination coordinates here */ };
        SDL_RenderCopy(init.gRenderer, tile.texture, nullptr, &destRect);
    }

    // Render the object textures
    for (const auto& tile : objectTextures) {
        SDL_Rect destRect = { /* Set your destination coordinates here */ };
        SDL_RenderCopy(init.gRenderer, tile.texture, nullptr, &destRect);
    }

    // Present the renderer
    SDL_RenderPresent(init.gRenderer);
}

void Renderer::cleanup(Init& init)
{
    SDL_Quit();
    SDL_DestroyWindow(init.window);
    SDL_DestroyRenderer(init.gRenderer);
    

}