// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
//


#ifndef QSAR_EXCEPTION
#define QSAR_EXCEPTION

#ifndef BALL_COMMON_EXCEPTION_H
#include <BALL/COMMON/exception.h>
#endif


namespace BALL 
{
	namespace QSAR
	{
		namespace Exception
		{
			/** Exception for the case of given activity values <0 or activity values that are larger than the number of properties in the current input file */
			class InvalidActivityID : public BALL::Exception::GeneralException
			{
				public:
					InvalidActivityID(const char* file, unsigned long line, int act, int m) throw();
					
					InvalidActivityID(const char* file, unsigned long line) throw();
			};		
					
			/** Exception for wrong number of properties or wrong format of properties within structure input files */
			class PropertyError : public BALL::Exception::GeneralException
			{
				public:
					PropertyError(const char* file, unsigned long line, const char* sd_file, int mol, const char* mess="") throw();
			};
	
			
			/** Exception for singular, i.e. non-invertible, matrices */
			class SingularMatrixError : public BALL::Exception::GeneralException
			{
				public:
					SingularMatrixError(const char* file, unsigned long line, const char* mess="") throw();
			};

			
			/** class for errors that are due to inconsistent use of methods by the user; e.g. requesting training of a model before some data has been read ... */
			class InconsistentUsage : public BALL::Exception::GeneralException
			{
				public:
					InconsistentUsage(const char* file, unsigned long line, const char* mess="") throw();
			};

			
			/** Exception for creation of a kernel with wrong parameters */
			class KernelParameterError : public BALL::Exception::GeneralException
			{
				public:
					KernelParameterError(const char* file, unsigned long line, const char* mess) throw();
			};

			
			/** Wrong type of input data for a model, e.g. non-discrete y-values for a classification model */
			class WrongDataType : public BALL::Exception::GeneralException
			{
				public:
					WrongDataType(const char* file, unsigned long line, const char* mess) throw();
			};
			
			/** No variance present to be explained by PCA, so that PCR can not be done */
			class NoPCAVariance : public BALL::Exception::GeneralException
			{
				public:
					NoPCAVariance(const char* file, unsigned long line, const char* mess) throw();
			};

			/** exception for creation of a model with wrong number of parameters or with wrong types of parameters */
			class ModelParameterError : public BALL::Exception::GeneralException
			{
				public:
					ModelParameterError(const char* file, unsigned long line, const char* mess) throw();
			};
			
			/** There may not be more PLS components than features */
			class TooManyPLSComponents : public BALL::Exception::GeneralException
			{
				public:
					TooManyPLSComponents(const char* file, unsigned long line, int comp, int features) throw();
			};

			/** File format observed for an input data file (sdf-file) does not fit the expected file format */
			class WrongFileFormat : public BALL::Exception::GeneralException
			{
				public:
					WrongFileFormat(const char* file, unsigned long line, const char* input_file) throw();
			};
			
			/** exception for specification of an invalid parameters for feature selection */
			class FeatureSelectionParameterError : public BALL::Exception::GeneralException
			{
				public:
					FeatureSelectionParameterError(const char* file, unsigned long line, const char* mess) throw();
			};
			
			/** exception that is thrown when parameters are missing or incorrect within an config-file section */
			class ConfigurationReadingError : public BALL::Exception::GeneralException
			{
				public: 
					ConfigurationReadingError(const char* file, unsigned long line, const char* message) throw();
			};


		}
	}
}


#endif // QSAR_EXCEPTION

