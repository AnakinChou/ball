// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//

#ifndef BALL_VIEW_RENDERING_RENDERINGWINDOW_H
#define BALL_VIEW_RENDERING_RENDERINGWINDOW_H

#include <BALL/COMMON/global.h>
#include <BALL/VIEW/RENDERING/renderTarget.h>

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

///Macro checks at compile time, whether <tt>aTypeA</tt> and <tt>aTypeB</tt> are the same
#define BALLVIEW_IS_SAME_TYPE(aTypeA, aTypeB) (boost::is_same<aTypeA, aTypeB>::value)

///Macro checks at compile time, whether <tt>aType</tt> is int or float
#define BALLVIEW_STATIC_ASSERT_TYPE_IS_INT_OR_FLOAT(aType)				                                \
        BOOST_STATIC_ASSERT(BALLVIEW_IS_SAME_TYPE(aType, int) || BALLVIEW_IS_SAME_TYPE(aType, float))

namespace BALL
{
	namespace VIEW
    {        
        /**
         * General rendering window interface.
         * Such a window represents a surface on a screen or other device, where a buffer encapsulated by
         * \link RenderTarget \endlink interface can be displayed
         */
		template<typename taPixelDatatype>
		class BALL_VIEW_EXPORT RenderWindow : public RenderTarget
		{
		    // only int or floats are allowed as template parameters
            BALLVIEW_STATIC_ASSERT_TYPE_IS_INT_OR_FLOAT(taPixelDatatype);
            
            // type of the pixel buffer pointer
            typedef boost::shared_ptr<taPixelDatatype> t_PixelPtr;

		public:
			
            RenderWindow();

            virtual ~RenderWindow();            

            /* Initialize window internals. After that call, window is ready to receive \link resize \endlink call             
             * returns false if the initialization fails
			 */
			virtual bool init();

			/** 
             * Request new window size. 
             * Returns false if such a size cannot be supplied
             * This call must be made before the window buffer is handed out to be rendered.
             * This precondition is being checked automatically, see \link getBuffer \endlink
             */ 
			virtual bool resize(const unsigned int width, const unsigned int height);
            
			/**
             * Request that the image is actually displayed on the screen or other device the window encapsulated.
             * You should implement this method in subclass.
             * This is different from \link RenderTarget \endlink \link releaseBuffer \endlink.
             * ReleaseBuffer only informs the window that a buffer is ready, but does not imply the buffer is actually
             * displayed somewhere. This is done by refresh. On the other hand, refresh called inbetween
             * getBuffer and releaseBuffer has no effect.
             */ 
			virtual void refresh();


			/* =====================
             * RenderTarget methods
             * ===================== */	

            /*
             * See \link RenderTarget \endlink for general description.
             * In addition there is a precondition that \link init \endlink must be called before 
             * getBuffer. If not, \link NoBufferAvailable \endlink exception is thrown.
             */
            virtual FrameBufferPtr getBuffer() throw(BALL::Exception::NoBufferAvailable);            

            /*
             * See \link RenderTarget \endlink for description.
             */
			virtual FrameBufferFormat getFormat() const;

            /*
             * See \link RenderTarget \endlink for description.
             */
			virtual void releaseBuffer(FrameBufferPtr buffer);			

		protected:
			t_PixelPtr m_pixels;					// raw pixel buffer
            FrameBufferPtr m_framebuffer;           // frame buffer given out to the wild by getBuffer method
			FrameBufferFormat m_fmt;				// description of the buffer format
            const PixelFormat m_pfm;                // pixel format of the window
			bool m_bufferLocked;					// pixel buffer is being accessed by another object?            
            const unsigned int m_minimalWidth;      // minimum with the window can have
            const unsigned int m_minimalHeight;     // minimum height the window can have
		};

        typedef RenderWindow<float> t_RenderWindow;

	} // namespace VIEW

} // namespace BALL

#endif // BALL_VIEW_RENDERING_RENDERINGWINDOW_H
