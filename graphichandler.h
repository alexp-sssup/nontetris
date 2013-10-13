#ifndef _GRAPHIC_HANDLER_H
#define _GRAPHIC_HANDLER_H

#ifdef __DUETTO__
#include "duettogl.h"
#else
#include <GL/glew.h>
#endif

#include "polygon.h"
#include "piece.h"
#include "fileloader.h"

#include <functional>
#include "NontetrisConfig.h"


struct GraphicPiece
{
	GLuint VBOid;
	GLuint num;
	int tex;
};

class GraphicHandler
{
	GLint uPMatrixLoc;
	GLint uRTVecLoc;
	GLint uMyTexLoc;
	GLint aVertexPositionLoc;
	GLuint tex_background;
	GLuint tex[7];

	GLuint pieces_fbo[7];
	GLuint vbo_background;

	int width;
	int height;

	GLuint sp, isp;
	GLint aGlobalVertexPositionLoc;
	GLint aGlobalTextureCoordLoc;

public:
	GraphicHandler(int width = 600, int height = 540, bool fullscreen = false, FileLoader * fileloader = NULL);
	~GraphicHandler();
	GraphicPiece * createpiece(piece<float> pol);
	bool render(const std::function< void(const std::function<void(float x, float y, float rot, GraphicPiece * d)> &)> & allbodies );
};

#endif //_GRAPHIC_HANDLER_H