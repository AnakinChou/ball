// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: atomVector.h,v 1.18 2003/03/03 14:17:56 anhi Exp $

#ifndef BALL_MOLMEC_COMMON_ATOMVECTOR_H 
#define BALL_MOLMEC_COMMON_ATOMVECTOR_H 

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_MATHS_VECTOR3_H
#	include <BALL/MATHS/vector3.h>
#endif

namespace BALL 
{ 
    /**  \addtogroup  MolmecCommon
     *  @{
     */	
	class Gradient;
	class Atom;
	class Composite;
	
	/**	Atom vector class.
			This class is used to store atom pointers.  \par
			<b>Definition:</b>BALL/MOLMEC/COMMON/atomVector.h
	*/
	class AtomVector
		:	private ::std::vector<Atom*>
	{
    public:

    BALL_CREATE_DEEP(AtomVector)

		/**	@name Type definitions
		*/
		//@{
		
		/**	Iterator type
		*/
		typedef ::std::vector<Atom*>::iterator Iterator;

		/**	Const iterator type.
		*/
		typedef ::std::vector<Atom*>::const_iterator ConstIterator;

		//@}
    /**	@name	Constructors and Destructors	
    */
    //@{

    /**	Default constructor.
    */
    AtomVector();

    /**	Construct from a Composite.
				This method constructs an AtomVector from a given composite
				using selection or not.
				@param	composite the composite containing the atoms
				@param	selected_only store the selected atoms only (if <b>true</b>)
    */
    AtomVector(const Composite& composite, bool selected_only = false);

    /**	Copy constructor
    */
    AtomVector(const AtomVector& atoms, bool deep = true);

    /**	Destructor.
    */
    virtual ~AtomVector();

		/**	Clear the vector.
				Removes all atoms from the vector
		*/
		using std::vector<Atom*>::clear;

    //@}
    /**	@name	Assignments 
    */
    //@{

    /**	Assignment operator
    */
    const AtomVector& operator = (const AtomVector& rhs);

		/**	Assign from another atom vector
		*/
		void set(const AtomVector& atoms);

    /**	Assignment operator for Composites.
				Calls  \link set set \endlink  and extracts all atoms, if none of the atoms in 
				<tt>composite</tt> are selected or the selected atoms	only 
				(if any atom is selected in <tt>composite</tt>.
				The implementation calls <tt> \link set</tt>(<tt>rhs set</tt>(<tt>rhs \endlink , {\tt rhs</tt>. \link containsSelection containsSelection \endlink ())</tt>.
				@see	Selectable
    */
    const AtomVector& operator = (const Composite& rhs);

		/**	Assign from a composite.
				This method iterates over the composite tree and extracts all atoms. 
				@param	selected_only extract only selected atoms if set to <b>true</b>
		*/
		void set(const Composite& composite, bool selected_only = false);

    //@}
    /**	@name	Accessors 
    */
    //@{

		/**	Return the vector size;
		*/
		using ::std::vector<Atom*>::size;

		/// Random access operator
		// ?????: problem with GCC3 using std::vector<Atom*>::operator [];
		Atom*       & operator [] (int i)       { return ::std::vector<Atom*>::operator [] (i); }
		Atom* const & operator [] (int i) const { return ::std::vector<Atom*>::operator [] (i); }
		
		/**	Store the current atom positions.
				AtomVector also contains an array with positions for each atom.
				 \link moveTo moveTo \endlink  considers these coordinates as start coordinates.
		*/
		void savePositions();

		/**	Resets the atom positions to the saved positions.
				If coordinates weres stored using  \link savePositions savePositions \endlink , the atoms
				coordinates are reset to the saved positions.
				If no savedPositions exist the coordinates remain unchanged.
		*/
		void resetPositions();

		/**	Move all atoms along a direction vector.
				The method translates all atoms a long a given direction.
				The direction vector is multiplied with a step length <tt>step</tt>.
				If a saved position exists ( \link savePositions savePositions \endlink ), it is used as a start
				position (i.e. the final positions are $\vec{\mathrm{start}} + \mathrm{step} \vec{\mathrm{direction}}$).
				Otherwise, the current atom positions are used.
				If the gradient's size differs from the number of atoms, nothing is done.
		*/
		void moveTo(const Gradient& direction, float step = 1.0);

		/**	Insert an atom pointer.
		*/
		using ::std::vector<Atom*>::push_back;

		/**	Resize the vector.
		 *  If the vector is resized to to more elements, than are contained,
		 *  it is filled with NullPointers.
		*/
		void resize(Size new_size);

    //@}
		/**	@name	Iteration
		*/
		//@{

		/**	Return an iterator, pointing to the first atom pointer.
		*/
		//?????: GCC3 using std::vector<Atom*>::begin;
					iterator begin()			 { return ::std::vector<Atom*>::begin(); }
		const_iterator begin() const { return ::std::vector<Atom*>::begin(); }

		/**	Return an iterator, pointing behind the last atom pointer.
		*/
		//?????: GCC3 using std::vector<Atom*>::end;
					iterator end()			 { return ::std::vector<Atom*>::end(); }
		const_iterator end() const { return ::std::vector<Atom*>::end(); }

		//@}
		
		protected:

		/*_	The saved positions.
		*/
		std::vector<Vector3>	saved_position_;
  };

     /** @} */
} // end of namespace BALL

#endif // BALL_MOLMEC_MINIMIZATION_GRADIENT_H 
