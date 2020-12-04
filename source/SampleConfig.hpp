#pragma once

#include "config/config.h"

EMP_BUILD_CONFIG( SampleConfig,
  GROUP(MAIN, "Global settings"),
  VALUE(SEED, int, -1, "Random number generator seed"),
  VALUE(TIME_STEPS, int, 1000, "Number of time steps to run for"),
  VALUE(PLATE_LENGTH, double, 10.0, "Length of plate in mm"),
  VALUE(PLATE_WIDTH, double, 6.0, "Width of plate in mm"),
  VALUE(PLATE_DEPTH, double, 1.45, "Depth of plate in mm"),
  VALUE(CELL_DIAMETER, double, 20.0, "Cell length and width in microns"),
  VALUE(INIT_POP_SIZE, int, 100, "Number of cells to seed population with"),
  VALUE(DATA_RESOLUTION, int, 10, "How many updates between printing data?"),
  VALUE(SAMPLE_TEXT_INPUT, std::string, "none", "Input textbox"),
  VALUE(SAMPLE_BOOLEAN_INPUT, bool, true, "Bool defaulted to on"),
);
