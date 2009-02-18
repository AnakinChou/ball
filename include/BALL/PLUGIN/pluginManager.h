#ifndef BALL_PLUGIN_PLUGINMANAGER_H
#define BALL_PLUGIN_PLUGINMANAGER_H

#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtCore/QMutex>
#include <QtCore/QReadWriteLock>

#include <list>

class QPluginLoader;
class QObject;

namespace BALL
{
	class BALLPlugin;
	class PluginHandler;

	/**
	 * A singleton that takes care of handling all plugins.
	 * It is responsible for loading, starting and stopping plugins.
	 * For the task of properly initializing the plugins it utilizes
	 * the PluginHandler helper classes, that need to be supplemented
	 * for each new plugin type.
	 */
	class PluginManager
	{
		public:
			~PluginManager();

			/**
			 * Use this method to obtain the PluginManager instance.
			 *
			 * This method is thread safe.
			 */
			static PluginManager& instance();

			/**
			 * Tries to load all plugins (files named like: pluginMyPlugin.$LIBRARY_SUFFIX)
			 * located in the specified directoy dir.
			 *
			 * @param dir the directory to search for plugins.
			 */
			void setPluginDirectory(const QString& dir);

			/**
			 * Loads the plugin specified by plugin_name.
			 *
			 * @param plugin_name The path to the plugin to load
			 *
			 * @return NULL if the plugin could not be loaded. A valid pointer
			 *         to the loaded plugin otherwise.
			 */
			BALLPlugin* loadPlugin(const QString& plugin_name);

			/**
			 * Unloads the plugin specified by plugin_name.
			 *
			 * @param plugin_name The name of the plugin to unload
			 */
			bool unloadPlugin(const QString& plugin);

			/**
			 * Searches for the plugin and returns a pointer
			 * to it if it has been loaded.
			 *
			 * @param plugin The name of the plugin to search
			 *
			 * @return NULL if the plugin could not be found, a pointer to
			 *         it otherwise
			 */
			QObject* getPluginInstance(const QString& plugin);

			/**
			 * Searches for the plugin and returns a pointer
			 * to it if it has been loaded.
			 *
			 * @param pos The position of the plugin in the plugin list
			 *
			 * @return NULL if the plugin could not be found, a pointer to
			 *         it otherwise
			 */
			QObject* getPluginInstance(int pos);

			/**
			 * See startPlugin(BALLPlugin* plugin)
			 */
			bool startPlugin(int plugin);

			/**
			 * See startPlugin(BALLPlugin* plugin)
			 */
			bool startPlugin(const QString& plugin);

			/**
			 * Starts the specified plugin through a applicable
			 * PluginHandler
			 *
			 * @param plugin A pointer to the plugin to be started
			 *
			 * @return false if no suitable handler could be found,
			 *         true otherwise.
			 */
			bool startPlugin(BALLPlugin* plugin);

			/**
			 * See stopPlugin(BALLPlugin* plugin)
			 */
			bool stopPlugin(int plugin);

			/**
			 * See stopPlugin(BALLPlugin* plugin)
			 */
			bool stopPlugin(const QString& plugin);

			/**
			 * Stops the specified plugin by letting all PluginHandlers
			 * stop it.
			 *
			 * @param plugin A pointer to the plugin to be stopped
			 *
			 * @return false if one handler could not stop the plugin,
			 *         true otherwise.
			 */
			bool stopPlugin(BALLPlugin* plugin);

			/**
			 * Returns the number of loaded plugins.
			 */
			int getPluginCount() const;

			/**
			 * Register a new PluginHandler. This handler will then
			 * be available for starting new plugins.
			 */
			void registerHandler(PluginHandler* h);

		private:
			PluginManager();
			PluginManager(const PluginManager&);
			const PluginManager& operator=(const PluginManager&);

			QString plugin_dir_;
			QHash<QString, QPluginLoader*> loaders_;
			std::list<PluginHandler*> handlers_;

			static PluginManager* manager_;

			//This mutex is used in the creation of the singleton
			static QMutex mutex_;
			//This mutex guards the handlers_ list
			mutable QReadWriteLock handler_mutex_;
			//This mutex guards the loaders_ list
			mutable QReadWriteLock loader_mutex_;
	};
}

#endif //BALL_PLUGIN_PLUGINMANAGER_H

