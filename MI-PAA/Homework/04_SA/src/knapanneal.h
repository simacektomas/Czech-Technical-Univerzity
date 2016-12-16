/*-------------------------------------------------------------------------------------------------*/
class KnapState: public State {
        public:
                                KnapState(int value){};
                                KnapState(int size, bool* configuration);
                                ~KnapState();
    
                virtual double  criterium() const;
                virtual bool    solution() const;
                virtual State*  adjecency() const;
        private:
                virtual int     compare(const State& state) const;
                virtual string  print() const;

		bool *          configuration;
        	int             size;
};
/*-------------------------------------------------------------------------------------------------*/
