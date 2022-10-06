#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/Collapse.hpp"
#include "emp/prefab/CommentBox.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Document.hpp"

void collapse_example( emp::web::Document& doc ) {

  // ------ Collapse Example ------
  emp::prefab::Card collapse_ex("INIT_CLOSED");
  doc << collapse_ex;
  collapse_ex.AddHeaderContent("<h3>Collapse</h3>");
  collapse_ex << "<h3>Live Demo:</h3><hr>";
  emp::prefab::CommentBox box1;
  box1.AddContent("<h3>Box 1</h3>");
  emp::web::Div btn1;
  btn1.SetAttr("class", "btn btn-info");
  btn1 << "Button 1: controls box 1";

  emp::prefab::CommentBox box2;
  box2.AddContent("<h3>Box 2</h3>");
  emp::web::Div btn2;
  btn2.SetAttr("class", "btn btn-info");
  btn2 << "Button 2: controls box 2";

  emp::prefab::CollapseCoupling collapse1(btn1, box1, true);
  emp::prefab::CollapseCoupling collapse2(btn2, box2, true);

  // emp::web::Div btn3;
  // btn3.SetAttr("class", "btn btn-success");
  // btn3 << "Button 3: controls all boxes";
  //
  // collapse1.AddController(btn3, true);
  // collapse2.AddController(btn3, true);

  collapse_ex << collapse1.GetControllerDiv(0);
  collapse_ex << collapse1.GetTargetDiv(0);
  collapse_ex << collapse2.GetControllerDiv(0);
  collapse_ex << collapse2.GetTargetDiv(0);
  // collapse_ex << collapse1.GetControllerDiv(1);

  collapse_ex << "<br><br><h3>Code:</h3><hr>";

  const std::string collapse_code =
    R"(
      #include "emp/prefab/CommentBox.hpp"
      #include "emp/web/web.hpp"
      #include "emp/web/Div.hpp"

      #include "prefab/Collapse.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::CommentBox box1;
        box1.AddContent("<h3>Box 1</h3>");
        emp::web::Div btn1;
        btn1.SetAttr("class", "btn btn-info");
        btn1 << "Button 1: controls box 1";

        emp::prefab::CommentBox box2;
        box2.AddContent("<h3>Box 2</h3>");
        emp::web::Div btn2;
        btn2.SetAttr("class", "btn btn-info");
        btn2 << "Button 2: controls box 2";

        emp::prefab::CollapseCoupling collapse1(btn1, box1, true);
        emp::prefab::CollapseCoupling collapse2(btn2, box2, true);

        doc << collapse1.GetControllerDiv(0);
        doc << collapse1.GetTargetDiv(0);
        doc << collapse2.GetControllerDiv(0);
        doc << collapse2.GetTargetDiv(0);
      }
    )";

  emp::prefab::CodeBlock collapse_code_block(collapse_code, "c++");
  collapse_ex << (collapse_code_block);

}
