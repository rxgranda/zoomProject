#pragma once
#include "widget.h"
class Arco :
	public Widget
{
public:
	Arco(osg::Vec3f inicio,osg::Vec3f fin);
	Arco(int x=0, int y=0, int z=0, int radio=1);
	virtual void cambiarTransparencia(float transparencia);
	virtual osg::Vec3f getBorde ();
	virtual osg::ref_ptr<Widget> clone();
	virtual osg::ref_ptr< osg::Node> getWidget();

	~Arco(void);
};