#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void font_awesome_icon_example( emp::web::Document& doc ) {

  // ------ FontAwesome Icon Example ------
  emp::prefab::Card fa_icon_ex("INIT_CLOSED");
  doc << fa_icon_ex;
  fa_icon_ex.AddHeaderContent("<h3>FontAwesome Icon</h3>");
  fa_icon_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  emp::web::Div toggleIcons;
  fa_icon_ex.AddBodyContent(toggleIcons);
  emp::prefab::FontAwesomeIcon check("fa-check-square-o");
  toggleIcons << check;
  emp::prefab::FontAwesomeIcon dots("fa-ellipsis-v");
  toggleIcons << dots;
  emp::prefab::FontAwesomeIcon code("fa-code");
  toggleIcons << code;
  emp::prefab::FontAwesomeIcon up("fa-angle-double-up");
  toggleIcons << up;
  check.SetCSS("margin-left", "15px");
  dots.SetCSS("margin-left", "15px");
  code.SetCSS("margin-left", "15px");
  up.SetCSS("margin-left", "15px");

  fa_icon_ex.AddBodyContent("<br>More icons <a href=\"https://fontawesome.com/v4.7.0/icons/\" target=\"_blank\">here</a><br>");

  fa_icon_ex.AddBodyContent("<br><br><h3>Code:</h3><hr>");

  const std::string icon_code =
    R"(
      #include "emp/prefab/FontAwesomeIcon.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        emp::web::Div toggleIcons;
        doc << toggleIcons;
        toggleIcons << "<p> Toggle Icons </p>";

        emp::prefab::FontAwesomeIcon check("fa-check-square-o");
        toggleIcons << check;
        emp::prefab::FontAwesomeIcon dots("fa-ellips-v");
        toggleIcons << dots;
        emp::prefab::FontAwesomeIcon code("fa-code");
        toggleIcons << code;
        emp::prefab::FontAwesomeIcon up("fa-angle-double-up");
        toggleIcons << up;

        check.SetCSS("margin-left", "15px");
        dots.SetCSS("margin-left", "15px");
        code.SetCSS("margin-left", "15px");
        up.SetCSS("margin-left", "15px");
      }
    )";

  emp::prefab::CodeBlock icon_code_block(icon_code, "c++");
  fa_icon_ex.AddBodyContent(icon_code_block);
  fa_icon_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string icon_html =
    R"(
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    )";
  emp::prefab::CodeBlock icon_html_block(icon_html, "html");
  fa_icon_ex.AddBodyContent(icon_html_block);

}
