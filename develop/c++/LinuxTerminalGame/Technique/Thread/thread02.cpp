#include <iostream>
#include <thread>

using namespace std;

int main()
{
	std::thread t1 = std::thread([] {
	    cout << std::this_thread::get_id() << '\n';
        while(true);
	});

	std::thread t2 = std::thread([] {
		cout << std::this_thread::get_id() << '\n';
        while(true);
	});

	std::thread t3 = std::thread([] {
		cout << std::this_thread::get_id() << '\n';
        while(true);
	});

	std::thread t4 = std::thread([] {
		cout << std::this_thread::get_id() << '\n';
        while(true);
	});

	t1.join();  // error
	//t2.join();
	//t3.join();
	//t4.join();
}