#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ToggleSwitch.hpp"
#include "emp/web/Document.hpp"

void toggle_switch_example(emp::web::Document& doc ) {

  // ------ Toggle Switch Example ------
  emp::prefab::Card toggle_switch_ex("INIT_CLOSED");
  doc << toggle_switch_ex;
  toggle_switch_ex.AddHeaderContent("<h3>Toggle Switch</h3>");
  toggle_switch_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  emp::prefab::ToggleSwitch on_switch(
    [](std::string val){ std::cout << "callback " << val << std::endl; },
    "Switch Defult On",
    true
  );
  toggle_switch_ex.AddBodyContent(on_switch);

  toggle_switch_ex.AddBodyContent("<br>");

  emp::prefab::ToggleSwitch off_switch(
    [](std::string val){ std::cout << "callback " << val << std::endl; },
    "",
    false
  );
  toggle_switch_ex.AddBodyContent(off_switch);

  off_switch.AddLabel("Switch Defult Off");

  toggle_switch_ex.AddBodyContent("<br><br><br><h3>Code:</h3><hr>");

  const std::string toggle_code =
    R"(
      #include "emp/prefab/ToggleSwitch.hpp"
      #include "emp/web/Input.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::ToggleSwitch on_switch(
          [](std::string val){ std::cout << "callback " << val << std::endl; },
          "Switch Defult On",
          true
        );
        doc << on_switch;

        doc << "<br>";

        emp::prefab::ToggleSwitch off_switch(
          [](std::string val){ std::cout << "callback " << val << std::endl; },
          "",
          false
        );
        doc << off_switch;
        off_switch.AddLabel("Switch Defult Off");
      }
    )";

  emp::prefab::CodeBlock toggle_code_block(toggle_code, "c++");
  toggle_switch_ex.AddBodyContent(toggle_code_block);

}
