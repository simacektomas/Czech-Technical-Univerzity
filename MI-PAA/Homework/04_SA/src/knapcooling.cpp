#include <cstddef>
#include <string>
#include <iostream>

using namespace std;
/*-------------------------------------------------------------------------------------------------*/
/*
 * Represent state of any problem state space,
 * each state is one configuration of problem instance and don't have to be
 * solution.
 */
class State {
	public:
		virtual bool 		solution() const = 0;					//check if the state is solution of the problem
		virtual double 		criterium() const = 0;					//return value of optimalization criterium
		virtual State*		adjecency() const = 0;
		// comparing two states
		friend 	bool 		operator>(const State& left, const State& right);
		friend	bool 		operator<(const State& left, const State& right);
		friend 	ostream&	operator<<(ostream& os, const State& state);
	private:
		virtual int 		compare(const State& state) const = 0;
		virtual string 		print() const = 0;
};
/*--------------------------------------------------------------------*/
bool operator>(const State& left, const State& right){
	int result = left.compare(right);
	if (result <= 0) return false;
	return true;
}
/*--------------------------------------------------------------------*/
bool operator<(const State& left, const State& right){
	int result = left.compare(right);
	if (result >= 0) return false;
	return true;
}
/*--------------------------------------------------------------------*/
ostream& operator<<(ostream& os,const State& state){
	return os << state.print();
}
/*--------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------*/
/*
 *
 *
 *
 *
 */
class KnapState: public State {
	public:
				KnapState(int value){};
				KnapState(int size, bool* configuration);
				~KnapState();
		
		virtual double 	criterium() const;
		virtual bool 	solution() const;
		virtual State*	adjecency() const;
	private:
		virtual int 	compare(const State& state) const;
		virtual string 	print() const;

		//Knapsack state
		bool * 		configuration;
		int 		size;
};
/*--------------------------------------------------------------------*/
KnapState::KnapState(int size, bool* configuration)
:size(size), configuration(configuration)
{}
/*--------------------------------------------------------------------*/
KnapState::~KnapState(){
	delete configuration;
}
/*--------------------------------------------------------------------*/
double KnapState::criterium() const {
	cout << "Still calling this one" << endl;
	return rand();
}
/*--------------------------------------------------------------------*/
bool KnapState::solution() const {
	return true;
}
/*--------------------------------------------------------------------*/
int KnapState::compare(const State& state) const {
	if(this->criterium() >  state.criterium()) return 1; 
	if(this->criterium() == state.criterium()) return 0; 
	if(this->criterium() <  state.criterium()) return -1;
}
/*--------------------------------------------------------------------*/
/*
 * This function chose neighbour from adjecency state. It is equivalent of using 
 * an operator of state space on current state.
 */
State* KnapState::adjecency() const {
	int 	soperator = rand() % size;
	int 	add = rand() % 2; 				//add item
	bool*	nconfiguration = new bool[size];

	for(int i = 0; i < size; i++)
		if(configuration[i])nconfiguration[i] = true;
		else nconfiguration[i] = false;
	
	if(add == 1){					//if add = 1 we add an item on soperator position
		nconfiguration[soperator] = true;
	}
	else {						//we remove item on soperator position
		nconfiguration[soperator] = false;
	}
	return new KnapState(size, nconfiguration);	
}
/*--------------------------------------------------------------------*/
string KnapState::print() const {
	string state = "[ ";
	for(int i = 0; i < size; i++)
		if(configuration[i]) state += "1 ";
		else state += "0 ";
	return state + "]";
}
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*
 *			   configuration
 * 			init state <-- init
 * 			curr state <-- init
 *			best state <-- init
 *			init T     <-- T
 *			        |
 *	|-----------------------|
 *	|		        |
 *	|	             frozen() ---[yes]-----> result
 *	|	|---------------|[no]
 *	|	|		|
 *	|	|		|
 *	|	|	   equilibrium() ---------------------[yes]
 *	|	|		|[no]				|
 *	|	|		|				|
 *	|	|  curr state <-- curr state.try();		|
 *	|	|   		|				|
 *	|	|   		|				|
 *	|	|   		|				|
 *	|	|   curr state > best state ---[yes]		|
 *	|	|		|[no]		|		|
 *	|	|		|   best state <-- curr state	|
 *	|	|---------------|---------------|		|
 *	|							|
 *	|-------------------------------------------------------|
 */

/*
 *
 *
 *
 */
class Annealing {
	public:
			Annealing(double T_s, double T_e, double cooling);
		State& 	anneal(State& init);
	private:
		bool 	equilibrium();
		bool 	frozen();
		void 	cool();
		State& 	transform(State& state);
		
		double 	T_s;				//starting temperature
		double 	T_c;				//current temperature
		double	T_e;				//ending temperature
		double	cooling;			//how fast we are cooling T = T*cooling
};
/*--------------------------------------------------------------------*/
/*
 * Annealing configuration 
 */
Annealing::Annealing(double T_s, double T_e, double cooling)
:T_s(T_s), T_c(T_s), T_e(T_e), cooling(cooling)
{}
/*--------------------------------------------------------------------*/
State& Annealing::anneal(State& init){

	while(!frozen()){

		while(!equilibrium()){

		}
	}
}
/*--------------------------------------------------------------------*/
bool Annealing::equilibrium(){
}
/*--------------------------------------------------------------------*/
bool Annealing::frozen(){
	if(T_c < T_e) return true;
	return false;
}
/*--------------------------------------------------------------------*/
/*
 * This function controls the temerature of annealing. Each time equeilibrium ends
 * cool will lowe the temperature
 * T = T*a ; 0.8 < a < 0.999
 */
void Annealing::cool(){
	T_c = T_c*cooling;
}
/*--------------------------------------------------------------------*/
/*
 *
 *
 */
State& Annealing::transform(State& state){
}
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
int main (int argc, char * argv[]){
	srand (time(NULL));
	bool config[4] = [true, true, false, true];
	State* state = new KnapState(4, config);
	State* state2 = new KnapState(6);

	cout << *state << endl;

	if(*state < *state2) cout << "Ano" << endl;
	return 0;
}
