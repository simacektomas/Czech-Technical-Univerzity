#include <iostream>
#include "satannealing.h"

using namespace std;

int main (int argc, char** argv){
	srand(time(NULL));	

	SatInstance sinstance(argv[1]);	

	

	State * state = sinstance.solveAnnealing(stod(argv[2]),stod(argv[3]),stod(argv[4]),stod(argv[5]));
	cout << *state << endl;

	return 0;
}
