
//libraries
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
//headers
#include "texture.h"
#include "globals.h"


/******* TEXTURE CLASS DEFS *******/

//constructor
Texture::Texture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

//load image texture
void Texture::load_image(std::string path)
{
    //load image into surface
    SDL_Surface* surface = IMG_Load( path.c_str() );
    
    //error check
    if (surface == NULL)
        printf( "Couldn't load text surface.  Error: %s\n", IMG_GetError() );
    else
    {
        //make pacman spritesheet black background pixels transparent
        SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB(surface->format, 3, 3, 3) );
        
        //create texture from surface
        texture = SDL_CreateTextureFromSurface( renderer, surface);
        
        //error check
        if ( texture == NULL )
            printf( "Couldn't create texture from surface. Error: %s\n", IMG_GetError() );
        
        else
        {
            //grab dimensions from surface
            width = surface->w;
            height = surface->h;
        }
    }
    
    //free unneeded surface
    SDL_FreeSurface(surface);
}

//load text texture
void Texture::load_text(TTF_Font* font, SDL_Color color, std::string text)
{
    //load text into a surface
    SDL_Surface* surface = TTF_RenderText_Solid( font, text.c_str(), color );
    
    //error check
    if (surface == NULL)
        printf( "Couldn't load text surface. Error: %s\n", TTF_GetError() );
    
    else
    {
        //create texture from surface
        texture = SDL_CreateTextureFromSurface( renderer, surface );
        
        //error check
        if ( texture == NULL )
            printf( "Couldn't create texture out of surface. Error: %s\n", SDL_GetError() );
        
        else
        {
            //grab dimensions from surface
            width = surface->w;
            height = surface->h;
        }
    }
    
    //free unneeded surface
    SDL_FreeSurface( surface );
}

//render texture or texture clip to window
void Texture::render(int x, int y, SDL_Rect* clip, int centered, double scale, double rotation, SDL_Point* center, SDL_RendererFlip flip_type)
{
    //render target
    SDL_Rect render_rect;
    
    //if texture to be rendered with x, y as midpoint
    if (centered == CENTERED)
        render_rect = { x - width/2, y - height/2, width, height };
    
    //if texture to be rendered with x,y as top left point
    else if (centered == NOT_CENTERED)
        render_rect = { x, y, width, height };

    //if clipping, adjust render rectangle
    if (clip != NULL)
    {
        //if texture to be rendered with x, y as midpoint
        if (centered == CENTERED)
        {
            render_rect = { x - clip->w/2, y - clip->h/2};
            render_rect.w = clip->w*scale;
            render_rect.h = clip->h*scale;
        }
    
        //if texture to be rendered with x,y as top left point
        else if (centered == NOT_CENTERED)
        {
            render_rect = { x, y};
            render_rect.w = clip->w*scale;
            render_rect.h = clip->h*scale;
        }
    }
    
    //render full texture or texture clip
    SDL_RenderCopyEx( renderer, texture, clip, &render_rect, rotation, center, flip_type);
}

//free texture
Texture::~Texture()
{
    //if there is a texture
    if (texture != NULL)
    {
        //free texture
        SDL_DestroyTexture(texture);
        width = 0;
        height = 0;
    }
}
