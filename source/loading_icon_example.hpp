#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/prefab/LoadingIcon.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void loading_icon_example( emp::web::Document& doc ) {

  // ------ Loading Icon Example ------
  emp::prefab::Card loading_icon_ex("INIT_CLOSED");
  doc << loading_icon_ex;
  loading_icon_ex.AddHeaderContent("<h3>Loading Icon</h3>");
  loading_icon_ex << "<h3>Live Demo:</h3><hr>";
  emp::prefab::LoadingIcon spinner;
  loading_icon_ex << spinner;

  loading_icon_ex << ("<br><br><h3>Code:</h3><hr>");
  const std::string loading_code =
    R"(
      #include "emp/prefab/LoadingIcon.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::LoadingIcon spinner;
        doc << spinner;
      }
    )";
  emp::prefab::CodeBlock loading_code_block(loading_code, "c++");
  loading_icon_ex << loading_code_block;

}
