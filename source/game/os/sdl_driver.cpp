#include "os/sdl_driver.h"
#include <random>
#include <string>
#include <vector>

namespace os {

class SDLDriver;
SDLDriver *driver = 0;

class SDLDriver : public OSDriver {
public:
  SDLDriver() {}

  ~SDLDriver() {}

  bool systemRandom(unsigned char *buffer, unsigned bytes) {
    std::random_device rd;
    for (unsigned i = 0; i < bytes; ++i)
      buffer[i] = (unsigned char)rd();
    return true;
  }

  void setVerticalSync(int waitFrames) {}

  void swapBuffers(double minWait_s) {}

  void handleEvents(unsigned minWait_ms) {}

  void getDesktopSize(unsigned &width, unsigned &height) {}

  void createWindow(WindowData &data) {}

  void getVideoModes(std::vector<OSDriver::VideoMode> &output) {}

  void getMonitorNames(std::vector<std::string> &output) {}

  bool isWindowFocused() override { return true; }

  bool isWindowMinimized() override { return false; }

  void flashWindow() override {}

  bool isMouseOver() { return true; }

  void setClipboard(const std::string &text) {}

  std::string getClipboard() { return ""; }

  int getCharForKey(int key) { return 0; }

  int getKeyForChar(unsigned char chr) { return 0; }

  unsigned getDoubleClickTime() const { return 0; }

  void getLastMousePos(int &x, int &y) {}

  void getMousePos(int &x, int &y) {}

  void setMousePos(int x, int y) {}

  void setCursorVisible(bool visible) {}

  void setCursorLocked(bool locked) {}

  void setCursorShouldLock(bool locked) {}

  void sleep(int milliseconds) {}

  void resetTimer() {}

  int getTime() const { return 0; }

  double getAccurateTime() const { return 0.0; }

  void resetGameTime(double time) {}

  double getGameTime() const { return 0.0; }

  double getFrameTime() const { return 0.0; }

  double getGameSpeed() const { return 0.0; }

  void setGameSpeed(double speed) {}

  unsigned getProcessorCount() { return 1; }

  void setWindowTitle(const char *str) {}

  void setWindowSize(int width, int height) {}

  void closeWindow() {}
};

OSDriver *getSDLDriver() {
  if (!driver)
    driver = new SDLDriver();
  return driver;
}

}; // namespace os
