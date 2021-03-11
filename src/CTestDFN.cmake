# Code testing. Please run these before Pushing or PR
enable_testing()

# Simple
add_test(NAME Minimal COMMAND dfnTest "examples/minimal.jsonc" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Minimal2 COMMAND dfnTest "examples/minimal3Da.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# Snapping and incorporating faces of the mesh
add_test(NAME Incorporate_1 COMMAND dfnTest "examples/minimal-incorporate.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Incorporate_2 COMMAND dfnTest "examples/incorporate-lvl2.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Tetrahedra_0 COMMAND dfnTest "examples/tetrahedra0.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Tetrahedra_1 COMMAND dfnTest "examples/tetrahedra1.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Tetrahedra_2 COMMAND dfnTest "examples/tetrahedra2.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# Limit recovery
add_test(NAME FracLimits1 COMMAND dfnTest "examples/fraclimits1.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME FracLimits2 COMMAND dfnTest "examples/fraclimits2.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME FracLimits3 COMMAND dfnTest "examples/fraclimits3.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME FracLimits4 COMMAND dfnTest "examples/fraclimits4.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME FracLimits5 COMMAND dfnTest "examples/fraclimits5.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Octagon COMMAND dfnTest "examples/exampleOctagon.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# Snap Induced Overlap
# add_test(NAME SnapOverlap1 COMMAND dfnTest "examples/bug_snap_overlap.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# Frac 3D benchmarks
add_test(NAME Fl_Benchmark_1 COMMAND dfnTest "examples/flemisch_benchmark/flemisch_case1.txt" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_test(NAME Fl_Benchmark_2 COMMAND dfnTest "examples/flemisch_benchmark/fl_case2.json" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})