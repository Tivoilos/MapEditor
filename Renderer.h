#pragma once
#include "Init.h"
#include "Events.h"
#include "MapEditor.h"
#include "Camera.h"


class Renderer
{
public:

	void renderer(Init& init);
	void cleanup(Init& init);
};