#include <vector>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>
#include <osgUtil/Simplifier>
#include <osgViewer/Viewer>

#include "WidgetFactory.h"
#include "Nodo.h"


#define TAMANO_TEXTO 1

using namespace osg;
using namespace osgDB;
using namespace osgUtil;
using namespace osgViewer;



void leerXml(std::string fileName){
	//  leer archivo xml
	// construir representacion en jerarqu'ia
	// recorrer todo el archivo, decidir maximo y minimo volumen
	//construir los widgets con tamano adecuado
	// asignarles posincion
	// crear los nodos
	// renderizar escena

}
int main()
{

	osgViewer::Viewer viewer;
	ref_ptr<osg::Group> root = new osg::Group(); // root 
	ref_ptr<Widget> elemento=WidgetFactory::nuevoWidget("Seres vivos",osg::Vec4(0,0,0,300.0f),ESFERA); // seres vivos
	ref_ptr<Widget> elemento2=WidgetFactory::nuevoWidget("Celulas Eucariontas",osg::Vec4(0,0,0,50),ESFERA);
	ref_ptr<Widget> elemento3=WidgetFactory::nuevoWidget("Celulas Procariontas",osg::Vec4(0,0,0,50),ESFERA);
	ref_ptr<Widget> elemento31=WidgetFactory::nuevoWidget("Virus",osg::Vec4(-15,0,0,5),ESFERA);
	ref_ptr<Widget> elemento32=WidgetFactory::nuevoWidget("Bacterias",osg::Vec4(0,0,0,5),ESFERA);
	ref_ptr<Widget> elemento33=WidgetFactory::nuevoWidget("Cianofitas",osg::Vec4(15,0,0,2),ESFERA);
	ref_ptr<Widget> plano=WidgetFactory::nuevoWidget("",osg::Vec4(0,0,0,5.0f),PLANO);
	ref_ptr<Widget> plano2=WidgetFactory::nuevoWidget("",osg::Vec4(1,0,0,1),PLANO);
	//ref_ptr<Widget> arco=new Arco( osg::Vec3f(1,0,0), osg::Vec3f(30,30,30));
	//ref_ptr<Widget> arco=WidgetFactory::nuevoWidget("",osg::Vec4(1,0,0,1),2);
	plano2->cambiarPosicion(0,100,0);
	/*	elemento2->cambiarPosicion(20,0,0);
	elemento3->cambiarPosicion(-20,0,0);
	elemento31->cambiarPosicion(-5,0,0);
	elemento32->cambiarPosicion(0,0,0);
	elemento33->cambiarPosicion(5,0,0);
	*/

	std::vector<ref_ptr<osg::Node>> hijos3;
	std::vector<ref_ptr<osg::Node>> hijos;

	hijos3.push_back(elemento31);
	hijos3.push_back(elemento32);
	hijos3.push_back(elemento33);
	ref_ptr<Nodo> grupoProcariontas=new Nodo(elemento3,hijos3,500.0f,0);
	elemento2->cambiarPosicion(150,0,0);
	grupoProcariontas->cambiarPosicion(-150,0,0);

	hijos.push_back(grupoProcariontas);	
	hijos.push_back(elemento2);	
	ref_ptr<Nodo> nodoraiz=new Nodo(elemento,hijos,1500.0f, 1);

	root->addChild(plano->getWidget());
	//root->addChild(plano2->getWidget());
	//root->addChild(arco->getWidget());
	//	root->addChild(grupoProcariontas->getNodo());
	root->addChild(elemento->getWidget());
	root->addChild(nodoraiz->getNodo());




	// switch off lighting as we haven't assigned any normals.
	//root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);



	//  viewer.setSceneData( shadowScene.get());
	viewer.setSceneData( root.get());
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





