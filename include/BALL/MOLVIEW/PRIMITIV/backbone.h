// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: backbone.h,v 1.13 2003/03/03 14:18:09 anhi Exp $

#ifndef BALL_MOLVIEW_PRIMITIV_BACKBONE_H
#define BALL_MOLVIEW_PRIMITIV_BACKBONE_H

#ifndef BALL_DATATYPE_LIST_H
#	include <BALL/DATATYPE/list.h>
#endif

#ifndef BALL_KERNEL_ATOM_H
#	include <BALL/KERNEL/atom.h>
#endif

#ifndef BALL_VIEW_DATATYPE_COLOR_H
#	include <BALL/VIEW/DATATYPE/color.h>
#endif

#ifndef BALL_VIEW_KERNEL_GEOMETRICOBJECT_H
# include <BALL/VIEW/KERNEL/geometricObject.h>
#endif

#ifndef BALL_VIEW_PRIMITIV_LINE_H
#	include <BALL/VIEW/PRIMITIV/line.h>
#endif

#ifndef BALL_VIEW_PRIMITIV_SPHERE_H
#	include <BALL/VIEW/PRIMITIV/sphere.h>
#endif

#ifndef BALL_VIEW_PRIMITIV_TUBE_H
#	include <BALL/VIEW/PRIMITIV/tube.h>
#endif

namespace BALL
{
	using VIEW::Line;
	using VIEW::Tube;
	using VIEW::Sphere;
	using VIEW::GeometricObject;
	using VIEW::ColorRGBA;

	namespace MOLVIEW
	{
    /**  \addtogroup  MolviewPrimitives
     *  @{
     */
		/** Backbone class.
				An instance of Backbone represents a graphical representation of a spline
				path through a list of given  \link Atom Atom \endlink  objects. The spline path
				will be created from  \link Tube Tube \endlink  and  \link Sphere Sphere \endlink  objects. Before creating
				a Backbone there must be given a list of  \link Atom Atom \endlink  object and a list
				of  \link ColorRGBA ColorRGBA \endlink  objects. See the methods  \link setAtomList setAtomList \endlink  and
				 \link setAtomColorList setAtomColorList \endlink  for information.
				To create the Backbone use the method  \link createBackbone createBackbone \endlink .
				The class Backbone is derived from the class  \link GeometricObject GeometricObject \endlink .
				See this class for further information concerning
				interface and additional methods.  \par
				<b>Definition:</b> BALL/MOLVIEW/PRIMITIV/backbone.h
		*/
		class Backbone
			: public GeometricObject
		{
			public:

			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new backbone.
					@return      Backbone new constructed backbone
					@see         GeometricObject
			*/
			Backbone()
				throw();

			/** Copy constructor with cloning facility.
					Construct new backbone by copying the backbone {\em backbone}.
					The copy is either deep (default) or shallow.
					@param       backbone the backbone to be copied (cloned)
					@param       deep make a deep (=<tt>true</tt>) or shallow (=<tt>false</tt>)
					@return      Backbone new constructed backbone copied from {\em backbone}
					@see         GeometricObject
			*/
			Backbone(const Backbone& backbone, bool deep = true)
				throw();

			/** Copy constructor from geometricObject.
					Construct new backbone by copying the internal values from 
					 \link GeometricObject GeometricObject \endlink  {\em geometric_object}.
					@param       geometric_object the  \link GeometricObject GeometricObject \endlink  which internal values should be copied
					@return      Backbone new constructed backbone initialized from {\em geometric_object}
					@see         GeometricObject
			*/
			Backbone(const GeometricObject& geometric_object)
				throw();

			//@}
			/** @name Destructors 
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} backbone.
					Calls  \link destroy destroy \endlink .
					@see         destroy
			*/
			virtual ~Backbone()
				throw();

			/** Explicit default initialization.
					Calls  \link GeometricObject::clear GeometricObject::clear \endlink .
					@see  GeometricObject::clear
			*/
			virtual void clear()
				throw();

			/** Explicit destructor.
					Calls  \link GeometricObject::destroy GeometricObject::destroy \endlink .
					@see  GeometricObject::destroy
			*/
			virtual void destroy()
				throw();
			
			//@}
			/**	@name	Assignment methods
			*/
			//@{

			/** Assignment.
					Assign the backbone {\em backbone} to {\em *this}
					backbone.
					The copy is either deep (default) or shallow.
					The value of {\em *this} backbone is initialized to the value of 
					the backbone {\em backbone}.
					This method does not copy the structure of {\em backbone} into {\em *this}
					backbone. Only the geometric properties are copied. See  \link GeometricObject GeometricObject \endlink 
					for information.
					Calls  \link GeometricObject::set GeometricObject::set \endlink .
					@param       backbone the backbone to be copied
					@param       deep make a deep (=<tt>true</tt>) or shallow (=<tt>false</tt>) copy of {\em backbone}
					@see         GeometricObject::set
			*/
			void set(const Backbone& backbone, bool deep = true)
				throw();

			/** Assignment operator.
					Assign the backbone {\em backbone} to {\em *this}
					backbone.	The copy is deep.
					This method does not copy the structure of {\em backbone} into {\em *this}
					backbone. Only the geometric properties are copied. See  \link GeometricObject GeometricObject \endlink 
					for information.
					Calls  \link set set \endlink .
					The value of {\em *this} backbone is initialized to the value 
					of the backbone {\em backbone}. \par
					@param       backbone the backbone to be copied
					@return      Backbone& constant reference of {\em *this} backbone
					@see         set
			*/
			const Backbone& operator = (const Backbone& backbone)
				throw();

			/** Copying with cloning facility.
					Copy {\em *this} backbone to the backbone {\em backbone}.
					The copy is either deep (default) or shallow.
					This method does not copy the structure of {\em *this} backbone into
					{\em backbone}. Only the geometric properties are copied.
					See  \link GeometricObject GeometricObject \endlink 	for information.
					Calls  \link set set \endlink .
					The value of the backbone {\em backbone} is initialized to the
					value of {\em *this} backbone. \par
					@param       backbone the backbone to be assigned to
					@param       deep make a deep (=<tt>true</tt>) or shallow (=<tt>false</tt>) copy of {\em backbone}
					@see         set
			*/
			void get(Backbone& backbone, bool deep = true) const
				throw();

			/** Swapping of backbone's.
					Swap the value of {\em *this} backbone with the backbone
					{\em backbone}.
					This method does not swap the structure of {\em backbone} with {\em *this}
					backbone. Only the geometric properties are swapped. See  \link GeometricObject GeometricObject \endlink 
					for information.
					@param       backbone the backbone being swapped with {\em *this}  backbone
			*/
			void swap(Backbone& backbone)
				throw();

			//@}
			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{
			
			/** Set the atom list for the backbone.
					Set a list of atoms that should be used to create a backbone representation.
					{\em *this} backbone will create a spline path through these atoms
					(from the first atom to the last atom stored in this list).
					 \link Tube Tube \endlink  and  \link Sphere Sphere \endlink  objects will be used to build the spline.
					The color that should be used for each  \link Atom Atom \endlink  in this list must be
					stored in the atom color list (See  \link setAtomColorList setAtomColorList \endlink ) in the same
					order.
					@param  atoms the list containing the  \link Atom Atom \endlink  object through which a backbone representation should be created
					@see    setAtomColorList
					@see    Tube
					@see    Sphere
					@see    Atom
			*/
			void setAtomList(const List<Atom*> &atoms)
				throw();

			/** Set the color for the atoms.
					Set a list of  \link ColorRGBA ColorRGBA \endlink  objects that will be used for creating
					the backbone representation.
					Each color in this list correlates to an  \link Atom Atom \endlink  object in the atom list
					(See  \link setAtomList setAtomList \endlink ). If this list is empty or contains less 
					 \link ColorRGBA ColorRGBA \endlink  object than are  \link Atom Atom \endlink  objects in the other list
					than the color <tt>white</tt> will be used for all  \link Atom Atom \endlink  objects that will
					be left. If there are more color objects in this list than atom objects
					are in the other list only the color objects are used with position in this 
					list less or equal to the size of the atom list.
					@param  atom_colors the list of  \link ColorRGBA ColorRGBA \endlink  objects
					@see    setAtomList
					@see    ColorRGBA
					@see    ColorRGBA
			*/
			void setAtomColorList(const List<ColorRGBA> &atom_colors)
				throw();

			/** Create the backbone.
					Create the graphical representation of {\em *this} backbone.
					To create the representation of {\em *this} backbone a list of  \link Atom Atom \endlink 
					objects and their correlating list of  \link ColorRGBA ColorRGBA \endlink  objects must be
					previously set.
					@see   setAtomList
					@see   setAtomColorList
					@see   ColorRGBA
					@see   Atom					
			*/
			void createBackbone()
				throw();

			/** Return the type name of {\em *this} backbone.
					Virtually overridden method for specifying the type name of {\em *this}
					backbone.
					This method is used by the  \link Control Control \endlink  class to identify the
					backbone object.
					@return  String the type name of {\em *this} backbone
					@see     Control
			*/
			virtual String getTypeName() const
				throw();

			//@}
			/**	@name	debuggers and diagnostics
			*/
			//@{

			/** Internal state and consistency self-validation.
					Initiate self-validation of the internal state and data structure
					consistencies	of {\em *this} backbone.
					If the internal state of {\em *this} backbone is correct 
					(self-validated) and 
					consistent <tt>true</tt> is returned, <tt>false</tt> otherwise. 
					Calls {GeometricObject::isValid}.
					@return			bool <tt>true</tt> if the internal state of {\em *this} backbone 
											is correct (self-validated) and consistent, <tt>false</tt> otherwise
					@see        GeometricObject::isValid
			*/
 			virtual bool isValid() const
				throw();

			/** Internal value dump.
					Dump the current value of {\em *this} backbone to 
					the output ostream {\em s} with dumping depth {\em depth}.
					Calls  \link GeometricObject::dump GeometricObject::dump \endlink .
					@param   s output stream where to output the value of {\em *this} backbone
					@param   depth the dumping depth
					@see        GeometricObject::dump
			*/
			virtual void dump
				(std::ostream&  s = std::cout, Size depth = 0) const
				throw();

			//@}

			protected:
			
			/** Export method.
					This method handles the export of {\em *this} backbone into another
					format (eg. POVRAY, VRML) \par
				  <b>Note:</b> Not yet implemented.
					@return    bool <tt>true</tt> if successful,	<tt>false</tt> otherwise
			*/
			virtual bool extract()
				throw();

		  private:

			//_
			class SplinePoint
			{
			  public:

				SplinePoint() {}
				~SplinePoint() {}

				void setVector(const Vector3 &point);
				const Vector3 &getVector() const;

				void setTangentialVector(const Vector3 &tangent);
				const Vector3 &getTangentialVector() const;
				
				void setColor(const ColorRGBA &color);
				const ColorRGBA &getColor() const;

			  private:

				Vector3 point_;
				Vector3 tangent_;
				ColorRGBA color_;
			};


			//_
			virtual Sphere* createSphere_();

			//_
			virtual Tube* createTube_();

			//_
			virtual Line* createLine_();

			//_ init the spline array with both the positions from the atom list
			//_ and the colors from the color list
			void initSplineArray_();

			//_ calculates to every splinepoint the tangential vector
			void calculateTangentialVectors_();
			
			//_ computes the actual spline path through the given support points
			//_ in the splinepoint array
			void createSplinePath_();

			//_ create a spline segment between two spline points a and b
			void createSplineSegment_(const SplinePoint &a, const SplinePoint &b);

			//_ builds a graphical representation to this point with color
			void buildGraphicalRepresentation_(const Vector3 &point, const ColorRGBA &color);


			//_
			List<Atom*> atoms_;

			//_
			List<ColorRGBA> atom_colors_;

			//_
			SplinePoint *spline_array_;

			//_
			int size_of_spline_array_;

			//_
			bool have_start_point_;

			//_
			Vector3 last_point_;
		};

#		ifndef BALL_NO_INLINE_FUNCTIONS
#			include <BALL/MOLVIEW/PRIMITIV/backbone.iC>
#		endif
  /** @} */		
	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIEW_PRIMITIV_BACKBONE_H
