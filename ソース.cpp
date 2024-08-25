#include <iostream>
#include <chrono>
#include <thread>

class StopWatch {
protected:
	typedef std::chrono::steady_clock Clock;
	//typedef std::chrono::system_clock Clock;
	Clock::time_point S = Clock::now();
	Clock::time_point E = S;
public:

	bool Start() {
		S = Clock::now();
		E = S;
		return true;
	}
	bool Stop() {
		E = Clock::now();
		return true;
	}
	template<class T = std::chrono::milliseconds>
	T Result() {//stop(); first
		return std::chrono::duration_cast<T>(E - S);
	}
	template<class T = std::chrono::milliseconds>
	T Elapsed() {
		return std::chrono::duration_cast<T>(Clock::now() - S);
	}
};

bool Sleep(std::chrono::nanoseconds In) {
	std::this_thread::sleep_for(In);
	return true;
}

int main() {
	StopWatch SW;

	SW.Start();

	Sleep(std::chrono::milliseconds(1000));

	std::cout << SW.Elapsed().count()<<"ms" << std::endl;

	return 0;

}