// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: removeModel.h,v 1.11 2002/12/12 09:48:48 oliver Exp $

#ifndef BALL_MOLVIEW_FUNCTOR_REMOVEMODEL_H
#define BALL_MOLVIEW_FUNCTOR_REMOVEMODEL_H

#ifndef BALL_MOLVIEW_FUNCTOR_ATOMBONDMODELBASEPROCESSOR_H
#	include <BALL/MOLVIEW/FUNCTOR/atomBondModelBaseProcessor.h>
#endif

namespace BALL
{
	namespace MOLVIEW
	{
		/** RemoveModel class.
				The class RemoveModel is a processor that is responsible for removing models.
				It is started on a \Ref{Composite} object and removes all geometric primitives
				that are located on \Ref{Atom} and \Ref{Bond} objects and that have a model
				property. The method used for this action is \Ref{removeGeometricObjects_}.
				For information about the processor concept see \Ref{Processor} in tbe BALL
				documentation. \\
				{\bf Definition:} \URL{BALL/MOLVIEW/FUNCTOR/removeModel.h}
		*/
		class RemoveModel: public AtomBondModelBaseProcessor
		{
			public:

			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new removeModel.
					@return      RemoveModel new constructed removeModel
					@see         AtomBondModelBaseProcessor
			*/
			RemoveModel()
				throw();

			/** Copy constructor.
					Construct new removeModel by copying the removeModel
					{\em add_van_der_waals_model}.
					@param       model the removeModel to be copied
					@param       deep make a deep (={\tt true}) or shallow (={\tt false}) copy of {\em model}
					@return      RemoveModel new constructed removeModel copied from {\em model}
					@see         AtomBondModelBaseProcessor
			*/
			RemoveModel
				(const RemoveModel& model, bool deep = true)
				throw();

			//@}
			/** @name Destructors 
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} removeModel.
					Calls \Ref{destroy}.
					@see         destroy
			*/
			virtual ~RemoveModel()
				throw();

			/** Explicit default initialization.
					Calls \Ref{AtomBondModelBaseProcessor::clear}.
					@see  AtomBondModelBaseProcessor
			*/
			virtual void clear()
				throw();

			/** Explicit destructor.
					Empty for further purpose.
			*/
			virtual void destroy()
				throw();

			//@}
			/**	@name Processor specific methods
			*/
			//@{
			
			/** Start method.
					Clear the \Ref{FindGeometricObjects}.
					Calls \Ref{AtomBondModelBaseProcessor::start}.
					@return bool {\tt true} if the start of {\em *this} removeModel was successful, {\tt false} otherwise
					@see    operator()
					@see    AtomBondModelBaseProcessor
					@see    getSearcher_
					@see    FindGeometricObjects
			*/
			virtual bool start();
			
			/** Finish method.
					This method will be internally called from the processor mechanism if the processor
					has finished processing the \Ref{Composite} tree.
					Iterates over all previously inserted \Ref{Atom} objects 
					(inserted with the method \Ref{insertAtom_}) and their reachable \Ref{Bond} objects
					and removes all \Ref{GeometricObject} objects with the method 
					\Ref{removeGeometricObjects_}.
					@return bool {\tt true} if the finish of {\em *this} removeModel was successful, {\tt false} otherwise
					@see    insertAtom_
					@see    operator()
					@see    removeGeometricObjects_
					@see    GeometricObject
					@see    Atom
					@see    Bond
					@see    Composite
			*/
			virtual bool finish();
			
			/**	Operator method.
					This method iterates over each \Ref{Composite} object reachable in the 
					\Ref{Composite} tree. If {\em composite} is of kind \Ref{Atom} than 
					\Ref{GeometricObject} objects are searched that are already appended to the atom
					object. This is accomplished with the \Ref{FindGeometricObjects} object accessed
					with the method \Ref{getSearcher_}.
					If geometric objects are available that have a model property that atom
					is inserted with the method \Ref{insertAtom_}. The removal of geometricObjects
					is done in the \Ref{finish} method.
					@param  composite the \Ref{Composite} object that will be processed
					@return Processor::Result the result of {\em *this} removeModel
					@see    start
					@see    finish
					@see    insertAtom_
					@see    FindGeometricObjects
					@see    getSearcher_
					@see    AtomBondModelBaseProcessor
					@see    GeometricObject
					@see    Composite
					@see    Atom
			*/
			virtual Processor::Result operator() (Composite& composite);

			//@}
			/**	@name	debuggers and diagnostics
			*/
			//@{

			/** Internal value dump.
					Dump the current state of {\em *this} removeModel to 
					the output ostream {\em s} with dumping depth {\em depth}.
					Calls \Ref{AtomBondModelBaseProcessor::dump}.
					@param   s output stream where to output the state of {\em *this} removeModel
					@param   depth the dumping depth
					@see     AtomBondModelBaseProcessor
			*/
			virtual void dump
				(std::ostream& s = std::cout, Size depth = 0) const
				throw();
			//@}

			private:
		};

	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIEW_FUNCTOR_REMOVEMODEL_H
