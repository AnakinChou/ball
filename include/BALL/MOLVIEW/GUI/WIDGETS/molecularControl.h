// $Id: molecularControl.h,v 1.7.4.5 2002/11/28 21:14:26 amoll Exp $

#ifndef BALL_MOLVIEW_GUI_WIDGETS_MOLECULARCONTROL_H
#define BALL_MOLVIEW_GUI_WIDGETS_MOLECULARCONTROL_H

#ifndef BALL_VIEW_GUI_WIDGETS_CONTROL_H
#	include <BALL/VIEW/GUI/WIDGETS/control.h>
#endif

#ifndef BALL_MOLVIEW_FUNCTOR_MOLECULARINFORMATION_H
#	include <BALL/MOLVIEW/FUNCTOR/molecularInformation.h>
#endif

#ifndef BALL_MOLVIEW_FUNCTOR_MOLECULARFILTER_H
#	include <BALL/MOLVIEW/FUNCTOR/molecularFilter.h>
#endif

#ifndef BALL_KERNEL_ATOM_H
#	include <BALL/KERNEL/atom.h>
#endif

namespace BALL
{
	namespace MOLVIEW
	{
		using VIEW::MainControl;
		using VIEW::Information;
		using VIEW::Message;

		/**	The MolecularControl class.
				The MolecularControl class is a widget to display the molecular structure of 
				\Ref{Composite}	objects. 
				This class is derived from the class \Ref{Control} and extends it for showing
				molecular structures. The method \Ref{checkMenu} is overridden to enable and
				disable the menu entries properly. The cut, copy and paste menus will work
				only with \Ref{System} objects. Further the internal selection mechanism
				is reimplemented to work on molecular objects instead of \Ref{GeometricObject}
				objects. \\
				{\bf Definition:} \URL{BALL/MOLVIEW/GUI/WIDGETS/molecularControl.h}
		*/
		class MolecularControl: public BALL::VIEW::Control
		{			
			Q_OBJECT
			
		public:
			
			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Constructs new molecularControl.
					@param      parent the parent widget of {\em *this} molecularControl 
					@param      name the name of {\em *this} molecularControl 
					@return     MolecularControl new constructed molecularControl
					@see        Control
			*/
			MolecularControl(QWidget* parent = 0, const char* name = 0)
				throw();
			
			//@}

			/** @name Destructors 
			*/
			//@{

			/** Destructor.
					Default destruction of {\em *this} molecularControl.
			*/
			virtual ~MolecularControl()
				throw();
			//@}
			
			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{
			/**	Menu checking method.
					This method is called by the method \Ref{checkMenus} from the
					\Ref{MainControl} object before a popup menu is shown.
					The menus \Ref{cut}, \Ref{copy}, \Ref{paste} and \Ref{clearClipboard} will
					be enabled and disabled as molecular structures are selected. \Ref{Paste}
					and \Ref{clearClipboard} will only be enabled if \Ref{System} objects
					were cutted or copied before.
					The \Ref{cut} and \Ref{copy} menu entry are only enabled if all selected objects
					were \Ref{System} objects, disabled otherwise.				
					@param main_control the \Ref{MainControl} object whose menus should be checked
					@see   Control::checkMenu
					@see   show
					@see   checkMenus
			*/
			virtual void checkMenu(MainControl& main_control)
				throw();

			/** Builds a context menu.
					Calls \Ref{Control::buildContextMenu}.\\
					{\bf Note:} context menus for molecular structures must be added.
					@param   composite the \Ref{Composite} object for that a context menu should be created
					@param   item the \Ref{QListViewItem} object for that a context menu should be created
					@see     Control::buildContextMenu
			*/
			virtual void buildContextMenu(Composite* composite, QListViewItem* item)
				throw();
			//@}

		public slots:
				
			/** @name Public slots
			*/
			//@{
			/** Sents the selection.
					Calls \Ref{Control::sentSelection}.
					Filters the selection with the \Ref{MolecularFilter} and sents a message
					\Ref{MolecularSelectionMessage} through the \Ref{ConnectionObject} tree.
					@see  getSelection
					@see  ConnectionObject
					@see  MolecularFilter
					@see  MolecularSelectionMessage
					@see  notify_
			*/
			virtual void sentSelection();

			//@}
		

		signals:
			
		protected:

			/** @name Internal creation and message handling
			*/
			//@{
			/** Accesses the molecular information visitor.
					Accesses the \Ref{MolecularInformation} visitor of {\em *this} molecularControl.
					This method is used in the method \Ref{generateListViewItem_} to
					retrieve certain information of the given \Ref{Composite} object.
					@return  Information a reference to a \Ref{Information} visitor.
					@see     MolecularInformation
					@see     generateListViewItem_
			*/
		  virtual Information& getInformationVisitor_()
				throw();

			/** Recursive iteration method.
					Iterates over the children of the \Ref{Composite} {\em composite} and
					calls for each of these children the method \Ref{generateListViewItem_}.
					@param   item a pointer to a \Ref{QListViewItem} to which all children of {\em composite} will be inserted
					@param   composite a pointer to a \Ref{Composite} object whose children will be inserted into {\em item}
					@see     generateListViewItem_
			*/
			virtual void recurseGeneration_(QListViewItem* item, Composite* composite)
				throw();
			
			/** Recursive update method.
					Iterates over the children of the \Ref{Composite} {\em composite} and
					calls for each of these children the method \Ref{updateListViewItem_}.
					@param   item a pointer to a \Ref{QListViewItem} containing the subtree structure 
					@param   composite a pointer to a \Ref{Composite} object containing the (possibly) new substructure
					@return  bool {\tt true} if the subtree structure of {\em composite} and the subtree structure of 
												{\em item} are unequal, {\tt false} otherwise 
					@see     updateListViewItem_
			*/
			virtual bool recurseUpdate_(QListViewItem* item, Composite* composite)
				throw();
		
			/** Message handling.
					Catches the \Ref{Message} objects and reacts accordingly to the different
					messages.
					\begin{itemize}
					  \item  \Ref{NewMolecularMessage} - update always necessary
					  \item  \Ref{RemovedCompositeMessage} - update necessary if already inserted
					  \item  \Ref{ChangedCompositeMessage} - update necessary if \Ref{Composite} object has changed
					\end{itemize}
					@param   message a pointer to the \Ref{Message} object
					@return  bool {\tt true} if an update of {\em *this} molecularControl is necessary, {\tt false} otherwise
					@see     onNotify
			*/
			virtual bool reactToMessages_(Message* message)
				throw();
			//@}
			
			void atomProperties_(Atom* atom)
				throw();

		private:
			
			// retrieves information of a given composite (name, type)
			MolecularInformation molecular_information_;

			// tests wether a composite holds the criterias
			MolecularFilter molecular_filter_;
		};

	} // namespace MOLVIEW

} // namespace BALL

#endif // BALL_MOLVIE_MOLVIEW_GUI_WIDGETS_MOLECULARCONTROL_H_
