#include <iostream>
#include <string>
using namespace std;

class Tv {
	int size;
public:
	Tv() { size = 20; }
	Tv(int size) { this->size = size; }
	int getSize() 
	{ return size;}
};

class WideTv : public Tv {//Tv를 상속받는 WideTv
	bool videoln;
public:
	WideTv(int size, bool videoln) : Tv(size) {
		this->videoln = videoln;
	}
	bool getVideoln() { return videoln; }
};

class SmartTv : public WideTv {//WideTv를 상속받는 SmartTv
	string ipAddr;//인터넷 주소
public:
	SmartTv(string ipAddr, int size) : WideTv(size, true) {
		this->ipAddr = ipAddr;
	}
	string getlpAddr() { return ipAddr; }
};

int main() {
	SmartTv htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoln=" << boolalpha << htv.getVideoln() << endl;
	cout << "IP=" << htv.getlpAddr() << endl;
}
