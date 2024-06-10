#include <cstdlib>
#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#define STORAGE_MIN 10
#define STORAGE_MAX 20

using namespace std;

int storage = STORAGE_MIN;

mutex globalMutex;
condition_variable condition;

void consumer() {
	cout << "[CONSUMER] thread started" << endl;
	int toConsume = 0;
	while(true) {
		unique_lock <mutex> lock(globalMutex);
		if (storage < STORAGE_MAX) {
			condition.wait(lock);
			toConsume = storage - STORAGE_MIN;
			cout << "[CONSUMER] storage is maximum, consuming " << toConsume << endl;
		}
		storage -= toConsume;
		cout << "[CONSUMER] storage = " << storage << endl;
	}
}

void producer() {
	cout << "[PRODUCER] thread started" << endl;
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(200));
		unique_lock <mutex> lock(globalMutex);
		++storage;
		cout << "[PRODUCER] storage = " <<  storage << endl;
		if (storage >= STORAGE_MAX) {
			cout << "[PRODUCER] storage maximum" << endl;
			condition.notify_one();
		}
	}
}

int main(int argc, char ** argv) {
	thread thProducer(producer);
	thread thConsumer(consumer);
	thProducer.join();
	thConsumer.join();
	return 0;
}
