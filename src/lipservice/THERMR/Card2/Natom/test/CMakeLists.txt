
add_executable( lipservice.THERMR.Card2.Natom.test Natom.test.cpp )
target_compile_options( lipservice.THERMR.Card2.Natom.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.THERMR.Card2.Natom.test PUBLIC lipservice ) 
add_test( NAME lipservice.THERMR.Card2.Natom COMMAND lipservice.THERMR.Card2.Natom.test )