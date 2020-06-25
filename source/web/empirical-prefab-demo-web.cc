//  This file is part of Empirical Prefab Demo
//  Copyright (C) Sara Boyd, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "web/web.h"
#include "prefab/Card.h"
#include "prefab/Collapse.h"
#include "prefab/CommentBox.h"
#include "prefab/ConfigPanel.h"
#include "prefab/FontAwesomeIcon.h"
#include "web/Div.h"

#include "../example.h"

namespace UI = emp::web;

UI::Document doc("emp_base");

int main()
{
  // doc << "<h1>Hello, browser!</h1>";
  std::cout << "Hello, console!" << std::endl;

  doc << "<p>These prefabricated tools were created to help you quickly create interesting web applicications without being overwhelmed with the underlying HTML, CSS, and Bootstrap classes required. These tools use Empirical's web tools to provide structure for the site, and many of the prefab tools inherit from web tools so you can add your own styling and stream them into other web components in a similar way.</p>";

  doc << "<h1>Card Example</h1>";
  // Collapsible Card, default open
  emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
  doc << openCard;
  // Header content with bootstrap link properties
  openCard.AddHeaderContent("Open card");
  openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");
  openCard.SetCSS("margin-bottom", "15px");

  doc << "<h3>Code:</h3>";

  emp::web::Element card_pre("pre");
  emp::web::Element card_code("code");
  card_code.SetAttr("class", "c++");
  doc << card_pre << card_code;
  // card_code << "emp::web::Div link_ele;\nemp::web::Div toggle_ele;\nint i = 7;";
  
     const std::string str =
R"(
#include "prefab/Card.h"

emp::prefab::Card openCard(emp::prefab::Card::Collapse::OPEN, true);
doc << openCard;
// Header content with bootstrap link properties
openCard.AddHeaderContent("Open card");
openCard.AddBodyContent("Open body content <br> Glyphs <br> Linked title");
openCard.SetCSS("margin-bottom", "15px");
)";
card_code << str;

emscripten_run_script("hljs.initHighlighting.called = false; hljs.initHighlighting();");
  doc << "<hr>";


  doc << "<h1>Collapse Example</h1>";
  UI::Div btn;
  UI::Div content;

  emp::prefab::Collapse collapse(btn, content, true, "my_collapse");
  doc << collapse.GetLinkDiv();
  doc << collapse.GetToggleDiv();

  btn.SetAttr("class", "btn btn-info");
  btn << "Click me 1";
  content << "This content starts out open and has an id of 'my_collapse'.<hr>";
  content << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
  content.SetCSS(
    "width", "45%",
    "margin", "15px",
    "border", "1px solid #ede9e8",
    "border-radius", "5px",
    "padding", "10px"
  );
  doc << "<h3>Code:</h3>";

  doc << "<hr>";

  doc << "<h1>Comment Box Example</h1>";
  emp::prefab::CommentBox box;
    UI::Div title("desktop_content");
    title << "<p>Content that shows on all screen sizes</p>";
    box.AddContent(title);
    UI::Element mobile("span");
    mobile << "<p>Content that only shows on small screens <br>Web conponents can be added as content</p>";
    mobile << "<hr>";
    box.AddMobileContent(mobile);
    box.AddMobileContent("<b>String literals can also be added to box content!</b>");
    doc << box;

  doc << "<h3>Code:</h3>";

  doc << "<hr>";

  doc << "<h1>FontAwesome Icon Example</h1>";
  UI::Div toggleIcons;
  doc << toggleIcons;
  toggleIcons << "<p>Toggle Icons</p>";
  emp::prefab::FontAwesomeIcon up("fa-angle-double-up");
  toggleIcons << up;
  emp::prefab::FontAwesomeIcon down("fa-angle-double-down");
  toggleIcons << down;
  emp::prefab::FontAwesomeIcon right("fa-angle-double-right");
  toggleIcons << right;
  emp::prefab::FontAwesomeIcon left("fa-angle-double-left");
  toggleIcons << left;
  up.SetCSS("margin-left", "15px");
  down.SetCSS("margin-left", "15px");
  right.SetCSS("margin-left", "15px");
  left.SetCSS("margin-left", "15px");

  doc << "<h3>Code:</h3>";

  doc << "<hr>";
}
