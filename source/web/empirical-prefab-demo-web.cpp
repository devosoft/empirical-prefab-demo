//  This file is part of Empirical Prefab Demo
//  Copyright (C) Sara Boyd, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "emp/config/ArgManager.hpp"
#include "emp/prefab/LoadingModal.hpp"
#include "emp/web/web.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/UrlParams.hpp"

#include "../card_example.hpp"
#include "../code_block_example.hpp"
#include "../collapse_example.hpp"
#include "../comment_box_example.hpp"
#include "../config_panel_example.hpp"
#include "../control_panel_example.hpp"
#include "../empirical_info.hpp"
#include "../font_awesome_icon_example.hpp"
#include "../loading_icon_example.hpp"
#include "../modal_example.hpp"
#include "../readout_panel_example.hpp"
#include "../toggle_switch_example.hpp"

emp::web::Document doc("emp_base");

int main() {

  std::cout << "Hello, console!" << std::endl;

  empirical_info( doc );

  card_example( doc );
  code_block_example( doc );
  collapse_example( doc );
  comment_box_example( doc );
  config_panel_example( doc );
  control_panel_example( doc );
  font_awesome_icon_example( doc );
  loading_icon_example( doc );
  modal_example( doc );
  readout_panel_example( doc );
  toggle_switch_example( doc );

  emp::prefab::CloseLoadingModal();

  std::cout << "prefab demo setup success!" << std::endl;
}
