// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//

#ifndef BALL_VIEW_RENDERING_RENDERTARGET_H
#define BALL_VIEW_RENDERING_RENDERTARGET_H

#include <BALL/COMMON/global.h>
#include <BALL/COMMON/exception.h>

#include <assert.h>
#include <vector>
#include <boost/smart_ptr.hpp>

#include <BALL/VIEW/RENDERING/pixelFormat.h>

namespace BALL
{
	namespace VIEW
	{

		/** Stores a resolution consisting of width and height. */
		struct Resolution
		{
			unsigned int width;
			unsigned int height;

			Resolution() : width(0), height(0) { }
		    
			Resolution(const unsigned width, const unsigned int height) : width(width),height(height) { }
		};


		/** This is used by the RenderTarget to specify in which formats it can
		 *  provide buffers.
		 */
		class FrameBufferFormat
		{
		public:

			/** Constructs empty invalid framebuffer format */
			FrameBufferFormat() : 
				width(0), height(0), pitch(0), pixelFormat(PixelFormat::RGB_32)
			{ }

			FrameBufferFormat(const unsigned int width,
							  const unsigned int height, const PixelFormat &pixelFormat)
				: width(width), height(height), 
				  pitch(width * pixelFormat.computeByteSize()), 
				  pixelFormat(pixelFormat)
			{
				assert(pitch >= width * pixelFormat.computeByteSize());
			}

			FrameBufferFormat(const unsigned int width, const unsigned int height,
							  const unsigned int pitch, const PixelFormat &pixelFormat )
				: width(width), height(height), pitch(pitch), pixelFormat(pixelFormat)
			{
				assert(pitch >= width * pixelFormat.computeByteSize());
			}

			FrameBufferFormat(const FrameBufferFormat &format)
				: width(format.width), height(format.height), 
				  pitch(format.pitch), pixelFormat(format.pixelFormat)
			{
			}

			const FrameBufferFormat &operator=(const FrameBufferFormat &format)
			{
				width = format.width;
				height = format.height;
				pitch = format.pitch;
				pixelFormat = format.pixelFormat;
				return *this;
			}

			bool operator==(const FrameBufferFormat& format) const
			{
				return width==format.width && height==format.height &&
					   pitch==format.pitch && pixelFormat==format.pixelFormat;
			}

			bool operator!=(const FrameBufferFormat& format) const
			{
				return width!=format.width || height!=format.height ||
					   pitch!=format.pitch || pixelFormat!=format.pixelFormat;
			}

			bool isValid() const { return width > 0 && height > 0 && pitch > 0; }

			/** Returns width of writeable area of buffers in this format, 
			 *  in pixels.
			 */
			unsigned int getWidth() const { return width; }

			/** Sets width of writeable area of buffers in this format, 
			 *  in pixels.
			 */
			void setWidth(unsigned int width) { this->width = width; }

			/** Returns height of buffers in this format, in pixels. */
			unsigned int getHeight() const { return height; }

			/** Sets height of buffers in this format, in pixels. */
			void setHeight(unsigned int height) { this->height = height; }

			/** Returns actual line width of buffers in this format, in bytes */
			unsigned int getPitch() const { return pitch; }

			/** Sets actual line width of buffers in this format, in bytes */
			void setPitch(unsigned int pitch) { this->pitch = pitch; }

			/** Returns pixel format of buffers in this format */
			const PixelFormat &getPixelFormat() const { return pixelFormat; }
		    
			/** Sets pixel format of buffers in this format */
			void setPixelFormat(const PixelFormat &pixelFormat)
			{ this->pixelFormat = pixelFormat; }

			/** Computes size of the framebuffer with this format:
			 *  size = pitch * height
			 */
			size_t computeSize() const
			{
				// pitch is in bytes
				return isValid() ? (getPitch() * getHeight()) : 0;
			}

			/** Modify width and height of this format */
			void resize(const unsigned int newWidth, const unsigned int newHeight)
			{
				this->width = newWidth;
				this->height = newHeight;
			}

			/** Returns new FrameBufferFormat where width and height are
			 *  replaced by specified values.
			 */
			const FrameBufferFormat resized(const unsigned int newWidth, 
											const unsigned int newHeight) const
			{
				return FrameBufferFormat(newWidth, newHeight, pitch, pixelFormat);
			}

		private:
			/** Width of writeable area of this buffer, in pixels. */
			unsigned int width;

			/** Height of buffers in this format, in pixels. */
			unsigned int height;

			/** Actual line width of this buffer. You can compute the beginning of a
			 *  line as firstPixel + pitch * lineNr.
			 *  Unlike width and height, the pitch is measured in bytes. This may be
			 *  needed in cases where the pitch is not a multiple of the byte size of
			 *  a single pixel.
			 */
			unsigned int pitch;

			PixelFormat pixelFormat;
		};

		inline std::ostream &operator<<(std::ostream &o, const FrameBufferFormat &f)
		{
			o << f.getWidth() << "x" << f.getHeight() << ", pitch " << f.getPitch()
			  << ", pixel format: " << f.getPixelFormat();
			return o;
		}

		typedef std::vector<FrameBufferFormat> BufferFormatList;

		//-----------------------------------------------------------------------------

		class FrameBuffer
		{
		public:

			/** Constructs new FrameBuffer instance with the specified 
			 *  data and format.
			 */
			FrameBuffer( void* data, const FrameBufferFormat &format ) :
				data(data), format(format)
			{
			}

			/** You can override this if you want the data array to be deleted with the
			 *  FrameBuffer.
			 */
			virtual ~FrameBuffer() {}

			/** Returns pointer to the data of this buffer */
			void *getData() { return data; }

			/** Returns const pointer to the data of this buffer */
			const void *getData() const { return data; }

			/** Returns the format of this buffer */
			const FrameBufferFormat &getFormat() const { return format; }

		protected:

			/** Sets pointer to the data of this buffer */
			void setData(void *data) { this->data = data; }

			/** Sets the format of this buffer */
			void setFormat(const FrameBufferFormat &format) { this->format = format; }

		private:
			/**
			 *  This points to the memory area where the rendering results should
			 *  be written to (the first pixel of the result).
			 */
			void *data;

			/**
			 *  The format of this buffer.
			 */
			FrameBufferFormat format;
		};

		typedef boost::shared_ptr<FrameBuffer> FrameBufferPtr;
		
		//-----------------------------------------------------------------------------

		class RenderTarget
		{
		  public:

			virtual ~RenderTarget() { }

			/** Returns a buffer where the image data can be stored in the format
			 *  specified in the constructor.
			 *  The buffer will remain valid until update() is called with that buffer.
			 *  Each call to getBuffer() creates a new FrameBuffer.
			 *  If no new FrameBuffer can be created for this RenderTarget (e.g. if
			 *  the RenderTarget supports only a single buffer at a time), a
			 *  NoBufferAvailable exception is thrown.
			 */
            virtual FrameBufferPtr getBuffer() throw(BALL::Exception::NoBufferAvailable) = 0;

			virtual FrameBufferFormat getFormat() const = 0;

			/** Notify the RenderTarget that the buffer has changed.
			 *  The Renderer has to call this once it has filled the buffer
			 *  (i.e. after each frame).
			 *  This may cause the buffer to become invalid. Therefore, the Renderer
			 *  should get a new buffer for the next frame (with getBuffer()).
			 */
			virtual void releaseBuffer(FrameBufferPtr buffer) = 0;

		};

	} //namespace VIEW

} // namespace BALL

#endif // BALL_VIEW_RENDERING_RENDERTARGET_H 
