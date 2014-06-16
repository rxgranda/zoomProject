#include "WidgetFactory.h"

osg::ref_ptr<Widget> WidgetFactory::nuevoWidget(std::string nombre,osg::Vec4 parametros,int tipo){
		osg::ref_ptr<Widget> elemento;
		switch (tipo)
		{
		case 1:

			elemento=new Esfera(nombre,parametros[0],parametros[1],parametros[2],parametros[3]);
			break;
		case 2:
			elemento=new Arco;
			break;
		case 3:
			elemento=new Plano(parametros[0]);
			break;
		default:
			elemento=new Esfera(nombre);
			break;
		}
		return elemento;
}


WidgetFactory::~WidgetFactory(void)
{
}
