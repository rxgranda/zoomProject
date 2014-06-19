#include "Esfera.h"

int Esfera::renderOrder=20000;
const float Esfera::TRANSPACENCIA_LOD_1= 0.0f;
const float Esfera::TRANSPACENCIA_LOD_2= 0.25f;
const float Esfera::TRANSPACENCIA_LOD_3= 0.5f;
const float Esfera::TRANSPACENCIA_LOD_4= 0.75f;
const float Esfera::TRANSPACENCIA_LOD_5= 0.85f;
const float Esfera::TRANSPACENCIA_LOD_6= 0.93f;

Esfera::Esfera(std::string nombre, int x, int y, int z, int radio):Widget(nombre){		
	lod = new osg::LOD();
	//osg::Geode* g=dynamic_cast<osg::Geode*>(widgetGeode.get());
	osg::ref_ptr <osg::Geode>geode1=new osg::Geode(*widgetGeode);
	osg::ref_ptr <osg::Geode> geode2=new osg::Geode(*widgetGeode);
	osg::ref_ptr <osg::Geode> geode3=new osg::Geode(*widgetGeode);
	osg::ref_ptr <osg::Geode> geode4=new osg::Geode(*widgetGeode);
	osg::ref_ptr <osg::Geode> geode5=new osg::Geode(*widgetGeode);
	osg::ref_ptr <osg::Geode> geode6=new osg::Geode(*widgetGeode);

	unitSphere = new osg::Sphere( osg::Vec3(x,y,z), radio);
	unitSphereDrawable = new osg::ShapeDrawable(unitSphere);
	unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,1.0));
	float heigh=radio/7;
	osg::ref_ptr<osg::Cylinder> cilindro = new osg::Cylinder( osg::Vec3(x,y,z), radio+radio/10,heigh );
	osg::ref_ptr<osg::ShapeDrawable> cilindroDrawable = new osg::ShapeDrawable(cilindro);	
	

	osg::ref_ptr<osg::Sphere> esfera1 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable1 = new osg::ShapeDrawable(esfera1);
	esferaDrawable1->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,Esfera::TRANSPACENCIA_LOD_1));
	geode1->addDrawable(esferaDrawable1);
	
	osg::ref_ptr<osg::Sphere> esfera2 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable2 = new osg::ShapeDrawable(esfera2);
	esferaDrawable2->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,Esfera::TRANSPACENCIA_LOD_2));
	geode2->addDrawable(esferaDrawable2);

	osg::ref_ptr<osg::Sphere> esfera3 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable3 = new osg::ShapeDrawable(esfera3);
	esferaDrawable3->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,Esfera::TRANSPACENCIA_LOD_3));
	geode3->addDrawable(esferaDrawable3);

	osg::ref_ptr<osg::Sphere> esfera4 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable4 = new osg::ShapeDrawable(esfera4);
	esferaDrawable4->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,TRANSPACENCIA_LOD_4));
	geode4->addDrawable(esferaDrawable4);

	osg::ref_ptr<osg::Sphere> esfera5 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable5 = new osg::ShapeDrawable(esfera5);
	esferaDrawable5->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,TRANSPACENCIA_LOD_5));
	geode5->addDrawable(esferaDrawable5);

	osg::ref_ptr<osg::Sphere> esfera6 = new osg::Sphere( osg::Vec3(x,y,z), radio);
	osg::ref_ptr<osg::ShapeDrawable> esferaDrawable6 = new osg::ShapeDrawable(esfera6);
	esferaDrawable6->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,TRANSPACENCIA_LOD_6));
	geode6->addDrawable(esferaDrawable6);
	
	geode6->addDrawable(cilindroDrawable);
	geode5->addDrawable(cilindroDrawable);
	geode4->addDrawable(cilindroDrawable);
	geode3->addDrawable(cilindroDrawable);
	geode2->addDrawable(cilindroDrawable);
	//geode1->addDrawable(cilindroDrawable);
	
//	lod->addChild( geode1, FLT_MIN, radio );
	lod->addChild( geode1, FLT_MIN, radio*1.2 );
	lod->addChild( geode2, radio*1.2,radio*3);
	lod->addChild( geode3, radio*3, radio*5);
	lod->addChild( geode4,radio*5, radio*7);
	lod->addChild( geode5,radio*7, radio*9);
	lod->addChild( geode6,radio*9, radio*11);
	lod->addChild( widgetGeode, radio*11, FLT_MAX );
	
	//lod->addChild( geode4, 0.0, FLT_MAX );

	widgetGeode->addDrawable(unitSphereDrawable);
	widgetGeode->addDrawable(cilindroDrawable);
	// color=new osg::Vec4f(1.0f,1.0f,1.0f,1.0f);
	cilindroDrawable->setColor(osg::Vec4(1,1,1,1));
	transparencia(widgetGeode);
	//transparencia(geode1);
	transparencia(geode2);
	transparencia(geode3);
	transparencia(geode4);
	this->widgetXForm->removeChild(widgetGeode);
	this->widgetXForm->addChild(lod);
	
	/*if(transparente){
		transparencia();
		unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,valorTransparencia));
	}else{
		unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,1));
	}*/
	setText(nombre);
}


Esfera::Esfera(const Esfera& rhs):Widget(rhs){
	unitSphereDrawable=new osg::ShapeDrawable(*rhs.unitSphereDrawable);
	this->numeroHijos=rhs.numeroHijos;
	//unitSphere=new osg::ShapeDrawable(rhs.unitSphere);;	
}
int Esfera::getRenderOrder(){
	return renderOrder--;
}
 void Esfera::transparencia( osg::ref_ptr<osg::Geode> geode){
	osg::ref_ptr<osg::StateSet> state = geode->getOrCreateStateSet(); 
	state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN); 
	state->setMode(GL_BLEND,osg::StateAttribute::ON); 
	state->setMode( GL_BLEND_DST_ALPHA, osg::StateAttribute::ON );		
	state->setRenderBinDetails(getRenderOrder(), "DepthSortedBin"); 		
	state->setMode( GL_CULL_FACE, osg::StateAttribute::ON );
	state->setAttributeAndModes(new osg::BlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA), osg::StateAttribute::ON);
	geode->setStateSet(state);
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


void Esfera::cambiarTransparencia(float transparencia){
	unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,transparencia));
}

osg::ref_ptr<Widget> Esfera::clone(){
	return new Esfera(*this);
}

osg::ref_ptr< osg::Node> Esfera::getWidget(){
	return this->widgetXForm;
	}

Esfera::~Esfera(void)
{
}
