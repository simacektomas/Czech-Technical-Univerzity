#include "satannealing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
/*SATINSTANCE*/
/*----------------------------------------------------------------------------------------------------------------*/
SatInstance::SatInstance(string file)
:valid(true) {
	cout << file << endl;	

	valid = parseDIMACS(file);
	if ( valid ) cout << "VALID" << endl;
	else cout << "INVALID" << endl;
}
/*----------------------------------------------------------------------------------------------------------------*/
SatInstance::~SatInstance() {	
}
/*----------------------------------------------------------------------------------------------------------------*/
State* SatInstance::solveAnnealing(double tstart, double tend, double cool, int equilibrium) {
	vector<bool> iconfiguration;

	for(int i = 0; i < vcount; i++)
		iconfiguration.push_back(false);

	Annealing annealing(tstart, tend, cool, equilibrium);
	
	return annealing.anneal( new SatState(iconfiguration, this));
}
/*----------------------------------------------------------------------------------------------------------------*/
int SatInstance::vCount() const {
	return vcount;
}
/*----------------------------------------------------------------------------------------------------------------*/
int SatInstance::cCount() const {
	return ccount;
}
/*----------------------------------------------------------------------------------------------------------------*/
vector<int> SatInstance::getWeights() const {
	return weights;
}
/*----------------------------------------------------------------------------------------------------------------*/
vector<vector<int>> SatInstance::getFormule() const {
	return formule;
}
/*----------------------------------------------------------------------------------------------------------------*/
bool SatInstance::parseDIMACS(string file) {

	ifstream sfile(file);

	if (sfile.is_open()) {			

		string line;
		/* COMMENTS */
		while(getline(sfile, line)) {
			if(line[0] == 'c') {
				continue;	// comment line
			}
			else break;
		}
		/* PROBLEM LINE*/
		if(line[0] == 'p' && line[1] == ' '){ // we have a problem line
			string dummy, type, varcount, clausulecount;
			istringstream iss(line);
			iss >> dummy >> type >> varcount >> clausulecount;
			if(type == "cnf") {
				try{
					vcount = stoi(varcount);
					ccount = stoi(clausulecount);
				} catch (...) {
					cerr << "Error in instance source file " << file << ": (p line) cannot convert to int." << endl;					
					return false;
				}
			} else { // not supported type
				cerr << "Error in instance source file " << file << ": invalid file type." << endl;				
				return false;
			}		

			int i = 0;
			getline(sfile,line);
			iss.clear();
			iss.str(line);	

			while(i < ccount) {							
				/*READ ONE CLAUSULE (UNTIL 0)*/
				vector<int> clausule;
				while(true){
					string var;
					iss >> var;						
					if(var == "0") {
						if(iss.eof()){
							getline(sfile,line);
							iss.clear();
							iss.str(line);						
						}	
						break;
					}
															
					try{
						clausule.push_back(stoi(var));
					} catch(...) {
						cerr << "Error in instance source file " << file << ": Cannot covert var to int." << endl;				
						return false;
					}

					if(iss.eof()){
						getline(sfile,line);
						iss.clear();
						iss.str(line);						
					}					
				}				
				
				formule.push_back(clausule);
				i++;

			}
			/* GET LINE WITH WEIGHTS*/												
			if( line[0] == 'w' && line[1] == ' ') {
				iss >> dummy; // w character				

				for ( int i = 0; i < vcount; i++ ) {
					string weight;
					iss >> weight;					
					try {
						weights.push_back(stoi(weight));
					} catch(...){
						cerr << "Error in instance source file " << file << ": Cannot covert weight to int." << endl;				
						return false;
					}
				}
			}
			/*PRINT*/
			/*cout << "FORMULE: " << endl;
			for( vector<int> clausule: formule ) {
				for( int var : clausule )
					cout << var << " ";
				cout << endl;
			}
			cout << "WEIGHTS: " << endl;
			for( int weight: weights )
				cout << weight << " ";
			cout << endl;	*/	
		}
	}
}
/*----------------------------------------------------------------------------------------------------------------*/
/*SATSTATE*/
/*----------------------------------------------------------------------------------------------------------------*/
SatState::SatState(vector<bool> configuration, SatInstance* instance) 
:m_criterium(0), m_solution(false), m_configuration(configuration), m_instance(instance){
	/*satisfiability*/
	int count = 0;
	int clausulei = 0;
	for( const vector<int> & clausule: m_instance->getFormule() ) {			
		bool met = false;		
		for( int var: clausule ) {			
			bool negation = false;
			int value = 0;			
			if(var < 0) negation = true;

			if(m_configuration[abs(var) - 1]) {
				value = 1;
				if(negation) value = 0;
			} else {
				value = 0;
				if(negation) value = 1;
			}
			/*ONE OF VAR IN CLAUSULE IS TRUE THAN WHOLE CLAUSULE IS TRUE*/				
			if(value){
				met = true;						
			}
		}
		if(met) count ++;
		else m_nclausule.push_back(clausulei);

		m_clausulemap.push_back(met);
		
		clausulei++;
	}
	/*ALL CLAUSULES ARE MET*/
	if (count == m_instance->cCount()) m_solution = true;
	else m_solution = false;

	/*CRITERIUM*/
	const vector<int> & weights = m_instance->getWeights();
	int i = 0;
	for(bool var: m_configuration) {
		if(var) {
			m_criterium += weights[i];			
		}
		i++;
	}

}
/*----------------------------------------------------------------------------------------------------------------*/
SatState::~SatState() {

}
/*----------------------------------------------------------------------------------------------------------------*/
bool SatState::solution() const {
	return m_solution;
}
/*----------------------------------------------------------------------------------------------------------------*/
double SatState::criterium() const {
	if(m_solution) {
		return m_criterium;			
	} 
	else {
		int maxcrit = 0;
		for(int weight: m_instance->getWeights())
			maxcrit += weight;
		return (m_criterium - maxcrit);
	} 
}
/*----------------------------------------------------------------------------------------------------------------*/
State* SatState::adjecency() const {
	vector<bool> nconfiguration(m_configuration);

	/*int soperator = rand() % (m_instance->vCount());

	if(nconfiguration[soperator]) nconfiguration[soperator] = false;
	else nconfiguration[soperator] = true;*/

	if(!m_solution){	
		cout << "NOT SOLUTION" << endl;
		const vector<vector<int>>& formule = m_instance->getFormule();
		int soperator = rand() % (m_nclausule.size());

		const vector<int> & clausule = formule[soperator];

		int varflip = rand() % (clausule.size());

		int var = clausule[varflip];

		if(nconfiguration[abs(var)]) nconfiguration[abs(var)] = false;
		else nconfiguration[abs(var)] = true;
	} else {
		cout << "SOLUTION" << endl;
		int soperator = rand() % (m_instance->vCount());

		if(nconfiguration[soperator]) nconfiguration[soperator] = false;
		else nconfiguration[soperator] = true;
	}

	


	State * state = new SatState(nconfiguration, m_instance);
	cout << *state << endl;
	return state ;

}
/*----------------------------------------------------------------------------------------------------------------*/
int SatState::compare(const State& state) const {
	if(this->criterium() >  state.criterium()) return  1;
	if(this->criterium() == state.criterium()) return  0;
	if(this->criterium() <  state.criterium()) return -1;
}
/*----------------------------------------------------------------------------------------------------------------*/
string SatState::print() const {
	stringstream ss;
	ss << "State:[" << endl;
	ss << "\tcriterium: " << this->criterium() << endl;
	ss << "\tsolution: " << this->solution() << endl;
	ss << "\tconfiguration: [" ;
	if(m_configuration[0]) ss << "1";
	else ss << "0";
	for(int i = 1; i < m_configuration.size(); i++) {
		if(m_configuration[i]) ss << ",1";
		else ss << ",0";
	}
	ss << "]" << endl;

	ss << "\tclausulemap: [" ;
	if(m_clausulemap.size())		
		if(m_clausulemap[0]) ss << "1";
		else ss << "0";
	for(int i = 1; i < m_clausulemap.size(); i++) {
		if(m_clausulemap[i]) ss << ",1";
		else ss << ",0";
	}
	ss << "]" << endl;

	ss << "\tnclausule: [" ;
	if(m_nclausule.size())
		ss << m_nclausule[0];
	for(int i = 1; i < m_nclausule.size(); i++)
		ss << "," << m_nclausule[i];
	ss << "]" << endl << "]";

	return ss.str();
}
/*----------------------------------------------------------------------------------------------------------------*/
