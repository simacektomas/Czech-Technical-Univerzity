#include <string>
#include <vector>
#include "annealing.h"

using namespace std;
/*----------------------------------------------------------------------------------------------------------------*/
/*reprezentation of DIMACS CNF file*/
class SatInstance {
	public:
								SatInstance(string file);
								~SatInstance();					
			int 				vCount() const;
			int 				cCount() const;
			vector<int>			getWeights() const;
			vector<vector<int>>	getFormule() const;
					
			State * 			solveAnnealing(double tstart, double tend, double cool, int equilibrium);

	private:

			bool 				parseDIMACS(string file);

			int					vcount;
			int					ccount;	

			vector<int>			weights;
			vector<vector<int>>	formule;

			string 				type;
			
			bool				valid;
};
/*----------------------------------------------------------------------------------------------------------------*/
class SatState: public State {
	public:
							SatState(vector<bool> configuration, SatInstance* instance);
		virtual				~SatState();
		virtual bool		solution() const;
		virtual double		criterium() const;
		virtual State*		adjecency() const;

	private:
		virtual int			compare(const State& state) const;
		virtual string		print() const;

				int 		clausulesFulfilled();

			int 			m_criterium;			

			bool			m_solution;

			vector<bool>	m_configuration;
			vector<bool>	m_clausulemap;
			vector<int> 	m_nclausule;

			SatInstance*	m_instance;
};
/*----------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------*/
