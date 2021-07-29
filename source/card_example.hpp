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
  card_ex << "<h3>Live Demo:</h3><hr>";
  // Collapsible Card, default open
  emp::prefab::Card openCard("INIT_OPEN");
  card_ex << openCard;
  // Header content with bootstrap link properties
  openCard << "Open card";
  openCard << "Open body content <br> Glyphs <br> Linked title";
  openCard.SetCSS("margin-bottom", "15px");

  card_ex << "<br><h3>Code:</h3><hr>";

  const std::string card_code =
    R"(
      #include "emp/prefab/Card.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Card openCard("INIT_OPEN");
        doc << openCard;

        openCard.AddHeaderContent("Open card");
        openCard << "Open body content <br> Glyphs <br> Linked title";

        openCard.SetCSS("margin-bottom", "15px");
      }
    )";

  emp::prefab::CodeBlock card_code_block(card_code, "c++");
  card_ex << card_code_block;

}
