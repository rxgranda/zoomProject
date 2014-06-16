#pragma once
#include <iostream>
#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osgText/Text>
#include <osg/PositionAttitudeTransform>
#include <osg/StateSet>
#include <osg/StateAttribute>
#include <osg/LightSource>
#include <osg/BlendFunc>

class Widget 
	:public osg::Node
{
public:
	
	// Arbol
	int numeroHijos;
	// OSG Utils
	osg::ref_ptr<osg::Geode> widgetGeode;	
	osg::ref_ptr<osg::Geometry> widgetGeometry;
	osg::ref_ptr<osg::PositionAttitudeTransform> widgetXForm;
	osg::ref_ptr<osgText::Text> texto;
	
	
	Widget (std::string nombre);
	~Widget(void);
		
	osg::ref_ptr< osg::Node> getWidget();
	void cambiarPosicion(int x=0 ,int  y=0 ,int z=0);
	virtual osg::Vec3f getBorde();
};

