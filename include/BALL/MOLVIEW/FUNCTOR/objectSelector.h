// $Id: objectSelector.h,v 1.3.4.3 2002/11/09 20:57:51 amoll Exp $

#ifndef BALL_MOLVIEW_FUNCTOR_OBJECTSELECTOR_H
#define BALL_MOLVIEW_FUNCTOR_OBJECTSELECTOR_H

#ifndef BALL_MOLVIEW_FUNCTOR_ATOMBONDMODELBASEPROCESSOR_H
#	include <BALL/MOLVIEW/FUNCTOR/atomBondModelBaseProcessor.h>
#endif

namespace BALL
{
	namespace MOLVIEW
	{
		/** ObjectSelector class.
				The class ObjectSelector is responsible for selecting
				\Ref{Composite} objects. The method \Ref{Selectable::select} or 
				\Ref{Selectable::deselect} will be called from each processed \Ref{Composite} object
				according to the state of {\em *this} objectSelector.
				If \Ref{GeometricObject} objects are found their color will be set to the 
				selected color if they are selected.
				See \Ref{Selectable} for information about selecting or deselecting objects.
				for information about the processor concept see \Ref{Processor} in tbe BALL 
				documentation. \\
				{\bf Definition:} \URL{BALL/MOLVIEW/FUNCTOR/objectSelector.h}
				@see  Selectable
		*/
		class ObjectSelector: public AtomBondModelBaseProcessor
		{
			public:

			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new objectSelector. Set the state of {\em *this} 
					objectSelector to: select objects. See concept of
					\Ref{Selectable} for information concerning selection of objects.
					@return      ObjectSelector new constructed objectSelector
					@see         AtomBondModelBaseProcessor
					@see         Selectable
			*/
			ObjectSelector()
				throw();

			/** Copy constructor.
					Construct new objectSelector by copying the objectSelector
					{\em selector}.
					@param       selector the objectSelector to be copied
					@param       deep make a deep (={\tt true}) or shallow (={\tt false}) copy of {\em selector}
					@return      ObjectSelector new constructed objectSelector copied from {\em selector}
					@see         AtomBondModelBaseProcessor
			*/
			ObjectSelector(const ObjectSelector& selector, bool deep = true)
				throw();

			//@}
			/** @name Destructors 
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} objectSelector.
					Calls \Ref{destroy}.
					@see         destroy
			*/
			virtual ~ObjectSelector()
				throw();

			/** Explicit default initialization.
					Set state of {\em *this} objectSelector to: select objects.
					See concept of \Ref{Selectable} for information concerning selection 
					of objects.
					Calls \Ref{AtomBondModelBaseProcessor::clear}.
					@see  AtomBondModelBaseProcessor
					@see  Selectable
			*/
			virtual void clear()
				throw();

			/** Explicit destructor.
					Empty for further purpose.
			*/
			virtual void destroy()
				throw();

			//@}
			/**	@name	Assignment
			*/
			//@{

			/** Assignment.
					Assign the objectSelector {\em selector} to {\em *this} 
					objectSelector.
					Initializes the \Ref{AtomBondModelBaseProcessor} of {\em *this}
					objectSelector to that of {\em selector}.
					Calls \Ref{AtomBondModelBaseProcessor::set}.
					@param       selector the objectSelector to be copied 
					@param       deep make a deep (={\tt true}) or shallow (={\tt false}) copy of {\em selector}
					@see         AtomBondModelBaseProcessor
			*/
			void set(const ObjectSelector& selector, bool deep = true)
				throw();

			/** Assignment operator.
					Assign the objectSelector {\em selector} to {\em *this} 
					objectSelector.
					Initializes the \Ref{AtomBondModelBaseProcessor} of {\em *this} 
					objectSelector	to that of {\em selector}.
					Calls \Ref{set}.
					The assignment will be deep.
					@param       selector the objectSelector to be copied
					@return      ObjectSelector& constant reference of {\em *this} objectSelector
					@see         set
			*/
			const ObjectSelector& operator = (const ObjectSelector& selector)
				throw();

			/** Copying.
					Copy {\em *this} objectSelector to the objectSelector
					{\em selector}.
					Initializes the \Ref{AtomBondModelBaseProcessor} of {\em *this} objectSelector
					to that of {\em selector}.
					Calls \Ref{set}.
					@param       selector the objectSelector to be assigned to
					@param       deep make a deep (={\tt true}) or shallow (={\tt false}) copy of {\em selector}
					@see         set
			*/
			void get(ObjectSelector& selector, bool deep = true) const
				throw();

			/** Swapping of objectSelector's.
					Swap the \Ref{AtomBondModelBaseProcessor} and the state of {\em *this}
					objectSelector	with that of {\em selector}.
					Calls \Ref{AtomBondModelBaseProcessor::swap}
					@param       selector the objectSelector being swapped with {\em *this} atomBondModelBaseProcessor 
					@see         AtomBondModelBaseProcessor
			*/
			void swap(ObjectSelector& selector)
				throw();
			
			//@}
			/**	@name Processor specific methods
			*/
			//@{

			/** Start method.
					Calls \Ref{AtomBondModelBaseProcessor::start}.
					@return bool {\tt true} if the start of {\em *this} objectSelector was successful, {\tt false} otherwise
					@see    operator()
					@see    AtomBondModelBaseProcessor
			*/
			virtual bool start();
			
			/** Finish method.
					This method will be internally called from the processor mechanism if the processor
					has finished processing the \Ref{Composite} tree.
					All previously inserted \Ref{Atom} objects (inserted with the method \Ref{insertAtom_})
					will be processed. The connecting \Ref{Bond} objects will be selected or
					deselected according to the state of {\em *this} objectSelector.
					@return bool {\tt true} if the finish of {\em *this} objectSelector was successful, {\tt false} otherwise
					@see    select
					@see    deselect
					@see    Selectable
					@see    insertAtom_
					@see    operator()
					@see    Atom
					@see    Bond
					@see    Composite
			*/
			virtual bool finish();

			/**	Operator method.
					This method iterates over each \Ref{Composite} object reachable in the 
					\Ref{Composite} tree. If {\em composite} is of kind \Ref{Atom} this atom is
					selected according to the state of {\em *this} objectSelector
					and is inserted with the method \Ref{insertAtom_}.
					@param  composite the \Ref{Composite} object that will be processed
					@return Processor::Result the result of {\em *this} geometricObjectSelectot
					@see    select
					@see    deselect
					@see    Selectable
					@see    start
					@see    finish
					@see    insertAtom_
			*/
			virtual Processor::Result operator() (Composite& composite);

			//@}
			/**	@name	debuggers and diagnostics
			*/
			//@{

			/** Internal value dump.
					Dump the current state of {\em *this} objectSelector to 
					the output ostream {\em s} with dumping depth {\em depth}.
					Calls \Ref{AtomBondModelBaseProcessor::dump}.
					@param   s output stream where to output the state of {\em *this} objectSelector
					@param   depth the dumping depth
					@see     AtomBondModelBaseProcessor
			*/
			virtual void dump(std::ostream& s = std::cout, Size depth = 0) const
				throw();

			//@}
		};

		/** Deselector class
		 		This class behaves in the same way as its parent class ObjectSelector, but
				it deselects atoms and bonds.
		*/
		class ObjectDeselector : public ObjectSelector
		{
			virtual bool finish();
		};

	} // namespace MOLVIEW
} // namespace BALL

#endif // BALL_MOLVIEW_FUNCTOR_OBJECTSELECTOR_H
