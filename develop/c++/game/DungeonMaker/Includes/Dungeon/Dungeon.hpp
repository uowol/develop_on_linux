#ifndef LINUX_GAME_Dungeon_HPP
#define LINUX_GAME_Dungeon_HPP


#include <iostream>
#include <fstream> // ofstream
#include <vector>
#define H true  // 가로분할
#define V false // 세로분할

#define NONE     0
#define ROOM     1
#define CORRIDOR 2
#define WALL     3
#define LINE     4


namespace LinuxGame{
    typedef struct EDGE{ // typedef로 struct 키워드 없이 구조체 선언하기
        int x1;
        int y1;
        int x2;
        int y2;
    } Edge; // 구조체 별칭

    enum class Dungeons{
        BSP,
        Celluar_Automata
    };

    class Dungeon{
        private:
            int depth, width, height;
            Dungeons type;
            std::vector<std::vector<int>> dungeon;
            void init(int);
        public:
            Dungeon(const Dungeons&, const int, const int, const int);
            int getHeight(){return this->height;}
            int getWidth(){return this->width;}
            int getDepth(){return this->depth;}
            
            bool generateDungeon();
            std::string getStringMap();

            Edge BSP(int, int, int, int, bool, int);

    };
}

#endif