#pragma once
#include"WidgetFactory.h"
#include <osg/LOD>

class Nodo :
	public osg::Node
{
public:

	osg::ref_ptr<osg::Group> grupo;
	osg::ref_ptr<osg::LOD> zoomIN ;
	osg::ref_ptr<osg::PositionAttitudeTransform> widgetXForm;
	osg::ref_ptr<Widget> zoomOUT;
	std::vector<osg::ref_ptr<osg::Node>> hijos;
	int nivel;

	Nodo(void);
	~Nodo(void);


	void static anadirHijo( osg::ref_ptr<Widget> padre, osg::ref_ptr<osg::Node> hijo,osg::ref_ptr<osg::Group> grupo);

	Nodo(osg::ref_ptr<Widget> widgetResumen,std::vector<osg::ref_ptr<osg::Node>> widgetHijos, float distanciaDetalle, int level);
	void cambiarPosicion(int x=0 ,int  y=0 ,int z=0);
	osg::ref_ptr<osg::Node> getNodo();
};