#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class KnapsackProblem {
	public:
		KnapsackProblem( string instance );
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
		int * m_instance;

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
	

}

int main ( int args, char ** argv ){
	
	if ( args != 2 ) return 1;
	
	ifstream dataFile ( argv[1] );
	string instance;
	if ( dataFile.is_open() ){

		while ( getline( dataFile, instance ) ){
			
			KnapsackProblem knapsackInstance( instance );	
			knapsackInstance.showParameters();
		}

		dataFile.close();
	}
	else cout << "Unable to open file" << endl;

	return 0;
}
