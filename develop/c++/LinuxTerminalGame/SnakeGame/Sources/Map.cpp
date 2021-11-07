#ifndef MAP_CPP
#define MAP_CPP

#include <Map.hpp>

namespace LinuxGame{
    char getTile(int tile){
        if(tile == TILE_NONE){
            return ' ';
        }else if(tile == TILE_SNAKE){
            return 'a';
        }else if(tile == TILE_WALL){
            return 'w';
        }
        return ' ';
    }

    Map::Map(int width = 5, int height = 5){
        this->width = width;
        this->height = height;
    }
    const int& Map::getWidth() const{
        return this->width;
    }
    const int& Map::getHeight() const{
        return this->height;
    }
}

#endif