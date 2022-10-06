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
  doc << "<p>To uses any of these tools, you'll want to add the Bootstrap, Empirical prefab components, and friends' stylesheets + js to the head of your html file. Of course you can override the style of any of the classes in these files with your own CSS file if it is linked after these two.";

  const std::string styles_code =
    R"(
      <!-- styles -->
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
      <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css">
      <link rel="stylesheet/less" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/DefaultPrefabStyles.less">

      <!-- scripts -->
      <script src="https://code.jquery.com/jquery-1.12.4.min.js" integrity="sha256-ZosEbRLbNQzLpnKIkEdrPv7lOy9C27hHQ+Xp8a4MxAQ=" crossorigin="anonymous"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/less.js/4.1.3/less.min.js" integrity="sha512-6gUGqd/zBCrEKbJqPI7iINc61jlOfH5A+SluY15IkNO1o4qP1DEYjQBewTB4l0U4ihXZdupg8Mb77VxqE+37dg==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
      <script src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js"></script>

      <!-- feature specific scripts -->
      <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/LoadingModal.js"></script>
      <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/source/prefab/HighlightJS.js"></script>
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

}
