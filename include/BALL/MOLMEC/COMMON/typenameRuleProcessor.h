// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: typenameRuleProcessor.h,v 1.11 2003/08/26 08:04:26 oliver Exp $
//

// Molecular Mechanics: rule-based assignment of typenames 

#ifndef BALL_MOLMEC_COMMON_TYPENAMERULEPROCESSOR_H
#define BALL_MOLMEC_COMMON_TYPENAMERULEPROCESSOR_H

#ifndef BALL_MOLMEC_COMMON_RULEPROCESSOR_H
#	include <BALL/MOLMEC/COMMON/ruleProcessor.h>
#endif

namespace BALL 
{
	/**	Typename Rule Processor.
			
    	\ingroup  MolmecAssignment
	*/
	class TypenameRuleProcessor
		:	public RuleProcessor
	{
		public:

		BALL_CREATE(TypenameRuleProcessor)

		/**	Constructors and Destructors
		*/
		//@{

		/**	Default constructor
		*/
		TypenameRuleProcessor();
			
		/**	Detailed constructor
		*/
		TypenameRuleProcessor(INIFile& file, const String& prefix);
			
		/**	Copy constructor
		*/
		TypenameRuleProcessor(const TypenameRuleProcessor& rule_processor);

		/**	Destructor
		*/
		~TypenameRuleProcessor();

		//@}
		/**	@name Processor related methods
		*/
		//@{

		/**
		*/
		virtual Processor::Result operator () (Atom& atom);

		//@}

	};
} // namespace BALL


#endif // BALL_MOLMEC_COMMON_TYPENAMERULEPROCESSOR_H
