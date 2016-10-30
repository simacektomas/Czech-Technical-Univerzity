#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;
/*-------------------------------------------------------------------------------------------------*/
class KnapsackItem {
	public:
		/*---------------------------------------------------------------------------------*/
		KnapsackItem()
		:m_weight(0), m_price(0), m_ratio(0) {}
		/*---------------------------------------------------------------------------------*/
		KnapsackItem(int weight, int price)
		:m_weight(weight), m_price(price), m_ratio(double(price)/double(weight)) {}
		/*---------------------------------------------------------------------------------*/
		friend ostream& operator << (ostream& stream, const KnapsackItem& item) {
			return stream << '[' << item.m_weight << ", " << item.m_price << ']';
		}
		/*---------------------------------------------------------------------------------*/
		int getWeight() { return m_weight; }
		/*---------------------------------------------------------------------------------*/
		int getPrice() { return m_price; }
		/*---------------------------------------------------------------------------------*/
		double getRatio() { return m_ratio; }
		/*---------------------------------------------------------------------------------*/
		void setWeight(int weight) { m_weight = weight; }
		/*---------------------------------------------------------------------------------*/
		void setPrice(int price) { m_price = price; }
		/*---------------------------------------------------------------------------------*/
		void setRatio(double ratio) { m_ratio = ratio; }
		/*---------------------------------------------------------------------------------*/
	private:
		int m_weight;
		int m_price;
		double m_ratio;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackSolution {
	public:
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution(string type, int id, int n)	
		:m_type(type), m_price(0), m_weight(0), m_id(id), m_n(n) {}
		/*---------------------------------------------------------------------------------*/
		int getPrice() { return m_price; }
		/*---------------------------------------------------------------------------------*/
		int getWeight() { return m_weight; }
		/*---------------------------------------------------------------------------------*/
		int getId() { return m_id; }
		/*---------------------------------------------------------------------------------*/
		int getN() { return m_n; }
		/*---------------------------------------------------------------------------------*/
		void setPrice(int price) { m_price = price; }
		/*---------------------------------------------------------------------------------*/
		void setWeight(int weight) { m_weight = weight; }
		/*---------------------------------------------------------------------------------*/
		friend ostream& operator << (ostream& stream, const KnapsackSolution& solution) {
			stream <<  solution.m_id << ' ' << solution.m_n << ' ' << solution.m_price << endl;
		}
		/*---------------------------------------------------------------------------------*/
		
	private:
		string m_type;
		int m_price;
		int m_weight;
		int m_id;
		int m_n;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackInstance {
	public:
		/*---------------------------------------------------------------------------------*/
		KnapsackInstance()
		:m_id(-1), m_n(-1), m_capacity(-1), m_items(NULL) {}
		/*---------------------------------------------------------------------------------*/
		KnapsackInstance(string instance) {
			string id, n, capacity, weight, price;
			istringstream iss(instance);
			// Parse parameters from instance line
			iss >> id;
			iss >> n;
			iss >> capacity;
			m_id = std::stoi(id);
			m_n = std::stoi(n);
			m_capacity = std::stoi(capacity);
			// Parse knapsac items 
			m_items = new KnapsackItem*[m_n];	
			for(int i = 0; i<m_n; ++i) {
				iss >> weight;
				iss >> price;
				m_items[i] = new KnapsackItem(std::stoi(weight), std::stoi(price));
			}
		}
		/*---------------------------------------------------------------------------------*/
		~KnapsackInstance() {
			for(int i = 0; i<m_n; ++i) {
				delete m_items[i];
			}
			delete [] m_items;
		}
		/*---------------------------------------------------------------------------------*/
		friend ostream& operator << (ostream& stream, const KnapsackInstance & instance) {
			stream << "===INSTANCE===" << endl;
			stream << "id: " << instance.m_id << endl;
			stream << "n: " << instance.m_n << endl;
			stream << "capacity: " << instance.m_capacity << endl;
			for(int i = 0; i<instance.m_n; ++i) {
				stream << *instance.m_items[i] << ' ' ;
			}
			return stream << endl << "===END===";
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveBF() {
			int depth = 0;
			bool * permutation = new bool[m_n];
			KnapsackSolution solution("Bruteforce", m_id, m_n);
			
			permutation[depth] = true;
			bf(depth+1, permutation, solution);

			permutation[depth] = false;
			bf(depth+1, permutation, solution);

			delete [] permutation;
			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveBB() {
			int depth = 0;
			bool * permutation = new bool[m_n];
			KnapsackSolution solution("Bound&Branch", m_id, m_n);

			permutation[depth] = true;
			bf(depth+1, permutation, solution);

			permutation[depth] = false;
			bf(depth+1, permutation, solution);

			delete [] permutation;
			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveDP() {

		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveFPTAS() {

		}
		/*---------------------------------------------------------------------------------*/
	private:
		/*---------------------------------------------------------------------------------*/
		void bf(int depth, bool* permutation, KnapsackSolution& solution) {
			if(depth >= m_n) {
				int price = 0, weight = 0;
				for(int i = 0; i<m_n; ++i) {
					// if item in knapsack add his price to pool
					if(permutation[i]) {
						price += m_items[i]->getPrice();
						weight += m_items[i]->getWeight();
					}
				}
				// We founded new best solution
				if (price > solution.getPrice() && weight <= m_capacity) {
					solution.setPrice(price);
					solution.setWeight(weight);	
				}
				return;
			}
			permutation[depth] = true;
			bf(depth+1, permutation, solution);

			permutation[depth] = false;
			bf(depth+1, permutation, solution);
		}
		/*---------------------------------------------------------------------------------*/
		int m_id;
		int m_n;
		int m_capacity;
		KnapsackItem ** m_items;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackCollection {
	public:
		/*---------------------------------------------------------------------------------*/
		KnapsackCollection(string filename) {
			string line;
			// Open data file, read id, n, capacity and knapsack items
			ifstream dfile(filename);
			if (dfile.is_open()) {
				while(getline(dfile, line)) {
					// Construct knapsack instance and remeber it
					KnapsackInstance * instance = new KnapsackInstance(line); 	
					m_instances.push_back(instance);
				}
			}

		}
		/*---------------------------------------------------------------------------------*/
		~KnapsackCollection() {
			for(vector<KnapsackInstance*>::iterator it = m_instances.begin(); it != m_instances.end(); ++it) {
				delete *it;
			}
		}
		/*---------------------------------------------------------------------------------*/
		friend ostream& operator << (ostream& stream, const KnapsackCollection & collection) {
			for(auto const& instance: collection.m_instances) {
				stream << *instance << endl ;
			}
			return stream;
		}
		/*---------------------------------------------------------------------------------*/
		void solveBF() {
			for(auto const& instance: m_instances) {
				cout << instance->solveBF();
				
			}
		}
		/*---------------------------------------------------------------------------------*/
	private:
		vector<KnapsackInstance*> m_instances;
	
};
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
int main ( int args, char ** argv ) {

	if (args<2) return 1;
	KnapsackCollection collection( argv[1] );
	collection.solveBF();
}
