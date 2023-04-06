#pragma once
#include "compat/misc.h"
#include "util/generic.h"
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace profile {

struct SettingCategory {
  std::string name;
  std::vector<NamedGeneric *> settings;

  SettingCategory(const std::string &name);
  SettingCategory();
  ~SettingCategory();
};

class Settings {
public:
  std::vector<SettingCategory *> categories;
  umap<std::string, NamedGeneric *> settings;

  NamedGeneric *getSetting(const std::string &name);
  ~Settings();

  void clear();
  void loadDescriptors(const std::string &filename);
  void addCategory(SettingCategory *cat);

  void loadSettings(const std::string &filename);
  void saveSettings(const std::string &filename);
};

}; // namespace profile
