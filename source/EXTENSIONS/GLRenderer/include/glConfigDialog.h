#ifndef BALL_GLRENDERER_CONFIGDIALOG_H
#define BALL_GLRENDERER_CONFIGDIALOG_H

#include <BALL/VIEW/PLUGIN/VIEWPlugin.h>
#include <ui_glConfigDialog.h>

#include <memory>
#include <set>

namespace BALL
{
	namespace GLRenderer
	{
		class GLRenderer;

		class BALL_PLUGIN_EXPORT GLConfigDialog final : public BALL::VIEW::ConfigDialog
		{
			Q_OBJECT

			public:
				GLConfigDialog(QWidget* parent = nullptr, Qt::WindowFlags f = 0);
				~GLConfigDialog() noexcept override = default;

				GLConfigDialog(const GLConfigDialog&) = delete;
				GLConfigDialog& operator=(const GLConfigDialog&) = delete;

				void storeValues() override;

				void registerRenderer(GLRenderer &renderer);
				void unregisterRenderer(GLRenderer &renderer);

				void updateGLInfo(GLRenderer& renderer);

			private:
				std::unique_ptr<Ui::OpenGLSettings> ui_;
				std::set<GLRenderer*> renderers_;
		};
	} // namespace GLRenderer
} // namespace BALL

#endif // BALL_GLRENDERER_CONFIGDIALOG_H