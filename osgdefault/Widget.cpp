#include "Widget.h"


Widget::~Widget(void)
{
}

Widget::Widget (std::string nombre){
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
	stateText->setMode(GL_LIGHTING, osg::StateAttribute::OFF);// To disable shadows in text
	stateText->setAttribute(new osg::Program(),osg::StateAttribute::PROTECTED);// To disable shadows in text
	widgetGeode->setStateSet(stateText);				
}

osg::ref_ptr<osg::Node> Widget::getWidget(){
	return this->widgetXForm;
}


void Widget::cambiarPosicion(int x ,int  y ,int z){
	widgetXForm->setPosition(osg::Vec3(x,y,z));
}

osg::Vec3f Widget::getBorde(){				
	return 	osg::Vec3f(0,0,0);
}		