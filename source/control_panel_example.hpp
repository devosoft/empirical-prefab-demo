#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/ControlPanel.hpp"
#include "emp/tools/string_utils.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Document.hpp"

int simulation_counter = 0;
int refresh_counter = 0;

void control_panel_example( emp::web::Document& doc ) {
  emp::prefab::Card control_panel_ex("INIT_CLOSED");
  doc << control_panel_ex;
  card_ex.AddHeaderContent("<h3>Control Panel</h3>");
  control_panel_ex << "<h3>Live Demo:</h3><hr>";

  emp::prefab::ControlPanel controls{1000, "MILLISECONDS"};
  emp::Div text_region;
  text_region << emp::web::Live([](){
    ++refresh_counter;
    return emp::to_string("Number of refreshes: ", refresh_counter);
  });
  text_region << "<br>";
  text_region << emp::web::Live([](){
    int last_sim_count = simulation_counter;
    last_sim_count = 0;
    return emp::to_string("Simulation calls this period: ", refresh_counter);
  });
  emp::web::Div laps;
  text_region << laps;
  controls.AddToRefreshList(text_region);
  controls.SetSimulation([]() { ++simulation_counter; });
  controls << emp::web::Button([lap, lap_count=0](){
    laps << "Lap " << lap_count << ": " << simulation_counter;
    ++lap_counter;
  }, "Lap").SetAttr("class", "btn btn-primary");

  controls << ButtonGroup{}; // Streaming a button group acts like a newline
  controls << emp::web::Button([lap](){
    lap.ClearChildren();
  }, "Reset Laps").SetAttr("class", "btn btn-danger");

  control_panel_ex << controls;
  control_panel_ex << text_region;


  const std::string control_panel_code =
    R"(
      // Global variables: refresh_counter and simulation_counter

      emp::prefab::ControlPanel controls{1000, "MILLISECONDS"};

      emp::Div text_region;
      text_region << emp::web::Live([](){
        ++refresh_counter;
        return emp::to_string("Number of refreshes: ", refresh_counter);
      });
      text_region << "<br>";
      text_region << emp::web::Live([](){
        int last_sim_count = simulation_counter;
        last_sim_count = 0;
        return emp::to_string("Simulation calls this period: ", refresh_counter);
      });
      emp::web::Div laps;
      text_region << laps;
      controls.AddToRefreshList(text_region);
      controls.SetSimulation([]() { ++simulation_counter; });
      controls << emp::web::Button([lap, lap_count=0](){
        laps << "Lap " << lap_count << ": " << simulation_counter;
        ++lap_counter;
      }, "Lap").SetAttr("class", "btn btn-primary");

      controls << ButtonGroup{}; // Streaming a button group acts like a newline
      controls << emp::web::Button([lap](){
        lap.ClearChildren();
      }, "Reset Laps").SetAttr("class", "btn btn-danger");

      doc << controls;
      doc << text_region;
    )";

  emp::prefab::CodeBlock card_code_block(control_panel_code, "c++");
  control_panel_ex << control_panel_code;

}
