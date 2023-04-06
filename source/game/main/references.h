#pragma once
#include "mods/mod_manager.h"
#include "os/driver.h"
#include "profile/keybinds.h"
#include "profile/settings.h"
#include "render/camera.h"
#include "render/driver.h"
#include "resource/library.h"
#include "resource/locale.h"
#include "scripts/manager.h"

class Universe;
class NetworkManager;
class PhysicsWorld;
class GamePlatform;

namespace audio {
class ISoundDevice;
extern bool disableSFX;
}; // namespace audio

struct references {
  os::OSDriver *driver;

  resource::Library library;

  NetworkManager *network;

  GamePlatform *cloud;

  render::RenderDriver *render;
  scene::Node *scene;

  audio::ISoundDevice *sound;

  Universe *universe;

  PhysicsWorld *physics, *nodePhysics;

  resource::Locale locale;

  mods::Manager mods;

  profile::Keybinds keybinds;
  struct {
    profile::Settings mod;
    profile::Settings engine;
  } settings;

  struct {
    scripts::Manager *server;
    scripts::Manager *client;
    scripts::Manager *menu;
    scripts::Manager *cache_server;
    scripts::Manager *cache_shadow;
  } scripts;

  struct {
    asIScriptEngine *server;
    asIScriptEngine *client;
    asIScriptEngine *menu;
  } engines;

  references();
};

extern references devices;
