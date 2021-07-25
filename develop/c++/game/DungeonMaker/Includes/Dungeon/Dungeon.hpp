#ifndef LINUX_GAME_Dungeon_HPP
#define LINUX_GAME_Dungeon_HPP


#include <iostream>
#include <fstream> // ofstream
#include <vector>
#define H true  // 가로분할
#define V false // 세로분할

#define NONE            0
#define ROOM            1
#define CORRIDOR        2
#define WALL            3
#define LINE            4
#define PRE_ROOM        5
#define PRE_CORRIDOR    6
#define PLAYER          7
#define MONSTER         8


namespace LinuxGame{
    typedef struct EDGE{ // typedef로 struct 키워드 없이 구조체 선언하기
        int x1;
        int y1;
        int x2;
        int y2;
    } Edge; // 구조체 별칭

    typedef struct POINT{
		int x;
		int y;
	} Point;

    enum class Dungeons{
        BSP,
        Celluar_Automata
    };

    class Dungeon{
        private:
            int depth, width, height;
            int preX, preY, preBlock;
            std::vector<int> preMonsterX, preMonsterY, preMonsterBlock;
            std::vector<POINT> monsters = {};
            POINT player = {};
            Dungeons type;
            std::vector<std::vector<int>> dungeon;
            void init(int);
        public:
            Dungeon(const Dungeons&, const int, const int, const int, const int);
            int getHeight(){return this->height;}
            int getWidth(){return this->width;}
            int getDepth(){return this->depth;}
            const std::vector<std::vector<int>> & getDungeon() const;
            bool generateDungeon();
            std::string getStringMap();

            Edge BSP(int, int, int, int, bool, int);

            int& operator()(const int& x, const int& y){ return this->dungeon[y][x]; }
            const int& operator()(const int& x, const int& y) const { return this->dungeon[y][x]; }

            bool setPlayer(const int& x, const int& y);
            bool movePlayer(const int& dx, const int& dy);
            Point getPlayerPosition() const;

            bool setMonster(const int& idx, const int& x, const int& y);
            bool moveMonster(const int& idx, const int& dx, const int& dy);
            std::vector<Point> getMonsterPositions() const;
    };
}

#endif