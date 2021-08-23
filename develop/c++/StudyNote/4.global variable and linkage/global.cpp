int g_x;            // external linkage by default 
extern int g_y = 2; // external linkage by default, so this extern is redundant and ignored


static int add(int x, int y) { return x + y; }  // external linkage by default,

// 함수 전방 선언에는 extern 키워드가 필요하지 않다. 컴파일러는 함수 몸체인지 함수 원형인지 알아서 판단한다.
// 출처: https://boycoding.tistory.com/167?category=1007833 [소년코딩]