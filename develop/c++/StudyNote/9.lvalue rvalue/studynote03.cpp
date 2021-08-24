#include <iostream>

// 완벽한 전달은 오버로드된 함수의 필요성을 줄이고 전달 문제를 방지하는 데 도움이 됩니다. 
// 전달 문제는 참조를 매개 변수로 사용하는 제네릭 함수를 작성하고 이러한 매개 변수를 다른 함수에 전달 하거나 전달하는 경우에 발생할 수 있습니다.

// 제네릭 함수가 const T& 형식의 매개 변수를 사용하는 경우 호출된 함수는 해당 매개 변수의 값을 수정할 수 없습니다.
// 제네릭 함수가 T& 형식의 매개 변수를 사용하는 경우에는 rvalue(예: 임시 개체 또는 정수 리터럴)를 사용하여 해당 함수를 호출할 수 없습니다.

struct W {
   W(int&, int&) {}
};

struct X {
   X(const int&, int&) {}
};

struct Y {
   Y(int&, const int&) {}
};

struct Z {
   Z(const int&, const int&) {}
};

// lvalue 참조를 사용하기 때문에 rvalue를 사용하여 호출할 경우 오류가 발생합니다.
template <typename T, typename A1, typename A2>
T* factory(A1& a1, A2& a2){
   return new T(a1, a2);
}

// rvalue 참조를 사용하는 함수를 만들어줍니다.
template <typename T, typename A1, typename A2>
T* factory(A1&& a1, A2&& a2){
   // factory 함수의 매개변수를 템플릿 클래스의 생성자에 전달합니다. 
   std::cout << a1 + a2 << "\n";
   return new T(std::forward<A1>(a1), std::forward<A2>(a2));
}

int main(){
   int a = 4, b = 5;
   W* pw = factory<W>(a, b);
   X* px = factory<X>(2, b);
   Y* py = factory<Y>(a, 2);
   Z* pz = factory<Z>(2, 2);

   delete pw;
   delete px;
   delete py;
   delete pz;
}