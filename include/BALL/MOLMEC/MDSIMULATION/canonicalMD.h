// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: canonicalMD.h,v 1.22 2003/03/26 13:56:41 anhi Exp $

#ifndef BALL_MOLMEC_MDSIMULATION_CANONICALMD_H   
#define BALL_MOLMEC_MDSIMULATION_CANONICALMD_H   

// Include all necessary BALL headers 
#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_KERNEL_SYSTEM_H
#	include <BALL/KERNEL/system.h>
#endif

#ifndef BALL_KERNEL_ATOM_H         
#	include <BALL/KERNEL/atom.h>
#endif

#ifndef BALL_MATHS_VECTOR3_H         
#	include <BALL/MATHS/vector3.h>
#endif

#ifndef BALL_DATATYPE_OPTIONS_H
#	include <BALL/DATATYPE/options.h>
#endif

#ifndef BALL_MOLMEC_PARAMETER_FORCEFIELDPARAMETER_H
#	include <BALL/MOLMEC/PARAMETER/forceFieldParameters.h>
#endif

#ifndef BALL_MOLMEC_PARAMETER_ATOMTYPES_H
#	include <BALL/MOLMEC/PARAMETER/atomTypes.h>
#endif

#ifndef BALL_MOLMEC_COMMON_PERIODIC_BOUNDARY_H
#	include <BALL/MOLMEC/COMMON/periodicBoundary.h>
#endif

#ifndef BALL_MOLMEC_COMMON_FORCEFIELD_H
#	include <BALL/MOLMEC/COMMON/forceField.h>
#endif

#ifndef BALL_MOLMEC_MDSIMULATION_MOLECULARDYNAMICS_H
#	include <BALL/MOLMEC/MDSIMULATION/molecularDynamics.h>
#endif


#include <vector>

namespace BALL 
{
	/** A MD simulation in the canoncial ensemble.
			A class for doing molecular dynamics simulations      
			according to the principle of a canonical ensemble (NVT), i.e., 
			the temperature is kept constant. 
			This is achieved via the velocity rescaling proposed by
			Berendsen et al., J. Chem. Physics, 81:3684, 1984.
			Note that this approach does  not give all properties of a
			true canonical system. In particular, the heat capacity 
			cannot be calculated!	 \par
			
    	\ingroup  MDSimulation
	*/
  class CanonicalMD 
		: public MolecularDynamics
	{
    public: 


    /** A local auxiliary class
    */
    struct Aux_Factors
    {
      double factor1, factor2; 
    }; 
    

    /** @name Constructors and Destructors
    */
    //@{

    BALL_CREATE(CanonicalMD)

    /** The default constructor with no arguments.
    */
    CanonicalMD()
			throw();

    /** This constructor expects a force field .
        The force field's options are used and no saving of snapshots is done.
				@param myforcefield the forcefield we need for the simulation
    */
    CanonicalMD(ForceField& myforcefield)
			throw();

    /** This constructor expects a force field and a snapshot manager.
        The force field's options are used. 
				@param myforcefield the forcefield to use in the simulation
				@param ssm  a pointer to the SnapShotManager which will be used to 
				create trajectory files
    */
    CanonicalMD(ForceField& myforcefield, SnapShotManager* ssm)
			throw();

    /** This constructor wants a force field, a snapshot manager and new options.
				@param myforcefield the forcefield which is to be used in the	simulation
				@param ssm a pointer to the SnapShotManager used for creating 
								trajectory files
				@param myoptions arbitrary options that are to be used by this 
								instance instead of those defined therein
    */
    CanonicalMD(ForceField& myforcefield, SnapShotManager* ssm, 
								const Options& myoptions)
			throw();

    /** The standard copy constructor.
    */
    CanonicalMD(const CanonicalMD &rhs, bool deep = true)
			throw();

    /** The destructor.
    */
    virtual ~CanonicalMD()
			throw();

    //@}
    /** @name Assignments
    */
    //@{

    /// Assignment operator.
    CanonicalMD &operator = (const CanonicalMD& rhs)
			throw();

    //@}
    /** @name Setup methods
    */
    //@{

    /** This method does general setup things.
    */
    virtual bool setup(ForceField &myforcefield, SnapShotManager* ssm)
			throw();

    /** This method does general setup things. 
    */
    virtual bool setup(ForceField &myforcefield, SnapShotManager* ssm,
				const Options &myoptions)
			throw();

    /** This method is meant for additional preparations apart from those done in setup.
				@return bool, <b>true</b> if specificSetup() was successful
    */
    virtual bool specificSetup()
			throw();

    //@} 
    /** @name Accessors
		*/
		//@{

    /** This method sets a new relaxation time for the coupling to an external heat bath.
				@param time the time in [unit] 
    */
    void setBathRelaxationTime(double time)
			throw();

    /** This method gets the current value for heat bath coupling.
				@return the time in [unit]
    */
    double getBathRelaxationTime() const
			throw();

    /** Set a new time step for the numerical integration.
    */
    virtual void setTimeStep(double time)
			throw();

    /**  This method does the actual simulation stuff. 
         It runs for the indicated number of iterations. 
         If restart is true, the counting of iterations starts with the 
         number of the last iteration in the previous run.  
				 @param number the number of iterations that have to be simulated 
				 @param restart flag for restarting the simulation
    */
    virtual void simulateIterations(Size number, bool restart = false)
			throw();

    //@}

    protected:

    //_ @name Protected methods
    //_@{

    /*_ A protected method for calculating some factors that are needed all the time.
    */
    void calculateFactors_()
			throw();

    //_@}
    //_  @name Protected Attributes
    //_@{

    //_  The coupling parameter to the heat bath
    double bath_relaxation_time_; 

    //_  This vector contains special precomputed factors 
    vector<Aux_Factors> mass_factor_; 

    //_@} 

    };  // end of class CanonicalMD  
  } // end of namespace BALL 

#endif // BALL_MOLMEC_MDSIMULATION_CANONICALMD_H
