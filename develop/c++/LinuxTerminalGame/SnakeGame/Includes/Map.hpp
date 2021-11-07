#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#define TILE_NONE   0
#define TILE_SNAKE  1
#define TILE_WALL   2

namespace LinuxGame{
    
    char getTile(int tile);

    class Map{
        private:
            int width;
            int height;
        public:
            Map(int width, int height);
            const int& getWidth() const;
            const int& getHeight() const;

    };

}

#endif