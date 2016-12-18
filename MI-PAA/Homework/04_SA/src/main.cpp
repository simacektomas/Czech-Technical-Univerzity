#include "knapsack.h"

using namespace std;

int main(int argc, char* argv[]){
	srand(time(NULL));
	KnapsackCollection collection(argv[1]);	
	collection.solveAnnealing(std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4]), std::stoi(argv[5]));

	return 0;
}
