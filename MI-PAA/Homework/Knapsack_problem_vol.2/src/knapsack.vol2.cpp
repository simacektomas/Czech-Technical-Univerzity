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
	private:
		int m_weight;
		int m_price;
		double m_ratio;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackSolution {
	public:
	private:
		int m_price;
		int m_weight;
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

		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveBB() {

		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveDP() {

		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveFPTAS() {

		}
		/*---------------------------------------------------------------------------------*/
	private:
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
		/*---------------------------------------------------------------------------------*/
	private:
		vector<KnapsackInstance*> m_instances;
	
};
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
int main ( int args, char ** argv ) {
//	cout << "Hello world. Vol2" << endl;	
	if (args<2) return 1;
	cout << argv[0] << ' ' << args <<  endl;
	KnapsackCollection collection( argv[1] );
	cout << collection;

}
