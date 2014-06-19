#pragma once
#include "widget.h"
#include <osg/ShapeDrawable>


class Esfera :
	public Widget
{
public:
	Esfera(std::string nombre,int x=0, int y=0, int z=0, int radio=1);
	Esfera(const Esfera& rhs);
	~Esfera(void);
	
	osg::ref_ptr<osg::ShapeDrawable> unitSphereDrawable;
	osg::ref_ptr<osg::Sphere> unitSphere;
	osg::ref_ptr<osg::StateSet> state; 
	osg::ref_ptr<osg::LOD> lod; 
	static int renderOrder;

	static const float TRANSPACENCIA_LOD_1;
	static const float TRANSPACENCIA_LOD_2;
	static const float TRANSPACENCIA_LOD_3;
	static const float TRANSPACENCIA_LOD_4;
	static const float TRANSPACENCIA_LOD_5;
	static const float TRANSPACENCIA_LOD_6;
	
	
	static int getRenderOrder();
	void setText(std::string nombre);
	virtual osg::Vec3f getBorde ();
	virtual void cambiarTransparencia(float transparencia);
	virtual osg::ref_ptr<Widget> clone();
	virtual osg::ref_ptr< osg::Node> getWidget();

private:
	static void transparencia( osg::ref_ptr<osg::Geode> geode);
};


