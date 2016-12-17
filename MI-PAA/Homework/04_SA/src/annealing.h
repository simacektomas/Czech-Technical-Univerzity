using namespace std;
/*-------------------------------------------------------------------------------------------------*/
/*
 * Represent state of any problem state space,
 * each state is one configuration of problem instance and don't have to be
 * solution.
 */
class State {
        public:
		virtual			~State();

                virtual bool            solution() const = 0;                                   //check if the state is solution of the problem
                virtual double          criterium() const = 0;                                  //return value of optimalization criterium
                virtual State*          adjecency() const = 0;
                // comparing two states
                friend  bool            operator>(const State& left, const State& right);
                friend  bool            operator<(const State& left, const State& right);
                friend  ostream&        operator<<(ostream& os, const State& state);
        private:
                virtual int             compare(const State& state) const = 0;
                virtual string          print() const = 0;
};
/*-------------------------------------------------------------------------------------------------*/
/*
 *                         configuration
 *                      init state <-- init
 *                      curr state <-- init
 *                      best state <-- init
 *                      init T     <-- T
 *                              |
 *      |-----------------------|
 *      |                       |
 *      |                    frozen() ---[yes]-----> result
 *      |       |---------------|[no]
 *      |       |               |
 *      |       |               |
 *      |       |          equilibrium() ---------------------[yes]
 *      |       |               |[no]                           |
 *      |       |               |                               |
 *      |       |  curr state <-- curr state.try();             |
 *      |       |               |                               |
 *      |       |               |                               |
 *      |       |               |                               |
 *      |       |   curr state > best state ---[yes]            |
 *      |       |               |[no]           |               |
 *      |       |               |   best state <-- curr state   |
 *      |       |---------------|---------------|               |
 *      |                                                       |
 *      |-------------------------------------------------------|
 */
/*-------------------------------------------------------------------------------------------------*/
/*
 *
 *
 *
 */
class Annealing {
        public:
                        Annealing(double T_s, double T_e, double cooling, int equilibrium);
                State*  anneal(State* init);
        private:
                bool    equilibrium();
                bool    frozen();
                void    cool();
                State*  transform(State* state);

                double  T_s;                            //starting temperature
                double  T_c;                            //current temperature
                double  T_e;                            //ending temperature
                double  cooling;                        //how fast we are cooling T = T*cooling
		int	m_equilibrium;			//equilibrium parameter
		int	m_ecount;			//equilibrium cycles
		int	m_eaccepted;			//equilibrium accepted states
};
/*-------------------------------------------------------------------------------------------------*/


