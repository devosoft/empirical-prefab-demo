//  This file is part of Empirical Prefab Demo
//  Copyright (C) Sara Boyd, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "emp/config/ArgManager.hpp"
#include "emp/prefab/Card.hpp"
#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/Collapse.hpp"
#include "emp/prefab/CommentBox.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/prefab/LoadingIcon.hpp"
#include "emp/prefab/LoadingModal.hpp"
#include "emp/prefab/Modal.hpp"
#include "emp/prefab/ToggleSwitch.hpp"
#include "emp/web/UrlParams.hpp"
#include "emp/web/web.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Input.hpp"

#include "../SampleConfig.hpp"

namespace UI = emp::web;

UI::Document doc("emp_base");

SampleConfig cfg;

// TODO: Find a way to initialize config panels within main()
// Issue #366 (https://github.com/devosoft/Empirical/issues/366)
emp::prefab::ConfigPanel config_panel(cfg);

int main()
{

  std::cout << "Hello, console!" << std::endl;

  emp::web::Div empirical_info;
  doc << empirical_info;
  emp::prefab::FontAwesomeIcon info_icon("fa-info-circle");
  empirical_info << info_icon;
  info_icon.SetCSS(
    "margin-right", "10px",
    "display", "inline-block"
  );
  empirical_info << "<p style=\"display: inline-block\">This is part of <a href=\"https://github.com/devosoft/Empirical\" target=\"_blank\">Empirical</a>, a library of tools for developing efficient, reliable, and accessible scientific software.</p>";

  doc << "<p>These prefabricated tools were created to help you quickly create interesting web applicications without being overwhelmed with the underlying HTML, CSS, and Bootstrap classes required. These tools use Empirical's web tools to provide structure for the site, and many of the prefab tools inherit from web tools so you can add your own styling and stream them into other web components in a similar way.</p>";
  doc << "<p>To uses any of these tools, you'll want to add the Bootstrap and Empirical's DefaultPrefabStyle stylesheet to the head of your html file. Of course you can override the style of any of the classes in these files with your own CSS file if it is linked after these two.";

  const std::string styles_code =
    R"(
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
      <link rel="stylesheet/less" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical/source/fresh-prefab/DefaultPrefabStyles.less">
      <script src="//cdn.jsdelivr.net/npm/less" ></script>
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

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

  // ------ Collapse Example ------
  emp::prefab::Card collapse_ex("INIT_CLOSED");
  doc << collapse_ex;
  collapse_ex.AddHeaderContent("<h3>Collapse</h3>");
  collapse_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
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

  emp::web::Div btn3;
  btn3.SetAttr("class", "btn btn-success");
  btn3 << "Button 3: controls all boxes";

  collapse1.AddController(btn3, true);
  collapse2.AddController(collapse1.GetControllerDiv(1), true);

  collapse_ex.AddBodyContent(collapse1.GetControllerDiv(0));
  collapse_ex.AddBodyContent(collapse1.GetTargetDiv(0));
  collapse_ex.AddBodyContent(collapse2.GetControllerDiv(0));
  collapse_ex.AddBodyContent(collapse2.GetTargetDiv(0));
  collapse_ex.AddBodyContent(collapse1.GetControllerDiv(1));

  collapse_ex.AddBodyContent("<br><br><h3>Code:</h3><hr>");

  const std::string collapse_code =
    R"(
      #include "web/web.h"
      #include "web/Div.h"
      #include "prefab/CommentBox.h"

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

        // Create a button that controls two different CollapseCoupling instances
        emp::web::Div btn3;
        btn3.SetAttr("class", "btn btn-success");
        btn3 << "Button 3: controls all boxes" ;
        collapse1.AddController(btn3, true);
        collapse2.AddController(collapse1.GetControllerDiv(1), true);

        doc << collapse1.GetControllerDiv(0);
        doc << collapse1.GetTargetDiv(0);
        doc << collapse2.GetControllerDiv(0);
        doc << collapse2.GetTargetDiv(0);
        doc << collapse1.GetControllerDiv(1);
      }
    )";

  emp::prefab::CodeBlock collapse_code_block(collapse_code, "c++");
  collapse_ex.AddBodyContent(collapse_code_block);

  // ------ Comment Box Example ------
  emp::prefab::Card comment_box_ex("INIT_CLOSED");
  doc << comment_box_ex;
  comment_box_ex.AddHeaderContent("<h3>Comment Box</h3>");
  comment_box_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");
  emp::prefab::CommentBox box;
  comment_box_ex.AddBodyContent(box);
  UI::Div title("desktop_content");
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

  // ------ Config Panel Example ------
  emp::prefab::Card config_panel_ex("INIT_CLOSED");
  doc << config_panel_ex;
  config_panel_ex.AddHeaderContent("<h3>Config Panel</h3>");
  config_panel_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  // apply configuration query params and config files to Config
  auto specs = emp::ArgManager::make_builtin_specs(&cfg);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  // cfg.Read("config.cfg");
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);

  // setup configuration panel
  config_panel.Setup();
  config_panel_ex.AddBodyContent(config_panel.GetDiv());

  config_panel_ex.AddBodyContent("<br><h3>Code:</h3><hr>");

  const std::string cp_code =
    R"(
      #include "web/web.h"
      #include "prefab/ConfigPanel.h"
      #include "config/ArgManager.h"
      #include "web/UrlParams.h"

      #include "../SampleConfig.h"

      emp::web::Document doc("emp_base");

      SampleConfig cfg;
      emp::prefab::ConfigPanel config_panel(cfg);

      int main(){
        // apply configuration query params and config files to SampleConfig
        auto specs = emp::ArgManager::make_builtin_specs(&cfg);
        emp::ArgManager am(emp::web::GetUrlParams(), specs);
        // cfg.Read("config.cfg");
        am.UseCallbacks();
        if (am.HasUnused()) std::exit(EXIT_FAILURE);

        // setup configuration panel
        config_panel.Setup();
        doc << config_panel.GetDiv();
      }
    )";

  emp::prefab::CodeBlock cp_code_block(cp_code, "c++");
  config_panel_ex.AddBodyContent(cp_code_block);

  // ------ FontAwesome Icon Example ------
  emp::prefab::Card fa_icon_ex("INIT_CLOSED");
  doc << fa_icon_ex;
  fa_icon_ex.AddHeaderContent("<h3>FontAwesome Icon</h3>");
  fa_icon_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  UI::Div toggleIcons;
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
      #include "web/web.h"
      #include "prefab/FontAwesomeIcon.h"

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

  // ------ Loading Modal Example ------
  emp::prefab::Card loading_modal_ex("INIT_CLOSED");
  doc << loading_modal_ex;
  loading_modal_ex.AddHeaderContent("<h3>Loading Modal</h3>");
  loading_modal_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  loading_modal_ex.AddBodyContent("<p>Click button to show loading modal. It will close automatically after a few seconds.</p>");
  UI::Button loading_modal_demo([](){emscripten_run_script("DemoLoadingModal();");}, "Show Loading Modal");
  loading_modal_ex.AddBodyContent(loading_modal_demo);
  loading_modal_demo.SetAttr(
    "class", "btn btn-info"
  );

  loading_modal_ex.AddBodyContent("<br><br><br><h3>Code:</h3><hr>");
  const std::string loading_modal_code =
    R"(
      #include "web/web.h"
      #include "prefab/LoadingModal.h"

      emp::web::Document doc("emp_base");

      int main(){
        // Code that takes a while to render on web page

        emp::prefab::CloseLoadingModal();
      }
    )";
  emp::prefab::CodeBlock loading_modal_code_block(loading_modal_code, "c++");
  loading_modal_ex.AddBodyContent(loading_modal_code_block);
  loading_modal_ex.AddBodyContent("<p>Add Loading Modal script at the top of the body section of your HTML file.</p>");
  const std::string loading_modal_html =
    R"(
      <html>
      <head>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
        <script src="jquery-1.11.2.min.js></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"></script>
        <link rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical/source/prefab/DefaultConfigPanelStyle.css">
      </head>

      <body>
        <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical/source/prefab/LoadingModal.js"></script>
        <!-- Rest of web page -->
      </body>
      </html>
    )";
  emp::prefab::CodeBlock loading_modal_code_block_html(loading_modal_html, "html");
  loading_modal_ex.AddBodyContent(loading_modal_code_block_html);

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
  UI::Button close_btn([](){;}, "Close");
  close_btn.SetAttr("class", "btn btn-secondary");
  modal.AddFooterContent(close_btn);
  modal.AddButton(close_btn);

  modal.AddClosingX();

  UI::Button modal_btn([](){;}, "Show Modal");
  modal_ex.AddBodyContent(modal_btn);
  modal_btn.SetAttr("class", "btn btn-info");
  modal.AddButton(modal_btn);

  modal_ex.AddBodyContent("<br><br><br><h3>Code:</h3><hr>");
  const std::string modal_code =
    R"(
      #include "web/web.h"
      #include "web/Button.h"
      #include "prefab/Modal.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Modal modal;
        doc << modal;

        modal.AddHeaderContent("<h3>Modal Header Section</h3>");
        modal.AddBodyContent("This is the content of the modal");

        modal.AddFooterContent("Modal Footer Section");
        UI::Button close_btn([](){;}, "Close");
        close_btn.SetAttr("class", "btn btn-secondary");
        modal.AddFooterContent(close_btn);
        modal.AddButton(close_btn);

        modal.AddClosingX();

        UI::Button modal_btn([](){;}, "Show Modal");
        doc << modal_btn;
        modal_btn.SetAttr("class", "btn btn-primary");
        modal.AddButton(modal_btn);
      }
    )";
  emp::prefab::CodeBlock modal_code_block(modal_code, "c++");
  modal_ex.AddBodyContent(modal_code_block);

  // ------ Toggle Switch Example ------
  emp::prefab::Card toggle_switch_ex("INIT_CLOSED");
  doc << toggle_switch_ex;
  toggle_switch_ex.AddHeaderContent("<h3>Toggle Switch</h3>");
  toggle_switch_ex.AddBodyContent("<h3>Live Demo:</h3><hr>");

  emp::prefab::ToggleSwitch on_switch([](std::string val){}, "Switch Defult On", true);
  toggle_switch_ex.AddBodyContent(on_switch);

  toggle_switch_ex.AddBodyContent("<br>");

  emp::prefab::ToggleSwitch off_switch([](std::string val){}, NULL, false);
  toggle_switch_ex.AddBodyContent(off_switch);

  off_switch.AddLabel("Switch Defult Off");

  toggle_switch_ex.AddBodyContent("<br><br><br><h3>Code:</h3><hr>");

  const std::string toggle_code =
    R"(
      #include "web/web.h"
      #include "web/Input.h"
      #include "prefab/ToggleSwitch.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::ToggleSwitch on_switch([](std::string val){},"Switch Defult On", true);
        doc << on_switch;

        doc << "<br>";

        emp::prefab::ToggleSwitch off_switch([](std::string val){}, NULL, false);
        doc << off_switch;
        off_switch.AddLabel("Switch Defult Off");
      }
    )";

  emp::prefab::CodeBlock toggle_code_block(toggle_code, "c++");
  toggle_switch_ex.AddBodyContent(toggle_code_block);

  toggle_switch_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string toggle_html =
    R"(
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
    )";
  emp::prefab::CodeBlock toggle_html_block(toggle_html, "html");
  toggle_switch_ex.AddBodyContent(toggle_html_block);


  emp::prefab::CloseLoadingModal();
}
