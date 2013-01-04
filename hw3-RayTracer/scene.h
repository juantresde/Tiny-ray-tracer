#include <vector>
#include <stack>
#include <sstream>
#include "object.h"
using namespace std;

void rightmultiply(const mat4 & M, stack<mat4> &transform_stack);

struct Camera {
	vec3 eye;
	vec3 center;
	vec3 up;
	float fovy ; // For field of view
	Camera(const vec3 &_eye, const vec3 &_center, const vec3 &_up, const float& _fovy) : 
		eye(_eye), center(_center), up(_up), fovy(_fovy) {}
	
	// Default camera configuration
	Camera() : eye(0.0,0.0,5.0), up(0.0,1.0,0.0), center(0.0,0.0,0.0) {}
};
struct Light
{
    vec3 positionOrDirection; // Light Positions for point light
 	vec3 transform; // Lights transformed by modelview
 	Color color; // Light Colors
 	
 	enum Type {directional, point};
 	Type type;
};

class Scene
{
private:
	bool readvals (stringstream &s, const int numvals, float *values) ;

public:
	Scene();
	~Scene();

	void readfile (const string &filename);
	Camera camera; 
	
	int width, height; // width and height 
	int maxDepth; 	   // max depth of ray tracing


	// Lighting parameter array, similar to that in the fragment shader
	vector<Light> lights;

 	Materials materials; // This is global material
    Color ambient;    // Ambient is global material
    float attenuation[3]; // Global attenuation
    
	// For multiple objects, read from a file.  
	vector<Object*> objects;

	vector<vec3> vertexBuffer, vertexBufferWithNormal; // vertex buffer
	vector<vec3> vertexNormalBuffer; // vertex normal, correspond to vertex with normal
};