
add_executable( lipservice.ERRORR.Normal.Card8a.Mts.test Mts.test.cpp )
target_compile_options( lipservice.ERRORR.Normal.Card8a.Mts.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.ERRORR.Normal.Card8a.Mts.test PUBLIC lipservice ) 
add_test( NAME lipservice.ERRORR.Normal.Card8a.Mts COMMAND lipservice.ERRORR.Normal.Card8a.Mts.test )