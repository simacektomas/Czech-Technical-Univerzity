#include <iostream>
#include "satannealing.h"

using namespace std;

int main (int argc, char** argv){
	srand(time(NULL));	

	SatInstance sinstance(argv[1]);	


	int i = 0;
	bool flag = 0;
	for (int y = 0; y < 5; y++) {
		State * state = sinstance.solveAnnealing(stod(argv[2]),stod(argv[3]),stod(argv[4]),stod(argv[5]));	
		cout << *state << endl;
			if (state->solution()){
				flag = 1;
				break;
			}	
		//cout << ((SatState*)state)->getUnfulfiled() << endl;
		i++;
	}	
	if (flag) return 1;
	return 0;
}
