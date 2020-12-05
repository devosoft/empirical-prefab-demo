#pragma once

#include <string>

#include "emp/prefab/CodeBlock.hpp"
#include "emp/prefab/FontAwesomeIcon.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/Div.hpp"

void empirical_info( emp::web::Document& doc ) {

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
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
      <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css">
      <link rel="stylesheet/less" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@master/include/emp/prefab/DefaultPrefabStyles.less">
      <script src="https://cdn.jsdelivr.net/npm/less" ></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js">
      <script src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js"></script>
      <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical/source/prefab/HighlightJS.js"></script>
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

}
