#ifndef LINUX_GAME_Dungeon_CPP
#define LINUX_GAME_Dungeon_CPP


#include <Dungeon/Dungeon.hpp>


LinuxGame::Dungeon::Dungeon(const LinuxGame::Dungeons& dunType, const int iWidth, const int iHeight, const int iDepth, const int iNum_monster){
    std::srand((unsigned int) time(nullptr));
    this->player.x = 0;
	this->player.y = 0;
    this->type = dunType;
    this->width = iWidth;
    this->height = iHeight;
    this->depth = iDepth;
    this->monsters.resize(iNum_monster);
    this->preMonsterX.resize(iNum_monster);
    this->preMonsterY.resize(iNum_monster);
    this->preMonsterBlock.resize(iNum_monster);
    this->dungeon.resize(iHeight+2);
    for(int i = 0; i<iHeight+2; i++){
        this->dungeon[i].resize(iWidth+2);
    }
    this->init(NONE);
}

void LinuxGame::Dungeon::init(int tile){
    for(int i=0; i<this->dungeon.size(); i++){
        for(int j=0; j<this->dungeon[0].size(); j++){
            this->dungeon[i][j]=WALL;
        }
    }
    for(int i=1; i<=height; i++){
        for(int j=1; j<=width; j++){
            this->dungeon[i][j]=tile;
        }
    }
}

bool LinuxGame::Dungeon::generateDungeon(){
    try{
        switch(type){
            case Dungeons::BSP:
                BSP(1, 1, width, height, H, 0);
                break;
            case Dungeons::Celluar_Automata:
                break;
        }
    }catch(int e){
        return false;
    }
    return true;
}

std::string LinuxGame::Dungeon::getStringMap(){
    std::string output = "";
    for(int i=0; i<height+2; i++){
        for(int j=0; j<width+2; j++){
            switch(dungeon[i][j]){
                case NONE:
                    output+="0";
                    break;
                case ROOM:
                    output+=" ";
                    break;
                case CORRIDOR:
                    output+=".";
                    break;
                case WALL:
                    output+="W";
                    break;
                case LINE:
                    output+="O";
                    break;
				case PLAYER:
					output+="p";
                    break;
				case MONSTER:
					output+="m";
                    break;
            }
        }
        output+='\n';
    }
    return output;
}

LinuxGame::Edge LinuxGame::Dungeon::BSP(int x1, int y1, int x2, int y2, bool flag, int cnt){
    // ?????? ?????? ???????????? ???
    if(cnt == depth){
        int rx1 = x1 + (rand() % 2) + 2; // x1 + 1~3
        int ry1 = y1 + (rand() % 2) + 2;
        int rx2 = x2 - (rand() % 2) - 2; 
        int ry2 = y2 - (rand() % 2) - 2;
        if(rx1 >= x2) rx1 = x2-1;
        if(rx2 <= rx1) rx2 = rx1+1;
        if(ry1 >= y2) ry1 = y2-1;
        if(ry2 <= ry1) ry2 = ry1+1;
        for(int i=rx1; i<=rx2; i++){
            for(int j=ry1; j <= ry2; j++){
                this->dungeon[j][i] = ROOM;
            }
        }
        return Edge{rx1, ry1, rx2, ry2};
    }

    // +- 2 ??? ??????, 64 -> 30 -> 13 -> 4        : depth = 4i
    // +- 1 ??? ??????, 64 -> 31 -> 14 -> 6 -> 2   : depth = 5

    int tx1 = 0;
    int tx2 = 0;
    int ty1 = 0;
    int ty2 = 0;
    // ?????? ??????
    if(flag == V){
        // ?????? ??????
        int pivot = (y1+y2) / 2 + rand() % 5 - 2;
        for(int i=x1; i<=x2; i++){
            dungeon[pivot][i] = LINE;
        }
        Edge p1 = BSP(x1, y1, x2, pivot, H, cnt+1);
        Edge p2 = BSP(x1, pivot, x2, y2, H, cnt+1);

        tx1 = std::min(p1.x1, p2.x1);
        ty1 = p1.y2;
        tx2 = std::max(p1.x2, p2.x2);
        ty2 = p2.y1;

        // ?????? ??????
        int top, bottom;
        int line = 0;
        do{
            top = p1.x1 + (rand() % (p1.x2-p1.x1+1));
            bottom = p2.x1 + (rand() % (p2.x2-p2.x1+1));
        }while(dungeon[ty1][top] != ROOM || dungeon[ty2][bottom] != ROOM);

        for(int i=ty1+1;;i++){
            if(dungeon[i][top] == WALL) break;
            if(dungeon[i][top] == LINE){
                line = i; break;
            }
            dungeon[i][top] = CORRIDOR;
        }
        for(int i=ty2-1;;i--){
            if(dungeon[i][bottom] == WALL) break;
            if(dungeon[i][bottom] == LINE){
                break;
            }
            dungeon[i][bottom] = CORRIDOR;
        }
        for(int i=std::min(top, bottom); i<=std::max(top, bottom); i++)
            dungeon[line][i] = CORRIDOR;

        return Edge{tx1, p1.y1, tx2, p2.y2};
    }

    // ?????? ??????
    if(flag == H){
        // ?????? ??????
        int pivot = (x1+x2) / 2 + rand() % 5 - 2;
        for(int i=y1; i<=y2; i++){
            dungeon[i][pivot] = LINE;
        }
        Edge p1 = BSP(x1, y1, pivot, y2, V, cnt+1);
        Edge p2 = BSP(pivot, y1, x2, y2, V, cnt+1);

        tx1 = p1.x2;
        ty1 = std::min(p1.y1, p2.y1);
        tx2 = p2.x1;
        ty2 = std::max(p1.y2, p2.y2);

        // ?????? ??????
        int left, right;
        int line = 0;
        do{
            left = p1.y1 + (rand() % (p1.y2-p1.y1+1));
            right = p2.y1 + (rand() % (p2.y2-p2.y1+1));
        }while(dungeon[left][tx1] != ROOM || dungeon[right][tx2] != ROOM);

        for(int i=tx1+1;;i++){
            if(dungeon[left][i] == WALL) break;
            if(dungeon[left][i] == LINE){
                line = i; break;
            }
            dungeon[left][i] = CORRIDOR;
        }
        for(int i=tx2-1;;i--){
            if(dungeon[right][i] == WALL) break;
            if(dungeon[right][i] == LINE){
                break;
            }
            dungeon[right][i] = CORRIDOR;
        }
        for(int i=std::min(left, right); i<=std::max(left, right); i++)
            dungeon[i][line] = CORRIDOR;


        return Edge{p1.x1, ty1, p2.x2, ty2};
    }
    return Edge{tx1, ty1, tx2, ty2};
}

const std::vector<std::vector<int>> & LinuxGame::Dungeon::getDungeon() const{ // ?????? ???????????? ?????? ??????????????? const??? ?????? ????????? ????????? ??? ??????.
    return dungeon;
}

bool LinuxGame::Dungeon::setPlayer(const int& x, const int& y){
    if(dungeon[y][x]!=ROOM && dungeon[y][x]!=CORRIDOR) return false; // ????????? ?????? ???????????? ??????????????? ??? ??? ??????
    if(player.y*player.x != 0){ // ????????? ???????????? ??????
        preX = player.x;
        preY = player.y;
        dungeon[preY][preX] = preBlock;
    }else{ // ???????????? ??????
        preX = x;
        preY = y;
        preBlock = ROOM;
    }
    player.x = x;
    player.y = y;

    preBlock = dungeon[player.y][player.x];
    dungeon[player.y][player.x] = PLAYER;
    return true;
}

bool LinuxGame::Dungeon::movePlayer(const int& dx, const int& dy){
    // ?????? ?????? ???????????? ???????????? ?????? false??? ??????
	if(player.x+dx <1 ||player.y+dy <1 || player.x+dx >= width - 1 || player.y+dy >= height - 1) return false;

    // ????????? ?????? ???????????? ???????????? ?????? false??? ??????, ????????? ?????? ?????? ???????????? ???????????? true ??????
    return setPlayer(player.x+dx, player.y+dy); 
}

LinuxGame::Point LinuxGame::Dungeon::getPlayerPosition() const{
    return player;
}

bool LinuxGame::Dungeon::setMonster(const int& idx, const int& x, const int& y){
    if(dungeon[y][x]!=ROOM && dungeon[y][x]!=CORRIDOR) return false; // ????????? ?????? ???????????? ??????????????? ??? ??? ??????
    if(monsters[idx].y*monsters[idx].x != 0){ // ????????? ???????????? ??????
        preMonsterX[idx] = monsters[idx].x;
        preMonsterY[idx] = monsters[idx].y;
        dungeon[preMonsterY[idx]][preMonsterX[idx]] = preMonsterBlock[idx];
    }else{ // ???????????? ??????
        preMonsterX[idx] = x;
        preMonsterY[idx] = y;
        preMonsterBlock[idx] = ROOM;
    }
    monsters[idx].x = x;
    monsters[idx].y = y;

    preMonsterBlock[idx] = dungeon[monsters[idx].y][monsters[idx].x];
    dungeon[monsters[idx].y][monsters[idx].x] = MONSTER;
    return true;
}

bool LinuxGame::Dungeon::moveMonster(const int& idx, const int& dx, const int& dy){
    // ?????? ?????? ???????????? ???????????? ?????? false??? ??????
	if(monsters[idx].x+dx <1 ||monsters[idx].y+dy <1 || monsters[idx].x+dx >= width - 1 || monsters[idx].y+dy >= height - 1) return false;

    // ????????? ?????? ???????????? ???????????? ?????? false??? ??????, ????????? ?????? ?????? ???????????? ???????????? true ??????
    return setMonster(idx, monsters[idx].x+dx, monsters[idx].y+dy); 

}

std::vector<LinuxGame::Point> LinuxGame::Dungeon::getMonsterPositions() const{
    // std::vector<Point> vMonster;
    // vMonster.resize(this->monsters.size());
    // for(int i=0; i<monsters.size(); i++){
    //     vMonster[i] = {monsters[i].x, monsters[i].y};
    // }
    return monsters;
}

#endif