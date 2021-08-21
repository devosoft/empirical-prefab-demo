#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/web/Document.hpp"

void code_block_example( emp::web::Document& doc ) {

  // ------ Code Block Example ------
  emp::prefab::Card code_block_ex("INIT_CLOSED");
  doc << code_block_ex;
  code_block_ex.AddHeaderContent("<h3>Code Block </h1");
  code_block_ex << "<h3>Live Demo:</h3><hr>";

  const std::string code_block_code =
    R"(
      #include "emp/prefab/CodeBlock.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        const std::string inner_code =
          R"(
            int num = 9;
            std::cout << num << " is a square number" << std::endl;
          ) ";

        emp::prefab::CodeBlock my_code(inner_code, "c++");
        doc << my_code;
      }
      )";

  emp::prefab::CodeBlock code_block_block(code_block_code, "c++");
  code_block_ex << code_block_block ;

  code_block_ex << "<p>This code bock is built using the code displayed within.</p>";

  code_block_ex << "<p>Add to HTML file</p>";
  const std::string cb_html =
    R"(

    )";
  emp::prefab::CodeBlock cb_html_block(cb_html, "html");
  code_block_ex << cb_html_block;

  code_block_ex << "<p>NOTE: A list of all languages supported by HighlightJS can be found <a href=\"https://highlightjs.org/static/demo/\" target=\"_blank\">here</a>";

}
