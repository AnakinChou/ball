// $Id: molecularSurfaceGrid.h,v 1.6.2.1 2002/11/12 16:29:35 anker Exp $

#ifndef BALL_SOLVATION_MOLECULARSURFACEGRID_H
#define BALL_SOLVATION_MOLECULARSURFACEGRID_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

#ifndef BALL_MATHS_VECTOR3_H
#	include <BALL/MATHS/vector3.h>
#endif

#ifndef BALL_KERNEL_SYSTEM_H
#	include <BALL/KERNEL/system.h>
#endif

#ifndef BALL_DATATYPE_REGULARDATA3D_H
# include <BALL/DATATYPE/regularData3D.h>
#endif

// ?????
// I am an ugly hack. Fixme.
#define CCONN__OUTSIDE 1
#define CCONN__INSIDE  0
#define	CCONN__INSIDE_PROBE 128

namespace BALL 
{
	///
	TRegularData3D<char>* calculateSESGrid(const Vector3& lower, const Vector3& upper, 
														const float spacing, 
														const System& system, 
														const float probe_radius);

	///
	TRegularData3D<char>* calculateSASGrid(const Vector3& lower, const Vector3& upper, 
														const float spacing, 
														const System& system, 
														const float probe_radius);

} // namespace BALL

#endif // BALL_SOLVATION_MOLECULARSURFACEGRID_H
