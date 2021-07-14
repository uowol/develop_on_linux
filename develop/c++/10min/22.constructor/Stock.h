#include <iostream>
using namespace std;

class Stock
{
private: // 데이터 은닉: 클래스 내에서만 접근 가능
    /* data */
    string name;
    int shares;
    float share_val;
    double total_val;
    void set_total() { total_val = shares * share_val; }

public: // private 데이터에 접근 가능: 외부에서 접근 가능
    void buy(int, float);
    void sell(int, float);
    void update(float);
    void show();
    Stock(string, int, float); // 생성자
    Stock(); // 오버로딩
    ~Stock(); // 파괴자: 틸테(~)가 붙은 생성자, 매개변수를 가질 수 없음
};
