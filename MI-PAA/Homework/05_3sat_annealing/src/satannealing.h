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
			int 				getMinWeight() const;
			int 				getMaxWeight() const;
			int 				getSumWeights() const;
			vector<int>			getWeights() const;
			vector<vector<int>>	getFormule() const;
					
			State * 			solveAnnealing(double tstart, double tend, double cool, int equilibrium);

	private:

			bool 				parseDIMACS(string file);

			int					vcount;
			int					ccount;	

			vector<int>			weights;
			int 				m_minweight;
			int 				m_maxweight;
			int 				m_sumweights;

			vector<vector<int>>	formule;

			string 				type;
			string  			m_source;
			
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
				int 		getUnfulfiled() const;
				int 		getWeight() const;

	private:
		virtual int			compare(const State& state) const;
		virtual string		print() const;

			int 			clausulesFulfilled();

			int 			m_criterium;
			int 			m_weight;						

			bool			m_solution;


			vector<bool>	m_configuration;
			vector<bool>	m_clausulemap;
			vector<int> 	m_nclausule;

			SatInstance*	m_instance;
};
/*----------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------*/
