/*
 * print_ts.cpp
 *
 * Created on: Nov 5, 2020
 * 		Author: Adam Stillabower
 */

#include <mutex>
#include <iostream>
#include "print_ts.h"

using namespace std;

mutex mTx;

//create threadsafe implementations of the following functions
//example
//string s1 = "t";
//string s2 = "s";
//PRINT2(s1,s2);
//PRINT3(s1,s2,s1);
//should output
//ts
//tst
void PRINT1(std::string &txt) {
	lock_guard<std::mutex> lock(mTx);
	cout << txt << endl;
}
void PRINT2(std::string &txt, std::string &txt1) {
	lock_guard<std::mutex> lock(mTx);
	cout << txt << txt1 << endl;
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	lock_guard<std::mutex> lock(mTx);
	cout << txt << txt1 << txt2 << endl;
}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
	lock_guard<std::mutex> lock(mTx);
	cout << txt << txt1 << txt2 << txt3 << endl;
}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
	lock_guard<std::mutex> lock(mTx);
	cout << txt << txt1 << txt2 << txt3 << txt4 << endl;
}


