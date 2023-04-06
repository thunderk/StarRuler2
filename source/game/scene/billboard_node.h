#pragma once
#include "render/spritesheet.h"
#include "scene/node.h"

namespace render {
struct RenderState;
};

namespace scene {

class BillboardNode : public Node {
  const render::RenderState *material;
  double width;

public:
  BillboardNode(const render::RenderState *Material, double Width);
  void setWidth(double Width);

  bool preRender(render::RenderDriver &driver);
  void render(render::RenderDriver &driver);
};

class SpriteNode : public Node {
public:
  render::Sprite sprite;
  double width;

  SpriteNode(const render::Sprite &sprt, double Width);
  void setWidth(double Width);

  bool preRender(render::RenderDriver &driver);
  void render(render::RenderDriver &driver);
};

}; // namespace scene
