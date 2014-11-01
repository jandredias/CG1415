
#include "GameObject.h"
#include "DynamicObject.h"
#include "Vector4.h"
GameObject::GameObject(){}
GameObject::~GameObject(){}

void GameObject::setSize(double x, double y, double z){ _size.set(x, y, z); }
Vector3 GameObject::getSize(){ return _size; }
void GameObject::defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
								GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
								GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
								GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
								GLfloat Se){
	GLfloat Ka[] = { Ka_r, Ka_g, Ka_b, Ka_w };
	GLfloat Kd[] = { Kd_r, Kd_g, Kd_b, Kd_w };
	GLfloat Ks[] = { Ks_r, Ks_g, Ks_b, Ks_w };
	GLfloat Ke[] = { Ke_r, Ke_g, Ke_b, Ke_w };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ks);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Ke);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &Se);
}
