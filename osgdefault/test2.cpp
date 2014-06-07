///* 
//* OpenSceneGraph example, osgshape.
//*
//*  Permission is hereby granted, free of charge, to any person obtaining a copy
//*  of this software and associated documentation files (the "Software"), to deal
//*  in the Software without restriction, including without limitation the rights
//*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//*  copies of the Software, and to permit persons to whom the Software is
//*  furnished to do so, subject to the following conditions:
//*
//*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//*  THE SOFTWARE.
//*/
//
//
//#include <osg/Geode>
//#include <osg/ShapeDrawable>
//#include <osg/Material>
//#include <osg/Texture2D>
//#include <osgUtil/ShaderGen>
//
//
//#include <osgViewer/Viewer>
//#include <osg/Vec4>
//#include <osgDB/ReadFile>
//#include <osgDB/WriteFile>
//#include <osg/Stateset>
//#include <osg/NodeVisitor>
//
//#include <osgTerrain/Terrain>
//#include <osgTerrain/TerrainTile>
//#include <osgTerrain/Locator>
//#include <osg/CoordinateSystemNode>
//#include <osg/StateAttribute>
//#include <osgText/Text>
//#include <osg/Vec3>
//#include <osg/Math>
//#include <osg/PolygonMode>
//#include <osgDB/ReadFile>
//#include <osgUtil/LineSegmentIntersector>
//#include <osg/MatrixTransform>
//#include <osg/BlendFunc>
//#include <osg/StateAttribute>
//#include <osg/BlendColor>
//#include <osgGA/TrackballManipulator>
//// for the grid data..
//#include "terrain_coords.h"
//
//#include <stdio.h>   /* required for file operations */
//#include <conio.h>  /* for clrscr */
//#include <dos.h>  /* for delay */
//
//FILE *fr;            /* declare the file pointer */
//const int MAX = 1000000;
//float vertexGraph[MAX][3] ;
//int xLimit=0, zLimit=0;
//int iteracion;
//char *labelsX[MAX];// char array[MAX_NUMBER_STRINGS][MAX_STRING_SIZE]; 
//char *labelsZ[MAX];// char array[MAX_NUMBER_STRINGS][MAX_STRING_SIZE];
//bool primeraIteracion;
//int countLabelsX,countLabelsZ;
//char nombreArchivo[2000]="C:/Users/iwall/Desktop/PROYECTO VISUALIZACION/datos/taxa_summary_plots/raw_data/otu_table_nonchimeric_L2.txt";
//float escalaGrafica= 20.0f;
//
//#include <osg/Program>
//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>
//
///*static const char* vertSource = {
//"varying vec3 normal;\n"
//"void main()\n"
//"{\n"
//" normal = normalize(gl_NormalMatrix * gl_Normal);\n"
//" gl_Position = ftransform();\n"
//"}\n"
//};
//
//static const char* fragSource = {
//    "uniform vec4 color1;\n"
//    "uniform vec4 color2;\n"
//    "uniform vec4 color3;\n"
//    "uniform vec4 color4;\n"
//    "varying vec3 normal;\n"
//    "void main()\n"
//    "{\n"
//    "    float intensity = dot(vec3(gl_LightSource[0].position), normal);\n"
//    "    if (intensity > 0.95) gl_FragColor = color1;\n"
//    "    else if (intensity > 0.5) gl_FragColor = color2;\n"
//    "    else if (intensity > 0.25) gl_FragColor = color3;\n"
//    "    else gl_FragColor = color4;\n"
//    "}\n"
//};*/
//
//// For the pick event
//
//
////typedef osgUtil::LineSegmentIntersector::Intersection Intersection;
////
////class IntersectionSelector
////{
////	public:
////	   virtual bool handle(Intersection &intersection)
////	   {
////		   osg::NodePath &nodes = intersection.nodePath;
//// 
////		   for (int i = nodes.size() - 1; i >= 0; i--)
////		   {
////			   if (nodes[i]->getName() == "SELECTABLES")
////			   {
////				   if (nodes[i]->getNumDescriptions() == 1)
////				   {
////					   int index = atoi(nodes[i]->getDescription(0).c_str());
//// 
////					   if (index >= 0)
////					   {
////						   select(index, intersection);
////						   return true;
////					   }
////				   }
////			   }
////		   }
//// 
////		   return false;
////	   }
//// 
////	  virtual void select(int i, Intersection &intersection)
////	   {
////
////		   std::cout << "Select: " << i << std::endl;
////		   const osg::Vec3 &p = intersection.getLocalIntersectPoint();
////		   std::cout << "Point: " << p[0] << " " << p[1] << " " << p[2] << std::endl;
////	   }
////};
//// 
////class KeyEventHandler
////   : public osgGA::GUIEventHandler
////{
////		protected:
////		   float _mX, _mY;
////		   osgViewer::Viewer *m_viewer;
////		   IntersectionSelector *m_selector;
//// 
////		public:
//// 
////		   KeyEventHandler(osgViewer::Viewer *node, IntersectionSelector *selector)
////		   : osgGA::GUIEventHandler()
////		   {
////			   m_viewer = node;
////			   m_selector = selector;
////		   }
//// 
////		   virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
////		   {
////			   switch (ea.getEventType())
////			   {
////				   case(osgGA::GUIEventAdapter::KEYDOWN):
////				   {
////					   std::cout << "Keydown!" << std::endl;
//// 					   printf("interseccion");
////					   osg::ref_ptr<osgUtil::LineSegmentIntersector> ray = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::PROJECTION, ea.getXnormalized(), ea.getYnormalized());
////					   osgUtil::IntersectionVisitor visitor(ray);
//// 
////					   m_viewer->getCamera()->accept(visitor);
//// 
////					   if (ray->containsIntersections())
////					   {
////						   Intersection intersection = ray->getFirstIntersection();
//// 
////						   if (m_selector->handle(intersection))
////						   {
////							   return true;
////						   }
////					   }
////				   }
////				   default:
////					   return false;
////			   }
////		   }
////};
//
//
//class PickHandler : public osgGA::GUIEventHandler
//{
//public:
//    osg::Node* getOrCreateSelectionBox(); 
//    virtual bool handle( const osgGA::GUIEventAdapter& ea,
//                         osgGA::GUIActionAdapter& aa );
//	
//    
//protected:
//    osg::ref_ptr<osg::MatrixTransform> _selectionBox;
//};
//
//osgText::Text *_TextDescription;
//osgText::Text *_TextValue;
//
//osg::Node* PickHandler::getOrCreateSelectionBox()
//{
//    if ( !_selectionBox )
//    {
//        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
//        osg::ShapeDrawable *cajaSeleccion = new osg::ShapeDrawable(new osg::Box(osg::Vec3(), 1.0f));
//		osg::StateSet* ss = cajaSeleccion->getOrCreateStateSet();
//        ss->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
//        ss->setAttributeAndModes(new osg::PolygonMode(
//            osg::PolygonMode::FRONT_AND_BACK,osg::PolygonMode::LINE));
//		geode->addDrawable(cajaSeleccion);
//        
//		osg::StateSet* stateText = new osg::StateSet();    
//		stateText->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
//
//		_TextDescription = new osgText::Text();
//		_TextDescription->setCharacterSize(8);
//		_TextDescription->setFont("C:/WINDOWS/Fonts/impact.ttf");
//		_TextDescription->setAxisAlignment(osgText::Text::SCREEN);
//		_TextDescription->setBackdropType(osgText::Text::OUTLINE);
//		_TextDescription->setBackdropColor( osg::Vec4(0,0,0,1) );
//		_TextDescription->setColor(osg::Vec4(1,1,1,1));
//		_TextDescription->setDataVariance(osg::Object::DYNAMIC); // Hace que el objeto se pueda modificar, para el setText() que se modifica a cada rato.
//		_TextDescription->setStateSet(stateText);
//
//		_TextValue = new osgText::Text();
//		_TextValue->setCharacterSize(20);
//		_TextValue->setFont("C:/WINDOWS/Fonts/impact.ttf");
//		_TextValue->setAxisAlignment(osgText::Text::SCREEN);
//		_TextValue->setBackdropType(osgText::Text::OUTLINE);
//		_TextValue->setBackdropColor( osg::Vec4(0,0,0,1) );
//		_TextValue->setColor( osg::Vec4(1,1,1,1));
//		_TextValue->setDataVariance(osg::Object::DYNAMIC); // Hace que el objeto se pueda modificar, para el setText() que se modifica a cada rato.
//		_TextValue->setStateSet(stateText);
//
//		geode->addDrawable( _TextDescription );
//		geode->addDrawable( _TextValue );
//        _selectionBox = new osg::MatrixTransform;
//        _selectionBox->setNodeMask( 0x1 );
//        _selectionBox->addChild( geode.get() );
//        
//        
//
//    }
//    return _selectionBox.get();
//}
//
//osg::Node *nodeTextodelPadre_anterior;
//
//bool PickHandler::handle( const osgGA::GUIEventAdapter& ea,
//                          osgGA::GUIActionAdapter& aa )
//{
//    /*if ( ea.getEventType()!=osgGA::GUIEventAdapter::RELEASE ||
//         ea.getButton()!=osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON ||
//         !(ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_CTRL) )
//        return false;*/
//    
//    osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
//    if ( viewer )
//    {
//        osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
//            new osgUtil::LineSegmentIntersector(
//                osgUtil::Intersector::WINDOW, ea.getX(), ea.getY() );
//        osgUtil::IntersectionVisitor iv( intersector.get() );
//        iv.setTraversalMask( ~0x1 );
//        viewer->getCamera()->accept( iv );
//        
//        if ( intersector->containsIntersections() )
//        {
//            osgUtil::LineSegmentIntersector::Intersection result = *(intersector->getIntersections().begin());
//            
//
//			//result.drawable.getParent()->setNodeMask(0xFF);
//			osg::Group *nodoPadre=  result.drawable->getParent(0)->getParent(0);// Tomo el Node Group Abuelo del Cuadro Invisible.
//			osg::Node *nodeTextodelPadre = nodoPadre->getChild(0);// Tomo el primer Nodo del Nodo Padre que se supone que es el LabelGeode, porque se inserta primero.
//			nodeTextodelPadre->setNodeMask(0xFF);// Hago visible el Nodo labelgeode
//			if(nodeTextodelPadre_anterior!=nodeTextodelPadre)
//			{
//				if(nodeTextodelPadre_anterior!=NULL) // Verifco si todavia sigo apuntando a la misma zona
//					nodeTextodelPadre_anterior->setNodeMask(0x00);
//				nodeTextodelPadre_anterior = nodeTextodelPadre;
//				osg::BoundingBox bb = result.drawable->getBound();
//				osg::Vec3 worldCenter = bb.center() *
//					osg::computeLocalToWorld(result.nodePath);
//				_selectionBox->setMatrix(
//					osg::Matrix::scale(bb.xMax()-bb.xMin(),
//									  bb.yMax()-bb.yMin(),
//									  bb.zMax()-bb.zMin()) *
//					osg::Matrix::translate(worldCenter) );
//				_TextDescription->setPosition( osg::Vec3(0.0f,(bb.yMax()+35.0f)/(bb.yMax()-bb.yMin()),0.0f) );
//				_TextValue->setPosition( osg::Vec3(0.0f,(bb.yMax())/(bb.yMax()-bb.yMin()),0.0f) );
//				//printf("%s\n",(nodeTextodelPadre->getName()).c_str());
//				_TextDescription->setText("Quimico: " + nodeTextodelPadre->getDescription(1)+"\nTaxonomia: "+ nodeTextodelPadre->getDescription(0));
//				_TextValue->setText("  "+ nodeTextodelPadre->getDescription(2)+" %");
//				//_TextDescription->setText();
//				//_TextDescription->setPosition(worldCenter);
//			}
//        }
//    }
//    return false;
//}
//
//
//osg::ref_ptr<PickHandler> picker = new PickHandler;
//
//static osg::Geometry* createCube(float fRadius, osg::Vec3 vPosition) 
//{ 
//		//osg::Geode* geode = new osg::Geode(); 
//		
//
//		float red = fRadius / 50.0f;
//		if (red>1.0f)
//			red=1.0f;
//		float green = 1.0f - red;
//
//		osg::Geometry* cubeGeom = new osg::Geometry(); 
//
//		osg::Vec4Array *colors = new osg::Vec4Array; 
//		// Color Fondo
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 0
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 1
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 2
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 3
//		// Color Top
//		//colors->push_back(osg::Vec4(red, green, 0.0f, 1.0f) ); // 4
//		//colors->push_back(osg::Vec4(red, green, 0.0f, 1.0f) ); // 5
//		//colors->push_back(osg::Vec4(red, green, 0.0f, 1.0f) ); // 6
//		colors->push_back(osg::Vec4(red, green, 0.0f, 1.0f) ); // 7
//
//
//		////Color Lados
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 8
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 9
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 10
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 11
//
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 12
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 13
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 14
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 15
//
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 16
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 17
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 18
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 19
//
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 20
//		//colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); // 21
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 22
//		//colors->push_back(osg::Vec4(red,green, 0.0f, 1.0f) ); // 23
//
//
//		// define normals for each face 
//		osg::ref_ptr<osg::Vec3Array> cube_normals = new osg::Vec3Array; 
//		cube_normals->push_back(osg::Vec3( 0.0f,-1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,-1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,-1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,-1.0f, 0.0f)); 
//
//		cube_normals->push_back(osg::Vec3( 0.0f,+1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+1.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+1.0f, 0.0f)); 
//
//		cube_normals->push_back(osg::Vec3(+1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(+1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(+1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(+1.0f,+0.0f, 0.0f)); 
//
//		cube_normals->push_back(osg::Vec3(-1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(-1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(-1.0f,+0.0f, 0.0f)); 
//		cube_normals->push_back(osg::Vec3(-1.0f,+0.0f, 0.0f)); 
//
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,-1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,-1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,-1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,-1.0f)); 
//
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,+1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,+1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,+1.0f)); 
//		cube_normals->push_back(osg::Vec3( 0.0f,+0.0f,+1.0f)); 
//
//		//vPosition += osg::Vec3(+fRadius/2, +fRadius/2, +fRadius/2); 
//
//		// note, counterclockwise winding order with respect to normals 
//		osg::Vec3 myCoords[] = 
//		{
//		// bottom face 
//		osg::Vec3(-escalaGrafica/2, -fRadius, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, -fRadius, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, -fRadius, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, -fRadius, +escalaGrafica/2) + vPosition, 
//
//		// top face 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//
//		// right face 
//		osg::Vec3(+escalaGrafica/2, -fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, -fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//
//		// left face 
//		osg::Vec3(-escalaGrafica/2, -fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, -fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//
//		// front face 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, -fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, -fRadius+2.5f, -escalaGrafica/2) + vPosition, 
//
//		// back face 
//		osg::Vec3(-escalaGrafica/2, -fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, -fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(+escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition, 
//		osg::Vec3(-escalaGrafica/2, +fRadius+2.5f, +escalaGrafica/2) + vPosition 
//		}; 
//
//		int numCoords = sizeof(myCoords)/sizeof(osg::Vec3); 
//		osg::Vec3Array* vertices = new osg::Vec3Array(numCoords,myCoords); 
//		cubeGeom->setVertexArray(vertices); 
//
//		//cubeGeom->getOrCreateStateSet()->setAttribute( new osg::LineWidth(5.0f) );
//
//		cubeGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,numCoords)); 
//
//		cubeGeom->setColorArray(colors); 
//		cubeGeom->setColorBinding(osg::Geometry::BIND_OVERALL); 
//
//		cubeGeom->setNormalArray(cube_normals.get()); 
//		cubeGeom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX); 
//
//
//		//geode->addDrawable(cubeGeom); 
//		
//		return cubeGeom; 
//} 
//
//
//  // Para crear el Grafico
//osg::Group* createGraph()
//{
//	osg::Group* root = new osg::Group();
//
//	printf( " XLimit: %d // ZLimit: %d", xLimit,zLimit);
//
//
//	//osg::Geode* geode = new osg::Geode();
//
//	osg::Group *groupZoneGraph; // Representa una zona de la grafica( caja y label)
//	osg::Geode* labelGeode; // Para La etiqueta con los valores
//	osg::Geode *intersectGeode; // Representa al geode de la caja
//	osg::Box *intersectBox;
//	/*osg::StateSet* stateset = new osg::StateSet();
//
//    osg::Image* image = osgDB::readImageFile( "Images/lz.rgb" );
//    if (image)
//    {
//        osg::Texture2D* texture = new osg::Texture2D;
//        texture->setImage(image);
//        texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
//        stateset->setTextureAttributeAndModes(0,texture, osg::StateAttribute::ON);
//    }
//    
//    stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
//    
//
//    geode->setStateSet( stateset );*/
//	
//	
//
//	 // Creo un Geometry para los colores en la grafica
//	/*osg::Geometry* pGeo = new osg::Geometry;
//
//	// Vertices de cada punto de la grafica
//	osg::Vec3Array* mapVertices = new osg::Vec3Array;
//    
//	osg::Vec4Array* mapColors = new osg::Vec4Array; // Set de los de los colores que indican el nivel de Altura en la grafica
//
//	osg::Vec2Array* texcoords = new osg::Vec2Array;
//	osg::TemplateIndexArray <unsigned int, osg::Array::UIntArrayType,4,4> *colorIndexArray;
//	colorIndexArray =   new osg::TemplateIndexArray<unsigned int, osg::Array::UIntArrayType,4,4>;*/
//	
//
//
//
//	/*osg::HeightField* grid = new osg::HeightField;
//    grid->allocate(zLimit,xLimit);
//    grid->setXInterval(escalaGrafica);
//    grid->setYInterval(escalaGrafica);*/
//
//	//osgText::Text textOne = new osgText::Text();
//
//    /*for(unsigned int r=0;r<zLimit;++r)
//    {
//        for(unsigned int c=0;c<xLimit;++c)
//        {
//            grid->setHeight(c,r,vertexGraph[r+c*zLimit][2]);
//        }
//    }*/
//
//
//	char textLabel[1000]="";
//	osgText::Text* textEtiqueta;
//	osgText::Text* textOne;
//	int xLbl=0;
//	osg::Vec3  verticeGrafica;
//	
//
//	char idNode[500]=""; // Para darle un Nombre diferente a los nodos.
//	char line[2000]="";
//	fr = fopen (nombreArchivo, "rt");  /* open the file for reading */
//	fgets(line, 2000, fr);
//
//	float positionX=0.0f,positionY=0.0f,positionZ=0.0f;
//
//	for(unsigned int x=0;x<xLimit;++x)
//    {
//			fgets(line, 2000, fr);
//			// Coloca Etiqueta en EJE X
//			for(unsigned int z=0;z<zLimit;++z)
//			{
//				
//				//if(x==0)
//				//{
//				//		/*textEtiqueta = new osgText::Text();
//				//		textEtiqueta->setCharacterSize(5);
//				//		textEtiqueta->setFont("C:/WINDOWS/Fonts/impact.ttf");
//				//		textEtiqueta->setText(labelsX[z]);
//				//		textEtiqueta->setAxisAlignment(osgText::Text::SCREEN);
//				//		textEtiqueta->setPosition( osg::Vec3((zLimit*10.0f)+5.0f ,z*10.0f, 0.0f ) ); // (X,Y,Z) ---> (X,Z,Y)
//				//		textEtiqueta->setColor( osg::Vec4(107, 243, 92, 1) );
//				//		geode->addDrawable( textEtiqueta );*/
//				//}
//
//
//				//if(x==0) // Para colocar Etiqueta en Y, o Z
//				//{
//				//	/*textEtiqueta = new osgText::Text();
//				//	textEtiqueta->setCharacterSize(5);
//				//	textEtiqueta->setFont("C:/WINDOWS/Fonts/impact.ttf");
//				//	textEtiqueta->setText("z");
//				//		osg::BoundingBox *intersectBox = new osg::BoundingBox();
//				//intersectBox->set(-100.0f,zLimit-z-1-(escalaGrafica/2),x-(escalaGrafica/2),
//				//				  100.0f,zLimit-z-1+(escalaGrafica/2),x+(escalaGrafica/2)); //set (float xmin, float ymin, float zmin, float xmax, float ymax, float zmax)xtEtiqueta->setPosition( osg::Vec3( z*10.0f ,(xLimit*10.0f)+5.0f,0.0f ) ); // (X,Y,Z) ---> (X,Z,Y)
//				//	textEtiqueta->setColor( osg::Vec4(107, 243, 92, 1) );
//				//	geode->addDrawable( textEtiqueta );*/
//				//}
//
//				// Creo la Grafica
//				//osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
//
//				//grid
//				//grid->setHeight(zLimit-z-1,x,vertexGraph[z+x*zLimit][2]); // Se coloca desde el final al inicio en Z, para que la grafica se parezca a la grafica del .html
//
//				//Bounding
//				//osg::BoundingBox *intersectBox = new osg::BoundingBox();
//				//intersectBox->set(0.0f,zLimit-z-1-(escalaGrafica/2),x-(escalaGrafica/2),
//				//				  vertexGraph[z+x*zLimit][2],zLimit-z-1+(escalaGrafica/2),x-(escalaGrafica/2)); //set (float xmin, float ymin, float zmin, float xmax, float ymax, float zmax)
//
//
//				// Tomo el Vertice en este punto para pintarlo
//				//mapVertices->push_back( grid->getVertex(zLimit-z-1,x) );
//				//colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
//				//texcoords->push_back(osg::Vec2(zLimit-z-1,x));
//				//colorIndexArray->push_back(z+x*zLimit); // vertex 0 assigned color array element 0
//
//
//				labelGeode = new osg::Geode(); // Geode para Textos Labels
//
//				
//				
//				//labelGeode->setCullingActive(false);
//
//
//				positionX= x*escalaGrafica;
//				positionY= vertexGraph[z+x*zLimit][2];
//				positionZ= (zLimit-z-1)*escalaGrafica;
//
//
//				// Coloca el Label (POrcentaje) de de terminado dato.
//				//textOne = new osgText::Text();
//				/*textOne->setCharacterSize(4);
//				textOne->setFont("C:/WINDOWS/Fonts/impact.ttf");
//				sprintf(textLabel, "Taxonomia: %s \n Quimico: %s \n", strtok(line, "	") , labelsX[z]);
//				//sprintf(idNode, "%s_%s", strtok(line, "	") , labelsX[z]);
//				//printf("Z:%s/n",labelsZ[x]);
//				textOne->setText(textLabel);
//				textOne->setAxisAlignment(osgText::Text::SCREEN);
//				textOne->setPosition( osg::Vec3(positionX,positionY + 22.0f,(zLimit-z-1)*escalaGrafica ) );
//				//textOne->setPosition( osg::Vec3((zLimit-z-1)*escalaGrafica,x*escalaGrafica,vertexGraph[z+x*zLimit][2] + 22.0f ) ); // Position del Texto Porcentaje
//				//textOne->setPosition( osg::Vec3(x*10.0f,vertexGraph[x+z*xLimit][2] + 10.0f,z*10.0f ) );
//				textOne->setColor( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)  );
//				//textOne->setBackdropType(osgText::Text::OUTLINE);
//				//textOne->setBackdropColor(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));*/
//				//labelGeode->addDrawable( textOne );
//						
//
//				//osg::BoundingBox *intersectBox = new osg::BoundingBox();
//
//
//				//intersectBox->set(-100.0f,zLimit-z-1-(escalaGrafica/2),x-(escalaGrafica/2),
//				//				  100.0f,zLimit-z-1+(escalaGrafica/2),x+(escalaGrafica/2)); //set (float xmin, float ymin, float zmin, float xmax, float ymax, float zmax)
//
//
//				//textOne = new osgText::Text();
//				/*textOne->setCharacterSize(10);
//				textOne->setFont("C:/WINDOWS/Fonts/impact.ttf");
//				sprintf(textLabel, "  %.2f %%", vertexGraph[z+x*zLimit][2]);
//				textOne->setText(textLabel);
//				textOne->setAxisAlignment(osgText::Text::SCREEN);
//				textOne->setPosition( osg::Vec3(positionX,positionY + 5.0f,(zLimit-z-1)*escalaGrafica ) ); // Position del Texto Porcentaje
//				//textOne->setPosition( osg::Vec3((zLimit-z-1)*escalaGrafica,x*escalaGrafica,vertexGraph[z+x*zLimit][2] + 5.0f ) ); // Position del Texto Porcentaje
//				//textOne->setPosition( osg::Vec3(x*10.0f,vertexGraph[x+z*xLimit][2] + 10.0f,z*10.0f ) );
//				///if(vertexGraph[z+x*zLimit][2]>=80.0f)
//				//	textOne->setColor( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f)  );
//				//else if(vertexGraph[z+x*zLimit][2]<80.0f && vertexGraph[z+x*zLimit][2]>30.0f)
//				//	textOne->setColor( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f)  );
//				//else
//				textOne->setColor( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)  );
//				//textOne->setBackdropType(osgText::Text::OUTLINE);
//				//textOne->setBackdropColor(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
//				//textOne->setBackdropOffset(10.0f,10.0f);
//			    //textOne->setNodeMask(0x0);*/
//				//labelGeode->addDrawable( textOne );
//				labelGeode->setNodeMask(0x00);// Escondo el texto, no se dibuja
//
//				char porcentajeString[100];
//				sprintf(porcentajeString, "%.2f", vertexGraph[z+x*zLimit][2]);
//				//labelGeode->setName(textLabel);
//				std::vector<std::string> listadescripciones; // Arraylist de strings
//				listadescripciones.push_back(strtok(line, "	"));// 0
//				listadescripciones.push_back(labelsX[z]);// 1
//				listadescripciones.push_back(porcentajeString);// 2
//
//				// Los valores LabelX,LabelZ y Porcentaje se guarda en un arreglo de strings en el labelgeode
//				labelGeode->setDescriptions(listadescripciones); // 0
//
//
//				//osg::StateSet* statesetText = new osg::StateSet();
//				//osg::BlendColor* bcolor = new osg::BlendColor();
//				//bcolor->setConstantColor(osg::Vec4(1.0f, 0.0f, 0.0f, 0.0f));
//				//statesetText->setAttribute(bcolor, osg::StateAttribute::ON);
//				
//				//labelGeode->setStateSet(statesetText);
//				
//				groupZoneGraph = new osg::Group(); // Group que contendra los Geode del cuadro invisible y otro geode del Texto invisible.
//
//				groupZoneGraph->addChild(labelGeode); // Añado el nodo al GroupZona
//				
//				
//				
//				// Box que representara una cierta zona de la Grafica.
//				intersectGeode = new osg::Geode();
//				intersectBox = new osg::Box();
//				intersectBox->set( osg::Vec3(positionX,positionY/2.0f,positionZ), osg::Vec3(10.0f,(positionY/2.0f)+2.5f,10.0f));
//				//intersectGeode->se
//				//intersectBox->set( osg::Vec3((zLimit-z-1)*escalaGrafica,x*escalaGrafica,(vertexGraph[z+x*zLimit][2]/2)), osg::Vec3(10.0f,10.0f,(vertexGraph[z+x*zLimit][2]/2)+2.5f));
//				
//				//osg::Geometry *geometryBox = new osg::Geometry();
//				
//				osg::Geometry *geoBox = createCube(positionY/2.0f, osg::Vec3(positionX,positionY/2.0f,positionZ));
//				intersectGeode->addDrawable( geoBox );
//
//
//				//osg::ShapeDrawable *drawableBox = new osg::ShapeDrawable(intersectBox);
//				
//
//				//drawableBox->setColor( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)  );
//				//geometryBox->setShape(drawableBox->getShape());
//				//osg::Array* boxVertices = geometryBox->getVertexArray();
//				////geometryBox->setVertexArray( boxVertices ); 
//				////geometryBox->addPrimitiveSet(geometryBox->getPrimitiveSet()); 
//				////osg::Vec4Array* colors = new osg::Vec4Array;
//				////colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
//				////colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); //index 1 green
//				////colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) ); //index 2 blue
//				////colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 3 white 
//				//////colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 4 red
//				//geometryBox->setColorArray(colors);
//				//geometryBox->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
//				
//				
//				/*osg::ref_ptr<osg::Shader> vertShader = new osg::Shader( osg::Shader::VERTEX, vertSource );
//				osg::ref_ptr<osg::Shader> fragShader = new osg::Shader( osg::Shader::FRAGMENT, fragSource );
//
//				osg::ref_ptr<osg::Program> program = new osg::Program;
//				program->addShader( vertShader.get() );
//				program->addShader( fragShader.get() );
//
//				//osg::ref_ptr<osg::Node> model = osgDB::readNodeFile( "cow.osg" );*/
//
//				/*osg::StateSet* stateset = new osg::StateSet();
//
//				osg::Image* image = osgDB::readImageFile( "C:/Users/Admin/Desktop/redgreengradient.jpg" );
//				//image->allocateImage(20, 100, 1, GL_LUMINANCE, GL_FLOAT);
//				if (image)
//				{
//					osg::Texture2D* texture = new osg::Texture2D;
//					texture->setImage(image);
//					texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
//					texture->setTextureHeight(100);
//					texture->dirtyTextureParameters();
//					stateset->setTextureAttributeAndModes(0,texture, osg::StateAttribute::ON);
//				}
//    
//				stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);*/
//    
//				
//				/*intersectGeode->setStateSet( stateset );*/
//				
//				//drawableBox->
//
//				//osg::Vec3Array *vertices = (osg::Vec3Array *)drawableBox->asGeometry()->getVertexArray(); 
//				//osg::Geometry::PrimitiveSetList primitiveList = drawableBox->asGeometry()->getPrimitiveSetList(); 
//
//				//labelGeode->setNodeMask(0x0);
//				//labelGeode->setName("SELECTABLES");
//
//				/*osg::StateSet *invisibleSet = intersectGeode->getOrCreateStateSet();
//				osg::Material *material = (osg::Material *) invisibleSet->getAttribute(osg::StateAttribute::MATERIAL);
//				invisibleSet->setRenderBinDetails(0, "transparent");
//				invisibleSet->setMode( GL_BLEND, osg::StateAttribute::ON );
//				invisibleSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN); 
//				invisibleSet->setAttributeAndModes(material, osg::StateAttribute::OVERRIDE);
//				intersectGeode->setStateSet(invisibleSet);*/
//
//
//				groupZoneGraph->addChild(intersectGeode);
//
//				root->addChild(groupZoneGraph);
//			}
//
//			printf("Proceso... X:%d \n",x);
//	}
//
//	fclose(fr);
//	
//
//	/*osg::StateSet* pStateSet = geode->getOrCreateStateSet();
//	pStateSet->setMode( GL_LIGHTING, osg::StateAttribute::OFF );*/
//
//	//grid->setRotation(osg::Quat::Quat(1.0f,0.0f,0.0f,3.14159265f));
//
//	
//	//osgTerrain::Terrain* terreno = new osgTerrain::Terrain();
//	//osgTerrain::TerrainTile* tileTerreno = new osgTerrain::TerrainTile();
//	//osgTerrain::HeightFieldLayer* hfl = new osgTerrain::HeightFieldLayer(); 
//	//osgTerrain::Locator* locator = new osgTerrain::Locator();
//	////osgTerrain::GeometryTechnique* geoT = new new osgTerrain::GeometryTechnique();
//	////locator->setCoordinateSystemType(PROJECTED);
//	//
//	//hfl->setHeightField(grid);
//	////locator->setCoordinateSystemType(PROJECTED);
//	//hfl->setLocator(locator);
//	//tileTerreno->setElevationLayer(hfl); 
//	//tileTerreno->setVerticalScale(10.0f);
//	//terreno->setElevationLayer(
//
//	//osg::ShapeDrawable* gridDrawable = new osg::ShapeDrawable(grid);
//
//	//osg::Geometry* gridGeometry = gridDrawable->asGeometry();
//	//gridGeometry->setVertexArray( mapVertices );
//	//pGeo->setColorArray( mapColors );
//	//pGeo->setColorIndices(colorIndexArray);
//	//pGeo->setTexCoordArray(0,texcoords);
//	//pGeo->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
//	//geode->addDrawable(pGeo);
//
//    //geode->addDrawable(gridDrawable);
//	//geode->addDrawable(gridDrawable);
//	//root->addChild(geode); 
//
//	// Para eventos
//	root->addChild( picker->getOrCreateSelectionBox() );
//
//
//
//
//	/*osg::Geode* plane=new osg::Geode;
//	osg::InfinitePlane* p = new osg::InfinitePlane; 
//	p->set(osg::Vec3d(1,0,0),osg::Vec3d(0,0,0));
//	plane->addDrawable(new osg::ShapeDrawable(p));
//	root->addChild(plane);*/
//	osg::StateSet* stateset = new osg::StateSet();    
//	stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
//	//stateset->setMode( GL_LINE_SMOOTH, osg::StateAttribute::ON );
//    //stateset->setMode( GL_BLEND, osg::StateAttribute::ON );
//    root->setStateSet( stateset );
//
//	//root->addChild(geode);
//    return root;
//}
//
//
//// MAIN
//
//int main(int, char **)
//{
//
//   countLabelsX=0;
//   countLabelsZ=0;
//   
//   char firstLine[2000] ="";
//   char line[2000]="";
//   char *token;
//   fr = fopen (nombreArchivo, "rt");  /* open the file for reading */
//
//   int Xcoord=0,Ycoord=0,Zcoord=0;// Valores de las coordenadas. X y Z seran incrementales; mientras que Y seran valores dependiendo lo que da la tabla. Indica el Height.
//   char palabraString[] = " ";
//   
//   /* Leer las etiquestas correspondientes a la grafica X */
//	fgets(firstLine, 2000, fr); // Leo la Primera Linea la cual contiene los valores X (Nombres , no numeros) de la grafica
//	token = strtok(firstLine, "	");
//	while( token != NULL ) 
//	{
//				token = strtok(NULL, "	");
//				//sscanf (token, "%s", &palabraString);
//				labelsX[countLabelsX] = token;
//				printf( "%s\n", labelsX[countLabelsX]);
//				countLabelsX++;
//	}
//
//
//	
//   iteracion=0;
//
//   char *tokenI;
//
//   while(fgets(line, 2000, fr) != NULL)// Leo las Lineas siguientes las cuales tienen los valores numericos.
//   {
//		/*Tomo el primer Token el cual sera el valor Z, el nombre Label (Etiqueta) de la grafica del valor Z. */
//		printf("Se lee una linea \n");
//		/* walk through other tokens */
//		Zcoord=0;
//		token = strtok(line, "	");// Leo el primer token
//		//labelsZ[countLabelsZ] = token;
//		//countLabelsZ++;
//
//		token = strtok(NULL, "	"); // Leo el segundo token, debe ser un valor float para que empiece a correr loop posterior.
//		//printf("Z:%s /n",token);
//		//printf( " Xcoord: %d\n", Xcoord);
//		while( token != NULL ) 
//		{
//					vertexGraph[iteracion][1]=Xcoord*1.0f;
//					vertexGraph[iteracion][2]=atof(token) * 100.0f; // Valor Y. Porcentaje lo multiplico para que sea sobre 100
//					vertexGraph[iteracion][3]=Zcoord*1.0f;
//					//printf( " Zcoord: %d\n", Zcoord);
//					//printf( " X: %4.4f // Y: %4.4f // Z: %4.4f\n", vertexGraph[iteracion][1],vertexGraph[iteracion][2],vertexGraph[iteracion][3]);
//					Zcoord++;
//					iteracion++;
//					token = strtok(NULL, "	");
//		}
//		printf("\n");
//		Xcoord++;
//		if(Xcoord>xLimit)
//			xLimit=Xcoord;
//		if(Zcoord>zLimit)
//			zLimit=Zcoord;
//		
//	}
//
//    /*countLabelsZ=0;
//	while(labelsZ[countLabelsZ]!= NULL)
//	{
//		printf("Z:%s/n",labelsZ[countLabelsZ]);
//		countLabelsZ++;
//	}*/
//	fclose(fr);  /* close the file prior to exiting the routine */
//
//   
//   //  construct the viewer.
//    osgViewer::Viewer viewer;
//
//
//	// For multisample antialiasing
//	osg::DisplaySettings::instance()->setNumMultiSamples( 4 );
//
//
//    // add model to viewer.
//    viewer.setSceneData( createGraph() );
//	//viewer.realize(); 
//	//viewer.setUpViewInWindow(400, 400, 640, 480);
//	//viewer
//
//	osg::Vec3d eye( 0.0, 50.0, 1000.0 );
//    osg::Vec3d center( 0.0, 0.0, 0.0 );
//    osg::Vec3d up( 0.0, 1.0, 0.0 );
//
//    //viewer.getCamera()->setViewMatrixAsLookAt( eye, center, up );
//
//	/*KeyEventHandler* handler = new KeyEventHandler(viewer,new IntersectionSelector);
//	viewer.addEventHandler(handler);*/
//	
//
//	//Insertar .osg
//	/*osg::Node* terrain = osgDB::readNodeFile("C:\\DevTools\\OpenSceneGraph\\examples\\OpenSceneGraph-Data\\cessna.osg");
//    if(terrain == nullptr) {
//        return -1;
//    }*/
//
//	viewer.setCameraManipulator(new osgGA::TrackballManipulator);
//	viewer.getCameraManipulator()->setHomePosition(osg::Vec3d(-800.0, 300.0, -500.0), osg::Vec3d(0.0, 100.0, 200.0), osg::Vec3d(0.0, 1.0, 0.0));
//	viewer.home();
//	viewer.addEventHandler( picker );
//    return viewer.run();
//   //while(true){};
//   //return 0;
//}