// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Bus.h"
#include "Camera.h"
#include "Car.h"
#include "DynamicObject.h"
#include "Entity.h"
#include "Frog.h"
#include "GameManager.h"
#include "GameObject.h"
#include "LightSource.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "River.h"
#include "Riverside.h"
#include "Road.h"
#include "Roadside.h"
#include "StaticObject.h"
#include "Timberlog.h"
#include "Turtle.h"
#include "Vector3.h"
#include "Vector4.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Vector4 a;
	a.set(1, 2, 3, 4);
	std::cout << a.getW();
	return 0;
}

