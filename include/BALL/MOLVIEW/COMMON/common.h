// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: common.h,v 1.13 2002/02/27 12:19:08 sturm Exp $

#ifndef BALL_MOLVIEW_COMMON_COMMON_H
#define BALL_MOLVIEW_COMMON_COMMON_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_VIEW_KERNEL_GEOMETRICOBJECT_H
#	include <BALL/VIEW/KERNEL/geometricObject.h>
#endif

#define BALL_MOLVIEW_PRINT_PROPERTY(property) \
	(hasProperty(property) ? "yes" : "no")

using BALL::VIEW::GeometricObject;

namespace BALL
{
	
	namespace MOLVIEW
	{
		/*
		enum Address
		{
			ADDRESS__UNKOWN                    = 0,
			ADDRESS__STATIC_MODEL,
			ADDRESS__DYNAMIC_MODEL,
			ADDRESS__ALWAYS_FRONT_MODEL,
			ADDRESS__TRANSPARENT_MODEL,
			ADDRESS__STATIC_DRAWING_PRECISION,
			ADDRESS__STATIC_DRAWING_MODE,
			ADDRESS__DYNAMIC_DRAWING_PRECISION,
			ADDRESS__DYNAMIC_DRAWING_MODE,
			ADDRESS__CAMERA_DISTANCE
		};		

		enum Value
		{
			VALUE__MODEL_UNKOWN         = 0,
			VALUE__MODEL_LINES          = 1,
			VALUE__MODEL_STICK          = 2,
			VALUE__MODEL_BALL_AND_STICK = 3,
			VALUE__MODEL_SURFACE        = 4,
			VALUE__MODEL_VAN_DER_WAALS  = 5,
			VALUE__MODEL_REMOVE         = 6,
			VALUE__MODEL_BACKBONE       = 7,
			VALUE__SELECT               = 20,
			VALUE__DESELECT             = 21,

			VALUE__DRAWING_PRECISION_LOW    = 0,
			VALUE__DRAWING_PRECISION_MEDIUM = 1,
			VALUE__DRAWING_PRECISION_HIGH   = 2,
			VALUE__DRAWING_PRECISION_ULTRA  = 3,

			VALUE__DRAWING_MODE_DOTS      = 0,
			VALUE__DRAWING_MODE_WIREFRAME = 1,
			VALUE__DRAWING_MODE_SOLID     = 2
		};

		enum ColorCalculatorValues
		{
			COLORCALCULATOR_VALUES__ELEMENT          = 0,
			COLORCALCULATOR_VALUES__RESIDUE_NAME     = 1,
			COLORCALCULATOR_VALUES__ATOM_CHARGE      = 2,
			COLORCALCULATOR_VALUES__CUSTOM           = 3
		};
		*/

		//		struct GeometricObject
		//		{
			/** Predefined properties.
					Enumeration of all properties that are used by the MOLVIEW kernel.
					This properties define the models available in MOLVIEW.
					This enumeration is an extension of the property in the \Ref{GeometricObject}
					class.
			*/
			enum Property
			{
				/// unkown property
				PROPERTY__UNKNOWN = -1,
				/*
				// Object Properties
				PROPERTY__OBJECT_STATIC = VIEW::GeometricObject::PROPERTY__OBJECT_STATIC,     // Default
				PROPERTY__OBJECT_DYNAMIC,
				PROPERTY__OBJECT_ALWAYS_FRONT,               
				PROPERTY__OBJECT_TRANSPARENT,
				PROPERTY__OBJECT_OPAQUE,
				PROPERTY__OBJECT_VISIBLE,
				PROPERTY__OBJECT_HIDDEN,
				PROPERTY__OBJECT_OPENED,
				PROPERTY__OBJECT_CLOSED,
				
				// DrawingMode Properties
				PROPERTY__DRAWING_MODE_DOTS = VIEW::GeometricObject::PROPERTY__DRAWING_MODE_DOTS,
				PROPERTY__DRAWING_MODE_WIREFRAME,
				PROPERTY__DRAWING_MODE_SOLID,
				
				// DrawingPrecision Properties
				PROPERTY__DRAWING_PRECISION_LOW = VIEW::GeometricObject::PROPERTY__DRAWING_PRECISION_LOW,
				PROPERTY__DRAWING_PRECISION_MEDIUM,
				PROPERTY__DRAWING_PRECISION_HIGH,
				PROPERTY__DRAWING_PRECISION_ULTRA,
				PROPERTY__DRAWING_PRECISION_USER_DEFINED,
				*/
				
				/// defines the number of the first model available (the next free number).
				PROPERTY__FIRST_MODEL            = GeometricObject::NUMBER_OF_PROPERTIES,

				/// defines the property for the model: Van der Waals
				PROPERTY__MODEL_VDW              = PROPERTY__FIRST_MODEL,

				/// defines the property for the model: Dots
				PROPERTY__MODEL_DOTS,

				/// defines the property for the model: Ball and Stick
				PROPERTY__MODEL_BALL_AND_STICK,

				/// defines the property for the model: Lines
				PROPERTY__MODEL_LINES,

				/// defines the number of the last model available.
				PROPERTY__LAST_MODEL             = PROPERTY__MODEL_LINES,

				/// defines the start of the next free properties.
				NUMBER_OF_PROPERTIES
			};
			//		};

#			ifndef BALL_NO_INLINE_FUNCTIONS
#				include <BALL/MOLVIEW/COMMON/common.iC>
#			endif

	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIEW_COMMON_COMMON_H
