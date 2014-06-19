#pragma once
#include "Widget.h"
#include "Widget.h"
#include "Esfera.h"
#include "Arco.h"
#include "Plano.h"

#define ESFERA 1001
#define ARCO 1002
#define PLANO 1003


class WidgetFactory
{
public:
	static osg::ref_ptr<Widget> nuevoWidget( std::string nombre,osg::Vec4 parametros,int tipo=0);
	~WidgetFactory(void);
};