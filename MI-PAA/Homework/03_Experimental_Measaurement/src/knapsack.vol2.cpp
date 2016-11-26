#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <regex>

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
		int getWeight() const { return m_weight; }
		/*---------------------------------------------------------------------------------*/
		int getPrice() const { return m_price; }
		/*---------------------------------------------------------------------------------*/
		double getRatio() const { return m_ratio; }
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
		KnapsackSolution()
		:m_type("undef"), m_price(0), m_weight(0), m_id(0), m_n(0){}
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
		std::chrono::duration<double> getTime() { return m_time; }
		/*---------------------------------------------------------------------------------*/
		void setPrice(int price) { m_price = price; }
		/*---------------------------------------------------------------------------------*/
		void setWeight(int weight) { m_weight = weight; }
		/*---------------------------------------------------------------------------------*/
		void setTime(std::chrono::duration<double> time) { m_time = time; }
		/*---------------------------------------------------------------------------------*/
		friend ostream& operator << (ostream& stream, const KnapsackSolution& solution) {
			stream <<  solution.m_id << ' ' << solution.m_n << ' ' << solution.m_price << ' ' << solution.m_time.count();
		}
		/*---------------------------------------------------------------------------------*/
		
	private:
		string m_type;
		int m_price;
		int m_weight;
		int m_id;
		int m_n;
		std::chrono::duration<double> m_time;
};
/*-------------------------------------------------------------------------------------------------*/
               int heuristicCompare( const void * a, const void * b ){                                  
                        const KnapsackItem * item1 = *(const KnapsackItem **) a;                         
                        const KnapsackItem * item2 = *(const KnapsackItem **) b;                         
                        if( item1->getRatio() < item2->getRatio() ) return 1;                            
                        if( item1->getRatio() > item2->getRatio() ) return -1;                           
                        return 0;                                                                       
                }         
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
		KnapsackSolution solveHE() {
			KnapsackItem ** heuristic = new KnapsackItem*[m_n];
			KnapsackSolution solution("Heuristic", m_id, m_n);

			auto start = std::chrono::high_resolution_clock::now();
			
			for ( int i = 0; i < m_n; ++i ) heuristic[i] = m_items[i];
			qsort( heuristic, m_n, sizeof(KnapsackItem*), heuristicCompare );
			int currentWeight = 0;
			int overallPrice = 0;

			for ( int i = 0; i < m_n ; i++ ){
				int itemWeight = heuristic[i]->getWeight(); 
				int itemPrice = heuristic[i]->getPrice();
				if ( currentWeight + itemWeight > m_capacity ) continue; 
				currentWeight += itemWeight;
				overallPrice += itemPrice;
			}
			auto end = std::chrono::high_resolution_clock::now();
			solution.setTime(end-start);
			
			solution.setPrice(overallPrice);
			solution.setWeight(currentWeight);
			

			delete [] heuristic;
			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveBF() {
			int depth = 0;
			bool * permutation = new bool[m_n];
			KnapsackSolution solution("Bruteforce", m_id, m_n);
			
			auto start = std::chrono::high_resolution_clock::now();			

			permutation[depth] = true;
			bf(depth+1, permutation, solution);

			permutation[depth] = false;
			bf(depth+1, permutation, solution);

			auto end = std::chrono::high_resolution_clock::now();
			solution.setTime(end-start);	

			delete [] permutation;
			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveBB() {
			int depth = 0, priceSum = 0, weightSum = 0, potential = 0;
			bool * permutation = new bool[m_n];
			KnapsackSolution solution("Bound&Branch", m_id, m_n);
			
			for(int i = 0; i<m_n; ++i) {
				potential += m_items[i]->getPrice();
			}

			auto start = std::chrono::high_resolution_clock::now();			

			permutation[depth] = true;
			bb(depth+1,
			   potential - m_items[depth]->getPrice(),
			   priceSum + m_items[depth]->getPrice(),
			   weightSum + m_items[depth]->getWeight(),
			   permutation,
			   solution);

			permutation[depth] = false;
			bb(depth+1,
			   potential - m_items[depth]->getPrice(),
			   priceSum,
			   weightSum,
			   permutation,
			   solution);

			auto end = std::chrono::high_resolution_clock::now();
			solution.setTime(end-start);	

			delete [] permutation;
			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solvePD() {
			// price decomposition by dynamic programing
			int sumPrice = 0;
			
			KnapsackSolution solution("PriceDecomposition", m_id, m_n);

			for(int i = 0; i<m_n; ++i) {
				sumPrice += m_items[i]->getPrice();
			}
			// we need the first zero column, or the last index
			// we use sumPrice for allocating and we need that one extra collumn for price zero
			sumPrice++;
			// prepare table 
			int** pmatrix = new int*[m_n];
			for(int i = 0; i<m_n; ++i) {
				pmatrix[i] = new int[sumPrice];
				for(int y = 0; y<sumPrice; ++y){
					pmatrix[i][y] = -1;
				}
			}
			// now we will use sumPrice as an index so we need to decrement it, cause array of 13 collumn has max index 12
			sumPrice--;

			auto start = std::chrono::high_resolution_clock::now();

			//init
			pmatrix[0][0] = 0;
			// iterate over all items in knapsack
			for(int i = 0; i<m_n; ++i) {
				// We process new item
				int itemPrice = m_items[i]->getPrice();
				int itemWeight = m_items[i]->getWeight();
				int offset = i ? 1 : 0 ;
				//
				for(int y = sumPrice; y>=0; --y) {
					// we have value
					if ( pmatrix[i-offset][y] >= 0 ) {
						int estWeight = pmatrix[i-offset][y] + itemWeight;
						if(estWeight <= m_capacity){
							if(pmatrix[i][y+itemPrice] == -1){
								pmatrix[i][y+itemPrice] = estWeight;
							}
							else {
								if(pmatrix[i][y+itemPrice] > estWeight) {
									pmatrix[i][y+itemPrice] = estWeight;
								}
							}
						}
						pmatrix[i][y] = pmatrix[i-offset][y];
					}
				}
			}
			//find solution
			//
			int y = sumPrice;
			bool * permutation = new bool[m_n];
			for(int i = m_n-1; i>=0; --i){
				if(!i) {
					if( pmatrix[i][y] == 0 ) permutation[i] = 0;
					else permutation[i] = 1;
					break;
				} 		
		
				while(pmatrix[i][y] < 0) y--;
				
				if(pmatrix[i][y] == pmatrix[i-1][y]) permutation[i] = 0; 
				else {
					permutation[i] = 1;
					y -= m_items[i]->getPrice();
				}
			}


			for(int y = sumPrice; y>=0; --y) {
				if(!(pmatrix[m_n-1][y] < 0)){
					solution.setPrice(y);
					solution.setWeight(pmatrix[m_n-1][y]);
					break;
				}
			}

			auto end = std::chrono::high_resolution_clock::now();
			solution.setTime(end-start);
			// Delete matrix	
			for(int i = 0; i<m_n; ++i) {
				delete [] pmatrix[i];
			}
			delete [] pmatrix;

			return solution;
		}
		/*---------------------------------------------------------------------------------*/
		KnapsackSolution solveFPTAS( double epsilon ) {

			KnapsackSolution solution("FPTAS", m_id, m_n);

			if(!(epsilon > 0 && epsilon <= 1)) return solution;

			int maxPrice = 0, modSumPrice = 0;
			double K = 1;
			// count maximal price in items set
			for(int i = 0; i<m_n; ++i) {
				if(m_items[i]->getPrice() > maxPrice) maxPrice = m_items[i]->getPrice();
			}
			// count coeficient K = (epsilon*maxPrice)/m_n
			K = (epsilon*maxPrice)/m_n;
			if(K<1) K = 1;
			// p_i' = p_i/K
			for(int i = 0; i<m_n; ++i) {
				int price = m_items[i]->getPrice();
				modSumPrice += price/K;
			}


			modSumPrice++;
                        // prepare table 
                        int** pmatrix = new int*[m_n];
                        for(int i = 0; i<m_n; ++i) {
                                pmatrix[i] = new int[modSumPrice];
                                for(int y = 0; y<modSumPrice; ++y){
                                        pmatrix[i][y] = -1;
                                }
                        }
                        // now we will use sumPrice as an index so we need to decrement it, cause array of 13 collumn has max index 12
                        modSumPrice--;

			auto start = std::chrono::high_resolution_clock::now();
			// init 
			pmatrix[0][0] = 0;

                        for(int i = 0; i<m_n; ++i) {
                                // We process new item
                                int itemPrice = (m_items[i]->getPrice())/K;
                                int itemWeight = m_items[i]->getWeight();
                                int offset = i ? 1 : 0 ;
                                //
                                for(int y = modSumPrice; y>=0; --y) {
                                        // we have value
                                        if ( pmatrix[i-offset][y] >= 0 ) {
                                                int estWeight = pmatrix[i-offset][y] + itemWeight;
                                                if(estWeight <= m_capacity){
                                                        if(pmatrix[i][y+itemPrice] == -1){
                                                                pmatrix[i][y+itemPrice] = estWeight;
                                                        }
                                                        else {
                                                                if(pmatrix[i][y+itemPrice] > estWeight) {
                                                                        pmatrix[i][y+itemPrice] = estWeight;
                                                                }
                                                        }
                                                }
                                                pmatrix[i][y] = pmatrix[i-offset][y];
                                        }
                                }
                        }
                        //find solution
                        int y = modSumPrice;
                        bool * permutation = new bool[m_n];
                        for(int i = m_n-1; i>=0; --i){
                                if(!i) {
                                        if( pmatrix[i][y] == 0 ) permutation[i] = 0;
                                        else permutation[i] = 1;
                                        break;
                                }

                                while(pmatrix[i][y] < 0) y--;

                                if(pmatrix[i][y] == pmatrix[i-1][y]) permutation[i] = 0;
                                else {
                                        permutation[i] = 1;
                                        y -= (int)((m_items[i]->getPrice())/K);
                                }       
                        }

			int price = 0;
			int weight = 0;
		
			for(int i = 0; i<m_n; ++i) {
				if(permutation[i]) {
					price += m_items[i]->getPrice();
					weight += m_items[i]->getWeight();
				}
			}
			solution.setPrice(price);
			solution.setWeight(weight);

			auto end = std::chrono::high_resolution_clock::now();
			solution.setTime(end-start);


			// delete matrix
			for(int i = 0; i<m_n; ++i) {
				delete [] pmatrix[i];
			}

			delete [] pmatrix;

			return solution;

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
		void bb(int depth, int potential, int priceSum, int weightSum, bool* permutation, KnapsackSolution& solution) {

			if(weightSum > m_capacity || (priceSum + potential)< solution.getPrice()) return;
			
			if(depth >= m_n) {
				if(priceSum >= solution.getPrice()){
					solution.setPrice(priceSum);
					solution.setWeight(weightSum);
				}
				return;
			} 
				
			permutation[depth] = true;
			bb(depth+1,
			   potential - m_items[depth]->getPrice(),
			   priceSum + m_items[depth]->getPrice(),
			   weightSum + m_items[depth]->getWeight(),
			   permutation,
			   solution);

			permutation[depth] = false;
			bb(depth+1,
			   potential - m_items[depth]->getPrice(),
			   priceSum,
			   weightSum,
			   permutation,
			   solution);
			
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
		KnapsackCollection(string filename)
			:m_filename(filename) {
			string line;
			// Open data file, read id, n, capacity and knapsack items
			ifstream dfile(m_filename);
			if (dfile.is_open()) {
				while(getline(dfile, line)) {
					// Construct knapsack instance and remeber it
					KnapsackInstance * instance = new KnapsackInstance(line); 	
					m_instances.push_back(instance);
				}
			}
			size_t index = 0;
			m_solfile = m_filename;
			string search = "inst", replace = "sol";
			// find solution file name
			for(size_t pos = 0; ; pos+= replace.length()) {
				pos = m_solfile.find(search, pos);
				if(pos == string::npos) break;

				m_solfile.erase(pos, search.length());
				m_solfile.insert(pos, replace);
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
                void solveHE() { 
                        int count = 0, n = 0;                                                        
                        double averageTime = 0, rerr = 0, rerra = 0;                                                      
                        KnapsackSolution solution, optimal;                                                   
                        for(auto const& instance: m_instances) {                                         
                                solution = instance->solveHE();                                          
				optimal = instance->solvePD();
				rerr = (double)(optimal.getPrice()-solution.getPrice())/(double)optimal.getPrice();	

				rerra += rerr;
                                averageTime += solution.getTime().count();                               
                                count ++;                                                                
                        }                                                                                
                        averageTime /= (double) count;                                                   
			rerra /= (double) count;
                        cout << solution.getN() << " " << count << " " << averageTime << " " << rerra << endl;
		}
		/*---------------------------------------------------------------------------------*/
		void solveBF() {
			int count = 0, n = 0;
			double averageTime = 0;
			KnapsackSolution solution;
			for(auto const& instance: m_instances) {
				solution = instance->solveBF();
				averageTime += solution.getTime().count();
				count ++;
			}
			averageTime /= (double) count;
			cout << solution.getN() << " " << count << " " << averageTime << endl;
		}
		/*---------------------------------------------------------------------------------*/
		void solveBB() {
			int count = 0, n = 0;
			double averageTime = 0;			
			KnapsackSolution solution;
			for(auto const& instance: m_instances) {
				solution = instance->solveBB();
				averageTime += solution.getTime().count();	
				count ++;
			}
			averageTime /= (double) count;
			cout << solution.getN() << " " << count << " " << averageTime << endl;
		}
		/*---------------------------------------------------------------------------------*/
		void solvePD() {
			int count = 0, n = 0;
			double averageTime = 0;
			KnapsackSolution solution;
			for(auto const& instance: m_instances) {				
				solution = instance->solvePD();
				averageTime += solution.getTime().count();
				count ++;
			}
			averageTime /= (double) count;
			cout << solution.getN() << " " << count << " " << averageTime << endl;
		}
		/*---------------------------------------------------------------------------------*/
		void solveFPTAS( double epsilon ) {
			int count = 0, n = 0;
			double averageTime = 0;
			KnapsackSolution solution;
			for(auto const& instance: m_instances) {
				solution = instance->solveFPTAS(epsilon);
				averageTime += solution.getTime().count();
				count ++;
				cout << solution << endl;
			}
			averageTime /= (double) count;
			cout << solution.getN() << " " << count << " " << averageTime << endl;
		}
		/*---------------------------------------------------------------------------------*/
		void solveFPTASerr(double epsilon) {
			int count = 0, n = 0;
			double averageError = 0, maxError = 0, relError = 0;
			double avgTimePD = 0, avgTimeFPTAS = 0;
			KnapsackSolution pd, fptas;
			for(auto const& instance: m_instances) {
				pd = instance->solvePD();
				fptas = instance->solveFPTAS(epsilon);				
				// rel error
				relError = ((double)(pd.getPrice()-fptas.getPrice()))/(double)pd.getPrice();
				if(relError > maxError) maxError = relError;
				averageError += relError;

				avgTimePD += pd.getTime().count();
				avgTimeFPTAS += fptas.getTime().count();

				count++;

			}
			averageError /= (double)count;
			avgTimePD /= (double)count;
			avgTimeFPTAS /= (double)count;			

			cout << pd.getN() << ' ' << count << ' ' << avgTimePD << ' ' << avgTimeFPTAS << ' '  << averageError << ' ' << maxError << endl;
		}
		/*---------------------------------------------------------------------------------*/
	private:
		string m_filename;
		string m_solfile;
		vector<KnapsackInstance*> m_instances;
	
};
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
int main ( int args, char ** argv ) {

	if (args<3) return 1;
	KnapsackCollection collection( argv[2] );

	string opt = argv[1];
	if( opt == "BF") {
		collection.solveBF();
	}
	else if ( opt == "BB" ) {
		collection.solveBB();
	}
	else if ( opt == "HE" ) {
		collection.solveHE();
	}
	else if ( opt == "PD" ) {
		collection.solvePD();
	}
	else if ( opt == "FPTAS") {		
		if (args<4){
			cout << "Enter epsilon" << endl;
			return 1;
		}
		collection.solveFPTAS(std::stod(argv[3]));
	}
	else if ( opt == "ERR") {
		if (args<4) {
			cout << "Enter epsilon" << endl;
			return 1;
		}
		collection.solveFPTASerr(std::stod(argv[3]));
	}
	else {

		cout << "Invalid first argument" << endl;
		cout << "Usage: " << argv[0] << " [BF|BB|PD|FPTAS] <filename> " << endl;
		return 2;
	}
	return 0;
}
/*-------------------------------------------------------------------------------------------------*/
