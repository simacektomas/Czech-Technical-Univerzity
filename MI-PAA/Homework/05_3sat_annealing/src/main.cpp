#include <iostream>
#include "satannealing.h"

using namespace std;

int main (int argc, char** argv){
	srand(time(NULL));	

	SatInstance sinstance(argv[1]);	


	int i = 0;	
	double avgrTime = 0;
	for (int y = 0; y < 100; y++) {
		State * state = sinstance.solveAnnealing(stod(argv[2]),stod(argv[3]),stod(argv[4]),0);	
		//cout << *state << endl;		
		avgrTime += (double)sinstance.getTime();
		i++;						
	}		
	avgrTime/=(double)i;
	cout << avgrTime << endl;
	return 0;
}
