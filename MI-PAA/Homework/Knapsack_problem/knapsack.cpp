#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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


class KnapsackProblem {
	public:
		KnapsackProblem( string instance );
		~KnapsackProblem(){
			for ( int i = 0; i < m_count; ++i ){
				delete m_items[i];
			}
			delete [] m_items;

		};
		int solveBruteForce();
		int solveHeuristic();
		void showParameters(){
			cout << "id: " << m_id << endl;	
			cout << "count: " << m_count << endl;	
			cout << "knapsack: " << m_knapsack << endl;	
		};
	private:
		int m_id;
		int m_count;
		int m_knapsack;
		KnapsackItem ** m_items;

};

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
		m_items[i]->print();
		cout << " ";

	}
	cout << endl;
}

int KnapsackProblem::solveBruteForce(){

}

int heuristicCompare( const void * a, const void * b ){
	const KnapsackItem * item1 = *(const KnapsackItem **) a;
	const KnapsackItem * item2 = *(const KnapsackItem **) b;

	return ( item1->m_ratio - item2->m_ratio );
}

int KnapsackProblem::solveHeuristic(){

	KnapsackItem ** heuristic = new KnapsackItem*[m_count];
	for ( int i = 0; i < m_count; ++i ) heuristic[i] = m_items[i];

	//Sort the array by the heuristic ratio
	qsort( heuristic, m_count, sizeof(KnapsackItem*), heuristicCompare );
	for ( int i = 0; i < m_count; ++i ){ heuristic[i]->print(); cout << "|"; };
	cout << endl;

	delete [] heuristic;

}

int main ( int args, char ** argv ){
	
	if ( args != 2 ) return 1;
	
	ifstream dataFile ( argv[1] );
	string instance;
	if ( dataFile.is_open() ){

		while ( getline( dataFile, instance ) ){
			
			KnapsackProblem knapsackInstance( instance );	
			knapsackInstance.solveHeuristic();
		}

		dataFile.close();
	}
	else cout << "Unable to open file" << endl;

	return 0;
}
