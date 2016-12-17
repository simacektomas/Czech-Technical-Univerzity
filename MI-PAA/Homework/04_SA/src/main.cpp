#include "knapsack.h"

using namespace std;

int main(int argc, char* argv[]){
	srand(time(NULL));
	KnapsackCollection collection(argv[1]);	
	collection.solveAnnealing();

	return 0;
}
