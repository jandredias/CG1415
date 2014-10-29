#ifndef __ORTHOGONALCAMERA__
#define __ORTHOGONALCAMERA__
#include "Camera.h"
class OrthogonalCamera : public Camera
{
	double _left;
	double _right;
	double _bottom;
	double _top;
public:
	OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
	~OrthogonalCamera();
	void update(GLsizei w, GLsizei h);
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};


#endif