#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include "GL/glut.h"
#include "Vector4.h"
class GameObject : public Entity
{
	Vector3 _size;
	public:
		GameObject();
		virtual ~GameObject();
		void defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
								GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
								GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
								GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
								GLfloat se);
		virtual void draw() = 0;
		void setSize(double x, double y, double z);
		Vector3 getSize();
};


#endif
