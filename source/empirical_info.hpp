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
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css" integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" crossorigin="anonymous">
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">
      <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/styles/default.min.css" integrity="sha384-s4RLYRjGGbVqKOyMGGwfxUTMOO6D7r2eom7hWZQ6BjK2Df4ZyfzLXEkonSm0KLIQ" crossorigin="anonymous">
      <link rel="stylesheet/less" type="text/css" href="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/DefaultPrefabStyles.less" integrity="sha384-sq4+UmPTB19bGYpxuyAuWqL98Vu3/sP0K189i4Q9YjtoT75W6Y8SSaAE1hfsMfVq" crossorigin="anonymous">

      <!-- scripts -->
      <script src="https://code.jquery.com/jquery-1.12.4.min.js" integrity="sha256-ZosEbRLbNQzLpnKIkEdrPv7lOy9C27hHQ+Xp8a4MxAQ=" crossorigin="anonymous"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/less.js/4.1.3/less.min.js" integrity="sha512-6gUGqd/zBCrEKbJqPI7iINc61jlOfH5A+SluY15IkNO1o4qP1DEYjQBewTB4l0U4ihXZdupg8Mb77VxqE+37dg==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js" integrity="sha384-OgVRvuATP1z7JjHLkuOU7Xw704+h835Lr+6QL9UvYjZE3Ipu6Tp75j7Bh/kR0JKI" crossorigin="anonymous"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/10.0.0/highlight.min.js" integrity="sha384-lSDOH2m65GTr3YMjQmtQouX6jV/Xb6y1HNztdW5HsGrpSXTLt6CL/BesSu+6M0ow" crossorigin="anonymous"></script>

      <!-- feature specific scripts -->
      <script src="https://cdn.jsdelivr.net/gh/devosoft/Empirical@26dbbe3/include/emp/prefab/HighlightJS.js" integrity="sha384-Zfh3BfaS9t0VPODZ8NapeEOmrLkeT64Q28jbnxFLJ6ebS23iYWGoydQTNkp1qLUl" crossorigin="anonymous"></script>
    )";
  emp::prefab::CodeBlock styles(styles_code, "html");
  doc << styles;

}
