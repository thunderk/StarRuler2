#pragma once
#include "mesh.h"
#include "render/render_mesh.h"

namespace render {
RenderMesh *createGLMesh(const Mesh &mesh);
};
