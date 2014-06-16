#include "Plano.h"

Plano::Plano(int opt):Widget(""){    
	widgetGeometry=new osg::Geometry();        
	// note, anticlockwsie ordering.
	osg::Vec3 myCoords[] =
	{
		osg::Vec3(1000, 1000,0),
		osg::Vec3(-1000, 1000,0),
		osg::Vec3(-1000, -1000,0),
		osg::Vec3(1000,  -1000,0),           
	}; 
	osg::Vec3 myCoords2[] =
	{
		osg::Vec3(1000, 0,1000),
		osg::Vec3(-1000,0, 1000),
		osg::Vec3(-1000,0, -1000),
		osg::Vec3(1000, 0, -1000),           
	}; 
	int numCoords = sizeof(myCoords)/sizeof(osg::Vec3);      
	osg::ref_ptr<osg::Vec3Array> vertices;
	
	if (opt==0)
		vertices= new osg::Vec3Array(numCoords,myCoords);
	else
		vertices= new osg::Vec3Array(numCoords,myCoords2);

	widgetGeometry->setVertexArray(vertices);             
	osg::ref_ptr<osg::Vec4Array> colorl = new osg::Vec4Array; 

	if(opt==0)
		colorl->push_back(osg::Vec4(0.7098f,0.7098f,0.7098f,1.0f));
	else
		colorl->push_back(osg::Vec4(0,0,0,1.0f)); 	

	widgetGeometry->setColorArray(colorl.get()); 
	widgetGeometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE); 
	widgetGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,numCoords));                       
	widgetGeode->addDrawable(widgetGeometry);    
	widgetGeode->removeDrawable(texto);
}

Plano::~Plano(void)
{
}
