#include "knapsack.h"
#include "annealing.h"

using namespace std;

int main(int argc, char* argv[]){
	KnapsackCollection collection(argv[1]);	
	cout << collection << endl;	

	return 0;
}
