#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;
/*----------------------------------------------------------------------------------------------------------*/
struct KnapsackSolution {
	KnapsackSolution();
	int m_totalPrice;
	int m_totalWeight;
	int m_count;
	bool * m_solution;
	bool m_ref;
};
/*----------------------------------------------------------------------------------------------------------*/
struct KnapsackItem {
	public:
		KnapsackItem();
		KnapsackItem( int weight, int price )
		:m_weight(weight), m_price(price), m_ratio(double(price)/double(weight)){};
		void print(){ cout << m_weight << ":" << m_price << ":" << m_ratio;}; 

		int m_weight;
		int m_price;
		double m_ratio; 
};
/*----------------------------------------------------------------------------------------------------------*/
class KnapsackProblem {
	public:
		KnapsackProblem( string instance );
		~KnapsackProblem(){
			for ( int i = 0; i < m_count; ++i ){
				delete m_items[i];
			}
			delete [] m_items;

		};
		void bruteForce( int depth, bool * permutation );
		KnapsackSolution solveBruteForce();

		KnapsackSolution solveHeuristic();
	private:
		int m_id;
		int m_count;
		int m_knapsack;
		KnapsackItem ** m_items;
		int m_maxPrice;
		int m_maxWeight;

};
/*----------------------------------------------------------------------------------------------------------*/
KnapsackProblem::KnapsackProblem( string instance ){
	
	istringstream iss( instance );
	string token;
	// Get instance ID
	iss >> token;
	m_id = std::stoi( token );
	iss >> token;
	m_count = std::stoi( token );
	iss >> token;
	m_knapsack = std::stoi( token );	

	m_items = new KnapsackItem*[m_count];
	string price, weight;

	for ( int i = 0; i < m_count; ++i ){
		iss >> weight;
		iss >> price;
		m_items[i] = new KnapsackItem( std::stoi(weight), std::stoi(price) );
	}
	m_maxPrice = 0;
	m_maxWeight = 0;
}
/*----------------------------------------------------------------------------------------------------------*/
void KnapsackProblem::bruteForce( int depth, bool * permutation ){
	// permutation is completed
	if ( depth >= m_count ){
		int price = 0;
		int weight = 0;
		for ( int i = 0; i < m_count; i++ ){
			if ( permutation[i] ){
				price += m_items[i]->m_price;
				weight += m_items[i]->m_weight;
			}
		}
		
		if ( price > m_maxPrice && weight <= m_knapsack ){
			
			m_maxPrice = price;
			m_maxWeight = weight;
		}
		return;
	}
//	cout << depth << endl;
	permutation[depth] = true;
	bruteForce( depth+1, permutation ); 

	permutation[depth] = false;
	bruteForce( depth+1, permutation );

}
/*----------------------------------------------------------------------------------------------------------*/
KnapsackSolution KnapsackProblem::solveBruteForce(){
	int depth = 0;
	bool * permutation = new bool[m_count];
	auto start = std::chrono::high_resolution_clock::now();
	// 1_0_0_0*	
	permutation[depth] = true;
	bruteForce( depth+1, permutation );
	// 0_0_0_0*
	permutation[depth] = false;
	bruteForce( depth+1, permutation );
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> CpuTime = end-start;
	
	cout << "BRUTEFORCE" << endl;
	cout << "weight: " << m_maxWeight << " price:" << m_maxPrice << " time: " << CpuTime.count() << endl;
	delete [] permutation;
}
/*----------------------------------------------------------------------------------------------------------*/
int heuristicCompare( const void * a, const void * b ){
	const KnapsackItem * item1 = *(const KnapsackItem **) a;
	const KnapsackItem * item2 = *(const KnapsackItem **) b;

	return ( item2->m_ratio - item1->m_ratio );
}
/*----------------------------------------------------------------------------------------------------------*/
KnapsackSolution KnapsackProblem::solveHeuristic(){

	KnapsackItem ** heuristic = new KnapsackItem*[m_count];
	for ( int i = 0; i < m_count; ++i ) heuristic[i] = m_items[i];
	//Sort the array by the heuristic ratio
	qsort( heuristic, m_count, sizeof(KnapsackItem*), heuristicCompare );

	int currentWeight = 0;
	int overallPrice = 0;
	// Prepare array for heuristic solution
	// bool * solution = new bool[m_count];

	for ( int i = 0; i < m_count ; i++ ){
		int itemWeight = heuristic[i]->m_weight; 
		int itemPrice = heuristic[i]->m_price;
		if ( currentWeight + itemWeight > m_knapsack ) break; 
		currentWeight += itemWeight;
		overallPrice += itemPrice;
	}
	cout << "id: " << m_id << " knapsack: " << m_knapsack << endl << "HEURISTIC" << endl << "weight: " << currentWeight << " price: " << overallPrice << endl;

	delete [] heuristic;

}
/*----------------------------------------------------------------------------------------------------------*/
int main ( int args, char ** argv ){
	
	if ( args != 2 ) return 1;
	
	ifstream dataFile ( argv[1] );
	string instance;
	if ( dataFile.is_open() ){

		while ( getline( dataFile, instance ) ){
			
			KnapsackProblem knapsackInstance( instance );	
			knapsackInstance.solveHeuristic();
			knapsackInstance.solveBruteForce();
		}

		dataFile.close();
	}
	else cout << "Unable to open file" << endl;

	return 0;
}
