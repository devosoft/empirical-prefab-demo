#pragma once

#include <string>

#include "emp/math/Random.hpp"
#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ReadoutPanel.hpp"
#include "emp/web/Button.hpp"
#include "emp/web/Document.hpp"

int counter = 0;

void readout_panel_example( emp::web::Document& doc ) {

  // ------ Readout Panel Example ------
  emp::prefab::Card readout_panel_ex("INIT_CLOSED");
  doc << readout_panel_ex;
  readout_panel_ex.AddHeaderContent("<h3>Readout Panel</h1");
  readout_panel_ex << "<h3>Live Demo:</h3><hr>";

  emp::prefab::ReadoutPanel values("Readout Values", 100); // Refreshes 10 times a second

  // A random number generator
  std::function<std::string()> random_number = [=]() mutable {
    static emp::Random rand;
    return emp::to_string(rand.GetUInt());
  };
  values.AddValue(
    "Random", "A randomly generated number", random_number,
    "Counter", "How many times you've clicked the button", counter
  );

  readout_panel_ex << values;
  emp::web::Button adder([](){ ++counter; }, "Add one to counter");
  adder.SetAttr("class", "btn btn-primary");
  readout_panel_ex << adder;
  readout_panel_ex << "<br><br><h3>Code:</h3><hr>";

  const std::string readout_panel_code =
    R"(
      #include "emp/math/Random.hpp"
      #include "emp/prefab/Card.hpp"
      #include "emp/prefab/ReadoutPanel.hpp"
      #include "emp/web/web.hpp"
      #include "emp/web/Button.hpp"

      emp::web::Document doc("emp_base");
      int counter = 0;

      int main() {

        emp::prefab::ReadoutPanel values("Readout Values", 100); // Refreshes 10 times a second

        std::function<std::string()> random_number = [=]() mutable {
          static emp::Random rand;
          return emp::to_string(rand.GetUInt());
        };

        values.AddValue(
          "Random", "A randomly generated number", random_number,
          "Counter", "How many times you've clicked the button", counter
        );

        doc << values;
        emp::web::Button adder([](){ ++counter; }, "Add one to counter")
        adder.SetAttr("class", "btn");
        readout_panel_ex << adder;
      }
    )";

  emp::prefab::CodeBlock readout_panel_code_block(readout_panel_code, "c++");
  readout_panel_ex << readout_panel_code_block;
}
