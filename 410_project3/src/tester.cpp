/*
 * tester.cpp
 *
 * Created on: Nov 5, 2020
 * 		Author Adam Stillabower
 */
#include <mutex>
#include <string>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>
#include <iostream>
#include "tester.h"
#include "print_ts.h"

using namespace std;

std::string CANCEL = "USER_CHOSE_TO_CANCEL";
bool bDoWork = true;
std::vector<std::thread> threads;

/*
 * Helper method for startThreads
 *
 */
void printer(std::string s, WHICH_PRINT wp, int times, int msDelay) {
	switch (wp) {
	case P1:
		for (int i = 0; i < times; i++) {
			if(bDoWork) {
				PRINT1(s);
				this_thread::sleep_for(chrono::milliseconds(msDelay));
			} else {
				PRINT1(CANCEL);
				this_thread::sleep_for(chrono::milliseconds(msDelay));
				break;
			}
		}
		break;
	case P2:
		for (int i = 0; i < times; i++) {
					if(bDoWork) {
						PRINT2(s, s);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
					} else {
						PRINT1(CANCEL);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
						break;
					}
				}
		break;
	case P3:
		for (int i = 0; i < times; i++) {
					if(bDoWork) {
						PRINT3(s, s, s);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
					} else {
						PRINT1(CANCEL);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
						break;
					}
				}
		break;
	case P4:
		for (int i = 0; i < times; i++) {
					if(bDoWork) {
						PRINT4(s, s, s, s);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
					} else {
						PRINT1(CANCEL);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
						break;
					}
				}
		break;
	case P5:
		for (int i = 0; i < times; i++) {
					if(bDoWork) {
						PRINT5(s, s, s, s, s);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
					} else {
						PRINT1(CANCEL);
						this_thread::sleep_for(chrono::milliseconds(msDelay));
						break;
					}
				}
		break;
	}
}
/*
 * starts cancelable threads (this means that each thread periodicaly checks to see if it should stop)
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	for (int i = 0; i < numThreads; i++) {
		threads.push_back(std::thread(printer, s, wp, numTimesToPrint, millisecond_delay));
	}
}


/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads.  The body of this function should contain 1 line
 * of code.
 */
void setCancelThreads(bool bCancel) {
	bDoWork = !bCancel;

}

/*
 * waits for all threads to complete.  If you store references to your threads in a vector
 * remember to clear that vector after joining its threads.  Otherwise if you call this
 * function twice your application will crash.
 */
void joinThreads() {
	for(auto& t: threads) {
		t.join();
	}
	threads.clear();
	cout << "All threads complete" << endl;

}
