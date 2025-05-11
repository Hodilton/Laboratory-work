#include "./Adapter.h"
using namespace adapter_2;

//class Client {
//private:
//	IInterface* interface;
//
//public:
//	Client(IInterface* interface) : interface(interface) {}
//
//public:
//	void analizeData(Data& data) {
//		interface->method(data);
//	}
//};

class Client {
private:
	ExistingClass* interface;

public:
	Client(ExistingClass* interface) : interface(interface) {}

	void analyzeData(Data& data) {
		interface->method(data);
	}
};

int main() {
	/*Adapter adapter;
	Data data = "example";

	Client client(&adapter);
	client.analizeData(data);*/

	Adapter adapter;
	Data data = "example";

	Client client(&adapter);
	client.analyzeData(data);

	return 0;
}