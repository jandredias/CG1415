#===================================================================
#============= DO NOT CHANGE ANYTHING AFTER THIS LINE ==============
#===================================================================
CC = g++

FLAGS = -std=c++11 -O3 -ggdb -Wall -pedantic -Wpedantic -pedantic-errors \
        -Wextra -w -Waggressive-loop-optimizations -Werror -pedantic-errors \
				-Wparentheses -Wunknown-pragmas -lGL -lGLU -lglut
#        -static-libstdc++

COMP = $(CC) $(FLAGS) -g -c

Frogger: App.o Background.o Bus.o Camera.o Car.o DynamicObject.o Entity.o Frog.o FrogTarget.o GameManager.o GameObject.o LightSource.o LimitMap.o OrthogonalCamera.o PerspectiveCamera.o Player.o Polygon.o River.o Riverside.o Road.o Roadside.o StaticObject.o StreetLamp.o Texture.o TimberLog.o Tunnel.o Turtle.o Vector3.o Vector4.o
	$(CC) $(FLAGS) -g *.o -o $@

App.o: App.cpp GameManager.h Camera.h Vector3.h Entity.h Player.h Frog.h DynamicObject.h GameObject.h Vector4.h LightSource.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

Background.o: Background.cpp Background.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h
	$(COMP) $(FLAGS) $< -o $@

Bus.o: Bus.cpp Bus.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h
	$(COMP) $(FLAGS) $< -o $@

Camera.o: Camera.cpp Camera.h Vector3.h Entity.h
	$(COMP) $(FLAGS) $< -o $@

Car.o: Car.cpp Car.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h LightSource.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

DynamicObject.o: DynamicObject.cpp DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h LightSource.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

Entity.o: Entity.cpp Entity.h Vector3.h
	$(COMP) $(FLAGS) $< -o $@

Frog.o: Frog.cpp Frog.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h LightSource.h StaticObject.h  River.h TimberLog.h Car.h FrogTarget.h LimitMap.h Riverside.h Roadside.h  StreetLamp.h
	$(COMP) $(FLAGS) $< -o $@

FrogTarget.o: FrogTarget.cpp FrogTarget.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h Polygon.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

GameManager.o: GameManager.cpp GameManager.h Camera.h Vector3.h Entity.h Player.h Frog.h DynamicObject.h GameObject.h Vector4.h LightSource.h StaticObject.h LimitMap.h FrogTarget.h Background.h Road.h Roadside.h River.h Riverside.h OrthogonalCamera.h PerspectiveCamera.h TimberLog.h Car.h Tunnel.h StreetLamp.h Bus.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

GameObject.o: GameObject.cpp GameObject.h Entity.h Vector3.h Vector4.h DynamicObject.h
	$(COMP) $(FLAGS) $< -o $@

LightSource.o: LightSource.cpp LightSource.h Vector4.h Vector3.h
	$(COMP) $(FLAGS) $< -o $@

LimitMap.o: LimitMap.cpp LimitMap.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h
	$(COMP) $(FLAGS) $< -o $@

OrthogonalCamera.o: OrthogonalCamera.cpp OrthogonalCamera.h Camera.h Vector3.h Entity.h
	$(COMP) $(FLAGS) $< -o $@

PerspectiveCamera.o: PerspectiveCamera.cpp Frog.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h FrogTarget.h StaticObject.h Background.h Road.h Roadside.h River.h Riverside.h OrthogonalCamera.h Camera.h PerspectiveCamera.h TimberLog.h Car.h
	$(COMP) $(FLAGS) $< -o $@

Player.o: Player.cpp Player.h Frog.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h LightSource.h GameManager.h Camera.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

Polygon.o: Polygon.cpp Polygon.h GameManager.h Camera.h Vector3.h Entity.h Player.h Frog.h DynamicObject.h GameObject.h Vector4.h LightSource.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

River.o: River.cpp River.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h Polygon.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

Riverside.o: Riverside.cpp Riverside.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h Polygon.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

Road.o: Road.cpp Road.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h Polygon.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

StaticObject.o: StaticObject.cpp StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h
	$(COMP) $(FLAGS) $< -o $@

StreetLamp.o: StreetLamp.cpp StreetLamp.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h
	$(COMP) $(FLAGS) $< -o $@

Texture.o: Texture.cpp Texture.h
	$(COMP) $(FLAGS) $< -o $@

Roadside.o: Roadside.cpp Roadside.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h Polygon.h Texture.h
	$(COMP) $(FLAGS) $< -o $@

TimberLog.o: TimberLog.cpp Polygon.h TimberLog.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h GameManager.h Camera.h Player.h Frog.h LightSource.h StaticObject.h
	$(COMP) $(FLAGS) $< -o $@

Tunnel.o: Tunnel.cpp Tunnel.h StaticObject.h GameObject.h Entity.h Vector3.h Vector4.h Texture.h GameManager.h Camera.h Player.h Frog.h DynamicObject.h LightSource.h
	$(COMP) $(FLAGS) $< -o $@

Vector3.o: Vector3.cpp Vector3.h
	$(COMP) $(FLAGS) $< -o $@

Turtle.o: Turtle.cpp Turtle.h DynamicObject.h GameObject.h Entity.h Vector3.h Vector4.h
	$(COMP) $(FLAGS) $< -o $@

Vector4.o: Vector4.cpp Vector4.h Vector3.h
	$(COMP) $(FLAGS) $< -o $@

clean:
	rm -f *.o Frogger
