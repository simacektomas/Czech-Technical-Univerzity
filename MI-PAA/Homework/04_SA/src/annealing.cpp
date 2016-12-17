#include <iostream>
#include "annealing.h"

using namespace std;
/*--------------------------------------------------------------------*/
/*State class*/
/*--------------------------------------------------------------------*/
State::~State()
{}
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
/*--------------------------------------------------------------------*/
/*
 * Annealing configuration 
 */
Annealing::Annealing(double T_s, double T_e, double cooling, int equilibrium)
:T_s(T_s), T_c(T_s), T_e(T_e), cooling(cooling), m_equilibrium(equilibrium), m_ecount(0), m_eaccepted(0)
{}
/*--------------------------------------------------------------------*/
State* Annealing::anneal(State* init){
	
	State 	*cstate = init, *sbest = init, *nstate;

        while(!frozen()){

                while(!equilibrium()){
			nstate = transform(cstate);
			m_ecount++;		
                }
		cool();
        }
}
/*--------------------------------------------------------------------*/
bool Annealing::equilibrium(){
	if(m_eaccepted > m_equilibrium || m_ecount > 2*m_equilibrium) return true;
	return false;
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
State* Annealing::transform(State* state){
}
/*--------------------------------------------------------------------*/
