#pragma once

#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"

// Text alignment type
enum ALIGNMENT_types{
    LEFT_text,
    MIDLE_text,
    RIGHT_text
};

// Function of creating font with need height
TTF_Font* createFont(int size);

// Static text on screen with drawing functions
class staticText
{
private:
    TTF_Font* Font;
    SDL_Surface *Surface;
    SDL_Texture *Texture;
    SDL_Rect Rect;
public:
    void clear();
    void set(std::string text, int size, ALIGNMENT_types alignment, int x, int y, SDL_Color color = {255, 255, 255});
    void draw();
};

// Class of drawing dinamic text at screen
class dinamicText
{
private:
    TTF_Font* Font;
    SDL_Surface *Surface;
    SDL_Texture *Texture;
    SDL_Rect Rect;
    int X;
public:
    dinamicText(int size, int x, int y);
    void clear();
    void draw(std::string text, const ALIGNMENT_types alignment, SDL_Color color = {255, 255, 255});
};

// Class of HUD slider for better choosen parameters
class Slider{
private:
    SDL_Texture *textureLine;
    SDL_Texture *textureButton;
    SDL_Rect destLine;
    SDL_Rect destButton;
public:
    Slider(int y);
    void blit(Uint8 state);
    bool in(int x, int y);
    int getX();
};

class Button
{
private:
    SDL_Texture *texture;
    SDL_Rect dest;
public:
    Button(int x, int y, IMG_names textureIndex);
    void blit();
    bool in(int x, int y);
};

class Animation
{
private:
    Uint8 type;
    SDL_Texture* texture;
    Uint32 frame;
    Uint64 prevTick;
    SDL_Rect dest;
public:
    Animation( SDL_Rect destination, ANI_names newType );
    void blit();
    void clear();
};

class Bar
{
private:
    SDL_Rect Back_rect;
    SDL_Rect Front_rect;
    SDL_Rect IconeRect;
    SDL_Texture* IconeTexture;
    SDL_Color color;
public:
    Bar( const SDL_Rect dest, SDL_Color newColor, IMG_names icone );
    void blit( int width );
};
