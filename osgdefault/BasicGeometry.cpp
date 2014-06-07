

#include <vector>

#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osgText/Text>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>



#include <osg/LOD>
#include <osgDB/ReadFile>
#include <osgUtil/Simplifier>
#include <osgViewer/Viewer>

#include <osg/StateSet>
   #include <osg/StateAttribute>

   #include <osg/LightSource>
   #include <osg/BlendFunc>

#include"tinyxml\tinyxml.h"
#include"tinyxml\tinystr.h"



#define TAMANO_TEXTO 1
using namespace osg;
using namespace osgDB;
using namespace osgUtil;
using namespace osgViewer;
class Widget : public osg::Node {
	public: 
		// Arbol
		int numeroHijos;

		// OSG Utils
		ref_ptr<osg::Geode> widgetGeode;
		ref_ptr<osg::Geode> widgetGeodeSimp;
		ref_ptr<osg::Geometry> widgetGeometry;
		ref_ptr<osg::PositionAttitudeTransform> widgetXForm;
		ref_ptr<osgText::Text> texto;
		
		Widget (std::string nombre){

			//Arbol
			numeroHijos=0;
			// OSG Utils
			widgetGeode= new osg::Geode();
			widgetGeodeSimp= new osg::Geode();
			widgetXForm= new osg::PositionAttitudeTransform();
			texto = new osgText::Text();
			widgetXForm->addChild(widgetGeode);
			cambiarPosicion();
			setText(nombre);
			widgetGeode->addDrawable(texto);
			//widgetGeodeSimp->addDrawable(texto);
		}

		ref_ptr< osg::Node> getWidget(){
			return this->widgetXForm;
		}

		void setText(std::string nombre){
		   texto->setCharacterSize(0.3);
		   texto->setFont("C:/WINDOWS/Fonts/impact.ttf");
		   texto->setText(nombre);
		   texto->setAxisAlignment(osgText::Text::SCREEN);
		   texto->setPosition( osg::Vec3(-0.5,0,-1.5) );
		   texto->setColor( osg::Vec4(199, 77, 15, 1) );
		}
		void cambiarPosicion(int x=0 ,int  y=0 ,int z=0){
			widgetXForm->setPosition(osg::Vec3(x,y,z));
		}


		

};

class Esfera: public  Widget{
	public:
		ref_ptr<osg::ShapeDrawable> unitSphereDrawable;
		ref_ptr<osg::Sphere> unitSphere;
		 ref_ptr<osg::StateSet> state; 
		
		//centro y radio
		Esfera(std::string nombre, int x=0, int y=0, int z=0, int radio=1):Widget(nombre){
			
			 unitSphere = new osg::Sphere( osg::Vec3(x,y,z), radio);
			 unitSphereDrawable = new osg::ShapeDrawable(unitSphere);
			 widgetGeode->addDrawable(unitSphereDrawable);
			// color=new osg::Vec4f(1.0f,1.0f,1.0f,1.0f);
			 unitSphereDrawable->setColor(osg::Vec4(0.3843f,0.39245f,0.5412f,0.50f));
			 transparencia();
		}

		void transparencia(){
			state = widgetGeode->getOrCreateStateSet(); 
			state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN); 
			state->setAttributeAndModes(new osg::BlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA), osg::StateAttribute::ON);
			widgetGeode->setStateSet(state);
		
		}

};


class Arco: public  Widget{
	public:
	
		Arco(int x=0, int y=0, int z=0, int radio=1):Widget(""){		
				widgetGeometry=new osg::Geometry();
				osg::Vec3 sp(0,0,0); 
				osg::Vec3 ep(1,1,1); 	
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

		Arco(osg::Vec3f inicio,osg::Vec3f fin):Widget(""){		
				widgetGeometry=new osg::Geometry();
			//	osg::Vec3 sp(0,0,0); 
				//osg::Vec3 ep(1,1,1); 	
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
			//	widgetGeode->removeDrawable(texto);		
		}


};



class Plano: public Widget{
public: 
	Plano():Widget(""){    
        // create Geometry object to store all the vetices and lines primtive.
       widgetGeometry=new osg::Geometry();        
        // note, anticlockwsie ordering.
        osg::Vec3 myCoords[] =
        {
            osg::Vec3(100, 100,0),
            osg::Vec3(-100, 100,0),
            osg::Vec3(-100, -100,0),
            osg::Vec3(100,  -100,0),           
        };        
        int numCoords = sizeof(myCoords)/sizeof(osg::Vec3);      
        osg::Vec3Array* vertices = new osg::Vec3Array(numCoords,myCoords);       
        widgetGeometry->setVertexArray(vertices);             
        // This time we simply use primitive, and hardwire the number of coords to use 
        // since we know up front,
		osg::ref_ptr<osg::Vec4Array> colorl = new osg::Vec4Array; 
		colorl->push_back(osg::Vec4(0.7098f,0.7098f,0.7098f,1.0f)); 				
		widgetGeometry->setColorArray(colorl.get()); 
		widgetGeometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE); 
        widgetGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,numCoords));                       
        widgetGeode->addDrawable(widgetGeometry);    
		widgetGeode->removeDrawable(texto);
	}
};

class WidgetFactory{
	public:
		static ref_ptr<Widget> nuevoWidget( std::string nombre,int tipo=0){
			ref_ptr<Widget> elemento;
			switch (tipo)
			{
			  case 1:
				 elemento=new Esfera(nombre);
				 break;
				case 2:
				 elemento=new Arco;
				 break;
				 case 3:
				 elemento=new Plano;
				 break;
			  default:
				 elemento=new Esfera(nombre);
				 break;
			}
			return elemento;
		}



		




};

class Nodo :public osg::Node{

	public:
		ref_ptr<osg::Group> grupo;
		ref_ptr<LOD> zoomIN ;
		ref_ptr<osg::PositionAttitudeTransform> widgetXForm;
		ref_ptr<Widget> zoomOUT;
		std::vector<ref_ptr<osg::Node>> hijos;
		
		int nivel;

		Nodo(ref_ptr<Widget> widgetResumen,std::vector<ref_ptr<osg::Node>> widgetHijos, float distanciaDetalle, int level){
			grupo= new osg::Group();
			zoomIN = new LOD();
			widgetXForm= new osg::PositionAttitudeTransform();
			zoomOUT=widgetResumen;
			//WidgetFactory::
			anadirHijo(widgetResumen, zoomOUT,grupo);
			//std::vector<ref_ptr<Widget>>::iterator v = widgetHijos.begin();			
		
			std::vector<ref_ptr<osg::Node>>::iterator v = widgetHijos.begin();
			
			while( v != widgetHijos.end()) {
				//WidgetFactory::
				Nodo* nodo=dynamic_cast <Nodo*>(v->get());
				Widget* widget=dynamic_cast <Widget*>(v->get());
				if (widget==0){
					//Es NODO
					//osg::Widget widget=
					//anadirHijo(widgetResumen, v->get(),grupo);
					//hijos.push_back(v->get());
				}else if(nodo==0){
					//es Widget
					anadirHijo(widgetResumen, widget,grupo);
					hijos.push_back(v->get());
				}
				v++;
			}
			/*std::vector<ref_ptr<Widget>>::iterator v = widgetHijos.begin();
			
			while( v != widgetHijos.end()) {
				//WidgetFactory::
				anadirHijo(widgetResumen, v->get(),grupo);
				hijos.push_back(v->get());
				v++;
			}*/
			zoomIN->addChild( grupo, 0.0f, distanciaDetalle );
			//zoomIN->addChild( zoomOUT->getWidget() ,distanciaDetalle, FLT_MAX );
			cambiarPosicion();
			
			widgetXForm->addChild(zoomIN);
			nivel=level;
			//widgetXForm->addChild(widgetResumen);

		}

		/*Nodo(ref_ptr<Widget> widgetResumen,std::vector<ref_ptr<Nodo>> nodosHijos, float distanciaDetalle, int level){
			nodos=nodosHijos;
			grupo= new osg::Group();
			zoomIN = new LOD();
			widgetXForm= new osg::PositionAttitudeTransform();
			zoomOUT=widgetResumen;
			//WidgetFactory::
			anadirHijo(widgetResumen, zoomOUT,grupo);
			std::vector<ref_ptr<Nodo>>::iterator v = nodosHijos.begin();
			while( v != nodosHijos.end()) {
				ref_ptr<LOD> zoomin=v->get()->zoomIN;
				//WidgetFactory::
				anadirNodoHijo(zoomOUT,zoomin ,grupo);
				v++;
			}
			zoomIN->addChild( grupo, 0.0f, distanciaDetalle );
		//	zoomIN->addChild( zoomOUT->getWidget() ,distanciaDetalle, FLT_MAX );
			cambiarPosicion();
			widgetXForm->addChild(zoomIN);
			nivel=level;
		}
		*/
		
		void cambiarPosicion(int x=0 ,int  y=0 ,int z=0){
			widgetXForm->setPosition(osg::Vec3(x,y,z));
		}

		ref_ptr<osg::Node> getNodo(){
			return this->widgetXForm;
		}
		


		void static anadirHijo( ref_ptr<Widget> padre, ref_ptr<Widget> hijo,ref_ptr<osg::Group> grupo){
			
			 osg::BoundingSphere boundingSpherePadre=padre->getWidget()->getBound();
			 osg::Vec3f centroPadre =boundingSpherePadre.center();
			 osg::BoundingSphere boundingSphereHijo=hijo->getWidget()->getBound();
			 osg::Vec3f centroHijo=boundingSphereHijo.center();			
			/* std::cout <<centroPadre.x()<<std::endl;
			 std::cout <<centroPadre.y()<<std::endl;
			 std::cout <<centroPadre.z()<<std::endl;
			  std::cout <<centroHijo.x()<<std::endl;
			 std::cout <<centroHijo.y()<<std::endl;
			 std::cout <<centroHijo.z()<<std::endl;*/
			// osg::Vec3f nuevoCentroPadre =new ()

			 ref_ptr<Widget> arco= new Arco(centroPadre,centroHijo);
			 padre->numeroHijos++;
			 grupo->addChild(arco->getWidget());
			// grupo->addChild(padre->getWidget());
			 grupo->addChild(hijo->getWidget());
			 //grupo->addChild(padre->widgetGeodeSimp); no me acuerdo para que lo puse
			 
		}

		
		void static anadirNodoHijo( ref_ptr<Widget> padre, ref_ptr<LOD> hijo,ref_ptr<osg::Group> grupo){
			
			 osg::BoundingSphere boundingSpherePadre=padre->getWidget()->getBound();
			 osg::Vec3f centroPadre =boundingSpherePadre.center();
			 osg::BoundingSphere boundingSphereHijo=hijo->getChild(1)->getBound();
			 osg::Vec3f centroHijo=boundingSphereHijo.center();			
			/* std::cout <<centroPadre.x()<<std::endl;
			 std::cout <<centroPadre.y()<<std::endl;
			 std::cout <<centroPadre.z()<<std::endl;
			  std::cout <<centroHijo.x()<<std::endl;
			 std::cout <<centroHijo.y()<<std::endl;
			 std::cout <<centroHijo.z()<<std::endl;
			// osg::Vec3f nuevoCentroPadre =new ()*/

			 ref_ptr<Widget> arco= new Arco(centroPadre,centroHijo);
			// padre->numeroHijos++;
			 grupo->addChild(arco->getWidget());
			// grupo->addChild(padre->getWidget());
			 grupo->addChild(hijo);
			// grupo->addChild(padre->widgetGeodeSimp);
			 
		}
};

/*
void inicializarEscena(ref_ptr<Nodo> arbol){
	std::vector<ref_ptr<Widget>>::iterator v = arbol.begin();
			
			while( v != widgetHijos.end()) {
				WidgetFactory::anadirHijo(widgetResumen, v->get(),grupo);
				hijos.push_back(v->get());
				v++;
			}

}

*/

int main()
{
	
    osgViewer::Viewer viewer;
    
	ref_ptr<osg::Group> root = new osg::Group(); // root 
	


	
	ref_ptr<Widget> elemento=WidgetFactory::nuevoWidget("Seres vivos",0); // seres vivos
	ref_ptr<Widget> elemento2=WidgetFactory::nuevoWidget("Celulas Eucariontas",0);
	ref_ptr<Widget> elemento3=WidgetFactory::nuevoWidget("Celulas Procariontas",0);

		
	ref_ptr<Widget> elemento31=WidgetFactory::nuevoWidget("Virus",0);
	ref_ptr<Widget> elemento32=WidgetFactory::nuevoWidget("Bacterias",0);
	ref_ptr<Widget> elemento33=WidgetFactory::nuevoWidget("Cianofitas",0);

	ref_ptr<Widget> plano=WidgetFactory::nuevoWidget("",3);

	elemento2->cambiarPosicion(10,0,0);
	elemento3->cambiarPosicion(-10,0,0);
	elemento31->cambiarPosicion(-15,0,-2);
	elemento32->cambiarPosicion(-5,0,-2);
	elemento33->cambiarPosicion(-10,-7,-5);

	std::vector<ref_ptr<osg::Node>> hijos3;
	std::vector<ref_ptr<Nodo>> hijos;
	
	hijos3.push_back(elemento31);
	hijos3.push_back(elemento32);
	hijos3.push_back(elemento33);
	ref_ptr<Nodo> grupoProcariontas=new Nodo(elemento3,hijos3,20.0f,0);
	//hijos.push_back(grupoProcariontas);	
	//ref_ptr<Nodo> nodoraiz=new Nodo(elemento,hijos,30.0f, 1);

//	root->addChild(plano->getWidget());
	root->addChild(grupoProcariontas->getNodo());
	root->addChild(elemento3->getWidget());
//	root->addChild(nodoraiz->getNodo());

	/*hijos.push_back(elemento2);
	hijos.push_back(elemento3);
	ref_ptr<Nodo> nodoraiz=new Nodo(elemento,hijos,30.0f);


	root->addChild(elemento->getWidget());
	root->addChild(nodoraiz->getNodo());*/
	/*
	
	ref_ptr<osg::Group> seresvivos = new osg::Group(); //Seres vivos
	ref_ptr<LOD> seresvivosLOD = new LOD();

	ref_ptr<osg::Group> procariontas = new osg::Group(); //procariontas
	ref_ptr<LOD> procariontasLOD = new LOD();
	
	ref_ptr<osg::Group> eucariontas = new osg::Group(); //eucariontas
	ref_ptr<LOD> eucariontasLOD = new LOD();

	ref_ptr<osg::Group> flagelados = new osg::Group(); //eucariontas
	ref_ptr<LOD> flageladosLOD = new LOD();

	ref_ptr<osg::Group> algas = new osg::Group(); //eucariontas
	ref_ptr<LOD> algasLOD = new LOD();*/

	/*ref_ptr<Widget> elemento=WidgetFactory::nuevoWidget("Seres vivos",0); // seres vivos

	ref_ptr<Widget> elemento2=WidgetFactory::nuevoWidget("Celulas Eucariontas",0);
	ref_ptr<Widget> elemento21=WidgetFactory::nuevoWidget("Flagelados",0);
	
	ref_ptr<Widget> elemento21=WidgetFactory::nuevoWidget("Flagelados",0);
	


	ref_ptr<Widget> elemento211=WidgetFactory::nuevoWidget("Euloflagelados",0);
	ref_ptr<Widget> elemento212=WidgetFactory::nuevoWidget("Dinoflagelados",0);

	ref_ptr<Widget> elemento22=WidgetFactory::nuevoWidget("Algas",0);
	ref_ptr<Widget> elemento221=WidgetFactory::nuevoWidget("Doradas",0);
	ref_ptr<Widget> elemento222=WidgetFactory::nuevoWidget("Verdes",0);
	ref_ptr<Widget> elemento223=WidgetFactory::nuevoWidget("Rojas Pardas",0);


	ref_ptr<Widget> elemento23=WidgetFactory::nuevoWidget("Protozoarios",0);


	

	
	elemento2->cambiarPosicion(10,0,0);
	elemento21->cambiarPosicion(6,0,-2);
	elemento211->cambiarPosicion(3,1,-4);
	elemento212->cambiarPosicion(9,1,-4);

	elemento22->cambiarPosicion(15,0,-2);
	elemento221->cambiarPosicion(13,0,-4);
	elemento222->cambiarPosicion(17,0,-4);


	elemento23->cambiarPosicion(10,-5,-3);

	elemento3->cambiarPosicion(-10,0,0);
	elemento31->cambiarPosicion(-15,0,-2);
	elemento32->cambiarPosicion(-5,0,-2);
	elemento33->cambiarPosicion(-10,-7,-5);
	

	WidgetFactory::anadirHijo(elemento22,elemento221,algas);
	WidgetFactory::anadirHijo(elemento22,elemento222,algas);

	WidgetFactory::anadirHijo(elemento21,elemento211,flagelados);
	WidgetFactory::anadirHijo(elemento21,elemento212,flagelados);

	WidgetFactory::anadirHijo(elemento2,elemento21,eucariontas);
	WidgetFactory::anadirHijo(elemento2,elemento22,eucariontas);
	WidgetFactory::anadirHijo(elemento2,elemento23,eucariontas);

	WidgetFactory::anadirHijo(elemento3,elemento31,procariontas);
	WidgetFactory::anadirHijo(elemento3,elemento32,procariontas);
	WidgetFactory::anadirHijo(elemento3,elemento33,procariontas);

	WidgetFactory::anadirHijo(elemento,elemento2,seresvivos);
	WidgetFactory::anadirHijo(elemento,elemento3,seresvivos);

	
	
	algasLOD->addChild( algas, 0.0f, 15.0f );
//	flageladosLOD->addChild( elemento21->getWidget() ,15.0f, FLT_MAX );
	flageladosLOD->addChild( flagelados, 0.0f, 15.0f );


	//eucariontasLOD->addChild( elemento2->getWidget() ,20.0f, FLT_MAX );
	eucariontasLOD->addChild( eucariontas, 0.0f, 20.0f );

	
	//procariontasLOD->addChild( elemento3->getWidget() ,20.0f, FLT_MAX );
	procariontasLOD->addChild( procariontas, 0.0f, 20.0f );

	seresvivosLOD->addChild( elemento->getWidget() ,30.0f, FLT_MAX );
	seresvivosLOD->addChild( seresvivos, 0.0f, 30.0f );

	root->addChild(seresvivosLOD);
	root->addChild(procariontasLOD);
	root->addChild(eucariontasLOD);
	root->addChild(flageladosLOD);
	root->addChild(algasLOD);
	//elemento2->cambiarPosicion(10,0,0);
	//elemento3->cambiarPosicion(-10,0,0);
	//procariontas->


	/*
	*/






	
	/*
	
	
	
	ref_ptr<Widget> elemento2211=WidgetFactory::nuevoWidget("Crisofitas",0);
	ref_ptr<Widget> elemento2212=WidgetFactory::nuevoWidget("Pirrofitas",0);


	
	ref_ptr<Widget> elemento2221=WidgetFactory::nuevoWidget("Unicelulares",0);
	ref_ptr<Widget> elemento2222=WidgetFactory::nuevoWidget("Pluricelulares",0);





	
	ref_ptr<Widget> elemento231=WidgetFactory::nuevoWidget("Ciliados",0);
	ref_ptr<Widget> elemento232=WidgetFactory::nuevoWidget("Sacordarios",0);
	ref_ptr<Widget> elemento233=WidgetFactory::nuevoWidget("Mastigoforos",0);
	ref_ptr<Widget> elemento234=WidgetFactory::nuevoWidget("Cuiudosporidos",0);
	ref_ptr<Widget> elemento235=WidgetFactory::nuevoWidget("Sporozoarios",0);


	*/

	/**/
		
	



	/*elemento4->cambiarPosicion(2,0,0);
	elemento5->cambiarPosicion(9,0,0);
	elemento6->cambiarPosicion(12,0,0);*/
	
	
	//root->addChild(elemento->getWidget());
	/*root->addChild(elemento2->getWidget());
	root->addChild(elemento3->getWidget());*/




	/*
	WidgetFactory::anadirHijo(elemento,elemento2,root);
	WidgetFactory::anadirHijo(elemento,elemento3,root);
	WidgetFactory::anadirHijo(elemento3,elemento31,procariontas);
	WidgetFactory::anadirHijo(elemento3,elemento32,procariontas);
	WidgetFactory::anadirHijo(elemento3,elemento33,procariontas);
	*/
	     




	/*
	
	ref_ptr<LOD> lodNode = new LOD();
	//// add the meshes
	ref_ptr<osg::Group>  highLOD = new osg::Group();
	highLOD->addChild(elemento3->widgetXForm);
	highLOD->addChild(elemento4->widgetXForm);
	lodNode->addChild( elemento->widgetXForm, 10.0f, FLT_MAX );
	lodNode->addChild( highLOD, 0.0f, 10.0f );


	ref_ptr<LOD> lodNode2 = new LOD();
	//// add the meshes
	
	ref_ptr<osg::Group> highLOD2 = new osg::Group();
	highLOD2->addChild(elemento5->widgetXForm);
	highLOD2->addChild(elemento6->widgetXForm);
	
	lodNode2->addChild( elemento2->widgetXForm, 10.0f, FLT_MAX );
	lodNode2->addChild( highLOD2, 0.0f, 10.0f );


	


	//root->addChild(lodNode);
	//root->addChild(lodNode2);
	


	root->addChild(plano->getWidget());
	root->addChild(arco1->getWidget());
	
	
	//root->addChild(elemento2->widgetXForm);-*/

	    // switch off lighting as we haven't assigned any normals.
    root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

    //The final step is to set up and enter a simulation loop.

    viewer.setSceneData( root );
    //viewer.run();

    viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();
	viewer.getCamera()->setClearColor(osg::Vec4(0.8509f,0.8509f,0.8509f,1.0f)); 
    while( !viewer.done() )
    {
        viewer.frame();
    }

    return 0;
}




