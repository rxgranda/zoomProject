#pragma once
#include "widget.h"
#include <osg/ShapeDrawable>
class Esfera :
	public Widget
{
public:
	Esfera(std::string nombre, int x=0, int y=0, int z=0, int radio=1);
	~Esfera(void);
	
	osg::ref_ptr<osg::ShapeDrawable> unitSphereDrawable;
	osg::ref_ptr<osg::Sphere> unitSphere;
	osg::ref_ptr<osg::StateSet> state; 
	static int renderOrder;
	
	
	static int getRenderOrder();
	void setText(std::string nombre);
	osg::Vec3f getBorde();

private:
	void transparencia();
};


