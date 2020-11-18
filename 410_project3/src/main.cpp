#include "tester.h"
#include "print_ts.h"

using namespace std;



int main() {
	string a = " hello ";
	string b = " there ";
	int numThrd = 2;
	int timestoPrnt = 2;
	int millSecDely = 200000;

	startThreads(a, numThrd, P2, timestoPrnt, millSecDely);
	startThreads(b, numThrd, P2, timestoPrnt, millSecDely);
	setCancelThreads(true);
	joinThreads();
	return 0;
 }
