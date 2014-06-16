#pragma once
#include "Widget.h"
#include "Widget.h"
#include "Esfera.h"
#include "Arco.h"
#include "Plano.h"

class WidgetFactory
{
public:
	static osg::ref_ptr<Widget> nuevoWidget( std::string nombre,osg::Vec4 parametros,int tipo=0);
	~WidgetFactory(void);
};