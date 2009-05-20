// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: materialSettings.h,v 1.6.16.1 2007/03/25 21:25:51 oliver Exp $
//

#ifndef BALL_VIEW_DIALOGS_MATERIALSETTINGS_H
#define BALL_VIEW_DIALOGS_MATERIALSETTINGS_H

#ifndef BALL_COMMON_GLOBAL_H
# include <BALL/COMMON/global.h>
#endif

#ifdef BALL_COMPILER_MSVC
# include <BALL/VIEW/UIC/ui_materialSettings.h>
#else
# include <BALL/VIEW/UIC/materialSettingsData.h>
#endif


#ifndef BALL_VIEW_KERNEL_PREFERENCESENTRY
# include <BALL/VIEW/KERNEL/preferencesEntry.h>
#endif

#include <QtGui/QWidget>
#include <QtGui/QLabel>

namespace BALL
{
	namespace VIEW
	{
		class Scene;
		class Representation;

		/** Dialog for setting the Material, which is added to the Preferences.
		 		This dialog allows the control of the Materials of a Scene.
				Materials can be added, removed and adjusted.
				\ingroup ViewDialogs
		*/
		class BALL_VIEW_EXPORT MaterialSettings 
			: public QWidget,
				public Ui_MaterialSettingsData,
				public PreferencesEntry
		{ 
			Q_OBJECT

			public:

			/// Constructor
			MaterialSettings( QWidget* parent = 0, const char* name = "MaterialSettings", Qt::WFlags fl = 0 );

			/// Destructor
			~MaterialSettings() {}

			/// Apply the new values to the stage
			void apply();

			/// set the current representation
			void setCurrentRepresentation(Representation const* representation)
			{
				current_representation_ = representation;
			}

			public slots:

			virtual void ambientFactorChanged();
			virtual void specularityFactorChanged();
			virtual void reflectivenessFactorChanged();
			virtual void shininessFactorChanged();
			virtual void updateDirectlyBoxChanged();
			virtual void editAmbientColor();
			virtual void editSpecularityColor();
			virtual void editReflectivenessColor();
			virtual void rendererChanged();
			private:

			void setValues_(const QSlider& slider, QLabel& label, int divisor);

			Representation const* current_representation_;
		};

	}
}

#endif
