// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: regularData2DWidget.h,v 1.23 2003/03/26 13:08:59 sturm Exp $

#ifndef BALL_VIEW_GUI_WIDGET_REGULARDATA2DWIDGET_H
#define BALL_VIEW_GUI_WIDGET_REGULARDATA2DWIDGET_H

#include <qlabel.h>
#include <qwidget.h>
#include <qstatusbar.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qscrollview.h>
#include <qpopupmenu.h>

#include <iostream>
#include <fstream>
#include <string>

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_CONCEPT_COMPOSITE_H
# include <BALL/CONCEPT/composite.h>
#endif

#ifndef BALL_VIEW_KERNEL_MESSAGE_H
# include <BALL/VIEW/KERNEL/message.h>
#endif

#ifndef BALL_VIEW_GUI_WIDGETS_MODULARWIDGET_H
#	include <BALL/VIEW/GUI/WIDGETS/modularWidget.h>
#endif

#ifndef BALL_VIEW_GUI_KERNEL_MAINCONTROL_H
# include <BALL/VIEW/GUI/KERNEL/mainControl.h>
#endif

#ifndef BALL_FORMAT_BRUKER2DFILE_H
# include <BALL/FORMAT/bruker2DFile.h>
#endif

#ifndef BALL_DATATYPE_REGULARDATA2D_H
# include <BALL/DATATYPE/regularData2D.h>
#endif

#ifndef BALL_FORMAT_JCAMPFILE_H
# include <BALL/FORMAT/JCAMPFile.h>
#endif

#ifndef BALL_DATATYPE_CONTOUR_H
# include <BALL/DATATYPE/contour.h>
#endif

#ifndef BALL_VIEW_GUI_DIALOGS_DLGMOVEOVERLAY_H
# include <BALL/VIEW/GUI/DIALOGS/dlgMoveOverlay.h>
#endif

namespace BALL
{
	namespace VIEW
	{
/** New RegularData2D Message Class.
\ingroup ViewGuiWidgets
 */
class NewRegularData2DMessage
	: public CompositeMessage
{
	
	public:
	 
  /** @name Constructors and Destructors
   */
  //@{
	
	///
  NewRegularData2DMessage();

	///
  NewRegularData2DMessage(const CompositeMessage& message, bool deep = true);

	///
  virtual ~NewRegularData2DMessage()
		throw();
	
  //@}
	
};

/** RegularData2DWidget.
\ingroup ViewGuiWidgets
 */
class RegularData2DWidget 
	: public QScrollView,
    public ModularWidget
{
  Q_OBJECT
		
	public:

	BALL_EMBEDDABLE(RegularData2DWidget)

	///
  RegularData2DWidget(int lx_, int ly_, double min = 0, double max = 1., QWidget* parent = 0);

	///
  RegularData2DWidget(const RegularData2DWidget& widget);

	///
  ~RegularData2DWidget()
		throw();

  /** Create a legend of width w, height h.
   */
  void createLegend( int w, int h );

  /** Scales the data in the rectangle (x1, y1, x2, y2) to the dimensions nx, ny.
   */
  void scale(Size nx, Size ny, double x1, double y1, double x2, double y2);

  /** Creates a lorentzian "peak" in the (interpolated) data with width xwidth, ywidth, amplitude amp 
   *  and maximum at xpos, ypos.
   */
  void addLorentzian(double xpos, double ypos, double amp, int xwidth = 1, int ywidth = 1);

  /** Decides whether the coordinates (x, y) (in regular-data coordinates) are visible and if so,
	 		returns the Position in the Pixmap.
  */
  bool isVisibleAs(double x, double y, pair<Position, Position>& res);

	///
  void onNotify(Message* message)
		throw();

	public slots:
	
	///
  bool reactToMessages_(Message* message);

	///
  void paintEvent(QPaintEvent* );

	///
  void drawContents(QPainter *paint, int clipx, int clipy, int clipw, int cliph);

	///
  void resizeEvent(QResizeEvent* );

	///
  void NewMousePos(Position x, Position y);

	///
  void Selected(QPoint beg, QPoint end);

	///
  void slotZoomOut();
 
	///
  void enterEvent(QEvent* );

	///
  void leaveEvent(QEvent* );

	///
  void mousePressEvent(QMouseEvent* e);
  
  /**	@name	ModularWidget related methods
   */
  //@{
	
  /**	Setup the menu entries.
			RegularData2DWidget creates an entry in Tools|RegularData2DWidget and connects
			the entry to createPlot()
  */
  virtual void initializeWidget(MainControl& main_control);
	// throw();
					
  /**	Remove menu entries.
   */
  virtual void finalizeWidget(MainControl& main_control);
	//  throw();
	
  //@}

  void createPlot();

  /** Creates a new contour plot erasing all former plots.
   */
  void createContour();

  /** Display the data as contour-plot.
   */
  void plotContour();

  /** Create a contour plot as an overlay over the pixmap we are using right now.
   */
  void plotOverlay();

	///
  void slotOverlayMove(int i);

	///
  void plot();

	///
  void viewportMousePressEvent(QMouseEvent* e);

	///
  void viewportMouseMoveEvent(QMouseEvent* e);

	///
  void viewportMouseReleaseEvent(QMouseEvent* e);

	///
  void mouseReleaseEvent(QMouseEvent* e);

 protected:

	//_
  void eraseSelectFrame();

	//_
  void drawSelectFrame();

	//_
  Position legend_last_x_, legend_last_y_;

  /*_ Length of original data. 
	 */
  Size lengthx_, lengthy_;

  /*_ Length of field (after interpolation). 
	 */
  Size full_length_x_, full_length_y_;

  /*_ Range. 
	 */
  double min_, max_;

  /*_ Flag that decides whether to plot mousepos or not. 
	 */
  bool showMousePos_;

  /*_ Shows mouse position.
	 */
  QLabel* posLabel_;

  /*_ Stores the spectrum 
	 */
  RegularData2D* spec_;

  /*_ Context-menu 
	 */
  QPopupMenu *men_;

  /*_ If we zoom into the data, we have to store the position of the lower left corner of the
     	area we are looking at at the moment and we have to know a zoom - factor.
  */
  double xvis_low_, xvis_high_, yvis_low_, yvis_high_;

	//_
  Position act_lower_left_x_;

	//_
  Position act_lower_left_y_;

	//_
  double zoom_x_;

	//_
  double zoom_y_;

  /*_ This class creates and stores a number of contour-lines 
	 */
  Contour* cont_;

  /*_ The number and range of the contour-lines we want to plot. 
	 */
  Size cont_num_;

	//_
  double cont_start_, cont_end_;

	//_
  DlgMoveOverlay* mvover_;

	//_
  Position ind_side_, ind_updown_;

  /*_ These variables store the parameters of the spectrum 
	 */
  Size spec_length_x_, spec_length_y_;
 
	//_
  QPixmap *pm_, *legend_map_;
  
  /*_ This pixmap is intended to hold the contour-lines 
	 */
  QPixmap *pm_cont_;

  /*_ decide if we plot contour-lines 
	 */
  bool plot_cont_;

  /*_ decide if we plot the data itself 
	 */
  bool plot_data_;

  /*_ If a selection is in progress, the coordinate of the first endpoint of the
	    selected rectangle is stored in here.
  */
  QPoint last_selection_;

  /*_ If a selection is in progress, the coordinate of the actual endpoint of the 
     	selected rectangle is stored in here.
  */
  QPoint selection_;

	//_
  bool select_;

	//_
  QStatusBar *stat_;

	//_
  QWidget *legend_wid_;

	//_
  bool isOverlay_;
	
};
  
} } // namespaces

#endif
