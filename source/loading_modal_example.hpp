#pragma once

#include <string>

#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/prefab/LoadingModal.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void loading_modal_example( emp::web::Document& doc ) {

  // ------ Loading Modal Example ------
  emp::prefab::Card loading_modal_ex("INIT_CLOSED");
  doc << loading_modal_ex;
  loading_modal_ex.AddHeaderContent("<h3>Loading Modal</h3>");
  loading_modal_ex << "<h3>Live Demo:</h3><hr>";

  loading_modal_ex << "<p>Click button to show loading modal. It will close automatically after a few seconds.</p>";
  emp::web::Button loading_modal_demo([](){emscripten_run_script("DemoLoadingModal();");}, "Show Loading Modal");
  loading_modal_ex << loading_modal_demo;
  loading_modal_demo.SetAttr(
    "class", "btn btn-info"
  );

  loading_modal_ex << "<br><br><br><h3>Code:</h3><hr>";
  const std::string loading_modal_code =
    R"(
      #include "emp/prefab/LoadingModal.hpp"
      #include "emp/web/web.hpp"

      emp::web::Document doc("emp_base");

      int main(){
        // Code that takes a while to render on web page

        emp::prefab::CloseLoadingModal();
      }
    )";
  emp::prefab::CodeBlock loading_modal_code_block(loading_modal_code, "c++");
  loading_modal_ex << loading_modal_code_block;
  loading_modal_ex << "<p>Add Loading Modal script at the top of the body section of your HTML file.</p>";
  const std::string loading_modal_html =
    R"(
      <html>
      <head>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="jquery-1.11.2.min.js></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"></script>
        <link rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/DefaultConfigPanelStyle.css">
      </head>

      <body>
        <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/LoadingModal.js"></script>
        <!-- Rest of web page -->
      </body>
      </html>
    )";
  emp::prefab::CodeBlock loading_modal_code_block_html(loading_modal_html, "html");
  loading_modal_ex << loading_modal_code_block_html;

}
