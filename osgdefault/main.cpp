#include <vector>
#include <fstream>
#include <sstream>
#include<iostream>
#include <string>
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

std::string filename="datos.txt";


void leerXml(){
	//  leer archivo xml

	std::string line;
	int lineNumber=1;
	std::ifstream stream (filename);
	if (stream.is_open())
	{
		try{
			while (stream.good())
			{
				std::getline(stream,line);
				if (line.compare(0,1,"#") == 0){
					lineNumber++;
					continue;
					
				}
				if(line.empty()){
					lineNumber++;
					continue;
				}
				//std::cout << line << std::endl;				
				std::string delimiter = ";;";
				std::size_t pos = 0;
				std::string token;
				std::vector<std::string> info;
				while ((pos = line.find(delimiter)) != std::string::npos) {
					token = line.substr(0, pos);
					//std::cout << token << std::endl;
					info.push_back(token);
					line.erase(0, pos + delimiter.length());
				}
				info.push_back(line);//ultimo token encontrado
				//std::cout << line+":P" << std::endl;
				std::cout << info.at(0)+" " <<info.at(1)+" " <<info.at(2)+" " <<info.at(3)+" " <<info.at(4)+" "<< std::endl;
				//validacion
				std::stringstream ss,ssPadre,ssPeso;
				// ID
				ss << info.at(0);
				int id = 0;
				ss >> id;
				if(ss.good()) {
					std::cout <<"Linea: "<<lineNumber<< " Id no es un numero valido, Programa terminado" << std::endl;
					break;
				}
				else if(id == 0 && info.at(0)[0]!= '0') {
					std::cout <<"Linea: "<<lineNumber<< " Id no es un numero valido, Programa terminado" << std::endl;
					break;
				}
				else {
					std::cout << id<< std::endl;
				}

				// ID PADRE
				
				ssPadre << info.at(4);
				int idPadre = 0;
				ssPadre >> idPadre;
				if(ssPadre.good()) {
					std::cout <<"Linea: "<<lineNumber<< " Id Padre no es un numero valido, Programa terminado" << std::endl;
					break;
				}
				else if(idPadre == 0 && info.at(4)[0]!= '0') {
					std::cout <<"Linea: "<<lineNumber<< " Id Padre no es un numero valido, Programa terminado" << std::endl;
					break;
				}
				else {
					std::cout << idPadre<< std::endl;
				}



				// Peso Relativo
				ssPeso << info.at(3);
				float peso = 0;
				ssPeso >> peso;
				if(ssPeso.good()) {
					std::cout <<"Linea: "<<lineNumber<< " Peso relativo al padre debe ser un numero entre 0 y 1.0 , Programa terminado" << std::endl;
					break;
				}
				else if(peso == 0 && info.at(3)[0]!= '0') {
					std::cout <<"Linea: "<<lineNumber<< " Peso relativo al padre debe ser un numero entre 0 y 1.0 ,Programa terminado" << std::endl;
					break;
				}
				else {
					std::cout << peso<< std::endl;
				}






				lineNumber++;
			}
			stream.close();
		} catch (...) {
			stream.close();
		}
	}
	else
	{
		std::cout << "No se puede leer el archivo" << std::endl << std::endl;
	}

	std::string in;
	std::cin>> in;

	// construir representacion en jerarqu'ia
	// recorrer todo el archivo, decidir maximo y minimo volumen
	//construir los widgets con tamano adecuado
	// asignarles posincion
	// crear los nodos
	// renderizar escena

}
int main()
{
	 leerXml();
/*	osgViewer::Viewer viewer;
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
	///

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
	*/
	return 0;
}





