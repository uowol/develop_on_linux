#include <iostream>

using namespace std;

int main(){
    // 구조체: 다른 데이터형이 허용되는 데이터의 집합
    
    struct Player{
        // 멤버
        string name;
        string position;
        float height;
        float weight;
    } B; // 위 구조체와 같은 B 라는 변수를 바로 만들 수 있음 
    
    B.name = "Son";
    B.position = "Striker";
    B.height = 183;
    B.weight = 77;

    Player A = {
        "Son",
        "Striker",
        183,
        77
    };

    cout << A.name << endl;
    cout << A.position << endl;
    cout << A.height << endl;
    cout << A.weight << endl;

    Player team1[] = {
        {"A", "A", 1, 1},
        {"B", "B", 1, 1}
    };

    cout << team1[0].weight << endl;

    
    return 0;
}