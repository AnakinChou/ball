// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: extendedProperty.h,v 1.6.2.1 2003/01/07 13:18:41 anker Exp $

#ifndef BALL_MOLVIEW_KERNEL_EXTENDEDPROPERTY_H
#define BALL_MOLVIEW_KERNEL_EXTENDEDPROPERTY_H

#ifndef BALL_CONCEPT_PROPERTY_H
#	include <BALL/CONCEPT/property.h>
#endif

namespace BALL
{
	namespace MOLVIEW
	{

		/** ExtendedPropertyManager class.
				The class ExtendedPropertyManager overrides the \Ref{setProperty} method
				from the class \Ref{PropertyManager}. That is necessary because there are
				certain properties which cannot be set together (e.g. properties of the
				model group). If such a property is set all other previously set properties
				from the same group are cleared (e.g. the properties MODEL_BALL_AND_STICK
				and MODEL_VAN_DER_WAALS cannot be set together, so the last set property
				will clear the one previously set).
				This class will be used by the class \Ref{BaseModelProcessor}, so that all
				derived processors can make use of the properties. \\
				{\bf Definition:} \URL{BALL/MOLVIEW/KERNEL/extendedProperty.h}
		*/
		class ExtendedPropertyManager: public PropertyManager
		{
			public:

			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new extendedPropertyManager.
					@return      ExtendedPropertyManager new constructed extendedPropertyManager
					@see         PropertyManager
			*/
			ExtendedPropertyManager()
				throw();

			/** Copy constructor.
					Construct new extendedPropertyManager by copying the 
					extendedPropertyManager {\em extended_property_manager}.
					The copy is either deep (default) or shallow.
					The state of {\em *this} extendedPropertyManager is initialized to the state of 
					the extendedPropertyManager {\em extended_property_manager}.\\
					@param       extended_property_manager the extendedPropertyManager to be copied (cloned)
					@param       deep make a deep (={\tt true}) or shallow (={\tt false}) copy of {\em extended_property_manager}
					@return      ExtendedPropertyManager new extendedPropertyManager cloned from {\em extended_property_manager}
					@see         PropertyManager
			*/
			ExtendedPropertyManager(const ExtendedPropertyManager& extended_property_manager, bool deep = true)
				throw();

			//@}

			/** @name Destructors
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} extendedPropertyManager.
			*/
			virtual ~ExtendedPropertyManager()
				throw();
			//@}

			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{

			/** Change the property of {\em *this} extendedPropertyManager.
					Change the property of {\em *this} extendedPropertyManager to the property
					represented by the parameter {\em property}. 
					See predefined properties for allowed	properties.
					This method overrides the method {\em setProperty} from the class
					\Ref{PropertyManager}. There are certain properties that cannot be
					set together (e.g. the model properties, the precision properties, etc.).
					If such a property is set all previously set properties of the same
					group are cleared (e.g. if the property DRAWING_PRECISION_LOW was set
					and the the property DRAWING_PRECISION_HIGH is set the former property
					will be cleared).
					@param       property the new property of {\em *this} extendedPropertyManager
			*/
			void setProperty(int property)
				throw();
			//@}
		};

	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIEW_KERNEL_EXTENDEDPROPERTY_H 
