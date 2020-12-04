#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/web/Document.hpp"

void card_example( emp::web::Document& doc ) {

  // ------ Card Example ------
  emp::prefab::Card card_ex("INIT_CLOSED");
  doc << card_ex;
  card_ex.AddHeaderContent("<h3>Card</h3>");
  card_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
  // Collapsible Card, default open
  emp::prefab::Card openCard("INIT_OPEN");
  card_ex.AddBodyContent(openCard);
  // Header content with bootstrap link properties
  openCard.AddHeaderContent("Open card");
  openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");
  openCard.SetCSS("margin-bottom", "15px");

  card_ex.AddBodyContent("<br><h3>Code:</h3><hr>");

  const std::string card_code =
    R"(
      #include "web/web.h"
      #include "prefab/Card.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Card openCard("INIT_OPEN");
        doc << openCard;

        openCard.AddHeaderContent("Open card");
        openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");

        openCard.SetCSS("margin-bottom", "15px");
      }
    )";

  emp::prefab::CodeBlock card_code_block(card_code, "c++");
  card_ex.AddBodyContent(card_code_block);
  card_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string card_html =
    R"(
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    )";
  emp::prefab::CodeBlock card_html_block(card_html, "c++");
  card_ex.AddBodyContent(card_html_block);

}
