#include "WidgetFactory.h"

osg::ref_ptr<Widget> WidgetFactory::nuevoWidget(std::string nombre,osg::Vec4 parametros,int tipo){
		osg::ref_ptr<Widget> elemento;
		switch (tipo)
		{
		case ESFERA:

			elemento=new Esfera(nombre,parametros[0],parametros[1],parametros[2],parametros[3]);
			break;
		case ARCO:
			elemento=new Arco;
			break;
		case PLANO:
			elemento=new Plano(parametros[0]);
			break;
		default:
			//elemento=new Esfera(nombre);
			break;
		}
		return elemento;
}


WidgetFactory::~WidgetFactory(void)
{
}
