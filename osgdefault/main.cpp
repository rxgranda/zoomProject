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

int main()
{

	osgViewer::Viewer viewer;
	ref_ptr<osg::Group> root = new osg::Group(); // root 
	ref_ptr<Widget> elemento=WidgetFactory::nuevoWidget("Seres vivos",osg::Vec4(0,0,0,300.0f),1); // seres vivos
	ref_ptr<Widget> elemento2=WidgetFactory::nuevoWidget("Celulas Eucariontas",osg::Vec4(0,0,0,50),1);
	ref_ptr<Widget> elemento3=WidgetFactory::nuevoWidget("Celulas Procariontas",osg::Vec4(0,0,0,50),1);
	ref_ptr<Widget> elemento31=WidgetFactory::nuevoWidget("Virus",osg::Vec4(-15,0,0,5),1);
	ref_ptr<Widget> elemento32=WidgetFactory::nuevoWidget("Bacterias",osg::Vec4(0,0,0,5),1);
	ref_ptr<Widget> elemento33=WidgetFactory::nuevoWidget("Cianofitas",osg::Vec4(15,0,0,2),1);
	ref_ptr<Widget> plano=WidgetFactory::nuevoWidget("",osg::Vec4(0,0,0,5.0f),3);
	ref_ptr<Widget> plano2=WidgetFactory::nuevoWidget("",osg::Vec4(1,0,0,1),3);
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


	/*osg::ref_ptr<osgShadow::ShadowedScene> shadowScene (new osgShadow::ShadowedScene);
	osg::ref_ptr<osgShadow::ShadowMap> sm ( new osgShadow::ShadowMap);
	int shadowsize = 16192;//1024; 8196
	sm->setTextureSize(osg::Vec2s(shadowsize, shadowsize)); // Para una sombra mas definida.
	/* sm->setTextureUnit(1);
	shadowScene->setShadowTechnique(sm.get());
	shadowScene->addChild(root.get());

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


	// switch off lighting as we haven't assigned any normals.
	root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	//The final step is to set up and enter a simulation loop.

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





