#pragma once

#include <string>

#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

#include "SampleConfig.hpp"

SampleConfig cfg;

void config_panel_example( emp::web::Document& doc ) {

  // ------ Config Panel Example ------
  emp::prefab::Card config_panel_ex("INIT_CLOSED");
  doc << config_panel_ex;
  config_panel_ex.AddHeaderContent("<h3>Config Panel</h3>");
  config_panel_ex << "<h3>Live Demo:</h3><hr>";

  // apply configuration query params and config files to Config
  auto specs = emp::ArgManager::make_builtin_specs(&cfg);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  // cfg.Read("config.cfg");
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);
  emp::prefab::ConfigPanel config_panel(cfg);

  // setup configuration panel
  config_panel_ex << config_panel;

  config_panel_ex << "<br><h3>Code:</h3><hr>";

  const std::string cp_code =
    R"(
      #include "emp/config/ArgManager.hpp"
      #include "emp/prefab/ConfigPanel.hpp"
      #include "emp/web/UrlParams.hpp"
      #include "emp/web/web.hpp"

      #include "../SampleConfig.h"

      emp::web::Document doc("emp_base");

      SampleConfig cfg;

      int main(){
        // apply configuration query params and config files to SampleConfig
        auto specs = emp::ArgManager::make_builtin_specs(&cfg);
        emp::ArgManager am(emp::web::GetUrlParams(), specs);
        // cfg.Read("config.cfg");
        am.UseCallbacks();
        if (am.HasUnused()) std::exit(EXIT_FAILURE);

        emp::prefab::ConfigPanel config_panel(cfg);
        doc << config_panel;
      }
    )";

  emp::prefab::CodeBlock cp_code_block(cp_code, "c++");
  config_panel_ex << cp_code_block;

}
