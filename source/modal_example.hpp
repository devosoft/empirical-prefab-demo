
#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/prefab/Modal.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void modal_example( emp::web::Document& doc ) {

  // ------ Modal Example ------
  emp::prefab::Card modal_ex("INIT_CLOSED");
  doc << modal_ex;
  modal_ex.AddHeaderContent("<h3>Modal</h3>");
  modal_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
  emp::prefab::Modal modal;
  modal_ex.AddBodyContent(modal);

  modal.AddHeaderContent("<h3>Modal Header Section</h3>");
  modal.AddBodyContent("This is the content of the modal");

  modal.AddFooterContent("Modal Footer Section");
  emp::web::Button close_btn([](){;}, "Close");
  close_btn.SetAttr("class", "btn btn-secondary");
  modal.AddFooterContent(close_btn);
  modal.AddButton(close_btn);

  modal.AddClosingX();

  emp::web::Button modal_btn([](){;}, "Show Modal");
  modal_ex.AddBodyContent(modal_btn);
  modal_btn.SetAttr("class", "btn btn-info");
  modal.AddButton(modal_btn);

  modal_ex.AddBodyContent("<br><br><br><h3>Code:</h3><hr>");
  const std::string modal_code =
    R"(
      #include "emp/prefab/Modal.hpp"
      #include "emp/web/Button.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Modal modal;
        doc << modal;

        modal.AddHeaderContent("<h3>Modal Header Section</h3>");
        modal.AddBodyContent("This is the content of the modal");

        modal.AddFooterContent("Modal Footer Section");
        emp::web::Button close_btn([](){;}, "Close");
        close_btn.SetAttr("class", "btn btn-secondary");
        modal.AddFooterContent(close_btn);
        modal.AddButton(close_btn);

        modal.AddClosingX();

        emp::web::Button modal_btn([](){;}, "Show Modal");
        doc << modal_btn;
        modal_btn.SetAttr("class", "btn btn-primary");
        modal.AddButton(modal_btn);
      }
    )";
  emp::prefab::CodeBlock modal_code_block(modal_code, "c++");
  modal_ex.AddBodyContent(modal_code_block);

}
