// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: colorExtension5.h,v 1.13 2003/03/14 11:50:22 sturm Exp $

#ifndef BALL_VIEW_KERNEL_COLOREXTENSION5_H
#define BALL_VIEW_KERNEL_COLOREXTENSION5_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_VIEW_DATATYPE_COLOR_H
#	include <BALL/VIEW/DATATYPE/color.h>
#endif

#ifndef BALL_VIEW_KERNEL_COLOREXTENSION4_H
#	include <BALL/VIEW/KERNEL/colorExtension4.h>
#endif

namespace BALL
{

	namespace VIEW
	{
    /**  \addtogroup  ViewKernelGeometricPrimitives
     *  @{
     */
		/** ColorExtension5 class.
				The class ColorExtension5 is used as a base class for all geometric 
				objects that needs five colors  \link ColorRGBA ColorRGBA \endlink . It provides the derived
				class with methods for accessing these colors.
				
		*/
		class ColorExtension5: public ColorExtension4
		{
			public:
					
			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new colorExtension5.
					The colors of {\em *this} colorExtension5 are set to (0.0, 0.0, 0.0, 1.0).
					Calls  \link ColorExtension4 ColorExtension4 \endlink .
					@return      ColorExtension5 new constructed colorExtension5
					@see         ColorRGBA
					@see         ColorExtension4
			*/
			ColorExtension5()
				throw();

			/** Copy constructor.
					Construct new colorExtension5 by copying the colorExtension5 
					{\em color_extension}. The colors of {\em *this} colorExtension5 are
					initialized to the colors of {\em color_extension}.
					Calls  \link ColorExtension4 ColorExtension4 \endlink .
					@param       color_extension the colorExtension5 to be copied
					@return      ColorExtension5 new constructed colorExtension5 copied from {\em color_extension}
					@see         ColorRGBA
					@see         ColorExtension4
			*/
			ColorExtension5(const ColorExtension5& color_extension)
				throw();

			//@}

			/** @name Destructors */
			//@{

			/** Destructor.
					Default destruction of {\em *this} colorExtension5.
					Calls  \link destroy destroy \endlink .
					@see         destroy
			*/
			virtual ~ColorExtension5()
				throw();

			/** Explicit default initialization.
					Set the colors of {\em *this} colorExtension5 to the color 
					(0.0, 0.0, 0.0, 1.0).
					Calls  \link ColorExtension4::clear ColorExtension4::clear \endlink .
					Calls  \link ColorRGBA::clear ColorRGBA::clear \endlink .
					@see  ColorExtension4::clear
					@see  ColorRGBA::clear
			*/
			virtual void clear()
				throw();

			/** Explicit destructor.
					Empty for further purpose.
			*/
			virtual void destroy()
				throw();
		
			//@}
			
			/**	@name	Assignment methods
			*/
			//@{

			/** Assignment.
					Assign the colorExtension5 {\em color_extension} to {\em *this} 
					colorExtension5.
					The colors of {\em *this} colorExtension5 are initialized to the colors of 
					the colorExtension5 {\em color_extension}.
					Calls  \link ColorExtension4::set ColorExtension4::set \endlink .
					Calls  \link ColorRGBA::set ColorRGBA::set \endlink .
					@param       color_extension the colorExtension5 to be copied
					@see         ColorExtension4::set
					@see         ColorRGBA
					@see         ColorRGBA::set
			*/
			void set(const ColorExtension5& color_extension)
				throw();

			/** Assignment operator.
					Assign the colorExtension5 {\em color_extension} to {\em *this}
					colorExtension5.
					Calls  \link set set \endlink .
					The colors of {\em *this} colorExtension5 are initialized to the colors 
					of the colorExtension5 {\em color_extension}. \par
					@param       color_extension the colorExtension5 to be copied
					@return      ColorExtension5& constant reference of {\em *this} colorExtension5
					@see         set
			*/
			const ColorExtension5& operator = (const ColorExtension5& color_extension)
				throw();

			/** Copying.
					Copy {\em *this} colorExtension5 to the colorExtension5
					{\em color_extension}.
					Calls  \link set set \endlink .
					The colors of the colorExtension5 {\em color_extension} 
					are initialized to the colors of {\em *this} colorExtension5. \par
					@param       color_extension the colorExtension5 to be assigned to
					@see         set
			*/
			void get(ColorExtension5& color_extension) const
				throw();

			/** Swapping of colorExtensions.
					Swap the colors of {\em *this} colorExtension5 with the colorExtension5
					{\em color_extension}.
					Calls  \link ColorExtension4::swap ColorExtension4::swap \endlink .
					Calls  \link ColorRGBA::swap ColorRGBA::swap \endlink .
					@param       color_extension the colorExtension5 being swapped with {\em *this} colorExtension 
					@see         ColorExtension5
					@see         ColorExtension4::swap
					@see         ColorRGBA::swap
			*/
			void swap(ColorExtension5& color_extension)
				throw();
			//@}

			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{

			/** Change the fifth color of {\em *this} colorExtension5.
					Change the fifth color of {\em *this} colorExtension5 to the color
					represented by the parameter {\em color}.
					@param       color the new fifth color of {\em *this} colorExtension5
					@see         getColor5
					@see         ColorRGBA
			*/
			void setColor5(const ColorRGBA& color)
				throw();
			
			/** Change the fifth color of {\em *this} colorExtension5.
					Change the fifth color of {\em *this} colorExtension5 to the color 
					represented	by the parameters {\em red}, {\em green}, {\em blue} and
					{\em alpha}.
					@param       red the red component of the new fifth color of {\em *this} colorExtension5
					@param       green the green component of the new fifth color of {\em *this} colorExtension5
					@param       blue the blue component of the new fifth color of {\em *this} colorExtension5
					@param       alpha the alpha component of the new fifth color of {\em *this} colorExtension5 (Default=255)
					@see         getColor5
					@see         ColorUnit
			*/
			void setColor5
				(const ColorUnit& red, const ColorUnit& green,
				 const ColorUnit& blue, const ColorUnit& alpha = 255)
				throw();
			
			/** Mutable inspection of the fifth color of {\em *this} colorExtension5.
					Access the mutual reference of the fifth color of {\em *this}
					colorExtension5.
					@return      ColorRGBA& mutable reference to the fifth color of {\em *this} colorExtension5
					@see         setColor5
					@see         ColorRGBA
			*/
			ColorRGBA& getColor5()
				throw();

			/** Non-mutable inspection of the fifth color of {\em *this} colorExtension5.
					For further information see  \link getColor5 getColor5 \endlink .
			*/
			const ColorRGBA& getColor5() const
				throw();

			/** Inspection of the fifth color of {\em *this} colorExtension5.
					Access the fifth color of {\em *this} colorExtension5 by using
					 \link ColorRGBA ColorRGBA \endlink .
					@param       color the color receiving the fifth color of {\em *this} colorExtension5
					@see         setColor5
					@see         ColorRGBA
			*/
			void getColor5(ColorRGBA& color) const
				throw();

			/** Inspection of all the components of the fifth color of {\em *this} colorExtension5.
					Access all the components of the fifth color of {\em *this} colorExtension5
					by using  \link ColorUnit ColorUnit \endlink .
					@param       red the red component of the fifth color of {\em *this} colorExtension5
					@param       green the green component of the fifth color of {\em *this} colorExtension5
					@param       blue the blue component of the fifth color of {\em *this} colorExtension5
					@param       alpha the alpha component of the fifth color of {\em *this} colorExtension5
					@see         setColor5
					@see         ColorUnit
			*/
			void getColor5
				(ColorUnit& red, ColorUnit& green,
				 ColorUnit& blue, ColorUnit& alpha) const
				throw();

			/** Inspection of the components of the fifth color of {\em *this}
					colorExtension5.
					Access only the red, green and blue components of the fifth color 
					of {\em *this} colorExtension5	by using  \link ColorUnit ColorUnit \endlink .
					@param       red the red component of the fifth color of {\em *this} colorExtension5
					@param       green the green component of the fifth color of {\em *this} colorExtension5
					@param       blue the blue component of the fifth color of {\em *this} colorExtension5
					@see         setColor5
					@see         ColorUnit
			*/
			void getColor5
				(ColorUnit& red, ColorUnit& green, ColorUnit& blue) const
				throw();

			/** Change the first, second, third, fourth and fifth color of {\em *this} 
					colorExtension5.
					Change the first, second, third, fourth and fifth color of {\em *this}
					colorExtension5	to the colors	represented by the parameters 
					{\em a}, {\em b}, {\em c}, {\em d} and {\em e}.
					Calls  \link ColorExtension4::setColors ColorExtension4::setColors \endlink .
					@param       a the new first color of {\em *this} colorExtension5
					@param       b the new second color of {\em *this} colorExtension5
					@param       c the new third color of {\em *this} colorExtension5
					@param       d the new fourth color of {\em *this} colorExtension5
					@param       e the new fifth color of {\em *this} colorExtension5
					@see         getColors
					@see         ColorExtension4::setColors
					@see         ColorRGBA
			*/
			void setColors
				(const ColorRGBA& a,
				 const ColorRGBA& b,
				 const ColorRGBA& c,
				 const ColorRGBA& d,
				 const ColorRGBA& e)
				throw();
				
			/** Inspection of the first, second, third, fourth and fifth color of {\em *this}
					colorExtension5.
					Access the first, second, third, fourth and fifth color of {\em *this}
					colorExtension5	by using  \link ColorRGBA ColorRGBA \endlink .
					Calls  \link ColorExtension4::getColors ColorExtension4::getColors \endlink .
					@param       a the color receiving the first color of {\em *this} colorExtension5
					@param       b the color receiving the second color of {\em *this} colorExtension5
					@param       c the color receiving the third color of {\em *this} colorExtension5
					@param       d the color receiving the fourth color of {\em *this} colorExtension5
					@param       e the color receiving the fifth color of {\em *this} colorExtension5
					@see         setColors
					@see         ColorExtension4::getColors
					@see         ColorRGBA
			*/
			void getColors
				(ColorRGBA& a, ColorRGBA& b,
				 ColorRGBA& c, ColorRGBA& d,
				 ColorRGBA& e) const
				throw();

			//@}
			
			/**	@name	debuggers and diagnostics
			*/	
			//@{

			/** Internal value dump.
					Dump the current state of {\em *this} colorExtension5 to 
					the output ostream {\em s} with dumping depth {\em depth}.
					@param   s output stream where to output the state of {\em *this} colorExtension5
					@param   depth the dumping depth
					@see     ColorRGBA::operator <<
			*/
			virtual void dump
				(std::ostream& s = std::cout, Size depth = 0) const
				throw();
			//@}

			private:
		
			/* color 5 */
			ColorRGBA color5_;
		};


#		ifndef BALL_NO_INLINE_FUNCTIONS
#			include <BALL/VIEW/KERNEL/colorExtension5.iC>
#		endif
  /** @} */
	} // namespace VIEW

} // namespace BALL

#endif // BALL_VIEW_KERNEL_COLOREXTENSION5_H 
