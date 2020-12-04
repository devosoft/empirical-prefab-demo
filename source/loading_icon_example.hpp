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
  loading_icon_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
  emp::prefab::LoadingIcon spinner;
  loading_icon_ex.AddBodyContent(spinner);

  loading_icon_ex.AddBodyContent("<br><br><h3>Code:</h3><hr>");
  const std::string loading_code =
    R"(
      #include "web/web.h"
      #include "prefab/LoadingIcon.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::LoadingIcon spinner;
        doc << spinner;
      }
    )";
  emp::prefab::CodeBlock loading_code_block(loading_code, "c++");
  loading_icon_ex.AddBodyContent(loading_code_block);
  loading_icon_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string loading_html =
    R"(
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    )";
  emp::prefab::CodeBlock loading_html_block(loading_html, "html");
  loading_icon_ex.AddBodyContent(loading_html_block);

}
