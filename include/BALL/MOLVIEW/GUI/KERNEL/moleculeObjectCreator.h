// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: moleculeObjectCreator.h,v 1.6 2002/12/12 09:48:52 oliver Exp $

#ifndef BALL_MOLVIEW_GUI_KERNEL_MOLECULEOBJECTCREATOR_H
#define BALL_MOLVIEW_GUI_KERNEL_MOLECULEOBJECTCREATOR_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_KERNEL_ATOM_H
#	include <BALL/KERNEL/atom.h>
#endif

#ifndef BALL_KERNEL_BOND_H
#	include <BALL/KERNEL/bond.h>
#endif

#ifndef BALL_KERNEL_FOREACH_H
#	include <BALL/KERNEL/forEach.h>
#endif

#ifndef BALL_KERNEL_MOLECULE_H
#	include <BALL/KERNEL/molecule.h>
#endif

#ifndef BALL_KERNEL_PROTEIN_H
# include <BALL/KERNEL/protein.h>
#endif

#ifndef BALL_KERNEL_SYSTEM_H
# include <BALL/KERNEL/system.h>
#endif

#ifndef BALL_VIEW_GUI_KERNEL_OBJECTCREATOR_H
#	include <BALL/VIEW/GUI/KERNEL/objectCreator.h>
#endif
  
namespace BALL
{

	namespace MOLVIEW
	{

		using VIEW::ObjectCreator;

		/** MoleculeObjectCreator class.
				The class MoleculeObjectCreator is a class for converting \Ref{PersistentObject}
				objects that represent molecular structures into \Ref{Composite} objects.
				Objects that do not represent molecular structures will not be converted.
				All necessary initialization and registration of molecular structure patterns
				will be done in the method \Ref{initPersistenceManager}.
				The conversion will be executed in the method \Ref{convertObject}.
				This class is used by the class \Ref{Server} to convert incoming
				\Ref{PersistentObject} objects to \Ref{Composite} objects. \\
				{\bf Definition:} \URL{BALL/MOLVIEW/GUI/KERNEL/moleculeObjectCreator.h}
		*/
		class MoleculeObjectCreator: public ObjectCreator
		{
			public:

			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Constructs new moleculeObjectCreator.
					@return      MoleculeObjectCreator new constructed moleculeObjectCreator
					@see         ObjectCreator
			*/
			MoleculeObjectCreator()
				throw();

			//@}

			/** @name Destructors 
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} moleculeObjectCreator.
					Calls \Ref{destroy}.
					@see         destroy
			*/
			virtual ~MoleculeObjectCreator()
				throw();

			/** Explicit default initialization.
					Calls \Ref{ObjectCreator::clear}.
					@see  ObjectCreator::clear
			*/
			virtual void clear()
				throw();

			/** Explicit destructor.
					Calls \Ref{ObjectCreator::destroy}.
					@see  ObjectCreator::destroy
			*/
			virtual void destroy()
				throw();
			//@}


			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{		
			/** Initializes the persistence manager.
					Initializes the \Ref{TextPersistenceManager} of {\em *this} moleculeObjectCreator.
					Registers all necessary molecular structures available in BALL.
					See \Ref{TextPersistenceManager} for information on how and why
					to register \Ref{PersistentObject} classes.
					@param  pm the \Ref{TextPersistenceManager} to be initialized
					@see    TextPersistenceManager
					@see    convertObject
			*/
			virtual void initPersistenceManager(TextPersistenceManager &pm)
				throw();

			/** Converts persistent objects.
					If {\em po} is an object that represents a molecular structure (an \Ref{Atom},
					\Ref{Protein} or \Ref{System}) it will be converted into a \Ref{Composite}
					object and returned. If it is none of the above {\tt 0} will be returned.
					See \Ref{TextPersistenceManager} for information
					on how to convert \Ref{PersistentObject} objects into other objects.				
					@param  po a reference to a \Ref{PersistentObject} to be converted
					@return Composite* a converted \Ref{Composite} object if {\em po} could successfully be converted into a \Ref{Composite} object
					@see    initPersistenceManager
			*/
			virtual Composite *convertObject(PersistentObject &po)
				throw();
			//@}
		};

	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIEW_GUI_KERNEL_MOLECULEOBJECTCREATOR_H 
