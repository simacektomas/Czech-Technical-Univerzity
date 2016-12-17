#include <cstring>
#include <sstream>
#include <fstream>
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
int KnapsackInstance::getSize() const {
	return m_n;
}
/*---------------------------------------------------------------------------------*/
int KnapsackInstance::getCapacity() const {
	return m_capacity;
}
/*---------------------------------------------------------------------------------*/
KnapsackItem** KnapsackInstance::getItems() const {
	return m_items;
}
/*---------------------------------------------------------------------------------*/
void KnapsackInstance::solveAnnealing() {
	/*Get initial configuration*/
	bool	solution = false;
	bool	*iconfiguration = new bool[m_n];
	State	*istate, *sstate;
	while (!solution) {
		for(int i = 0; i<m_n; i++) {
			int value = rand() % 2;
			if(value) iconfiguration[i] = true;
			else iconfiguration[i] = false;
		}
		istate = new KnapState(iconfiguration, this);

		if(istate->solution()) solution = true;
	}
	cout << "Initial ";
	cout << *istate << endl;	
	Annealing annealing(5,1,0.900,5);
	sstate = annealing.anneal(istate);
	delete istate;
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
void KnapsackCollection::solveAnnealing() {
/*	for(auto const& instance: m_instances) {
		instance->solveAnnealing();
	}*/
	m_instances[0]->solveAnnealing();
}
/*---------------------------------------------------------------------------------*/
ostream& operator<<(ostream& stream, const KnapsackCollection& collection) {
	for(auto const& instance: collection.m_instances) {
		stream << *instance << endl;
	}
	return stream;
}
/*---------------------------------------------------------------------------------*/
/*KnapState class*/
/*---------------------------------------------------------------------------------*/
KnapState::KnapState(bool* configuration, KnapsackInstance* instance) 
:m_configuration(configuration), m_instance(instance) {
	int price = 0, weight = 0;
	KnapsackItem** items = m_instance->getItems();	

	for(int i = 0; i < m_instance->getSize(); i++){
		if(m_configuration[i]) {
			price += items[i]->getPrice();
			weight += items[i]->getWeight();
		}
	}
	m_price = price;
	m_weight = weight;
}
/*---------------------------------------------------------------------------------*/
KnapState::KnapState(int price, int weight, bool* configuration, KnapsackInstance* instance) 
:m_price(price), m_weight(weight), m_configuration(configuration), m_instance(instance) {}
/*---------------------------------------------------------------------------------*/
KnapState::~KnapState() {
	delete [] m_configuration;
}
/*---------------------------------------------------------------------------------*/
double KnapState::criterium() const {
	return m_price;
}
/*---------------------------------------------------------------------------------*/
bool KnapState::solution() const {
	if(m_weight > m_instance->getCapacity()) return false;
	return true;
}
/*---------------------------------------------------------------------------------*/
/*
 *
 *
 */
State* KnapState::adjecency() const {
	int 	nprice = m_price, nweight = m_weight;
	int	soperator = rand() % (m_instance->getSize());
	int	sadd = rand() % 2;
	bool	sflag = false;
	bool*	nconfiguration = new bool[m_instance->getSize()];
	KnapsackItem** m_items = m_instance->getItems();
	/*Copy configuration*/
	for(int i = 0; i < m_instance->getSize(); i++)
		if(m_configuration[i])nconfiguration[i] = true;
		else nconfiguration[i] = false;

	if(sadd) {
		if(!nconfiguration[soperator]) sflag = true;
		nconfiguration[soperator] = true;

	}
	else {
		if(nconfiguration[soperator]) sflag = true;
		nconfiguration[soperator] = false;
	}

	if(sflag) { /*we changed price and weight of state*/
		if(sadd) {	/*we added the item = > change the price*/
			nprice += m_items[soperator]->getPrice();
			nweight+= m_items[soperator]->getWeight(); 			
		} else {
			nprice -= m_items[soperator]->getPrice();
                        nweight-= m_items[soperator]->getWeight();
		}
	} 

	return new KnapState(nprice, nweight, nconfiguration, m_instance);
	
}
/*---------------------------------------------------------------------------------*/
int KnapState::compare(const State& state) const {

}
/*---------------------------------------------------------------------------------*/
string KnapState::print() const {
	stringstream is;
	is << "State: [" << endl;
	is << "\tsize: " << m_instance->getSize() << endl;
	is << "\tprice: " << m_price << endl;
	is << "\tweight: " << m_weight << endl;
	is << "\tcapacity: " << m_instance->getCapacity() << endl;
	is << "\tconfigruration: [";
	for(int i = 0; i < m_instance->getSize(); i++){
		if(m_configuration[i]) is << "1 ";
		else is << "0 ";
	}
	is << "]" << endl << "]";

	return is.str();
}
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/


