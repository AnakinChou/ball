// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: chargeRuleProcessor.h,v 1.12 2003/03/26 13:56:38 anhi Exp $
// Molecular Mechanics: rule-based assignment of charges 

#ifndef BALL_MOLMEC_COMMON_CHARGERULEPROCESSOR_H
#define BALL_MOLMEC_COMMON_CHARGERULEPROCESSOR_H

#ifndef BALL_MOLMEC_COMMON_RULEPROCESSOR_H
#	include <BALL/MOLMEC/COMMON/ruleProcessor.h>
#endif

namespace BALL 
{
	/**	Charge Rule Processor.
			
    	\ingroup  MolmecAssignment
	*/
	class ChargeRuleProcessor
		:	public RuleProcessor
	{
		public:

		BALL_CREATE(ChargeRuleProcessor)

		/**	Constructors and Destructors
		*/
		//@{

		/**	Default constructor
		*/
		ChargeRuleProcessor();
			
		/**	Detailed constructor
		*/
		ChargeRuleProcessor(INIFile& file, const String& prefix = "ChargeRules");
			
		/**	Copy constructor
		*/
		ChargeRuleProcessor(const ChargeRuleProcessor& rule_processor);

		/**	Destructor
		*/
		~ChargeRuleProcessor();

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


#endif // BALL_MOLMEC_COMMON_CHARGERULEPROCESSOR_H
