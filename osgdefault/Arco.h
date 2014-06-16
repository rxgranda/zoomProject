#pragma once
#include "widget.h"
class Arco :
	public Widget
{
public:
	Arco(osg::Vec3f inicio,osg::Vec3f fin);
	Arco(int x=0, int y=0, int z=0, int radio=1);	
	~Arco(void);
};