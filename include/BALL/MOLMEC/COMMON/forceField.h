// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: forceField.h,v 1.19 2002/12/12 09:48:47 oliver Exp $

#ifndef BALL_MOLMEC_COMMON_FORCEFIELD_H
#define BALL_MOLMEC_COMMON_FORCEFIELD_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_KERNEL_SYSTEM_H
#	include <BALL/KERNEL/system.h>
#endif

#ifndef BALL_DATATYPE_OPTIONS_H
#	include <BALL/DATATYPE/options.h>
#endif

#ifndef BALL_CONCEPT_TIMESTAMP_H
#	include <BALL/CONCEPT/timeStamp.h>
#endif

#ifndef BALL_MOLMEC_PARAMETER_FORCEFIELDPARAMETERS_H
#	include <BALL/MOLMEC/PARAMETER/forceFieldParameters.h>
#endif

#ifndef BALL_MOLMEC_PARAMETER_ATOMTYPES_H
#	include <BALL/MOLMEC/PARAMETER/atomTypes.h>
#endif

#ifndef BALL_MOLMEC_COMMON_PERIODIC_BOUNDARY_H
#	include <BALL/MOLMEC/COMMON/periodicBoundary.h>
#endif

#ifndef BALL_MOLMEC_COMMON_ATOMVECTOR_H
#	include <BALL/MOLMEC/COMMON/atomVector.h>
#endif

#include <vector>

namespace BALL 
{

	class ForceFieldComponent;

	/**	Force field class.
			This class is used to represent a general force field.
			Each force field by itself is composed by several
			different force field components which are represented
			by \Ref{ForceFieldComponent} objects.\\
			Each ForceField object provides a list of components
			which may be manipulated by the user to generate the
			force field he needs.\\
			ForceField only represents a baseclass to the specific force field
			implementations (e.g. \Ref{AMBER}) and implements the common interface 
			and the neccessary mechanisms to administer the force field	components.\\
			A typical force field contains a small number of components (e.g. bond stretch,
			bend, torsion and non-bonding interactions). 
			A specialized forcefield has to implement each of these components (by deriving them
			from \Ref{ForceFieldComponent} and must be derived from ForceField.
			Basically only the default constructor for the new forcefield has to
			be modified to create an instance of each of the components and 
			register them by calling \Ref{insertComponent}. But in order to implement
			the setup methods of the force field components efficiently, 
			jobs like assigning atom types, reading parameter files and the such should be
			provided for all force field components by the corrseponding ForceField
			object. This should be implemented in the force field-specific \Ref{specificSetup} 
			method.\\
			For an efficient and easy to use implementation of a forcefield
			parameter file, please refer to \Ref{ForceFieldParameters} and its
			related objects.\\
			Each force field provides as well energy and its derivatives, the force
			on each atom. A calculation of the energy is done by calling
			\Ref{updateEnergy}. This method iterates over the list of force field
			components and invokes the updateEnergy method of each of these components.
			The total energy may then be retrieved by calling \Ref{getEnergy}.\\
			Analogously, a force calculation is performed by invoking \Ref{updateForces}.
			\Ref{getForces} returns a pointer to an array containing the forces
			for each atom.\\
			{\bf Definition:} \URL{BALL/MOLMEC/COMMON/forceField.h}
	*/
	class ForceField
	{
		public:

		friend class ForceFieldComponent;

		/**	@name	Type Definitions
		*/
		//@{

		/**	Atom pair vector.
				This type is used to represent "pair lists". In fact, it is
				a {\tt vector} of {\tt pair}s of atom pointers.
		*/
		typedef vector<pair<Atom*, Atom*> >	PairVector;

		//@}
		/**	@name	Constructors and Destructors	
		*/
		//@{
		
		BALL_CREATE(ForceField)

		/**	Default constructor.
		*/
		ForceField();

		/**	Constructor.
		*/
		ForceField(System& system);

		/**	Constructor.
		*/
		ForceField(System& system, const Options& options);

		/**	Copy constructor
		*/
		ForceField(const ForceField& force_field);

		/**	Destructor.
		*/
		virtual ~ForceField();

		/**	Clear method.
		*/
		virtual void clear()
			throw();

		//@}
		/**	@name	Assignments 
		*/
		//@{

		/**	Assignment operator
		*/
		ForceField&	operator = (const ForceField& force_field);

		//@}
		/**	@name	Debugging and Diagnostics 
		*/
		//@{

		/**	Is the force field valid?
		*/
		bool isValid() const
			throw();

		//@}
		/**	@name	Setup methods 
		*/
		//@{

		/**	Sets up the force field and its components.
		*/
		bool setup(System& system);

		/**	Sets up the force field and its components.
		*/
		bool setup(System& system, const Options& options);

		/**	Force field specific setup.
				This method is called by setup.
		*/
		virtual bool specificSetup();

		//@}
		/**	@name	Accessors 
		*/
		//@{

		/**	Sets the force field name.
		*/
		void setName(const String& name);
		
		/**	Returns the force field name
		*/
		String getName() const;
		
		/**	Returns the number of atoms stored in the force field
		*/
		Size getNumberOfAtoms() const;

		/**	Returns the number of non-fixed atoms stored in the force field.
				If the option {\tt SELECTION_FIXED} is set to {\bf true} or
				{\tt SELECTION_MOVABLE} is set to {\bf true} the atom array
				is split. The first section (indices 0 to \Ref{getNumberOfMovableAtoms})
				contains the atoms that are to be moved, the rest of the array contains
				the fixed atoms.
		*/
		Size getNumberOfMovableAtoms() const;

		/**	Returns a reference to the atom vector
		*/
		const	AtomVector& getAtoms() const;

		/**	Returns a pointer to the system
		*/
		System* getSystem();

    /** Returns a const pointer to the system
    */
    const System* getSystem() const;

		/**	Return the status of the selection mechanism
		*/
		bool getUseSelection();

		/**	Set the status of the selection mechanism
		*/
		void setUseSelection(bool use_selection);

		/**	Returns a pointer to the parameter file
		*/
		ForceFieldParameters& getParameters();

		/**	Returns the number of components registered by the force field.
		*/
		Size countComponents() const;

		/**	Return the point of time of the last call to update.
				ForceField contains a time stamp which is used to determine
				whether the selection or even the topology of the system
				has changed. Every time update is called, the 
				\Ref{update_time_stamp_} is updated. Similarly, all setup methods
				update the \Ref{setup_time_stamp_}
		*/
		const TimeStamp& getUpdateTime() const
			throw();
		
		/**	Return the point of time of the last call to setup.
				ForceField contains a time stamp which is used to determine
				whether the selection or even the topology of the system
				has changed. Every time update is called, the 
				\Ref{update_time_stamp_} is updated. Similarly, all setup methods
				update the \Ref{setup_time_stamp_}
		*/
		const TimeStamp& getSetupTime() const
			throw();
		
		/**	Insert a new component into the force field's component list.
		*/
		void insertComponent(ForceFieldComponent* force_field_component);

		/**	Remove a component from the force field's component list.
		*/
		void removeComponent(const ForceFieldComponent* force_field_component);

		/**	Remove a component from the force field's component list.
		*/
		void removeComponent(const String& name);

		/**	Return a pointer to the specified force field component.
				If the specified index does not exist, 0 is returned.
				The given index should be smaller than the value returned by
				countComponents. The first component in the list has the index zero.
		*/
		ForceFieldComponent* getComponent(const Size	index) const;

		/**	Return a pointer to the specified force field component.
				If a component with the specified name does not exist, 0 is returned.
		*/
		ForceFieldComponent*	getComponent(const String& name) const;

		/**	Return the sum of energies of all registered force field components. 
				No calculation will be performed. This method simply returns the 
				last value for the total energy calculated by updateEnergy.
				@return	double - energy in kJ/mol
		*/
		double getEnergy() const;

		/**	Calculate the sum of energies of all force field components and returns its value.
		*/
		double updateEnergy();

		/**	Calculate the forces caused by each component and updates the current forces.
		*/
		void updateForces();

		/**	Calculates the RMS of the current gradient
		*/
		double getRMSGradient() const;

		/**	Return the update frequency for pair lists etc.
				This method is used by minimizers or the MD simulation to determine the number
				of iterations between two calls to \Ref{update}.
		*/
		virtual Size getUpdateFrequency() const;

		/**	Update internal data structures.
				The force field may use this method to update internal data structures
				(e.g. pair lists) periodically. The MD simulation class as well as the minimizer classes
				use \Ref{getUpdateFrequency} to determine the number of iterations
				between two calls to update.\\
				The default implementation calls \Ref{ForceFieldComponent::update} for
				each component in the force field.
		*/
		virtual void update();

		//@}
		/**	@name	Public Attributes
		*/
		//@{
		
		/**	Force field options
		*/
		Options	options;

		/**	Periodic boundary
		*/
		PeriodicBoundary	periodic_boundary;

		//@}

		protected:

		/*_	Collect all atoms into the atoms_ vector.
		*/
		void collectAtoms_(const System& system);

		/*_	Sort the atom vector wrt selection.
		*/
		void sortSelectedAtomVector_();
		
		/*_	@name	Protected Attributes
		*/
		//_@{

		/*_	The system the force field is bound to
		*/
		System*	system_;

		/*_	The atoms in the simulated system
		*/
		AtomVector	atoms_;

		/*_ An object containing the force field parameters read from a file
		*/
		ForceFieldParameters	parameters_;	

		/*_	The boolean variable indicates if the setup of the force field was successful
		*/
		bool 	valid_;

		/*_ The force field name
		*/
		String	name_;

		/*_	The total energy
		*/
		double	energy_;
		
		/*_	The components of the force field
		*/
		vector<ForceFieldComponent*>	components_;

		/*_	The number of movable atoms in the force field
		*/
		Size	number_of_movable_atoms_;

		/*_	Are atoms in the system selected?
		*/
		bool	use_selection_;

		/*_	The time of the last call to update.
		*/
		TimeStamp	update_time_stamp_;

		/*_	The time of the last call to setup.
		*/
		TimeStamp	setup_time_stamp_;

		//_@}
	};

} // namespace BALL

#endif // BALL_MOLMEC_COMMON_FORCEFIELD_H
