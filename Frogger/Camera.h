#ifndef __CAMERA__
#define __CAMERA__

#include "Vector3.h"
#include "Entity.h"

#ifndef __GLUT__
#define __GLUT__
#include "GL/glut.h"
#endif


class Camera : public Entity {
	Vector3 _up;
	Vector3 _at;
	double _near;
	double _far;
	public:
		Camera(double near, double far);
		~Camera();
		double getNear();
		double getFar();
		void setUp(double x, double y, double z);
		void setAt(double x, double y, double z);
		Vector3 getUp();
		Vector3 getAt();
		virtual void update(GLsizei w, GLsizei h) = 0;
		virtual void computeProjectionMatrix() = 0;
		virtual void computeVisualizationMatrix() = 0;
};
#endif
