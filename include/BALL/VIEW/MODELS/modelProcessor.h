// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: modelProcessor.h,v 1.18 2005/07/16 21:00:35 oliver Exp $
//

#ifndef BALL_VIEW_MODELS_MODELPROCESSOR_H
#define BALL_VIEW_MODELS_MODELPROCESSOR_H

#ifndef BALL_CONCEPT_COMPOSITE_H
#	include <BALL/CONCEPT/composite.h>
#endif

#ifndef BALL_DATATYPE_LIST_H
#	include <BALL/DATATYPE/list.h>
#endif

#ifndef BALL_CONCEPT_PROPERTY_H
# include <BALL/CONCEPT/property.h>
#endif

namespace BALL
{
	namespace VIEW
	{
		class GeometricObject;
		
		/** Base class for all model processors.
		 		Every model processor has a list with all GeometricObject 's it has
				created. It also stores the drawing precision, it will use for creating new models.
				You can apply model processors like every other UnaryProcessor for Composite 's: <br>
				\verbatim				
					Molecule m;
					ModelProcessor model_processor;
					m.apply(model_processor);
				\endverbatim
				\ingroup  ViewModels
		*/
		class BALL_EXPORT ModelProcessor
			: public UnaryProcessor<Composite>,
				public PropertyManager
		{
			public:

				BALL_CREATE(ModelProcessor)
				
				///
				typedef List<GeometricObject*> GeometricObjectList;

				///
				ModelProcessor()
					throw();

				///
				ModelProcessor(const ModelProcessor& model_processor)
					throw();

				/** Destructor, calls clear
				*/
				virtual ~ModelProcessor()
					throw();

				/// Clear all datastructures, but dont destroy the geometric objects.
				virtual void clear()
					throw();

				///
				virtual bool isValid() const
					throw() {return true;};

 				/** Needed in derived classes, which store references to the Composite instances they worked on.
				 		Here only needed for a common interface and therefore empty.
				*/
				virtual void clearComposites()
					throw() {}

				///
				virtual void dump(std::ostream& /*s = std::cout*/, Size /*depth = 0*/) const
					throw(){};

				/// Return the list with the created geometric objects
				GeometricObjectList& getGeometricObjects() 
					throw() { return geometric_objects_;}
				
				/// Return the list with the created geometric objects
				const GeometricObjectList& getGeometricObjects() const
					throw() { return geometric_objects_;}
				
				///
				void setDrawingPrecision(Index precision)
					throw() { drawing_precision_ = precision;}

				///
				Index getDrawingPrecision() const
					throw() { return drawing_precision_;}

				///
				void setSurfaceDrawingPrecision(float precision)
					throw() { surface_drawing_precision_ = precision;}

				///
				float getSurfaceDrawingPrecision() const
					throw() { return surface_drawing_precision_;}

				/** Method to create geometric objects.
				 		This method is called in Representation::update() after
						all operator() was called for all Composites.
				 		To be overloaded in derived classes
				*/
				virtual bool createGeometricObjects() 
					throw() { return true;}
				
				protected:
				
				//_
				GeometricObjectList geometric_objects_;

				//_
				Index drawing_precision_;

				//_
				float surface_drawing_precision_;
	};

	} // namespace VIEW
} // namespace BALL

#endif // BALL_VIEW_MODELS_MODELPROCESSOR_H
