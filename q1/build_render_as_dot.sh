#!/bin/bash
set -euo pipefail

g++ render_as_dot.cpp string_set.cpp tree.cpp -o render_as_dot
