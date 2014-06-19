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
#include <osg/LOD>

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
	
	Widget(const Widget& rhs){
		numeroHijos=rhs.numeroHijos;
		osg::PositionAttitudeTransform *widgetXFormTMP =new osg::PositionAttitudeTransform(*rhs.widgetXForm);
		widgetXForm=widgetXFormTMP;

	//widgetXForm=;
	//texto=;
	//unitSphere=new osg::ShapeDrawable(rhs.unitSphere);;	
	}
	Widget (std::string nombre){
			//Arbol
		numeroHijos=0;
		// OSG Utils
		widgetGeode= new osg::Geode();		
		widgetXForm= new osg::PositionAttitudeTransform();
		texto = new osgText::Text();
		widgetXForm->addChild(widgetGeode);
		cambiarPosicion();
		widgetGeode->addDrawable(texto);

		//Deshabilitar sombre del texto
		osg::ref_ptr<osg::StateSet> stateText  = widgetGeode->getOrCreateStateSet(); 
		stateText->setMode(GL_LIGHTING, osg::StateAttribute::ON);// To disable shadows in text
		stateText->setAttribute(new osg::Program(),osg::StateAttribute::PROTECTED);// To disable shadows in text
		widgetGeode->setStateSet(stateText);				

	};
	~Widget(void){}
		

	void cambiarPosicion(int x=0 ,int  y=0 ,int z=0){
		widgetXForm->setPosition(osg::Vec3(x,y,z));
	}
	virtual void cambiarTransparencia(float transparencia)=0;
	virtual osg::Vec3f getBorde()=0;
	virtual osg::ref_ptr<Widget> clone()=0;
	virtual osg::ref_ptr< osg::Node> getWidget()=0;
};

