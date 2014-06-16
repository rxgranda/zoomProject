#include "Arco.h"


Arco::Arco(osg::Vec3f inicio,osg::Vec3f fin):Widget(""){		
	widgetGeometry=new osg::Geometry();
	osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array; 
	points->push_back(inicio); 
	points->push_back(fin); 
	osg::ref_ptr<osg::Vec4Array> colorl = new osg::Vec4Array; 
	colorl->push_back(osg::Vec4(0.0078f,0.01578f,0.6117f,1.0f)); 
	widgetGeometry->setVertexArray(points.get()); 
	widgetGeometry->setColorArray(colorl.get()); 
	widgetGeometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE); 
	widgetGeometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));		
	widgetGeode->addDrawable(widgetGeometry);
	widgetGeode->removeDrawable(texto);				
}

Arco::Arco(int x, int y, int z, int radio):Widget(""){		
	widgetGeometry=new osg::Geometry();
	osg::Vec3 sp(0,0,0); 
	osg::Vec3 ep(30,30,30); 	
	osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array; 
	points->push_back(sp); 
	points->push_back(ep); 
	osg::ref_ptr<osg::Vec4Array> colorl = new osg::Vec4Array; 
	colorl->push_back(osg::Vec4(0.0078f,0.01578f,0.6117f,1.0f)); 
	widgetGeometry->setVertexArray(points.get()); 
	widgetGeometry->setColorArray(colorl.get()); 
	widgetGeometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE); 
	widgetGeometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));		
	widgetGeode->addDrawable(widgetGeometry);
	widgetGeode->removeDrawable(texto);				
}
	

Arco::~Arco(void)
{
}
