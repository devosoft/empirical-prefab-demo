//  This file is part of Empirical Prefab Demo
//  Copyright (C) Sara Boyd, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "web/web.h"
#include "web/Div.h"
#include "web/Input.h"
#include "prefab/Card.h"
#include "prefab/CodeBlock.h"
#include "prefab/Collapse.h"
#include "prefab/CommentBox.h"
#include "prefab/ConfigPanel.h"
#include "prefab/FontAwesomeIcon.h"
#include "prefab/LoadingIcon.h"
#include "prefab/ToggleSwitch.h"

#include "../example.h"
#include "../SampleConfig.h"
#include "config/ArgManager.h"
#include "web/UrlParams.h"

namespace UI = emp::web;

UI::Document doc("emp_base");

SampleConfig cfg;

emp::prefab::ConfigPanel config_panel(cfg);

int main()
{
  std::cout << "Hello, console!" << std::endl;

  doc << "<p>These prefabricated tools were created to help you quickly create interesting web applicications without being overwhelmed with the underlying HTML, CSS, and Bootstrap classes required. These tools use Empirical's web tools to provide structure for the site, and many of the prefab tools inherit from web tools so you can add your own styling and stream them into other web components in a similar way.</p>";
  doc << "<p>To uses any of these tools, you'll want to add the Bootstrap and Empirical's DefaultConfigStyle stylesheet to the head of your html file. Of course you can override the style of any of the classes in these files with your own CSS file if it is linked after these two.";

  const std::string styles_code = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"&gt
      &ltlink rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@prefab/source/prefab/DefaultConfigPanelStyle.css"&gt
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

  doc << "<br><br><h1>Card Example</h1>";
  // Collapsible Card, default open
  emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
  doc << openCard;
  // Header content with bootstrap link properties
  openCard.AddHeaderContent("Open card");
  openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");
  openCard.SetCSS("margin-bottom", "15px");

  doc << "<br><h3>Code:</h3>";
  
  const std::string card_code =
    R"(
      #include "web/web.h"
      #include "prefab/Card.h"

      emp::web::Document doc("emp_base");

      emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
      doc << openCard;
      
      openCard.AddHeaderContent("Open card");
      openCard.AddBodyContent("Open body content &ltbr&gt Glyphs &ltbr&gt Linked title");

      openCard.SetCSS("margin-bottom", "15px");
    )";

  emp::prefab::CodeBlock card_code_block(card_code, "c++");
  doc << card_code_block;
  // card_code_block << "should throw error"; // it does
  doc << "<p>Add to HTML file</p>";
  const std::string card_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock card_html_block(card_html, "c++");
  doc << card_html_block;

  doc << "<hr><br>";

  doc << "<h1>Code Block Example</h1";

  const std::string code_block_code = 
    R"(
      #include "web/web.h"
      #include "prefab/CodeBlock.h"

      emp::web::Document doc("emp_base");

      const std::string inner_code = 
        R&quot(
          int num = 9;
          std::cout << num << " is a square number" << std::endl;
        )&quot;

      emp::prefab::CodeBlock my_code(inner_code, "c++");
      doc << my_code;
      )";

  emp::prefab::CodeBlock code_block_block(code_block_code, "c++");
  doc << code_block_block;

  doc<< "<p>This code bock is built using the code displayed within.</p>";

  doc << "<p>Add to HTML file</p>";
  const std::string cb_html = 
    R"(
      &ltlink rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css"&gt
      &ltscript src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js"&gt&lt/script&gt
      &ltscript&gt hljs.initHighlightingOnLoad();&lt/script&gt    
    )";
  emp::prefab::CodeBlock cb_html_block(cb_html, "html");
  doc << cb_html_block;

  doc << "<hr><br>";

  doc << "<h1>Collapse Example</h1>";
  UI::Div btn;
  UI::Div content;

  emp::prefab::Collapse collapse(btn, content, true, "my_collapse");
  doc << collapse.GetLinkDiv();
  doc << collapse.GetToggleDiv();

  btn.SetAttr("class", "btn btn-info");
  btn << "Click me";
  content << "This content starts out open and has an id of 'my_collapse'.<hr>";
  content << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
  content.SetCSS(
    "width", "45%",
    "margin", "15px",
    "border", "1px solid #ede9e8",
    "border-radius", "5px",
    "padding", "10px"
  );
  doc << "<br><h3>Code:</h3>";

  const std::string collapse_code =
    R"(
      #include "web/web.h"
      #include "prefab/Collapse.h"
      
      emp::web::Document doc("emp_base");

      emp::web::Div btn;
      emp::web::Div content;

      emp::prefab::Collapse collapse(btn, content, true, "my_collapse");
      doc << collapse.GetLinkDiv();
      doc << collapse.GetToggleDiv();

      btn << "Click me";
      content << "This content starts out open and has an id of 'my_collapse'. &lthr&gt";
      content << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor.";
      
      btn.SetAttr("class", "btn btn-info");
      content.SetCSS(
        "width", "45%",
        "margin", "15px",
        "border", "1px solid #ede9e8",
        "border-radius", "5px",
        "padding", "10px"
      );
    )";

  emp::prefab::CodeBlock collapse_code_block(collapse_code, "c++");
  doc << collapse_code_block;

  doc << "<hr><br>";

  doc << "<h1>Comment Box Example</h1>";
  emp::prefab::CommentBox box;
  UI::Div title("desktop_content");
  title << "<p>Content that shows on all screen sizes</p>";
  box.AddContent(title);
  UI::Element mobile("span");
  mobile << "<p>Content that only shows on small screens <br>Web conponents can be added as content</p>";
  mobile << "<hr>";
  box.AddMobileContent(mobile);
  box.AddMobileContent("<b>String literals can also be added to boxes!</b>");
  doc << box;

  doc << "<br><h3>Code:</h3>";

  const std::string comment_box_code =
    R"(
      #include "web/web.h"
      #include "prefab/CommentBox.h"
      
      emp::web::Document doc("emp_base");

      emp::prefab::CommentBox box;

      emp::web::Div title("desktop_content");
      title << "&ltp&gt Content that shows on all screen sizes &lt/p&gt";
      box.AddContent(title);

      emp::web::Element mobile("span");
      mobile << "&ltp&gt Content that only shows on small screens. Web conponents can be added as content &lt/p&gt";
      box.AddMobileContent(mobile);
      box.AddMobileContent("&ltb&gt String literals can also be added to box content! &lt/b&gt");

      doc << box;
    )";

  emp::prefab::CodeBlock comment_box_code_block(comment_box_code, "c++");
  doc << comment_box_code_block;

  doc << "<hr><br>";

  doc << "<h1>Config Panel Example</h1>";

  // apply configuration query params and config files to Config
  auto specs = emp::ArgManager::make_builtin_specs(&cfg);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  // cfg.Read("config.cfg");
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);

  // setup configuration panel
  config_panel.Setup();
  doc << config_panel.GetDiv();

  doc << "<br><h3>Code: </h3>";

  const std::string cp_code =
    R"(
      #include "web/web.h"
      #include "prefab/ConfigPanel.h"
      #include "config/ArgManager.h"
      #include "web/UrlParams.h"
      
      #include "../SampleConfig.h"

      SampleConfig cfg;
      emp::prefab::ConfigPanel config_panel(cfg);

      emp::web::Document doc("emp_base");
      
      // apply configuration query params and config files to SampleConfig
      auto specs = emp::ArgManager::make_builtin_specs(&cfg);
      emp::ArgManager am(emp::web::GetUrlParams(), specs);
      // cfg.Read("config.cfg");
      am.UseCallbacks();
      if (am.HasUnused()) std::exit(EXIT_FAILURE);

      // setup configuration panel
      config_panel.Setup();
      doc << config_panel.GetDiv();
    )";

  emp::prefab::CodeBlock cp_code_block(cp_code, "c++");
  doc << cp_code_block;

  doc << "<hr><br>";

  doc << "<h1>FontAwesome Icon Example</h1>";
  UI::Div toggleIcons;
  doc << toggleIcons;
  toggleIcons << "<p>Toggle Icons</p>";
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

  doc << "<br>More icons <a href=\"https://fontawesome.com/v4.7.0/icons/\">here</a><br>";

  doc << "<br><h3>Code:</h3>";

  const std::string icon_code =
    R"(
      #include "web/web.h"
      #include "prefab/FontAwesomeIcon.h"
      
      emp::web::Document doc("emp_base");
      
      emp::web::Div toggleIcons;
      doc << toggleIcons;
      toggleIcons << "&ltp&gt Toggle Icons &lt/p&gt";

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
    )";

  emp::prefab::CodeBlock icon_code_block(icon_code, "c++");
  doc << icon_code_block;
  doc << "<p>Add to HTML file</p>";
  const std::string icon_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock icon_html_block(icon_html, "html");
  doc << icon_html_block;

  doc << "<hr><br>";

  doc << "<h1>Loading Icon Example</h1>";
  emp::prefab::LoadingIcon spinner;
  doc << spinner;

  doc << "<br><br><h3>Code:</h3>";
  const std::string loading_code = 
    R"(
      #include "web/web.h"
      #include "prefab/LoadingIcon.h"

      emp::web::Document doc("emp_base");

      emp::prefab::LoadingIcon spinner;
      doc << spinner;
    )";
  emp::prefab::CodeBlock loading_code_block(loading_code, "c++");
  doc << loading_code_block;
  doc << "<p>Add to HTML file</p>";
  const std::string loading_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock loading_html_block(loading_html, "html");
  doc << loading_html_block;

  doc << "<hr><br>";  


  doc << "<h1>Toggle Switch Example</h1>";

  UI::Input input_element(
      [](std::string str){;},
      "checkbox", NULL, "input_id"
  );
  emp::prefab::ToggleSwitch my_switch(input_element);
  doc << my_switch;

  my_switch.AddLabel("Switch Label");

  doc << "<br><br><h3>Code:</h3>";

  const std::string toggle_code =
    R"(
      #include "web/web.h"
      #include "web/Input.h"
      #include "prefab/ToggleSwitch.h"
      
      emp::web::Document doc("emp_base");
      
      emp::web::Input input_element(
        [](std::string str){;},
        "checkbox", NULL, "input_id"
      );
      emp::prefab::ToggleSwitch my_switch(input_element);
      doc << my_switch;

      my_switch.AddLabel("Switch Label");
    )";

  emp::prefab::CodeBlock toggle_code_block(toggle_code, "c++");
  doc << toggle_code_block;

  doc << "<p>Add to HTML file</p>";
  const std::string toggle_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"&gt
    )";
  emp::prefab::CodeBlock toggle_html_block(toggle_html, "html");
  doc << toggle_html_block;

  doc << "<hr><br>";
}
