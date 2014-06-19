#include "Nodo.h"

Nodo::Nodo(osg::ref_ptr<Widget> widgetResumen,std::vector<osg::ref_ptr<osg::Node>> widgetHijos, float distanciaDetalle, int level){
	grupo= new osg::Group();
	zoomIN = new osg::LOD();
	widgetXForm= new osg::PositionAttitudeTransform();
	zoomOUT=widgetResumen;
	hijos=widgetHijos;
	anadirHijo(widgetResumen, zoomOUT,grupo);
	std::vector<osg::ref_ptr<osg::Node>>::iterator v = widgetHijos.begin();

	while( v != widgetHijos.end()) {
		Nodo* nodo=dynamic_cast <Nodo*>(v->get());
		Widget* widget=dynamic_cast <Widget*>(v->get());
		if (widget==0){//Es NODO									
			anadirHijo(widgetResumen, nodo,grupo);				
		}else if(nodo==0){//es Widget				
			anadirHijo(widgetResumen, widget,grupo);
		}
		v++;
	}		
	zoomIN->addChild( grupo, 0.0f, distanciaDetalle );
	zoomIN->addChild( zoomOUT->getWidget() ,distanciaDetalle, FLT_MAX );
	cambiarPosicion();
	widgetXForm->addChild(zoomIN);
	nivel=level;
	//	widgetXForm->addChild(grupo);
}

void Nodo::cambiarPosicion(int x ,int  y ,int z){
	widgetXForm->setPosition(osg::Vec3(x,y,z));
}

osg::ref_ptr<osg::Node> Nodo::getNodo(){
	return this->widgetXForm;
}
void  Nodo::anadirHijo( osg::ref_ptr<Widget> padre, osg::ref_ptr<osg::Node> hijo,osg::ref_ptr<osg::Group> grupo){

	osg::BoundingSphere boundingSpherePadre=padre->getWidget()->getBound();

	osg::Vec3f centroPadre =boundingSpherePadre.center();
	osg::Vec3f centroPadre2=osg::Vec3f (centroPadre.x(),centroPadre.y(),centroPadre.z());
	Nodo* nodo=dynamic_cast <Nodo*>(hijo.get());
	Widget* widget=dynamic_cast <Widget*>(hijo.get());
	osg::BoundingSphere boundingSphereHijo;		

	if(nodo==0){
		boundingSphereHijo=widget->getWidget()->getBound();
		grupo->addChild(widget->getWidget());
	}else if(widget==0){
		boundingSphereHijo=nodo->getNodo()->getBound();
		grupo->addChild(nodo->getNodo());		
	}
	osg::Vec3f centroHijo=boundingSphereHijo.center();			
	osg::Vec3f centroHijo2=osg::Vec3f (centroHijo.x(),centroHijo.y(),centroHijo.z()+boundingSphereHijo.radius()/3);

	osg::ref_ptr<Widget> arco= new Arco(centroPadre2,centroHijo2);
	padre->numeroHijos++;
	grupo->addChild(arco->getWidget());		
}



Nodo::~Nodo(void)
{
}