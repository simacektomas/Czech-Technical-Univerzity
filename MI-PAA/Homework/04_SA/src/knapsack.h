#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*-------------------------------------------------------------------------------------------------*/
class KnapsackItem {
        public:
                		KnapsackItem();
                		KnapsackItem(int weight, int price);
                	int 	getWeight() const;
               		int 	getPrice() const;
                	double 	getRatio() const;
                	void 	setWeight(int weight);
                	void 	setPrice(int price);
                	void 	setRatio(double ratio);

                friend 	ostream& operator << (ostream& stream, const KnapsackItem& item);
        private:
                int m_weight;
                int m_price;
                double m_ratio;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackInstance {
        public:
                		KnapsackInstance();
		                KnapsackInstance(string instance);
        		        ~KnapsackInstance();

                friend ostream& operator << (ostream& stream, const KnapsackInstance & instance);
	private: 
		int m_id;
                int m_n;
                int m_capacity;
                KnapsackItem ** m_items;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackCollection {
	public:
				KnapsackCollection(string filename);
				~KnapsackCollection();
		friend ostream& operator<<(ostream& stream, const KnapsackCollection& collection);
	private:
		string 				m_filename;
		string 				m_solfile;
		vector<KnapsackInstance*> 	m_instances;
};
/*-------------------------------------------------------------------------------------------------*/
