// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: bond.h,v 1.33 2003/02/25 15:53:11 sturm Exp $

#ifndef BALL_KERNEL_BOND_H
#define BALL_KERNEL_BOND_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_CONCEPT_PROPERTY_H
#	include <BALL/CONCEPT/property.h>
#endif

#ifndef BALL_CONCEPT_COMPOSITE_H
#	include <BALL/CONCEPT/composite.h>
#endif

#ifndef BALL_CONCEPT_ATOMCONTAINER_H
#	include <BALL/KERNEL/atomContainer.h>
#endif

#ifndef BALL_DATATYPE_STRING_H
#	include <BALL/DATATYPE/string.h>
#endif


#define BALL_BOND_DEFAULT_FIRST_ATOM    0
#define BALL_BOND_DEFAULT_SECOND_ATOM   0
#define BALL_BOND_DEFAULT_NAME          ""
#define BALL_BOND_DEFAULT_ORDER         ORDER__UNKNOWN
#define BALL_BOND_DEFAULT_TYPE          TYPE__UNKNOWN


namespace BALL 
{
    /** \ingroup Kernel
     *  @{
     */
	class Atom;
	class Fragment;
	class System;

	/** Bond class.
			An instance of Bond represents a bond between two atoms.
			Bond equality is defined as bond identity.
			A linear ordering of bonds is defined as the linear order of the  \link Object::Handle Object::Handle \endlink s.
			There can be only one bond between two atoms (double, triple, etc. bonds are represented
			using just one bond and an appropriate value for the bond order attribute, see  \link setBondOrder setBondOrder \endlink ).
			 \par
			The "first" and "second" atom are assigned in a unique way: the first atom is always
			the atom with the lower  \link Handle Handle \endlink  thant the second atom.
			 \par
			The "state" of a bond is defined by its attributes:
			\begin{itemize}
				\item "first atom" ( \link Bond::first_ Bond::first_ \endlink )
				\item "second atom" ( \link Bond::second_ Bond::second_ \endlink )
				\item "bond name" ( \link Bond::name_ Bond::name_ \endlink )
				\item "bond order" ( \link Bond::bond_order_ Bond::bond_order_ \endlink )
				\item "bond type" ( \link Bond::bond_type_ Bond::bond_type_ \endlink )
			\end{itemize}
			<b>Definition:</b> BALL/KERNEL/bond.h
	*/
	class Bond
		: public Composite,
			public PropertyManager
	{
		public:

		///
		friend class Atom;

		BALL_CREATE_DEEP(Bond)

		/**	@name	Exceptions
		*/
		//@{
			
		/**	Too many bonds created.
				This exception may be thrown by  \link createBond createBond \endlink  if the maximum number
				of bonds (8 bonds) is exceeded.
		*/
		class TooManyBonds
			:	public	Exception::GeneralException
		{
			public:
			TooManyBonds(const char* file, int line)
				throw();
			TooManyBonds(const char* file, int line, const Atom& atom1, const Atom& atom2)
				throw();
		};

		/**	Not bound to two atoms.
				This exception may be thrown by  \link getLength getLength \endlink  if this instance is not bound.
		*/
		class NotBound
			:	public	Exception::GeneralException
		{
			public:
			NotBound(const char* file, int line)
				throw();
		};

		//@}
		/** @name Type definitions 
		*/
		//@{

		/** Bond type.
		*/
		typedef short Order;
		typedef short Type;

		//@}  
		/** @name Enumerations 
		*/
		//@{
		
		/**	Predefined constants for the bond order 
		*/
		enum BondOrder
		{
			/// Default value
			ORDER__UNKNOWN        = 0,
			///
			ORDER__SINGLE         = 1,
			///
			ORDER__DOUBLE         = 2,
			///
			ORDER__TRIPLE         = 3,
			///
			ORDER__QUADRUPLE      = 4,
			///
			ORDER__AROMATIC       = 5,
			///
			NUMBER_OF_BOND_ORDERS
		};
			
		/**	Predefined constants for the bond type.
				Those are just defined for convenience but they are not
				used right now.
		*/
		enum BondType
		{
			/// 
			TYPE__UNKNOWN           = 0,
			///
			TYPE__COVALENT          = 1,
			///
			TYPE__HYDROGEN          = 2,
			///
			TYPE__DISULPHIDE_BRIDGE = 3,
			///
			TYPE__SALT_BRIDGE       = 4,
			///
			TYPE__PEPTIDE           = 5,
			
			///
			NUMBER_OF_BOND_TYPES
		};

		/** Predefined properties.
				Enumeration of all properties that are used by Bond.
		*/
		enum Property
		{
			NUMBER_OF_PROPERTIES = 0
		};
		//@}  

		/** @name Constructors and Destructors 
		*/
		//@{

		/** Default constructor.
				The state of this bond is:
				\begin{itemize}
					\item bond has no first atom (=0)
					\item bond has no second atom (=0)
					\item bond name is the empty string (="")
					\item bond order is unknown (= \link Bond::ORDER__UNKNOWN Bond::ORDER__UNKNOWN \endlink )
					\item bond type is unknown (= \link Bond::TYPE__UNKNOWN Bond::TYPE__UNKNOWN \endlink )
				\end{itemize}
		*/
		Bond()
			throw();

		/** Copy constructor.
				Calls  \link Bond::createBond Bond::createBond \endlink .
				The state of this bond is initialized to the state of bond.
				 \par
				<b>Note:</b> Deep copying of bonds makes no sense, the parameter <tt>deep</tt> is therefore
				ignored. The use of this method is not recommended because it may result in inconcistencies
				of the whole the kernel data structure. This if for internal use only!
				@param			 bond the bond to be copied
				@param       deep ignored
				@see         createBond
		*/
		Bond(const Bond& bond, bool deep = true)
			throw();
	
		/** Detailed constructor.
				Calls  \link createBond createBond \endlink  to create a new bond between the two atoms
				@param       name name of the constructed bond
				@param       first first atom of the constructed bond
				@param       second second atom of the constructed bond
				@param       order order of the constructed bond
				@param       type type of the constructed bond
				@exception TooManyBonds if one of the atom already possesses  \link Atom::MAX_NUMBER_OF_BONDS Atom::MAX_NUMBER_OF_BONDS \endlink  bonds.
		*/
		Bond(const String& name, Atom& first, Atom& second, Order order = BALL_BOND_DEFAULT_ORDER,
				 Type type = BALL_BOND_DEFAULT_TYPE)
			throw(TooManyBonds);

		/** Create a bond.
				Connect the two atoms <tt>first</tt> and <tt>second</tt> via a bond.
				@param 	bond the instantiated bond that connects the first atom <tt>first</tt> 
								to the second atom <tt>second</tt>
				@param 	first the first atom of the bond
				@param 	second the second atom of the bond
				@return Bond* <tt>this</tt>
				@exception TooManyBonds if one of the atom already possesses  \link Atom::MAX_NUMBER_OF_BONDS Atom::MAX_NUMBER_OF_BONDS \endlink  bonds.
		*/
		static Bond* createBond(Bond& bond, Atom& first, Atom& second)
			throw(TooManyBonds);

		/** Destructor.
				Default destruction of this bond.
				If the bond is connecting two atoms, they are disconnected.
		*/
		virtual ~Bond()
			throw();

		/** Explicit default initialization.
				Set the state of this bond to the default values.
				The state of this bond is:
				\begin{itemize}
					\item bond has no connectivity with first atom (=0)
					\item bond has no connectivity with second atom (=0)
					\item bond name is the empty string (="")
					\item bond order is unknown (= \link Bond::ORDER__UNKNOWN Bond::ORDER__UNKNOWN \endlink )
					\item bond type is unknown (= \link Bond::TYPE__UNKNOWN Bond::TYPE__UNKNOWN \endlink )
				\end{itemize}
		*/
		virtual void clear()
			throw();

		/** Explicit destructor.
				Destroy this bond explicitly without releasing its heap memory thus
				this bond may exist further.	Calls  \link Bond::clear Bond::clear \endlink .
				Set the state of this bond to the default values. 
				<b>Note:</b> Destroy is equivalent to  \link Bond::clear Bond::clear \endlink .
				@see Bond::clear
		*/
		virtual void destroy()
			throw();

		//@}
		/**	@name Persistence 
		*/
		//@{
	
		/**	Write a bond to a persistent stream.
				@param pm the persistence manager
		*/
		void persistentWrite(PersistenceManager& pm, const char* name = 0) const
			throw(Exception::GeneralException);

		/**	Read a bond from a persistent stream.
				@param pm the persistence manager
		*/
		void persistentRead(PersistenceManager& pm)
			throw(Exception::GeneralException);

		/**	Finalize the deserialization.
				Bond might have to swap <tt>first_</tt> and <tt>second_</tt> to ensure
				the correct order (see  \link Bond Bond \endlink ).
		*/
		void finalize()
			throw(Exception::GeneralException);

		//@}

		/**	@name Predicates
		*/
		//@{
		/**	Equality operator.
				@see Object::operator ==
		*/
		bool operator == (const Bond& bond) const
			throw();

		/**	Inequality operator
				@see operator ==
		*/
		bool operator != (const Bond& bond) const
			throw();
		//@}

		/** @name Assignment methods 
		*/
		//@{
	
		/** Assignment operator.
				Assign a deep copy (on the level of  \link Composite Composite \endlink ).
				
				<b>Note:</b> The use of this method is not recommended because it may result in inconcistencies
				of the whole system. This is for internal use only.
				@param  bond the bond to be copied
				@return Bond - this bond
				@see    Bond::set
		*/
		const Bond& operator = (const Bond& bond)
			throw();

		/** Swap the contents of two bonds
				@param bond the bond <tt>this</tt> is being swapped with
				@see   Bond::Bond
		*/
		void swap(Bond& bond)
			throw();
	
		//@}

		/** @name Accessors
		*/
		//@{ 

		/** Set the first atom.
				This method does not ensure the correct order of atoms 
				(see  \link Bond Bond \endlink ), so its use is recommended for internal purposes only.
				@param atom the atom to set
		*/
		void setFirstAtom(Atom* atom)
			throw();
	
		/** Return a pointer to the first atom.
		*/
		const Atom* getFirstAtom() const
			throw();
	 
		/** Set the second atom.
				This method does not ensure the correct order of atoms 
				(see  \link Bond Bond \endlink ), so its use is recommended for internal purposes only.
				@param atom the atom to set
		*/
		void setSecondAtom(Atom* atom)
			throw();
	
		/** Return a pointer to the second atom.
		*/
		const Atom* getSecondAtom() const
			throw();

		/**	Return the partner atom of an atom.
				If the given <tt>atom</tt> is part of this bond, the other atom
				of the bond is returned. 0 is returned if <tt>atom</tt> is not
				one of the bond's atoms.
				@param	atom one of the bond's atoms
				@return	the atom's bond partner
		*/
		Atom* getPartner(const Atom& atom) const
			throw();

		/** Set the name.
				@param name the new name of this bond
		*/
		void setName(const String& name)
			throw();

		/** Return the name.
				@return      String - constant reference to the name of this bond
		*/
		const String& getName() const
			throw();

		/** Set the bond order.
				@param       bond_order the new order of this bond
		*/
		void setOrder(Order bond_order)
			throw();
	
		/** Return the bond order.
				@return      Order the order of the bond
		*/
		Order getOrder() const
			throw();
	
		/** Set the bond type
				@param       bond_type the new type
		*/
		void setType(Type bond_type)
			throw();
	
		/** Return the bond type
				@return      Type - the bond type
		*/
		Type getType() const
			throw();
	
		/** Return the bond length
				@exception NotBound if the bond has not two atoms
				@return      float - the distance between the two atoms
		*/
		float getLength() const
			throw(NotBound);

		/** Return the partner of the atom in this bond.
				@param			 atom an atom
				@return      Atom a constant pointer to the atom,
										 0 if the atom is not part of the bond
		*/
		const Atom* getBoundAtom(const Atom& atom) const
			throw();

		//@}

		/** @name Predicates 
		*/
		//@{ 

		/** Determine whether the bond belongs to an atom.
				Calls  \link Atom::hasBond Atom::hasBond \endlink .
				@param atom the atom that is queried to connect this bond to another atom
				@return  bool - <tt>true</tt> if bond connects the atom {\em atom} with another atom, 
												<tt>false</tt> otherwise
				@see     Atom::hasBond
		*/
		bool isBondOf(const Atom& atom) const
			throw();

		/** Determine whether this bond contains any atom.
				@return   bool - <tt>true</tt> if bond connects the atom {\em atom} with another atom, 
												 <tt>false</tt> otherwise
				@see      Atom::hasBond
		*/
		bool isBound() const
			throw();

		/** Determine whether the bond connects two fragments.
				If both atoms have no roots, the result is false.
				Calls  \link Composite::getRoot Composite::getRoot \endlink .
				@return   bool - <tt>true</tt> if this bond is intermolecular, 
												 <tt>false</tt> otherwise
				@see      Composite::getRoot
		*/
		bool isInterBond() const
			throw();

		/** Request for the intermolecular bonding of this bond within {\em atom_container}.
				Query, if this bond connects a atom within {\em atom_container} instance with an atom outside.
				Calls  \link Composite::isDescendantOf Composite::isDescendantOf \endlink .
				@param  	atom_container the queried parent fragment.
				@return  	bool -	<tt>true</tt> if this bond is intermolecular, 
													<tt>false</tt> otherwise
				@see      Composite::isDescendantOf
		*/
		bool isInterBondOf(const AtomContainer& atom_container) const
			throw();

		/**	Request for the intramolecular bonding of this bond.
				Query, if this bond connects its two atoms within a common parent  \link Composite Composite \endlink  instance.
				If both atoms have no roots, the result is true.
				Calls  \link Composite::getRoot Composite::getRoot \endlink .
				@return bool - <tt>true</tt> if this bond is intramolecular, 
											 <tt>false</tt> otherwise
				@see    Composite::getRoot
		*/
		bool isIntraBond() const
			throw();

		/** Request for the intramolecular bonding of this bond within {\em atom_container}.
				Query, if this bond connects its two atoms within the common parent {\em atom_container} instance.
				Calls  \link Composite::isDescendantOf Composite::isDescendantOf \endlink .
				@param  atom_container the queried parent fragment.
				@return bool - <tt>true</tt> if this bond is intramolecular, 
											 <tt>false</tt> otherwise
				@see    Composite::isDescendantOf
		*/
		bool isIntraBondOf(const AtomContainer& atom_container) const
			throw();

		//@}

		/** @name Debuggers and diagnostics 
		*/
		//@{ 

		/** Internal state and consistency self-validation.
				@return   bool - <tt>true</tt> if the internal state of this bond is correct (self-validated)
									and consistent, <tt>false</tt> otherwise
		*/
		virtual bool isValid() const
			throw();

		/** Internal state dump.
				Dump the current internal state of this bond to the output ostream {\em s}
				with dumping depth {\em depth}.
				@param	s output stream where to output the internal state of this bond
				@param  depth the dumping depth
		*/
		virtual void dump(std::ostream& s = std::cout, Size depth = 0) const
			throw();
	
		//@}

		protected:

		/**	@name Atributes
		*/
		//@{

		// First atom of the bond (bond owner)
		Atom*		first_;

		// Second atom
		Atom*		second_;

		// Bond name
		String	name_;

		// Bond order
		Order		bond_order_;

		// Bond type
		Type		bond_type_;
		//@}

		private:

		void arrangeBonds_() 
			throw();

		void clear_()
			throw();
	};

# ifndef BALL_NO_INLINE_FUNCTIONS
#   include <BALL/KERNEL/bond.iC>
# endif
  /** @} */
} // namespace BALL

#endif // BALL_KERNEL_BOND_H
