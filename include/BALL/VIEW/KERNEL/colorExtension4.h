// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: colorExtension4.h,v 1.12 2003/03/03 14:18:33 anhi Exp $

#ifndef BALL_VIEW_KERNEL_COLOREXTENSION4_H
#define BALL_VIEW_KERNEL_COLOREXTENSION4_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_VIEW_DATATYPE_COLOR_H
#	include <BALL/VIEW/DATATYPE/color.h>
#endif

#ifndef BALL_VIEW_KERNEL_COLOREXTENSION3_H
#	include <BALL/VIEW/KERNEL/colorExtension3.h>
#endif

namespace BALL
{
	
	namespace VIEW
	{
    /**  \addtogroup  ViewKernelGeometricPrimitives
     *  @{
     */
		/** ColorExtension4 class.
				The class ColorExtension4 is used as a base class for all geometric 
				objects that needs four colors  \link ColorRGBA ColorRGBA \endlink . It provides the derived
				class with methods for accessing these colors.
				<b>Definition:</b> BALL/VIEW/KERNEL/colorExtension4.h
		*/
		class ColorExtension4: public ColorExtension3
		{
			public:
		
			/**	@name	Constructors
			*/	
			//@{

			/** Default Constructor.
					Construct new colorExtension4.
					The colors of {\em *this} colorExtension4 are set to (0.0, 0.0, 0.0, 1.0).
					Calls  \link ColorExtension3 ColorExtension3 \endlink .
					@return      ColorExtension4 new constructed colorExtension4
					@see         ColorRGBA
					@see         ColorExtension3
			*/
			ColorExtension4()
				throw();

			/** Copy constructor.
					Construct new colorExtension4 by copying the colorExtension4 
					{\em color_extension}. The colors of {\em *this} colorExtension4 are
					initialized to the colors of {\em color_extension}.
					Calls  \link ColorExtension3 ColorExtension3 \endlink .
					@param       color_extension the colorExtension4 to be copied
					@return      ColorExtension4 new constructed colorExtension4 copied from {\em color_extension}
					@see         ColorRGBA
					@see         ColorExtension3
			*/
			ColorExtension4(const ColorExtension4& color_extension)
				throw();

			//@}

			/** @name Destructors */
			//@{

			/** Destructor.
					Default destruction of {\em *this} colorExtension4.
					Calls  \link destroy destroy \endlink .
					@see         destroy
			*/
			virtual ~ColorExtension4()
				throw();

			/** Explicit default initialization.
					Set the colors of {\em *this} colorExtension4 to the color 
					(0.0, 0.0, 0.0, 1.0).
					Calls  \link ColorExtension3::clear ColorExtension3::clear \endlink .
					Calls  \link ColorRGBA::clear ColorRGBA::clear \endlink .
					@see  ColorExtension3::clear
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
					Assign the colorExtension4 {\em color_extension} to {\em *this} 
					colorExtension4.
					The colors of {\em *this} colorExtension4 are initialized to the colors of 
					the colorExtension4 {\em color_extension}.
					Calls  \link ColorExtension3::set ColorExtension3::set \endlink .
					Calls  \link ColorRGBA::set ColorRGBA::set \endlink .
					@param       color_extension the colorExtension4 to be copied
					@see         ColorExtension3::set
					@see         ColorRGBA
					@see         ColorRGBA::set
			*/
			void set(const ColorExtension4& color_extension)
				throw();

			/** Assignment operator.
					Assign the colorExtension4 {\em color_extension} to {\em *this}
					colorExtension4.
					Calls  \link set set \endlink .
					The colors of {\em *this} colorExtension4 are initialized to the colors 
					of the colorExtension4 {\em color_extension}. \par
					@param       color_extension the colorExtension4 to be copied
					@return      ColorExtension4& constant reference of {\em *this} colorExtension4
					@see         set
			*/
			const ColorExtension4& operator = (const ColorExtension4& color_extension)
				throw();

			/** Copying.
					Copy {\em *this} colorExtension4 to the colorExtension4
					{\em color_extension}.
					Calls  \link set set \endlink .
					The colors of the colorExtension4 {\em color_extension} 
					are initialized to the colors of {\em *this} colorExtension4. \par
					@param       color_extension the colorExtension4 to be assigned to
					@see         set
			*/
			void get(ColorExtension4& color_extension) const
				throw();

			/** Swapping of colorExtensions.
					Swap the colors of {\em *this} colorExtension4 with the colorExtension4
					{\em color_extension}.
					Calls  \link ColorExtension3::swap ColorExtension3::swap \endlink .
					Calls  \link ColorRGBA::swap ColorRGBA::swap \endlink .
					@param       color_extension the colorExtension4 being swapped with {\em *this} colorExtension 
					@see         ColorExtension4
					@see         ColorExtension3::swap
					@see         ColorRGBA::swap
			*/
			void swap(ColorExtension4& color_extension)
				throw();
			//@}

			/**	@name	Accessors: inspectors and mutators 
			*/
			//@{

			/** Change the fourth color of {\em *this} colorExtension4.
					Change the fourth color of {\em *this} colorExtension4 to the color
					represented by the parameter {\em color}.
					@param       color the new fourth color of {\em *this} colorExtension4
					@see         getColor4
					@see         ColorRGBA
			*/
			void setColor4(const ColorRGBA& color)
				throw();
			
			/** Change the fourth color of {\em *this} colorExtension4.
					Change the fourth color of {\em *this} colorExtension4 to the color 
					represented	by the parameters {\em red}, {\em green}, {\em blue} and
					{\em alpha}.
					@param       red the red component of the new fourth color of {\em *this} colorExtension4
					@param       green the green component of the new fourth color of {\em *this} colorExtension4
					@param       blue the blue component of the new fourth color of {\em *this} colorExtension4
					@param       alpha the alpha component of the new fourth color of {\em *this} colorExtension4 (Default=255)
					@see         getColor4
					@see         ColorUnit
			*/
			void setColor4
				(const ColorUnit& red, const ColorUnit& green,
				 const ColorUnit& blue, const ColorUnit& alpha = 255)
				throw();
			
			/** Mutable inspection of the fourth color of {\em *this} colorExtension4.
					Access the mutual reference of the fourth color of {\em *this}
					colorExtension4.
					@return      ColorRGBA& mutable reference to the fourth color of {\em *this} colorExtension4
					@see         setColor4
					@see         ColorRGBA
			*/
			ColorRGBA& getColor4()
				throw();

			/** Non-mutable inspection of the fourth color of {\em *this} colorExtension4.
				  For further information see  \link getColor4 getColor4 \endlink .
			*/
			const ColorRGBA& getColor4() const
				throw();

			/** Inspection of the fourth color of {\em *this} colorExtension4.
					Access the fourth color of {\em *this} colorExtension4 by using
					 \link ColorRGBA ColorRGBA \endlink .
					@param       color the color receiving the fourth color of {\em *this} colorExtension4
					@see         setColor4
					@see         ColorRGBA
			*/
			void getColor4(ColorRGBA& color) const
				throw();

			/** Inspection of all the components of the fourth color of {\em *this} colorExtension4.
					Access all the components of the fourth color of {\em *this} colorExtension4
					by using  \link ColorUnit ColorUnit \endlink .
					@param       red the red component of the fourth color of {\em *this} colorExtension4
					@param       green the green component of the fourth color of {\em *this} colorExtension4
					@param       blue the blue component of the fourth color of {\em *this} colorExtension4
					@param       alpha the alpha component of the fourth color of {\em *this} colorExtension4
					@see         setColor4
					@see         ColorUnit
			*/
			void getColor4
				(ColorUnit& red, ColorUnit& green,
				 ColorUnit& blue, ColorUnit& alpha) const
				throw();

			/** Inspection of the components of the fourth color of {\em *this}
					colorExtension4.
					Access only the red, green and blue components of the fourth color 
					of {\em *this} colorExtension4	by using  \link ColorUnit ColorUnit \endlink .
					@param       red the red component of the fourth color of {\em *this} colorExtension4
					@param       green the green component of the fourth color of {\em *this} colorExtension4
					@param       blue the blue component of the fourth color of {\em *this} colorExtension4
					@see         setColor4
					@see         ColorUnit
			*/
			void getColor4
				(ColorUnit& red, ColorUnit& green, ColorUnit& blue) const
				throw();

			/** Change the first, second, third and fourth color of {\em *this} colorExtension4.
					Change the first, second, third and fourth color of {\em *this} colorExtension4
					to the colors	represented by the parameters {\em a}, {\em b}, {\em c} and
					{\em d}.
					Calls  \link ColorExtension3::setColors ColorExtension3::setColors \endlink .
					@param       a the new first color of {\em *this} colorExtension4
					@param       b the new second color of {\em *this} colorExtension4
					@param       c the new third color of {\em *this} colorExtension4
					@param       d the new fourth color of {\em *this} colorExtension4
					@see         getColors
					@see         ColorExtension3::setColors
					@see         ColorRGBA
			*/
			void setColors
				(const ColorRGBA& a, const ColorRGBA& b,
				 const ColorRGBA& c, const ColorRGBA& d)
				throw();
				
			/** Inspection of the first, second, third and fourth color of {\em *this}
					colorExtension4.
					Access the first, second, third and fourth color of {\em *this} colorExtension4
					by using  \link ColorRGBA ColorRGBA \endlink .
					Calls  \link ColorExtension3::getColors ColorExtension3::getColors \endlink .
					@param       a the color receiving the first color of {\em *this} colorExtension4
					@param       b the color receiving the second color of {\em *this} colorExtension4
					@param       c the color receiving the third color of {\em *this} colorExtension4
					@param       d the color receiving the fourth color of {\em *this} colorExtension4
					@see         setColors
					@see         ColorExtension3::getColors
					@see         ColorRGBA
			*/
			void getColors
				(ColorRGBA& a, ColorRGBA& b,
				 ColorRGBA& c, ColorRGBA& d) const
				throw();

			//@}
			
			/**	@name	debuggers and diagnostics
			*/	
			//@{

			/** Internal value dump.
					Dump the current state of {\em *this} colorExtension4 to 
					the output ostream {\em s} with dumping depth {\em depth}.
					@param   s output stream where to output the state of {\em *this} colorExtension4
					@param   depth the dumping depth
					@see     ColorRGBA::operator <<
			*/
			virtual void dump(std::ostream& s = std::cout, Size depth = 0) const
				throw();
			//@}

			private:
		
			/* color 4 */
			ColorRGBA color4_;
		};


#		ifndef BALL_NO_INLINE_FUNCTIONS
#			include <BALL/VIEW/KERNEL/colorExtension4.iC>
#		endif
    /** @} */
	} // namespace VIEW

} // namespace BALL

#endif // BALL_VIEW_KERNEL_COLOREXTENSION4_H 
