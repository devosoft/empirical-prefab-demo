#pragma once

#include <string>

#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/CommentBox.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void comment_box_example( emp::web::Document& doc ) {

  // ------ Comment Box Example ------
  emp::prefab::Card comment_box_ex("INIT_CLOSED");
  doc << comment_box_ex;
  comment_box_ex.AddHeaderContent("<h3>Comment Box</h3>");
  comment_box_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
  emp::prefab::CommentBox box;
  comment_box_ex.AddBodyContent(box);
  emp::web::Div title("desktop_content");
  title << "<p>Content for comment box</p>";
  box.AddContent(title);

  comment_box_ex.AddBodyContent("<br><h3>Code:</h3><hr>");

  const std::string comment_box_code =
    R"(
      #include "web/web.h"
      #include "prefab/CommentBox.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::CommentBox box;
        doc << box;

        emp::web::Div title("desktop_content");
        title << "<p> Content for comment box</p>";
        box.AddContent(title);
      }
    )";

  emp::prefab::CodeBlock comment_box_code_block(comment_box_code, "c++");
  comment_box_ex.AddBodyContent(comment_box_code_block);

}
