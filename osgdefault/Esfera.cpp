#include "Esfera.h"

int Esfera::renderOrder=20;

Esfera::Esfera(std::string nombre, int x, int y, int z, int radio):Widget(nombre){		
	unitSphere = new osg::Sphere( osg::Vec3(x,y,z), radio);
	unitSphereDrawable = new osg::ShapeDrawable(unitSphere);
	widgetGeode->addDrawable(unitSphereDrawable);
	// color=new osg::Vec4f(1.0f,1.0f,1.0f,1.0f);
	unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,0.50f));
	transparencia();
	setText(nombre);
}

int Esfera::getRenderOrder(){
	return renderOrder--;
}
void Esfera::transparencia(){
	state = widgetGeode->getOrCreateStateSet(); 
	state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN); 
	state->setMode(GL_BLEND,osg::StateAttribute::ON); 
	state->setMode( GL_BLEND_DST_ALPHA, osg::StateAttribute::ON );		
	state->setRenderBinDetails(getRenderOrder(), "DepthSortedBin"); 		
	state->setMode( GL_CULL_FACE, osg::StateAttribute::ON );
	state->setAttributeAndModes(new osg::BlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA), osg::StateAttribute::ON);
	widgetGeode->setStateSet(state);
}

void Esfera::setText(std::string nombre){
	texto->setCharacterSize(unitSphere->getRadius()*0.25);
	texto->setFont("C:/WINDOWS/Fonts/impact.ttf");
	texto->setText(nombre);
	texto->setAxisAlignment(osgText::Text::SCREEN);
	osg::Vec3f posicion=unitSphere->getCenter();		  		  
	texto->setPosition(  osg::Vec3(posicion.x(),posicion.y(),posicion.z()+unitSphere->getRadius()+1));
	texto->setColor( osg::Vec4(199, 77, 15, 1) );
}

osg::Vec3f Esfera::getBorde(){
	osg::Vec3f centro=unitSphere->getCenter();
	osg::Vec3f borde=osg::Vec3f(centro.x(),centro.y(),centro.z()+unitSphere->getRadius());
	return borde;

}

Esfera::~Esfera(void)
{
}
