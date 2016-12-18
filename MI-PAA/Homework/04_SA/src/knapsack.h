#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "annealing.h"

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

			int	getSize() const;
			int	getCapacity() const;
		KnapsackItem**	getItems() const;
			double	getTime() const;
		
			State*	solveAnnealing(double tstart, double tend, double cool, int equilibrium);

                friend ostream& operator << (ostream& stream, const KnapsackInstance & instance);
	private: 
		int m_id;
                int m_n;
                int m_capacity;
		std::chrono::duration<double> m_time;
                KnapsackItem ** m_items;
};
/*-------------------------------------------------------------------------------------------------*/
class KnapsackCollection {
	public:
				KnapsackCollection(string filename);
				~KnapsackCollection();

			void	solveAnnealing(double tstart, double tend, double cool, int equilibrium);

		friend ostream& operator<<(ostream& stream, const KnapsackCollection& collection);
	private:
		string 				m_filename;
		string 				m_solfile;
		vector<KnapsackInstance*> 	m_instances;
};
/*-------------------------------------------------------------------------------------------------*/
/*
 *
 *
 */
class KnapState: public State {
	public:
				KnapState(bool* configuration, KnapsackInstance* instance);
				KnapState(int price, int weight, bool* configuration, KnapsackInstance* instance);
				~KnapState();
		
		virtual double 	criterium() const;
		virtual bool 	solution() const;
		virtual State*	adjecency() const;
	private:
		virtual int 	compare(const State& state) const;
		virtual string 	print() const;

		int			m_price;
		int			m_weight;
		bool* 			m_configuration;
		KnapsackInstance*	m_instance;
		
		
};
/*-------------------------------------------------------------------------------------------------*/
