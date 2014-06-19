#pragma once
#include "widget.h"
class Plano :
	public Widget
{
public:
	Plano(int opt=0);
	~Plano(void);
	virtual void cambiarTransparencia(float transparencia);	
	virtual osg::Vec3f getBorde ();
	virtual osg::ref_ptr<Widget> clone();
	virtual osg::ref_ptr< osg::Node> getWidget();

};