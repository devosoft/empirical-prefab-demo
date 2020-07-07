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
#include "prefab/LoadingModal.h"
#include "prefab/Modal.h"
#include "prefab/ToggleSwitch.h"

#include "../example.h"
#include "../SampleConfig.h"
#include "config/ArgManager.h"
#include "web/UrlParams.h"

namespace UI = emp::web;

UI::Document doc("emp_base");

SampleConfig cfg;

int main()
{
  emp::prefab::ConfigPanel & config_panel = *(new emp::prefab::ConfigPanel(cfg));

  std::cout << "Hello, console!" << std::endl;

  doc << "<p>These prefabricated tools were created to help you quickly create interesting web applicications without being overwhelmed with the underlying HTML, CSS, and Bootstrap classes required. These tools use Empirical's web tools to provide structure for the site, and many of the prefab tools inherit from web tools so you can add your own styling and stream them into other web components in a similar way.</p>";
  doc << "<p>To uses any of these tools, you'll want to add the Bootstrap and Empirical's DefaultConfigStyle stylesheet to the head of your html file. Of course you can override the style of any of the classes in these files with your own CSS file if it is linked after these two.";

  // TODO: When prefab branch is merged into master, need to remove @prefab in in jsDelivr links
  const std::string styles_code = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"&gt
      &ltlink rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@prefab/source/prefab/DefaultConfigPanelStyle.css"&gt
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

  // ------ Card Example ------
  emp::prefab::Card card_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << card_ex;
  card_ex.AddHeaderContent("<h3>Card Example</h3>");
  // Collapsible Card, default open
  emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
  card_ex.AddBodyContent(openCard);
  // Header content with bootstrap link properties
  openCard.AddHeaderContent("Open card");
  openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");
  openCard.SetCSS("margin-bottom", "15px");

  card_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");
  
  const std::string card_code =
    R"(
      #include "web/web.h"
      #include "prefab/Card.h"

      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
        doc << openCard;
        
        openCard.AddHeaderContent("Open card");
        openCard.AddBodyContent("Open body content &ltbr&gt Glyphs &ltbr&gt Linked title");

        openCard.SetCSS("margin-bottom", "15px");
      }
    )";

  emp::prefab::CodeBlock card_code_block(card_code, "c++");
  card_ex.AddBodyContent(card_code_block);
  card_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string card_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock card_html_block(card_html, "c++");
  card_ex.AddBodyContent(card_html_block);

  // ------ Code Block Example ------
  emp::prefab::Card code_block_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << code_block_ex;
  code_block_ex.AddHeaderContent("<h3>Code Block Example</h1");

  const std::string code_block_code = 
    R"(
      #include "web/web.h"
      #include "prefab/CodeBlock.h"

      emp::web::Document doc("emp_base");

      int main(){
        const std::string inner_code = 
          R&quot(
            int num = 9;
            std::cout << num << " is a square number" << std::endl;
          )&quot;

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
      &ltlink rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css"&gt
      &ltscript src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js"&gt&lt/script&gt
      &ltscript&gt hljs.initHighlightingOnLoad();&lt/script&gt    
    )";
  emp::prefab::CodeBlock cb_html_block(cb_html, "html");
  code_block_ex.AddBodyContent(cb_html_block);

  // ------ Collapse Example ------
  emp::prefab::Card collapse_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << collapse_ex;
  collapse_ex.AddHeaderContent("<h3>Collapse Example</h3>");
  UI::Div btn;
  UI::Div content;

  emp::prefab::Collapse collapse(btn, content, true, "my_collapse");
  collapse_ex.AddBodyContent(collapse.GetLinkDiv());
  collapse_ex.AddBodyContent(collapse.GetToggleDiv());

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
  collapse_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");

  const std::string collapse_code =
    R"(
      #include "web/web.h"
      #include "prefab/Collapse.h"
      
      emp::web::Document doc("emp_base");
      
      int main(){
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
      }
    )";

  emp::prefab::CodeBlock collapse_code_block(collapse_code, "c++");
  collapse_ex.AddBodyContent(collapse_code_block);

  // ------ Comment Box Example ------
  emp::prefab::Card comment_box_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << comment_box_ex;
  comment_box_ex.AddHeaderContent("<h3>Comment Box Example</h3>");
  emp::prefab::CommentBox box;
  comment_box_ex.AddBodyContent(box);
  UI::Div title("desktop_content");
  title << "<p>Content that shows on all screen sizes</p>";
  box.AddContent(title);
  UI::Element mobile("span");
  mobile << "<p>Content that only shows on small screens <br>Web conponents can be added as content</p>";
  mobile << "<hr>";
  box.AddMobileContent(mobile);
  box.AddMobileContent("<b>String literals can also be added to boxes!</b>");

  comment_box_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");

  const std::string comment_box_code =
    R"(
      #include "web/web.h"
      #include "prefab/CommentBox.h"
      
      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::CommentBox box;
        doc << box;

        emp::web::Div title("desktop_content");
        title << "&ltp&gt Content that shows on all screen sizes &lt/p&gt";
        box.AddContent(title);

        emp::web::Element mobile("span");
        mobile << "&ltp&gt Content that only shows on small screens. Web conponents can be added as content &lt/p&gt";
        box.AddMobileContent(mobile);
        box.AddMobileContent("&ltb&gt String literals can also be added to box content! &lt/b&gt");
      }
    )";

  emp::prefab::CodeBlock comment_box_code_block(comment_box_code, "c++");
  comment_box_ex.AddBodyContent(comment_box_code_block);

  // ------ Config Panel Example ------
  emp::prefab::Card config_panel_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << config_panel_ex;
  config_panel_ex.AddHeaderContent("<h3>Config Panel Example</h3>");

  // apply configuration query params and config files to Config
  auto specs = emp::ArgManager::make_builtin_specs(&cfg);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  // cfg.Read("config.cfg");
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);

  // setup configuration panel
  config_panel.Setup();
  config_panel_ex.AddBodyContent(config_panel.GetDiv());

  config_panel_ex.AddBodyContent("<br><hr><br><h3>Code: </h3>");

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
  emp::prefab::Card fa_icon_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << fa_icon_ex;
  fa_icon_ex.AddHeaderContent("<h3>FontAwesome Icon Example</h3>");

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

  fa_icon_ex.AddBodyContent("<br>More icons <a href=\"https://fontawesome.com/v4.7.0/icons/\">here</a><br>");

  fa_icon_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");

  const std::string icon_code =
    R"(
      #include "web/web.h"
      #include "prefab/FontAwesomeIcon.h"
      
      emp::web::Document doc("emp_base");
      
      int main(){
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
      }
    )";

  emp::prefab::CodeBlock icon_code_block(icon_code, "c++");
  fa_icon_ex.AddBodyContent(icon_code_block);
  fa_icon_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string icon_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock icon_html_block(icon_html, "html");
  fa_icon_ex.AddBodyContent(icon_html_block);

  // ------ Loading Icon Example ------
  emp::prefab::Card loading_icon_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << loading_icon_ex;
  loading_icon_ex.AddHeaderContent("<h3>Loading Icon Example</h3>");
  emp::prefab::LoadingIcon spinner;
  loading_icon_ex.AddBodyContent(spinner);

  loading_icon_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");
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
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"&gt
    )";
  emp::prefab::CodeBlock loading_html_block(loading_html, "html");
  loading_icon_ex.AddBodyContent(loading_html_block);

  // ------ Loading Modal Example ------
  emp::prefab::Card loading_modal_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << loading_modal_ex;
  loading_modal_ex.AddHeaderContent("<h3>Loading Modal Example</h3>");

  loading_modal_ex.AddBodyContent("<p>Click button to show loading modal. It will close automatically after a few seconds.</p>");
  UI::Button loading_modal_demo([](){emscripten_run_script("DemoLoadingModal();");}, "Show Loading Modal");
  loading_modal_ex.AddBodyContent(loading_modal_demo);
  loading_modal_demo.SetAttr(
    "class", "btn btn-info"
  );

  loading_modal_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");
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
  // TODO: When prefab branch is merged into master, need to remove @prefab in in jsDelivr links
  const std::string loading_modal_html =
    R"(
      &lthtml&gt
      &lthead&gt
        &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"&gt
        &ltscript src="jquery-1.11.2.min.js&gt&lt/script&gt
        &ltscript src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" integrity="sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh" crossorigin="anonymous"&gt&lt/script&gt
        &ltscript src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" integrity="sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ" crossorigin="anonymous"&gt&lt/script&gt
        &ltlink rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@prefab/source/prefab/DefaultConfigPanelStyle.css"&gt
      &lt/head&gt

      &ltbody&gt
        &ltscript src="https://cdn.jsdelivr.net/gh/devosoft/Empirical@prefab/source/prefab/LoadingModal.js"&gt&lt/script&gt
        &lt!-- Rest of web page --&gt
      &lt/body&gt
      &lt/html&gt
    )";
  emp::prefab::CodeBlock loading_modal_code_block_html(loading_modal_html, "html");
  loading_modal_ex.AddBodyContent(loading_modal_code_block_html);

  // ------ Modal Example ------
  emp::prefab::Card modal_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << modal_ex;
  modal_ex.AddHeaderContent("<h3>Modal Example</h3>");
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

  modal_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");
  const std::string modal_code =
    R"(
      #include "web/web.h"
      #include "web/Button.h"
      #include "prefab/Modal.h"
      
      emp::web::Document doc("emp_base");

      int main(){
        emp::prefab::Modal modal;
        doc << modal;

        modal.AddHeaderContent("&lth3&gtModal Header Section&lt/h3&gt");
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
  emp::prefab::Card toggle_switch_ex(emp::prefab::Card::Collapse::CLOSED, true);
  doc << toggle_switch_ex;
  toggle_switch_ex.AddHeaderContent("<h3>Toggle Switch Example</h3>");

  UI::Input input_element(
      [](std::string str){;},
      "checkbox", NULL, "input_id"
  );
  emp::prefab::ToggleSwitch my_switch(input_element);
  toggle_switch_ex.AddBodyContent(my_switch);

  my_switch.AddLabel("Switch Label");

  toggle_switch_ex.AddBodyContent("<br><hr><br><h3>Code:</h3>");

  const std::string toggle_code =
    R"(
      #include "web/web.h"
      #include "web/Input.h"
      #include "prefab/ToggleSwitch.h"
      
      emp::web::Document doc("emp_base");
      
      int main(){
        emp::web::Input input_element(
          [](std::string str){;},
          "checkbox", NULL, "input_id"
        );
        emp::prefab::ToggleSwitch my_switch(input_element);
        doc << my_switch;

        my_switch.AddLabel("Switch Label");
      }
    )";

  emp::prefab::CodeBlock toggle_code_block(toggle_code, "c++");
  toggle_switch_ex.AddBodyContent(toggle_code_block);

  toggle_switch_ex.AddBodyContent("<p>Add to HTML file</p>");
  const std::string toggle_html = 
    R"(
      &ltlink rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"&gt
    )";
  emp::prefab::CodeBlock toggle_html_block(toggle_html, "html");
  toggle_switch_ex.AddBodyContent(toggle_html_block);


  emp::prefab::CloseLoadingModal();
}
