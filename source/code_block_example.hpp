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
  code_block_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  const std::string code_block_code =
    R"(
      #include "web/web.h"
      #include "prefab/CodeBlock.h"

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
  code_block_ex.AddBodyContent(code_block_block);

  code_block_ex.AddBodyContent("<p>This code bock is built using the code displayed within.</p>");

  code_block_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string cb_html =
    R"(
      <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css">
      <script src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js"></script>
      <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical/source/prefab/HighlightJS.js"></script>
    )";
  emp::prefab::CodeBlock cb_html_block(cb_html, "html");
  code_block_ex.AddBodyContent(cb_html_block);

  code_block_ex.AddBodyContent("<p>NOTE: A list of all languages supported by HighlightJS can be found <a href=\"https://highlightjs.org/static/demo/\" target=\"_blank\">here</a>");

}
