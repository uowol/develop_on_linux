#include "Stock.h"

int main(){
	// Stock s[4]; // 디폴트 생성자에 의해 생성된 객체
	Stock s[4] = {
		Stock("A", 10, 1000),
		Stock("B", 20, 1200),
		Stock("C", 30, 1400),
		Stock("D", 40, 1600),
	};

	Stock* first = &s[0];

	for(int i=1;i<4;i++){
		first = & first->topval(s[i]); // Stock.topval(...)의 주소값 : &
	}

	cout << first;

    return 0;
}