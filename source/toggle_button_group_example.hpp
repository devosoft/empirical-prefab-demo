#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ButtonGroup.hpp"
#include "emp/prefab/ToggleButtonGroup.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/tools/string_utils.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Document.hpp"

void toggle_button_group_example( emp::web::Document& doc ) {
  emp::prefab::Card tbg_ex("INIT_CLOSED");
  doc << tbg_ex;
  card_ex.AddHeaderContent("<h3>Toggle Button Group</h3>");
  tbg_ex << "<h3>Live Demo:</h3><hr>";

  tbg_ex << "<h5>On its own:<h5>";
  emp::prefab::ToggleButtonGroup reaction{
    emp::prefab::FontAwesomeIcon("fa-smile-o"), emp::prefab::FontAwesomeIcon("fa-frown-o"),
    "success", "danger"
  };
  emp::web::Div reaction_post;
  reaction.SetCallback([reaction_post](bool happy) {
    if (happy) {
      reaction_post << "Happy!";
    } else {
      reaction_post << "Sad :(";
    }
  });
  tbg_ex << reaction;
  tbg_ex << reaction_post;
  tbg_ex << "<h5>In button groups:<h5>";
  ButtonGroup grouping;
  grouping << emp::prefab::ToggleButtonGroup{ "Default", "Coloring" };
  grouping << emp::prefab::ToggleButtonGroup{
    "Custom", "Coloring", "light", "dark"
  };
  grouping << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-motorcycle"),
    emp::prefab::FontAwesomeIcon("fa-car"),
    "primary", "secondary"
  };
  tbg_ex << grouping;

  tbg_ex << "<h5>Hiding the inactive label:<h5>";
  ButtonGroup hidden;
  hidden << emp::prefab::ToggleButtonGroup{
    "Default", "Coloring",
    "success", "warning",
    false
  };
  hidden << emp::prefab::ToggleButtonGroup{
    "Custom", "Coloring", "light", "dark",
    false
  };
  hidden << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-motorcycle"), emp::prefab::FontAwesomeIcon("fa-car"),
    "primary", "secondary",
    false
  };
  tbg_ex << hidden;

  tbg_ex << "<h5>Graying out an inactive label:<h5>";
  tbg_ex << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-tree"), emp::prefab::FontAwesomeIcon("fa-tint"),
    "success", "primary",
    false, true
  };

  const std::string tbg_code =
  R"(
  doc << "<h5>On its own:<h5>";
  emp::prefab::ToggleButtonGroup reaction{
    emp::prefab::FontAwesomeIcon("fa-smile-o"), emp::prefab::FontAwesomeIcon("fa-frown-o"),
    "success", "danger"
  };
  emp::web::Div reaction_post;
  reaction.SetCallback([reaction_post](bool happy) {
    if (happy) {
      reaction_post << "Happy!";
    } else {
      reaction_post << "Sad :(";
    }
  });
  doc << reaction;
  doc << reaction_post;
  doc << "<h5>In button groups:<h5>";
  ButtonGroup grouping;
  grouping << emp::prefab::ToggleButtonGroup{ "Default", "Coloring" };
  grouping << emp::prefab::ToggleButtonGroup{
    "Custom", "Coloring", "light", "dark"
  };
  grouping << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-motorcycle"),
    emp::prefab::FontAwesomeIcon("fa-car"),
    "primary", "secondary"
  };
  doc << grouping;

  doc << "<h5>Hiding the inactive label:<h5>";
  ButtonGroup hidden;
  hidden << emp::prefab::ToggleButtonGroup{
    "Default", "Coloring",
    "success", "warning",
    false
  };
  hidden << emp::prefab::ToggleButtonGroup{
    "Custom", "Coloring", "light", "dark",
    false
  };
  hidden << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-motorcycle"), emp::prefab::FontAwesomeIcon("fa-car"),
    "primary", "secondary",
    false
  };
  doc << hidden;

  doc << "<h5>Graying out an inactive label:<h5>";
  doc << emp::prefab::ToggleButtonGroup{
    emp::prefab::FontAwesomeIcon("fa-tree"), emp::prefab::FontAwesomeIcon("fa-tint"),
    "success", "primary",
    false, true
  };
  )";

  emp::prefab::CodeBlock tbg_code_block(control_panel_code, "c++");
  tbg_ex << tbg_code_block;
}
