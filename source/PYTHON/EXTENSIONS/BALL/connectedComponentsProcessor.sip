// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id:$
//

%ModuleCode
	#include <BALL/STRUCTURE/connectedComponentsProcessor.h>
	using namespace BALL;
	typedef UnaryProcessor<Composite> CompositeProcessor;
%End



class ConnectedComponentsProcessor 
	: CompositeProcessor
{
%TypeHeaderCode
	#include <BALL/STRUCTURE/connectedComponentsProcessor.h>
	using namespace std;
	using namespace BALL;
	using namespace BALL::Exception;
	typedef UnaryProcessor<Composite> CompositeProcessor;	
	
	//typedef vector<Atom*>      Component;
	//typedef	vector<Component>	ComponentVector;
%End

	public:
		ConnectedComponentsProcessor();
		virtual ~ConnectedComponentsProcessor();
		
		void clear();
		virtual Processor::Result operator () (AtomContainer& /ac/);
%MethodCode
  sipRes = sipCpp->operator () (*a0);
%End
		Size getNumberOfConnectedComponents();

		//ComponentVector& getComponents();
		//const ComponentVector& getComponents() const;

		Size splitIntoMolecules(System& /to_split/);
		
};