#pragma once

#include <string>

#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

#include "SampleConfig.hpp"

SampleConfig cfg;

// TODO: Find a way to initialize config panels within main()
// Issue #366 (https://github.com/devosoft/Empirical/issues/366)
emp::prefab::ConfigPanel config_panel(cfg);

void config_panel_example( emp::web::Document& doc ) {

  // ------ Config Panel Example ------
  emp::prefab::Card config_panel_ex("INIT_CLOSED");
  doc << config_panel_ex;
  config_panel_ex.AddHeaderContent("<h3>Config Panel</h3>");
  config_panel_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  // apply configuration query params and config files to Config
  auto specs = emp::ArgManager::make_builtin_specs(&cfg);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  // cfg.Read("config.cfg");
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);

  // setup configuration panel
  config_panel.Setup();
  config_panel_ex.AddBodyContent(config_panel.GetConfigPanelDiv());

  config_panel_ex.AddBodyContent("<br><h3>Code:</h3><hr>");

  const std::string cp_code =
    R"(
      #include "web/web.h"
      #include "prefab/ConfigPanel.h"
      #include "config/ArgManager.h"
      #include "web/UrlParams.h"

      #include "../SampleConfig.h"

      emp::web::Document doc("emp_base");

      SampleConfig cfg;
      emp::prefab::ConfigPanel config_panel(cfg);

      int main(){
        // apply configuration query params and config files to SampleConfig
        auto specs = emp::ArgManager::make_builtin_specs(&cfg);
        emp::ArgManager am(emp::web::GetUrlParams(), specs);
        // cfg.Read("config.cfg");
        am.UseCallbacks();
        if (am.HasUnused()) std::exit(EXIT_FAILURE);

        // setup configuration panel
        config_panel.Setup();
        doc << config_panel.GetDiv();
      }
    )";

  emp::prefab::CodeBlock cp_code_block(cp_code, "c++");
  config_panel_ex.AddBodyContent(cp_code_block);

}
