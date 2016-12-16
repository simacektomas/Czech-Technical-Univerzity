#include <sstream>
#include <fstream>
#include <string>
#include "knapsack.h"

using namespace std;
/*---------------------------------------------------------------------------------*/
/*KnapsackItem class*/
/*---------------------------------------------------------------------------------*/
KnapsackItem::KnapsackItem()
:m_weight(0), m_price(0), m_ratio(0){}
/*---------------------------------------------------------------------------------*/
KnapsackItem::KnapsackItem(int weight, int price)
:m_weight(weight), m_price(price), m_ratio(double(price)/double(weight)) {}
/*---------------------------------------------------------------------------------*/
ostream& operator << (ostream& stream, const KnapsackItem& item) {
	return stream << '[' << item.m_weight << ", " << item.m_price << ']';
}
/*---------------------------------------------------------------------------------*/
int KnapsackItem::getWeight() const { 
	return m_weight; 
}
/*---------------------------------------------------------------------------------*/
int KnapsackItem::getPrice() const {
	return m_price;
}
/*---------------------------------------------------------------------------------*/
double KnapsackItem::getRatio() const {
	return m_ratio;
}
/*---------------------------------------------------------------------------------*/
void KnapsackItem::setWeight(int weight) {
	m_weight = weight;
}
/*---------------------------------------------------------------------------------*/
void KnapsackItem::setPrice(int price) {
	m_price = price;
}
/*---------------------------------------------------------------------------------*/
void KnapsackItem::setRatio(double ratio) {
	m_ratio = ratio;
}
/*---------------------------------------------------------------------------------*/
/*KnapsackInstance class*/
/*---------------------------------------------------------------------------------*/
KnapsackInstance::KnapsackInstance()
:m_id(-1), m_n(-1), m_capacity(-1), m_items(NULL) {}
/*---------------------------------------------------------------------------------*/
KnapsackInstance::KnapsackInstance(string instance) {
	string id, n, capacity, weight, price;
	istringstream iss(instance);
	
	iss >> id;
        iss >> n;
        iss >> capacity;
        m_id = std::stoi(id);
	m_n = std::stoi(n);
	m_capacity = std::stoi(capacity);

	m_items = new KnapsackItem*[m_n];
        for(int i = 0; i<m_n; ++i) {
		iss >> weight;
		iss >> price;
		m_items[i] = new KnapsackItem(std::stoi(weight), std::stoi(price));
	}

}
/*---------------------------------------------------------------------------------*/
KnapsackInstance::~KnapsackInstance() {
	for(int i = 0; i<m_n; ++i) {
		delete m_items[i];
	}
	delete [] m_items;
}
/*---------------------------------------------------------------------------------*/
ostream& operator << (ostream& stream, const KnapsackInstance & instance) {
	stream << "Instance: [" << endl;
	stream << "\tid: " << instance.m_id << endl;
	stream << "\tn: " << instance.m_n << endl;
	stream << "\tcapacity: " << instance.m_capacity << endl;
	stream << "\titems: ";
	for(int i = 0; i<instance.m_n; ++i) {
		stream << *instance.m_items[i] << ' ' ;
	}
	return stream << endl << "]";
}
/*---------------------------------------------------------------------------------*/
/*KnapsackCollection class*/
/*---------------------------------------------------------------------------------*/
KnapsackCollection::KnapsackCollection(string filename) 
:m_filename(filename) {
	string line;

	ifstream dfile(m_filename);
	if (dfile.is_open()) {
		while(getline(dfile, line)) {
			KnapsackInstance * instance = new KnapsackInstance(line);
			m_instances.push_back(instance);
		}
	}
}
/*---------------------------------------------------------------------------------*/
KnapsackCollection::~KnapsackCollection() {
	for(vector<KnapsackInstance*>::iterator it = m_instances.begin(); it != m_instances.end(); ++it) {
                                delete *it;
        }   
}
/*---------------------------------------------------------------------------------*/
ostream& operator<<(ostream& stream, const KnapsackCollection& collection) {
	for(auto const& instance: collection.m_instances) {
		stream << *instance << endl;
	}
	return stream;
}
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/


